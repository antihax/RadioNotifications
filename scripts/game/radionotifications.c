/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

#define RADIONOTIFICATIONS

class RadioNotificationEvent {
	int preamble;
	int voice;
	int noise;
	int signature;
	ref array<int> phonetics = {};
	int pause;

	// Non-replicated
	int delay;
	int repeat;

	[NonSerialized()] vector position = "0 0 0";
	[NonSerialized()] int heading = 0;
	[NonSerialized()] int state = 0;
	[NonSerialized()] int ticks = 0;
	[NonSerialized()] int lastTime = 0;

	void RadioNotificationEvent(int _preamble = -1, int _voice = 0, int _noise = 0, int _signature = -1, array<int> _phonetics = null, int _pause = 0, int _delay = 300, int _repeat = 3, vector _position = "0 0 0", int _heading = 0) {
		preamble = _preamble;
		voice = _voice;
		noise = _noise;
		signature = _signature;
		if (_phonetics) {
			phonetics.InsertAll(_phonetics);
		}
		pause = _pause;
		repeat = _repeat;
		delay = _delay;
		position = _position;
		heading = _heading;
	}

	void ~RadioNotificationEvent() {
		delete phonetics;
	}

	RadioNotificationEvent Clone() {
		RadioNotificationEvent e = new RadioNotificationEvent(preamble, voice, noise, signature, phonetics, pause, delay, repeat, position, heading);
		e.state = state;
#ifdef RADIONOTIFICATIONS_DEBUG
		Print(e.Dump());
#endif
		return e;
	}

	string Dump() {
		return string.Format("RadioNotificationEvent: %1 %2 %3 %4 %5 %6 %7 %8 %9", preamble, voice, noise, signature, phonetics, pause, delay, repeat, position);
	}

	bool SerializeRPC(BitStreamWriter ctx) {
		auto settings = GetRadioNotificationSettings();
		ctx.WriteRangedInt(preamble, 0, settings.numPreambles);
		ctx.WriteRangedInt(voice, 0, settings.numVoices);
		ctx.WriteRangedInt(noise, 0, settings.numNoises);
		ctx.WriteRangedInt(signature, 0, settings.numPreambles);
		ctx.WriteHalfVector(position);
		ctx.WriteRangedInt(heading, -360, 360);
		ctx.WriteRangedInt(pause, 0, 7);
		ctx.WriteRangedInt(phonetics.Count(), 0, 255);

		for (int i = 0; i < phonetics.Count(); ++i)
			if (!ctx.WriteRangedInt(phonetics[i], 0, 150))
				return false;

		return true;
	}

	bool DeserializeRPC(BitStreamReader ctx) {
		auto settings = GetRadioNotificationSettings();
		ctx.ReadRangedInt(preamble, 0, settings.numPreambles);
		ctx.ReadRangedInt(voice, 0, settings.numVoices);
		ctx.ReadRangedInt(noise, 0, settings.numNoises);
		ctx.ReadRangedInt(signature, 0, settings.numPreambles);
		ctx.ReadHalfVector(position);
		ctx.ReadRangedInt(heading, -360, 360);
		ctx.ReadRangedInt(pause, 0, 7);

		int len, p;
		ctx.ReadRangedInt(len, 0, 255);

		while (len--) {
			if (!ctx.ReadRangedInt(p, 0, 150))
				return false;
			phonetics.Insert(p);
		}
		return true;
	}
}

class RadioNotificationAlarmEvent {
	int alarm;
	int radius;
	[NonSerialized()] vector position = "0 0 0";
	[NonSerialized()] int state = 0;

	void RadioNotificationAlarmEvent(int _alarm = 255, int _radius = 100, vector _position = "0 0 0") {
		alarm = _alarm;
		radius = _radius;
		position = _position;
	}

	void ~RadioNotificationAlarmEvent() {
	}

	string Dump() {
		return string.Format("RadioNotificationAlarmEvent: %1 %2 %3 %4", alarm, radius, position, state);
	}

	RadioNotificationAlarmEvent Clone() {
		RadioNotificationAlarmEvent e = new RadioNotificationAlarmEvent(alarm, radius, position);
		e.state = state;
#ifdef RADIONOTIFICATIONS_DEBUG
		Print(e.Dump());
#endif
		return e;
	}

	bool SerializeRPC(BitStreamWriter ctx) {
		auto settings = GetRadioNotificationSettings();
		if (!ctx.WriteRangedInt(alarm, 0, settings.numAlarms))
			return false;
		if (!ctx.WriteRangedInt(radius, 100, 1000))
			return false;
		return ctx.WriteHalfVector(position);
	}

	bool DeserializeRPC(BitStreamReader ctx) {
		auto settings = GetRadioNotificationSettings();
		if (!ctx.ReadRangedInt(alarm, 0, settings.numAlarms))
			return false;
		if (!ctx.ReadRangedInt(radius, 100, 1000))
			return false;
		return ctx.ReadHalfVector(position);
	}
}
