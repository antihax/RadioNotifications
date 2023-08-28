/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2022 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

enum RadioNotificationRPC {
	CONFIGURATION = 0,
	RADIONOTIFICATION,
	RADIONOTIFICATIONALARM,
}

#ifndef SERVER
class RadioNotificationClientHandler {
	ref RadioNotificationSettings m_Settings;
	ref ScriptInvoker Event_RadioNotification = new ScriptInvoker();
	protected ref array<vector> m_PAS = {};
	protected static const string GRID_SIZE_CFG_PATH = "CfgWorlds %1 Grid Zoom1 stepX";

	void RadioNotificationClientHandler() {
		m_Settings = new RadioNotificationSettings();
		m_Settings.DefaultSettings();
		GetBitWiseManager().ConnectEndpoint("RadioNotifications", "CONFIGURATION", ScriptCaller.Create(ConfigurationRPC));
		GetBitWiseManager().ConnectEndpoint("RadioNotifications", "RADIONOTIFICATION", ScriptCaller.Create(RadioNotificationEventRPC));
		GetBitWiseManager().ConnectEndpoint("RadioNotifications", "RADIONOTIFICATIONALARM", ScriptCaller.Create(RadioNotificationAlarmEventRPC));
	}

	void ~RadioNotificationClientHandler() {
		delete Event_RadioNotification;
		delete m_Settings;
	}

	void RegisterPAS(vector loc) {
		m_PAS.Insert(loc);
	}

	// Read our configuration from the server
	bool ConfigurationRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		if (!m_Settings.DeserializeRPC(new BitStreamReader(ctx)))
			return false;
#ifdef RADIONOTIFICATIONS_DEBUG
		Print(m_Settings.Dump());
#endif
		return true;
	}

	// Server sent alarm
	bool RadioNotificationAlarmEventRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		ref RadioNotificationAlarmEvent e = new RadioNotificationAlarmEvent();
		if (!e.DeserializeRPC(new BitStreamReader(ctx))) {
			delete e;
			return false;
		}

#ifdef RADIONOTIFICATIONS_DEBUG
		Print(e.Dump());
#endif

		for (int i = 0; i < m_PAS.Count(); i++) {
			if (vector.Distance(m_PAS[i], e.position) < e.radius) {
				EffectSound alarm = SEffectManager.PlaySound("RadioNotification_Alarm" + e.alarm.ToString(), m_PAS[i]);
				alarm.SetAutodestroy(true);
				break;
			}
		}
		delete e;
		return true;
	}

	// Server sent a notification
	bool RadioNotificationEventRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		ref RadioNotificationEvent e = new RadioNotificationEvent();

		if (!e.DeserializeRPC(new BitStreamReader(ctx))) {
			delete e;
			return false;
		}

#ifdef RADIONOTIFICATIONS_DEBUG
		Print(e.Dump());
#endif
		// [TODO] find a better place for this and optimize it
		if (e.position[0] <= 0.0)
			e.position[0] = 0.1;
		if (e.position[2] <= 0.0)
			e.position[2] = 0.1;

		int gridX, gridZ;
		float GRID_SIZE = GetGame().ConfigGetFloat(string.Format(GRID_SIZE_CFG_PATH, GetGame().GetWorldName()));
		GetGame().GetWorld().GetGridCoords(e.position, GRID_SIZE, gridX, gridZ);
		array<int> p = {};
		for (int i = 0; i < e.phonetics.Count(); i++) {
			switch (e.phonetics[i]) {
			case 128: // GridRef 6n w/ cardinals
				// Replace with grid coords
				p.Insert(gridX / 100 % 10);
				p.Insert(gridX / 10 % 10);
				p.Insert(gridX % 10);
				p.Insert(48); // East

				p.Insert(gridZ / 100 % 10);
				p.Insert(gridZ / 10 % 10);
				p.Insert(gridZ % 10);
				p.Insert(46); // North
				break;

			case 129: // GridRef 4n w/ cardinals
				// Replace with grid coords
				p.Insert(gridX / 100 % 10);
				p.Insert(gridX / 10 % 10);

				p.Insert(48); // East

				p.Insert(gridZ / 100 % 10);
				p.Insert(gridZ / 10 % 10);
				p.Insert(46); // North
				break;

			case 130: // GridRef 6n w/ cardinals
				// Replace with grid coords
				p.Insert(gridX / 100 % 10);
				p.Insert(gridX / 10 % 10);
				p.Insert(gridX % 10);

				p.Insert(gridZ / 100 % 10);
				p.Insert(gridZ / 10 % 10);
				p.Insert(gridZ % 10);
				break;

			case 131: // GridRef 4n w/ cardinals
				// Replace with grid coords
				p.Insert(gridX / 100 % 10);
				p.Insert(gridX / 10 % 10);

				p.Insert(gridZ / 100 % 10);
				p.Insert(gridZ / 10 % 10);
				break;

			case 132: // Heading
				// Replace with heading in degrees
				p.Insert(e.heading / 100 % 10);
				p.Insert(e.heading / 10 % 10);
				p.Insert(e.heading % 10);
				break;

			case 133: // Random Number
				// Replace with heading in degrees
				p.Insert(Math.RandomIntInclusive(0, 9));
				break;

			case 134: // Random Phonetic Letter
				// Replace with heading in degrees
				p.Insert(Math.RandomIntInclusive(10, 35));
				break;

			case 255: // Empty
				break;
			default:
				p.Insert(e.phonetics[i]);
			}
		}

		// swap the phonetics array out once we detokenize
		delete e.phonetics;
		e.phonetics = p;

		// Pump the event to all the radios near the client
		Event_RadioNotification.Invoke(e);
		delete e;
		return true;
	}
}

protected ref RadioNotificationClientHandler g_RadioNotificationClientHandler;
static RadioNotificationClientHandler GetRadioNotificationClientHandler() {
	return g_RadioNotificationClientHandler;
}

static RadioNotificationSettings GetRadioNotificationSettings() {
	return g_RadioNotificationClientHandler.m_Settings;
}
#endif