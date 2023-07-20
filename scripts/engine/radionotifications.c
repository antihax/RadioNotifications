/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

#define RADIONOTIFICATIONS 1
#define RADIONOTIFICATIONS_PROFILE 1

class RadioNotificationEvent {
	int preamble;
	int voice;
	int noise;
	int signature;
	ref array<int> phonetics = {};
	int pause;
	int lifetime;

	[NonSerialized()] vector position = "0 0 0";
	[NonSerialized()] int state = 0;

	void RadioNotificationEvent(int _preamble = 255, int _voice = 0, int _noise = 0, int _signature = 255, array<int> _phonetics = null, int _pause = 0, int _lifetime = 0, vector _position = "0 0 0") {
		preamble = _preamble;
		voice = _voice;
		noise = _noise;
		signature = _signature;
		if (_phonetics) {
			phonetics.InsertAll(_phonetics);
		}
		pause = _pause;
		lifetime = _lifetime;
		position = _position;
	}

	void ~RadioNotificationEvent() {
		delete phonetics;
	}

	RadioNotificationEvent Clone() {
		RadioNotificationEvent e = new RadioNotificationEvent(preamble, voice, noise, signature, phonetics, pause, lifetime, position);
		e.state = state;
		return e;
	}

	bool SerializeRPC(Serializer ctx) {
		// Pack the 8-bit headers into 32-bit integer
		if (!ctx.Write((preamble & 0xFF) << 24 | (voice & 0xFF) << 16 | (noise & 0xFF) << 8 | signature & 0xFF)) {
			return false;
		}
		if (!ctx.Write(position)) {
			return false;
		}

		// Pad with empty phonetics until we have a multiple of 4
		// Since DayZ only allows sending 32 bit numbers we can align the phonetics to 32 bit
		while (phonetics.Count() % 4) {
			phonetics.Insert(255);
		}

		// Pack the pause and packed phonetics length as 16 bit into 32-bit integer
		int len = phonetics.Count() / 4;
		if (!ctx.Write((pause & 0xFFFF) << 16 | len & 0xFFFF)) {
			return false;
		}

		// Pack the 8-bit phonetics into 32-bit integers
		for (int i = 0; i < phonetics.Count(); i += 4) {
			if (!ctx.Write((phonetics[i] & 0xFF) << 24 | (phonetics[i + 1] & 0xFF) << 16 | (phonetics[i + 2] & 0xFF) << 8 | phonetics[i + 3] & 0xFF)) {
				return false;
			}
		}

		return true;
	}

	bool DeserializeRPC(Serializer ctx) {
		int p, len;

		// Unpack header 8-bit headers from 32-bit integer
		if (!ctx.Read(p)) {
			return false;
		}
		preamble = (p >> 24) & 0xFF;
		voice = (p >> 16) & 0xFF;
		noise = (p >> 8) & 0xFF;
		signature = p & 0xFF;

		if (!ctx.Read(position)) {
			return false;
		}
		if (!ctx.Read(p)) {
			return false;
		}
		pause = (p >> 16) & 0xFFFF;
		len = p & 0xFFFF;

		phonetics = new array<int>;
		while (len--) {
			if (!ctx.Read(p)) {
				return false;
			}
			int a, b, c, d;
			a = (p >> 24) & 0xFF;
			b = (p >> 16) & 0xFF;
			c = (p >> 8) & 0xFF;
			d = p & 0xFF;
			if (a != 255)
				phonetics.Insert(a);
			if (b != 255)
				phonetics.Insert(b);
			if (c != 255)
				phonetics.Insert(c);
			if (d != 255)
				phonetics.Insert(d);
		}
		return true;
	}
}

class RadioNotificationAlarmEvent {
	int alarm;

	[NonSerialized()] vector position = "0 0 0";
	[NonSerialized()] int state = 0;

	void RadioNotificationAlarmEvent(int _alarm = 255, vector _position = "0 0 0") {
		alarm = _alarm;
		position = _position;
	}

	void ~RadioNotificationAlarmEvent() {
	}

	RadioNotificationAlarmEvent Clone() {
		RadioNotificationAlarmEvent e = new RadioNotificationAlarmEvent(alarm, position);
		e.state = state;
		return e;
	}

	bool SerializeRPC(Serializer ctx) {
		if (!ctx.Write(alarm)) {
			return false;
		}
		return ctx.Write(position);
	}

	bool DeserializeRPC(Serializer ctx) {
		if (!ctx.Read(alarm)) {
			return false;
		}
		return ctx.Read(position);
	}
}
