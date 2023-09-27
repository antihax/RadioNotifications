/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */

/**
 * RadioNotificationSettings is a singleton class that stores all the settings for the mod configured from the JSON file
 * at $profile:RadioNotifications/Settings.json
 */
class RadioNotificationSettings {
	[NonSerialized()]
	static ref RadioNotificationSettings m_Settings;

	/// Called internally to initialize the singleton.
	static void Init() {
		m_Settings = new RadioNotificationSettings();
	}

	/// GetSettings returns the loaded settings. Should be called after mission start by mod developers.
	static RadioNotificationSettings GetSettings() {
		return m_Settings;
	}

	/// Expected version, used to detect if settings need to be reset. Not user configurable.
	[NonSerialized()]
	const int expectedVersion = 1;

	/// Current version, used to detect if settings need to be reset. Not user configurable.
	int version;

	/// Furthest distance a transmission can be heard.
	int maxDistance;

	/// Multiplier for base radios.
	float baseRadioMultiplier;

	/// Falloff to ignore transmissions.
	int ignoreDistance;

	/// Volume range for transmissions.
	float minVolume;

	/// Volume range for transmissions.
	float maxVolume;

	/// Radio Channel Broadcast.
	int radioChannel;

	/// Enable randomize noise to minimize predicting the message type.
	bool randomNoise;

	/// Disable players broadcasting on the radio.
	bool disablePlayerBroadcast;

	/// Map of events to their typeNames. See RadioNotificationEvent for more information.
	autoptr map<string, RadioNotificationEvent> eventMap;

	/// Static events to always repeat. See RadioNotificationStaticPair for more information.
	autoptr array<RadioNotificationStaticPair> staticEvents;

	/// Map of alarms to their typeNames. See RadioNotificationAlarmEvent for more information.
	autoptr map<string, RadioNotificationAlarmEvent> alarmMap;

	/// Static alarms to always repeat. See RadioNotificationStaticPair for more information.
	autoptr array<RadioNotificationStaticAlarmPair> staticAlarms;

	[NonSerialized()]
	protected static const string FOLDER = "$profile:RadioNotifications";
	[NonSerialized()]
	protected static const string SETTINGS = FOLDER + "\\Settings.json";

	/// Automatically detected
	[NonSerialized()]
	int numVoices; /// Automatically detected
	[NonSerialized()]
	int numPhonetics; /// Automatically detected
	[NonSerialized()]
	int numPreambles; /// Automatically detected
	[NonSerialized()]
	int numNoises; /// Automatically detected
	[NonSerialized()]
	int numAlarms; /// Automatically created
	[NonSerialized()]
	autoptr RadioNotificationOneTimePad pad; /// Automatically created
	[NonSerialized()]
	int padSeed;

	void RadioNotificationSettings() {
		eventMap = new map<string, RadioNotificationEvent>();
		staticEvents = new array<RadioNotificationStaticPair>();
		alarmMap = new map<string, RadioNotificationAlarmEvent>();
		staticAlarms = new array<RadioNotificationStaticAlarmPair>();
		padSeed = Math.RandomIntInclusive(0, 65534);
	}

	void InitOneTimePad() {
		pad = new RadioNotificationOneTimePad(padSeed);
	}

	/// GetOneTimePad returns the OneTimePad for decoding encrypted messages.
	RadioNotificationOneTimePad GetOneTimePad() {
		return pad;
	}

	/// DetectSoundSets is called internally to detect the number of sound sets available.
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
	}

	/// Serialize the settings to the client. Called internally.
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
		if (!ctx.WriteRangedInt(padSeed, 0, 65534))
			return false;
		return true;
	}

	/// Deserialize the settings from the client. Called internally.
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
		if (!ctx.ReadRangedInt(padSeed, 0, 65534))
			return false;

		// Setup the one time pad client side
		InitOneTimePad();
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

		if (version < expectedVersion) {
			Print("RadioNotificationSettings: Settings version mismatch, updating to " + expectedVersion.ToString() + " from " + version.ToString());
			version = expectedVersion;
			Save(); // Save new settings
		}

		if (maxDistance < 1000) {
			Print("maxDistance is less than 1000, resetting to 1000");
			maxDistance = 1000;
		}
		if (maxDistance > 20000) {
			Print("maxDistance is greater than 20000, resetting to 20000");
			maxDistance = 20000;
		}
		if (baseRadioMultiplier < 1.0) {
			Print("baseRadioMultiplier is less than 1.0, resetting to 1.0");
			baseRadioMultiplier = 1.0;
		}
		if (radioChannel < 0) {
			Print("radioChannel is less than 0, resetting to 0");
			radioChannel = 0;
		}
		if (radioChannel > 7) {
			Print("radioChannel is greater than 7, resetting to 7");
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
		baseRadioMultiplier = 1.5;
		ignoreDistance = 1000;
		minVolume = 0.1;
		maxVolume = 1.0;
		radioChannel = 2;
		disablePlayerBroadcast = true;

		eventMap.Insert("Wreck_Mi8_Crashed", new RadioNotificationEvent(1, 0, 3, 1, { 36, 37, 45, 22, 18, 8, 41, 128, 41, 128, 42 }, 1, 600, 3));
		eventMap.Insert("Wreck_UH1Y", new RadioNotificationEvent(1, 1, 2, 1, { 36, 37, 45, 30, 17, 1, 34, 41, 128, 41, 128, 42 }, 1, 600, 3));
		eventMap.Insert("StaticObj_Wreck_BRDM_DE", new RadioNotificationEvent(5, 7, 3, 6, { 44, 45, 11, 27, 13, 22, 43, 128, 43, 128, 42 }, 1, 600, 3));
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

class RadioNotificationStaticPair {
	vector position;
	RadioNotificationEvent anEvent; // cant call it event, reserved word
}

class RadioNotificationStaticAlarmPair {
	vector position;
	int delay;
	RadioNotificationAlarmEvent anEvent; // cant call it event, reserved word
	[NonSerialized()]
	int lastTime;
}