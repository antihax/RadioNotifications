
class RadioNotificationSettings {
	// Furthest distance a transmission can be heard.
	int maxDistance;

	// Multiplier for base radios.
	float baseRadioMultiplier;

	// Map of events to their typeNames.
	map<string, RadioNotificationEvent> eventMap;

	[NonSerialized()] protected static const string FOLDER = "$profile:RadioNotifications";
	[NonSerialized()] protected static const string SETTINGS = FOLDER + "\\Settings.json";

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
	}
}
