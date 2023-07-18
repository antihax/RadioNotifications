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

	// Active Voices for the current notification
	ref EffectSound m_ActiveVoiceSound;
	ref EffectSound m_ActiveNoiseSound;
	float m_VoiceVolume = 0;
	float m_NoiseVolume = 0;
	protected bool m_PlayingNoise = false;
	protected bool m_PlayingVoice = false;

	// Distance to ignore notifications. Should be a significant distance a
	// player could not move in the time it takes to play a notification.
	static const float IGNORE_THREASHOLD = 10000; // meters

	// Parent
	protected TransmitterBase m_Transmitter;

	void RadioNotificationTransmitterContext(TransmitterBase _transmitter) {
		m_Transmitter = _transmitter;
		// m_VoicePump = new Timer(CALL_CATEGORY_SYSTEM);
		// m_VoicePump.Run(15.0, this, "RunRandomVoice", null, true);
		m_VoiceDequeue = new Timer(CALL_CATEGORY_SYSTEM);
		m_VoiceDequeue.Run(1.0, this, "RunVoiceDequeue", null, true);
		GetRadioNotificationClientHandler().Event_RadioNotification.Insert(On_RadioNotification);
	}

	void ~RadioNotificationTransmitterContext() {
		// We can race deleting these this stack.
		if (GetRadioNotificationClientHandler())
			GetRadioNotificationClientHandler().Event_RadioNotification.Remove(On_RadioNotification);

		m_VoiceDequeue.Stop();
		if (m_ActiveVoiceSound)
			m_ActiveVoiceSound.SoundStop();
		if (m_ActiveNoiseSound)
			m_ActiveNoiseSound.SoundStop();
	}

	void On_RadioNotification(RadioNotificationEvent e) {
		// Make a copy so we don't race playing the same notification.
		m_RadioNotificationQueue.Insert(e.Clone());
	}

	// NextSegment plays audio in order.
	// Event_OnSoundWaveEnded calls again for next segment.
	// Return is our exit from the loop.
	void NextSegment() {
		string a;
		switch (m_CurrentRadioNotificationEvent.state) {
		case 0: // Preamble
			m_CurrentRadioNotificationEvent.state = 1;
			if (m_CurrentRadioNotificationEvent.preamble >= 0)
				a = "RadioNotification_Preamble" + m_CurrentRadioNotificationEvent.preamble.ToString();
			break;

		case 1: // Phonetics
			if (m_CurrentRadioNotificationEvent.phonetics.Count() > 0) {
				auto p = m_CurrentRadioNotificationEvent.phonetics.Get(0);
				m_CurrentRadioNotificationEvent.phonetics.Remove(0);
				a = "RadioNotification_Voice" + m_CurrentRadioNotificationEvent.voice.ToString() + "_Phonetic" + p.ToString();
			} else
				m_CurrentRadioNotificationEvent.state = 2;
			break;

		case 2: // Signature
			m_CurrentRadioNotificationEvent.state = 3;
			if (m_CurrentRadioNotificationEvent.signature >= 0)
				a = "RadioNotification_Preamble" + m_CurrentRadioNotificationEvent.signature.ToString();
			break;

		case 3:
			Print("RadioNotification: Finished");
			NoiseStop();
			delete m_CurrentRadioNotificationEvent;
			m_CurrentRadioNotificationEvent = null;
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
		if (m_PlayingVoice) {
			m_PlayingVoice = false;
			NextSegment();
		}
		UpdateVolumes();
	}

	void NoiseStop() {
		m_ActiveNoiseSound.SoundStop();
		m_PlayingNoise = false;
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

		// Start noise
		m_PlayingNoise = true;
		string n = "RadioNotification_Noise" + m_CurrentRadioNotificationEvent.noise.ToString();
		m_ActiveNoiseSound = PlaySoundSet(n, true);

		// Start sequencing after the pause
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(NextSegment, 1 + (m_CurrentRadioNotificationEvent.pause * 1000), false);
	}

	// Prototype, keep for testing.
	void RunRandomVoice() {
		int num_preamble = 3;
		int num_voices = 3;
		int num_noise = 3;
		int num_phonetic = 45;

		auto e = new RadioNotificationEvent();
		e.preamble = Math.RandomInt(-1, num_preamble);
		e.signature = Math.RandomInt(-1, num_preamble);
		e.noise = Math.RandomInt(0, num_noise);
		e.voice = Math.RandomInt(0, num_voices);
		e.pause = Math.RandomInt(0, 2);
		e.position = "13000 10 10000";

		for (int i = 0; i < Math.RandomInt(5, 20); i++) {
			e.phonetics.Insert(Math.RandomInt(0, num_phonetic));
		}
		m_RadioNotificationQueue.Insert(e);
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

	// Update the volumes of the active sounds based on distance.
	void UpdateVolumes() {
		// We consider the squelch to be the falloff.
		// Maybe add a random factor to the distance to cause squelch breaking?
		static const float MAX_VOLUME = 1.0;
		static const float MIN_VOLUME = 0.1;

		// [TODO] Make this a config option.
		static const float MAX_DISTANCE = 10000.0;

		// If we are not playing anything, don't bother.
		if (!m_CurrentRadioNotificationEvent)
			return;

		// The base radio gets a distance boost.
		float distanceMultiplier = 1.0;
		if (m_Transmitter.GetType() == "BaseRadio")
			distanceMultiplier = 2.5;

		// Noise louder the further, voice louder the closer.
		float distance = Math.AbsFloat(vector.Distance(m_Transmitter.GetPosition(), m_CurrentRadioNotificationEvent.position)) / distanceMultiplier;
		m_VoiceVolume = Math.Clamp(1 - (distance / MAX_DISTANCE), MIN_VOLUME, MAX_VOLUME);
		m_NoiseVolume = Math.Clamp(distance / MAX_DISTANCE, MIN_VOLUME, MAX_VOLUME);

		// If the radio is off, or we are too far, silence.
		if (!m_Transmitter.IsOn() || distance > MAX_DISTANCE) {
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