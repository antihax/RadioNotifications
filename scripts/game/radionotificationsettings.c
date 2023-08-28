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

	// We detect these
	[NonSerialized()] int numVoices;
	[NonSerialized()] int numPhonetics;
	[NonSerialized()] int numPreambles;
	[NonSerialized()] int numNoises;
	[NonSerialized()] int numAlarms;

	void RadioNotificationSettings() {
		eventMap = new map<string, RadioNotificationEvent>();
		staticEvents = new array<RadioNotificationStaticPair>();
		alarmMap = new map<string, RadioNotificationAlarmEvent>();
	}

	void DetectSoundSets() {
		while (true) {
			if (!GetGame().ConfigIsExisting("CfgSoundSets RadioNotification_Voice" + numVoices.ToString() + "_Phonetic0"))
				break;
			++numVoices;
		}
		while (true) {
			if (!GetGame().ConfigIsExisting("CfgSoundSets RadioNotification_Voice0_Phonetic" + numPhonetics.ToString()))
				break;
			++numPhonetics;
		}
		while (true) {
			if (!GetGame().ConfigIsExisting("CfgSoundSets RadioNotification_Preamble" + numPreambles.ToString()))
				break;
			++numPreambles;
		}
		while (true) {
			if (!GetGame().ConfigIsExisting("CfgSoundSets RadioNotification_Noise" + numNoises.ToString()))
				break;
			++numNoises;
		}
		while (true) {
			if (!GetGame().ConfigIsExisting("CfgSoundSets RadioNotification_Alarm" + numAlarms.ToString()))
				break;
			++numAlarms;
		}

		Print("RadioNotification: Found " + numNoises.ToString() + " noise types");
		Print("RadioNotification: Found " + numVoices.ToString() + " voice types");
		Print("RadioNotification: Found " + numPreambles.ToString() + " preamble types");
		Print("RadioNotification: Found " + numPhonetics.ToString() + " phonetic types");
		Print("RadioNotification: Found " + numAlarms.ToString() + " alarm types");
	}

	void ~RadioNotificationSettings() {
		delete eventMap;
		delete staticEvents;
		delete alarmMap;
	}

	bool SerializeRPC(BitStreamWriter ctx) {
		if (!ctx.WriteRangedInt(maxDistance, 1000, 20000))
			return false;
		if (!ctx.WritePacked(randomNoise))
			return false;
		if (!ctx.WriteRangedInt(radioChannel, 0, 7))
			return false;
		if (!ctx.WriteHalfFloat(baseRadioMultiplier))
			return false;
		if (!ctx.WriteHalfFloat(minVolume))
			return false;
		if (!ctx.WriteHalfFloat(maxVolume))
			return false;
		if (!ctx.WritePacked(disablePlayerBroadcast))
			return false;
		return true;
	}

	string Dump() {
		return string.Format("RadioNotificationSettings: %1 %2 %3 %4 %5 %6 %7 %8 %9", maxDistance, baseRadioMultiplier, ignoreDistance, minVolume, maxVolume, radioChannel, randomNoise, disablePlayerBroadcast);
	}

	bool DeserializeRPC(BitStreamReader ctx) {
		if (!ctx.ReadRangedInt(maxDistance, 1000, 20000))
			return false;
		if (!ctx.ReadPacked(randomNoise))
			return false;
		if (!ctx.ReadRangedInt(radioChannel, 0, 7))
			return false;
		if (!ctx.ReadHalfFloat(baseRadioMultiplier))
			return false;
		if (!ctx.ReadHalfFloat(minVolume))
			return false;
		if (!ctx.ReadHalfFloat(maxVolume))
			return false;
		if (!ctx.ReadPacked(disablePlayerBroadcast))
			return false;
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
		if (maxDistance < 1000) {
			Error("maxDistance is less than 1000, resetting to 1000");
			maxDistance = 1000;
		}
		if (maxDistance > 20000) {
			Error("maxDistance is greater than 20000, resetting to 20000");
			maxDistance = 20000;
		}
		if (baseRadioMultiplier < 1.0) {
			Error("baseRadioMultiplier is less than 1.0, resetting to 1.0");
			baseRadioMultiplier = 1.0;
		}
		if (radioChannel < 0) {
			Error("radioChannel is less than 0, resetting to 0");
			radioChannel = 0;
		}
		if (radioChannel > 7) {
			Error("radioChannel is greater than 7, resetting to 7");
			radioChannel = 7;
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
		ignoreDistance = 1000;
		minVolume = 0.1;
		maxVolume = 1.0;
		radioChannel = 2;
		disablePlayerBroadcast = true;
		eventMap.Insert("Wreck_Mi8_Crashed", new RadioNotificationEvent(1, 0, 3, 1, {36, 37, 45, 22, 18, 8, 41, 128, 41, 128, 42}, 1, 600, 5));
		eventMap.Insert("Wreck_UH1Y", new RadioNotificationEvent(1, 1, 2, 1, {36, 37, 45, 30, 17, 1, 34, 41, 128, 41, 128, 42}, 1, 600, 5));
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
