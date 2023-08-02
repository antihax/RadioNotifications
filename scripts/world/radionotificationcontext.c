/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2022 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

#ifndef SERVER
// Our context class for the transmitters.
class RadioNotificationTransmitterContext {
	protected ref Timer m_VoiceDequeue;
	protected ref array<RadioNotificationEvent> m_RadioNotificationQueue = {};
	protected ref RadioNotificationEvent m_CurrentRadioNotificationEvent;
	protected ref Timer m_ActiveVoiceCancelTimer;

	// Active Voices for the current notification
	protected ref EffectSound m_ActiveVoiceSound;
	protected ref EffectSound m_ActiveNoiseSound;
	protected float m_VoiceVolume = 0;
	protected float m_NoiseVolume = 0;
	protected bool m_PlayingNoise = false;
	protected bool m_PlayingVoice = false;

	// Parent
	protected TransmitterBase m_Transmitter;

	void RadioNotificationTransmitterContext(TransmitterBase _transmitter) {
		m_Transmitter = _transmitter;
		m_ActiveVoiceCancelTimer = new Timer(CALL_CATEGORY_GAMEPLAY);

		m_VoiceDequeue = new Timer(CALL_CATEGORY_SYSTEM);
		m_VoiceDequeue.Run(0.25, this, "RunVoiceDequeue", null, true);
		GetRadioNotificationClientHandler().Event_RadioNotification.Insert(On_RadioNotification);
	}

	void ~RadioNotificationTransmitterContext() {
		// We can race deleting these this stack.
		if (GetRadioNotificationClientHandler())
			GetRadioNotificationClientHandler().Event_RadioNotification.Remove(On_RadioNotification);

		// remove voice cancel timer
		if (m_ActiveVoiceCancelTimer) {
			m_ActiveVoiceCancelTimer.Stop();
			delete m_ActiveVoiceCancelTimer;
		}

		// remove voice dequeue
		if (m_VoiceDequeue) {
			m_VoiceDequeue.Stop();
			delete m_VoiceDequeue;
		}

		// Remove active sounds; they autodelete
		if (m_ActiveVoiceSound)
			m_ActiveVoiceSound.SoundStop();
		if (m_ActiveNoiseSound)
			m_ActiveNoiseSound.SoundStop();
	}

	void On_RadioNotification(RadioNotificationEvent e) {

		// Too far, ignore
		float distanceMultiplier = GetRadioNotificationClientHandler().m_Settings.baseRadioMultiplier;
		float distance = Math.AbsFloat(vector.Distance(m_Transmitter.GetPosition(), e.position)) / distanceMultiplier;
		float MAX_DISTANCE = GetRadioNotificationClientHandler().m_Settings.maxDistance;
		float IGNORE_DISTANCE = GetRadioNotificationClientHandler().m_Settings.ignoreDistance;
		if (distance < (MAX_DISTANCE + IGNORE_DISTANCE)) {
			// Make a copy so we don't race playing the same notification.
			m_RadioNotificationQueue.Insert(e.Clone());
		}
	}

	// NextSegment plays audio in order.
	// Event_OnSoundWaveEnded calls again for next segment.
	// Return is our exit from the loop.
	void NextSegment() {
		string a;

		// Something broke.
		if (!m_CurrentRadioNotificationEvent) {
			NoiseStop();
			return;
		}

		switch (m_CurrentRadioNotificationEvent.state) {
		case 0: // Preamble
			m_CurrentRadioNotificationEvent.state = 1;
			if (m_CurrentRadioNotificationEvent.preamble != 255)
				a = "RadioNotification_Preamble" + m_CurrentRadioNotificationEvent.preamble.ToString();
			break;

		case 1: // Phonetics
			if (m_CurrentRadioNotificationEvent.phonetics.Count() > 0) {
				auto p = m_CurrentRadioNotificationEvent.phonetics.Get(0);
				m_CurrentRadioNotificationEvent.phonetics.RemoveOrdered(0);
				if (p < 0) {
					Print("RadioNotification::NextSegment Invalid phonetic " + p.ToString());
					m_CurrentRadioNotificationEvent.state = 3;
					break;
				}

				a = "RadioNotification_Voice" + m_CurrentRadioNotificationEvent.voice.ToString() + "_Phonetic" + p.ToString();
			} else
				m_CurrentRadioNotificationEvent.state = 2;
			break;

		case 2: // Signature
			m_CurrentRadioNotificationEvent.state = 3;
			if (m_CurrentRadioNotificationEvent.signature != 255)
				a = "RadioNotification_Preamble" + m_CurrentRadioNotificationEvent.signature.ToString();
			break;

		case 3:
			NoiseStop();
			return; // exit the loop
		}

		if (a != "") {
			m_ActiveVoiceSound = PlaySoundSet(a, false, true);
		} else
			NextSegment();
	}

	void Event_OnSoundWaveStarted() {
		m_PlayingVoice = true;
	}

	void Event_OnSoundWaveStartedVolumes() {
		UpdateVolumes();
	}

	void Event_OnSoundWaveEnded() {
		m_ActiveVoiceCancelTimer.Stop();
		if (m_PlayingVoice) {
			m_PlayingVoice = false;
			NextSegment();
		}

		UpdateVolumes();
	}

	void NoiseStop() {
		if (m_ActiveNoiseSound)
			m_ActiveNoiseSound.SoundStop();
		if (m_ActiveVoiceSound)
			m_ActiveVoiceSound.SoundStop();

		if (m_CurrentRadioNotificationEvent)
			delete m_CurrentRadioNotificationEvent;
		m_CurrentRadioNotificationEvent = null;

		m_ActiveVoiceCancelTimer.Stop();
		m_PlayingNoise = false;
		m_PlayingVoice = false;
		UpdateVolumes();
	}

