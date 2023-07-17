#define RADIONOTIFICATIONS 1

class RadioNotificationsContext {
};

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

	bool SerializeRPC(Serializer ctx) {
		ctx.Write((preamble & 0xFF) << 24 | (voice & 0xFF) << 16 | (noise & 0xFF) << 8 | signature & 0xFF);
		ctx.Write(position);

		// Pad with empty phonetics
		while (phonetics.Count() % 4) {
			phonetics.Insert(-127);
		}

		ctx.Write((pause & 0xFFFF) << 16) | (phonetics.Count() / 4 & 0xFFFF);

		// Pack the phonetics into 32-bit integers
		for (int i = 0; i < phonetics.Count(); i += 4) {
			ctx.Write((phonetics[i] & 0xFF) << 24 | (phonetics[i + 1] & 0xFF) << 16 | (phonetics[i + 2] & 0xFF) << 8 | phonetics[i + 3] & 0xFF);
		}

		return true;
	}

	bool DeserializeRPC(Serializer ctx) {
		int p, len;

		ctx.Read(p);
		preamble = (p >> 24) & 0xFF;
		voice = (p >> 16) & 0xFF;
		noise = (p >> 8) & 0xFF;
		signature = p & 0xFF;
		ctx.Read(p);

		pause = (p >> 16) & 0xFFFF;
		len = p & 0xFFFF;

		while (len--) {
			ctx.Read(p);
			phonetics.Insert((p >> 24) & 0xFF);
			phonetics.Insert((p >> 16) & 0xFF);
			phonetics.Insert((p >> 8) & 0xFF);
			phonetics.Insert(p & 0xFF);
		}

		return true;
	}

	/* for reference so i don't forget the order
	 int PackInt(cr a, char b, char c, char d) {
		 return (a & 0xFF << 24) | (b  & 0xFF << 16) | (c & 0xFF << 8) | d & 0xFF;
	 }

	 void unpack_int(int p, int a, int b, int c, int d) {
		 a = (p >> 24) & 0xFF;
		 b = (p >> 16) & 0xFF;
		 c = (p >> 8) & 0xFF;
		 d = p & 0xFF;
	 }*/
}
