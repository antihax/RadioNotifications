/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

class RadioNotificationStaticPair {
	vector position;
	RadioNotificationEvent anEvent; // cant call it event, reserved word
}

class RadioNotificationSettings {
	// Furthest distance a transmission can be heard.
	int maxDistance;

	// Multiplier for base radios.
	float baseRadioMultiplier;

	// Falloff to ignore transmissions.
	int ignoreDistance;

	// Volume range for transmissions.
	float minVolume;
	float maxVolume;

	// Radio Channel Broadcast
	int radioChannel;

	// Randomize noise to minimize predicting the message type
	bool randomNoise;

	// Disable players broadcasting on the radio
	bool disablePlayerBroadcast;

	// Map of events to their typeNames.
	ref map<string, RadioNotificationEvent> eventMap;

	// Static events to always repeat.
	ref array<RadioNotificationStaticPair> staticEvents;

	// Map of alarms to their typeNames.
	ref map<string, RadioNotificationAlarmEvent> alarmMap;

	[NonSerialized()] protected static const string FOLDER = "$profile:RadioNotifications";
	[NonSerialized()] protected static const string SETTINGS = FOLDER + "\\Settings.json";

	void RadioNotificationSettings() {
		eventMap = new map<string, RadioNotificationEvent>();
		staticEvents = new array<RadioNotificationStaticPair>();
		alarmMap = new map<string, RadioNotificationAlarmEvent>();
	}

	void ~RadioNotificationSettings() {
		delete eventMap;
		delete staticEvents;
		delete alarmMap;
	}

	bool SerializeRPC(Serializer ctx) {
		ctx.Write(maxDistance);
		ctx.Write(randomNoise);
		ctx.Write(radioChannel);
		ctx.Write(baseRadioMultiplier);
		ctx.Write(disablePlayerBroadcast);
		return true;
	}

	bool DeserializeRPC(Serializer ctx) {
		ctx.Read(maxDistance);
		ctx.Read(randomNoise);
		ctx.Read(radioChannel);
		ctx.Read(baseRadioMultiplier);
		ctx.Read(disablePlayerBroadcast);
		return true;
	}

	void Load() {
		if (FileExist(SETTINGS))
			JsonFileLoader<RadioNotificationSettings>.JsonLoadFile(SETTINGS, this);
		else {
			// Save default settings
			DefaultSettings();
			Save();
		}
	}

	void Save() {
		if (!FileExist(FOLDER))
			MakeDirectory(FOLDER);

		JsonFileLoader<RadioNotificationSettings>.JsonSaveFile(SETTINGS, this);
	}

	void DefaultSettings() {
		maxDistance = 5000;
		baseRadioMultiplier = 1.75;
		ignoreDistance = 2000;
		minVolume = 0.1;
		maxVolume = 1.0;
		radioChannel = 2;
		disablePlayerBroadcast = true;
		eventMap.Insert("Wreck_Mi8_Crashed", new RadioNotificationEvent(1, 0, 3, 1, {36, 37, 45, 22, 18, 8, 41, 128, 41, 128, 42}, 1, 300, 5));
		eventMap.Insert("Wreck_UH1Y", new RadioNotificationEvent(1, 1, 2, 1, {36, 37, 45, 30, 17, 1, 34, 41, 128, 41, 128, 42}, 1, 300, 5));
		alarmMap.Insert("ContaminatedArea_Dynamic", new RadioNotificationAlarmEvent(0));
	}

	// Get an event for the type name.
	RadioNotificationEvent GetEvent(string typeName) {
		RadioNotificationEvent e;
		if (eventMap.Find(typeName, e))
			return e;

		return null;
	}
	// Get an event for the type name.
	RadioNotificationAlarmEvent GetAlarm(string typeName) {
		RadioNotificationAlarmEvent e;
		if (alarmMap.Find(typeName, e))
			return e;

		return null;
	}
}