	// Dequeue and play the next notification in the queue. These will be a
	// slightly bit desynced.
	void RunVoiceDequeue() {
		UpdateVolumes();
		if (m_RadioNotificationQueue.Count() == 0 || m_PlayingNoise)
			return;

		// Why is this not atomic?
		m_CurrentRadioNotificationEvent = m_RadioNotificationQueue.Get(0);
		m_RadioNotificationQueue.Remove(0);

		// Check it wasn't deleted while we dequeued.
		if (!m_CurrentRadioNotificationEvent) {
			Print("RadioNotification::RunVoiceDequeue m_CurrentRadioNotificationEvent is null");
			NoiseStop();
			return;
		}

		// Start noise
		m_PlayingNoise = true;
		// [TODO] figure out how many noise samples there are
		if (GetRadioNotificationClientHandler().m_Settings.randomNoise)
			m_CurrentRadioNotificationEvent.noise = Math.RandomInt(0, 8);

		string n = "RadioNotification_Noise" + m_CurrentRadioNotificationEvent.noise.ToString();
		m_ActiveNoiseSound = PlaySoundSet(n, true);

		// Start sequencing after the pause
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(NextSegment, 1 + (m_CurrentRadioNotificationEvent.pause * 1000), false);
	}

	EffectSound PlaySoundSet(string voiceName, bool loop = false, bool notify = false) {
		EffectSound s = SEffectManager.PlaySoundOnObject(voiceName, m_Transmitter);
		if (!s) {
			Error("Sound failed to play" + voiceName);
			return s;
		}

		s.SetSoundAutodestroy(true);
		s.SetSoundLoop(loop);
		// This is a hack to fix a bug preventing setting volumes on sounds.
		if (notify) {
			// Set a timeout to kill the sound if it doesn't start.
			m_ActiveVoiceCancelTimer.Run(s.GetLength() + 1.25, this, "TimeoutAudio", null, false);

			s.Event_OnSoundWaveStarted.Insert(Event_OnSoundWaveStarted);
			s.Event_OnSoundWaveStarted.Insert(Event_OnSoundWaveStartedVolumes);
			s.Event_OnSoundWaveEnded.Insert(Event_OnSoundWaveEnded);
		} else {
			s.Event_OnSoundWaveStarted.Clear();
			s.Event_OnSoundWaveEnded.Clear();
			s.Event_OnSoundWaveStarted.Insert(Event_OnSoundWaveStartedVolumes);
		}

		return s;
	}

	void TimeoutAudio() {
		NextSegment();
	}

	// Update the volumes of the active sounds based on distance.
	void UpdateVolumes() {
		// If we are not playing anything, don't bother.
		if (!m_CurrentRadioNotificationEvent)
			return;

		// Hopefully this gets optimized out, but for readability sake.
		float MAX_VOLUME = GetRadioNotificationClientHandler().m_Settings.maxVolume;
		float MIN_VOLUME = GetRadioNotificationClientHandler().m_Settings.minVolume;
		float MAX_DISTANCE = GetRadioNotificationClientHandler().m_Settings.maxDistance;

		float distanceMultiplier = 1.0;
		if (m_Transmitter.GetType() == "BaseRadio")
			distanceMultiplier = GetRadioNotificationClientHandler().m_Settings.baseRadioMultiplier;

		// Noise louder the further, voice louder the closer.
		float distance = Math.AbsFloat(vector.Distance(m_Transmitter.GetPosition(), m_CurrentRadioNotificationEvent.position)) / distanceMultiplier;
		m_VoiceVolume = Math.Clamp(1 - (distance / MAX_DISTANCE), MIN_VOLUME, MAX_VOLUME);
		m_NoiseVolume = Math.Clamp(distance / MAX_DISTANCE, MIN_VOLUME, MAX_VOLUME);

		// If the radio is off, or we are too far, silence.
		// If we are not on the right channel, silence.
		// [TODO] Remove the modulo if they fix GetTunedFrequencyIndex > 7 bug.
		if (!m_Transmitter.IsOn() || distance > MAX_DISTANCE || m_Transmitter.GetTunedFrequencyIndex() % 8 != GetRadioNotificationClientHandler().m_Settings.radioChannel) {
			m_VoiceVolume = 0.0;
			m_NoiseVolume = 0.0;
		}

		// DayZ bug, SetSoundVolume does not work on first frame
		if (m_ActiveVoiceSound) {
			m_ActiveVoiceSound.SetSoundMaxVolume(m_VoiceVolume);
			m_ActiveVoiceSound.SetSoundVolume(m_VoiceVolume);
		}
		if (m_ActiveNoiseSound) {
			m_ActiveNoiseSound.SetSoundMaxVolume(m_NoiseVolume);
			m_ActiveNoiseSound.SetSoundVolume(m_NoiseVolume);
		}
	}

	// Radio back on
	void OnWorkStart() { UpdateVolumes(); }

	// Kill all sound when turned off
	void OnWorkStop() {
		// DayZ bug, SetSoundVolume does not work on first frame
		if (m_ActiveVoiceSound) {
			m_ActiveVoiceSound.SetSoundMaxVolume(0);
			m_ActiveVoiceSound.SetSoundVolume(0);
		}
		if (m_ActiveNoiseSound) {
			m_ActiveNoiseSound.SetSoundMaxVolume(0);
			m_ActiveNoiseSound.SetSoundVolume(0);
		}
	}
}
#endif