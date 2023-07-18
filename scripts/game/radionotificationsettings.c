/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2022 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

class RadioNotificationSettings {
	// Furthest distance a transmission can be heard.
	int maxDistance;

	// Multiplier for base radios.
	float baseRadioMultiplier;

	// Map of events to their typeNames.
	ref map<string, RadioNotificationEvent> eventMap;

	[NonSerialized()] protected static const string FOLDER = "$profile:RadioNotifications";
	[NonSerialized()] protected static const string SETTINGS = FOLDER + "\\Settings.json";

	void RadioNotificationSettings() {
		eventMap = new map<string, RadioNotificationEvent>();
	}

	void ~RadioNotificationSettings() {
		delete eventMap;
	}

	bool SerializeRPC(Serializer ctx) {
		ctx.Write(maxDistance);
		ctx.Write(baseRadioMultiplier);
		return true;
	}
	bool DeserializeRPC(Serializer ctx) {
		ctx.Read(maxDistance);
		ctx.Read(baseRadioMultiplier);
		return true;
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
		eventMap.Insert("Wreck_Mi8_Crashed", new RadioNotificationEvent(1, 2, 3, 4, {1, 2, 3, 4, 5, 6}, 1, 1200));
		eventMap.Insert("Wreck_UH1Y", new RadioNotificationEvent(1, 2, 3, 4, {1, 2, 3, 4, 5, 6}, 1, 1200));
	}

	// Get an event for the type name.
	RadioNotificationEvent GetEvent(string typeName) {
		RadioNotificationEvent e;
		if (eventMap.Find(typeName, e))
			return e;

		return null;
	}
}
