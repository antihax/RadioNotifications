
class RadioNotificationSettings {
	// Furthest distance a transmission can be heard.
	int maxDistance;

	// Multiplier for base radios.
	float baseRadioMultiplier;

	// Map of events to their typeNames.
	ref map<string, ref RadioNotificationEvent> eventMap;

	[NonSerialized()] protected static const string FOLDER = "$profile:RadioNotifications";
	[NonSerialized()] protected static const string SETTINGS = FOLDER + "\\Settings.json";

	void RadioNotificationSettings() {
		eventMap = new map<string, ref RadioNotificationEvent>();
	}

	void ~RadioNotificationSettings() {
		delete eventMap;
	}

	void Load() {
		if (FileExist(SETTINGS))
			JsonFileLoader<RadioNotificationSettings>.JsonLoadFile(SETTINGS, this);
		else {
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
		baseRadioMultiplier = 2.5;
		eventMap.Insert("Wreck_Mi8_Crashed", new RadioNotificationEvent(1, 1, 1, 1, {1, 2, 3, 4, 5, 6}, 1, 1200));
		eventMap.Insert("Wreck_UH1Y", new RadioNotificationEvent(1, 1, 1, 1, {1, 2, 3, 4, 5, 6}, 1, 1200));
	}
}
