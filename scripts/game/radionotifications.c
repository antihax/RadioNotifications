/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */

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

	[NonSerialized()]
	vector position = "0 0 0";
	[NonSerialized()]
	int heading = 0;
	[NonSerialized()]
	int state = 0;
	[NonSerialized()]
	int ticks = 0;
	[NonSerialized()]
	int lastTime = 0;

	string message;

	void RadioNotificationEvent(int _preamble = -1, int _voice = 0, int _noise = 0, int _signature = -1, array<int> _phonetics = null, int _pause = 0, int _delay = 300, int _repeat = 3, vector _position = "0 0 0", int _heading = 0, string _message = "") {
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
		message = _message;
	}

	void ~RadioNotificationEvent() {
		delete phonetics;
	}

	RadioNotificationEvent Clone() {
		RadioNotificationEvent e = new RadioNotificationEvent(preamble, voice, noise, signature, phonetics, pause, delay, repeat, position, heading, message);
		e.state = state;
		return e;
	}

	bool SerializeRPC(BitStreamWriter ctx) {
		auto settings = RadioNotificationSettings.GetSettings();
		ctx.WriteRangedInt(preamble, -1, settings.numPreambles);
		ctx.WriteRangedInt(voice, 0, settings.numVoices);
		ctx.WriteRangedInt(noise, 0, settings.numNoises);
		ctx.WriteRangedInt(signature, -1, settings.numPreambles);
		ctx.WriteHalfVector(position);
		ctx.WriteRangedInt(heading, -360, 360);
		ctx.WriteRangedInt(pause, 0, 7);
		bool msg = message != "";
		ctx.WritePacked(msg);
		if (msg) {
			string newMessage = settings.GetOneTimePad().EncodeMessage(settings.GetOneTimePad().GetRandomPadNumber(), message);
			ctx.WritePacked(newMessage);
		}

		// Write Phonetics
		ctx.WriteRangedInt(phonetics.Count(), 0, 255);
		for (int i = 0; i < phonetics.Count(); ++i)
			if (!ctx.WriteRangedInt(phonetics[i], 0, 150))
				return false;

		return true;
	}

	bool DeserializeRPC(BitStreamReader ctx) {
		auto settings = RadioNotificationSettings.GetSettings();
		ctx.ReadRangedInt(preamble, -1, settings.numPreambles);
		ctx.ReadRangedInt(voice, 0, settings.numVoices);
		ctx.ReadRangedInt(noise, 0, settings.numNoises);
		ctx.ReadRangedInt(signature, -1, settings.numPreambles);
		ctx.ReadHalfVector(position);
		ctx.ReadRangedInt(heading, -360, 360);
		ctx.ReadRangedInt(pause, 0, 7);
		bool msg;
		ctx.ReadPacked(msg);
		if (msg)
			ctx.ReadPacked(message);

		// Read Phonetics
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
	bool fixed;
	[NonSerialized()]
	vector position = "0 0 0";
	[NonSerialized()]
	int state = 0;

	void RadioNotificationAlarmEvent(int _alarm = 255, int _radius = 100, bool _fixed = false, vector _position = "0 0 0") {
		alarm = _alarm;
		radius = _radius;
		fixed = _fixed;
		position = _position;
	}

	void ~RadioNotificationAlarmEvent() {
	}

	RadioNotificationAlarmEvent Clone() {
		RadioNotificationAlarmEvent e = new RadioNotificationAlarmEvent(alarm, radius, fixed, position);
		e.state = state;
		return e;
	}

	bool SerializeRPC(BitStreamWriter ctx) {
		auto settings = RadioNotificationSettings.GetSettings();
		if (!ctx.WriteRangedInt(alarm, 0, settings.numAlarms))
			return false;
		if (!ctx.WriteRangedInt(radius / 10, 0, 1000))
			return false;
		if (!ctx.WritePacked(fixed))
			return false;
		return ctx.WriteHalfVector(position);
	}

	bool DeserializeRPC(BitStreamReader ctx) {
		auto settings = RadioNotificationSettings.GetSettings();
		if (!ctx.ReadRangedInt(alarm, 0, settings.numAlarms))
			return false;
		if (!ctx.ReadRangedInt(radius, 0, 1000))
			return false;
		radius *= 10;
		if (!ctx.ReadPacked(fixed))
			return false;
		return ctx.ReadHalfVector(position);
	}
}
