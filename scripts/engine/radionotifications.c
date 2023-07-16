#define RADIONOTIFICATIONS 1

class RadioNotificationsContext {
};

class RadioNotificationEvent {
	int preamble = -1;
	int voice = 0;
	int noise = 0;
	ref array<int> phonetics = {};
	int pause = 0;
	int signature = -1;
	int state = 0;

	[NonSerialized()]
		vector position = "0 0 0";

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