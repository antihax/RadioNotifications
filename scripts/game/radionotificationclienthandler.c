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

	void RegisterPAS(vector loc) {
		m_PAS.Insert(loc);
	}

	void RadioNotificationClientHandler() {
		m_Settings = new RadioNotificationSettings();
		m_Settings.DefaultSettings();
	}

	bool OnRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		int t;
		// Read our RPC type
		if (!ctx.Read(t)) {
			return false;
		}

		switch (t) {
		case RadioNotificationRPC.CONFIGURATION:
			if (!ConfigurationRPC(ctx)) {
				Print("RadioNotificationClientHandler::OnRPC ConfigurationRPC failed!");
				return false;
			}
			break;

		case RadioNotificationRPC.RADIONOTIFICATION:
			if (!RadioNotificationEventRPC(ctx)) {
				Print("RadioNotificationClientHandler::OnRPC RadioNotificationRPC failed!");
				return false;
			}
			break;

		case RadioNotificationRPC.RADIONOTIFICATIONALARM:
			if (!RadioNotificationAlarmEventRPC(ctx)) {
				Print("RadioNotificationClientHandler::OnRPC RadioNotificationRPC failed!");
				return false;
			}
			break;

		default:
			Print("RadioNotificationClientHandler::OnRPC Unknown RPC type " + t);
			return false;
		}

		return true;
	}

	// Read our configuration from the server
	bool ConfigurationRPC(ParamsReadContext ctx) {
		if (!m_Settings.DeserializeRPC(ctx))
			return false;
		return true;
	}

	// Server sent alarm
	bool RadioNotificationAlarmEventRPC(ParamsReadContext ctx) {
		RadioNotificationAlarmEvent e = new RadioNotificationAlarmEvent();
		if (!e.DeserializeRPC(ctx))
			return false;
		for (int i = 0; i < m_PAS.Count(); i++) {
			if (vector.Distance(m_PAS[i], e.position) < e.radius) {
				Print("Playing alarm at " + e.position.ToString());
				EffectSound alarm = SEffectManager.PlaySound("RadioNotification_Alarm" + e.alarm.ToString(), m_PAS[i]);
				alarm.SetAutodestroy(true);
				break;
			}
		}

		return true;
	}

	// Server sent a notification
	bool RadioNotificationEventRPC(ParamsReadContext ctx) {
		RadioNotificationEvent e = new RadioNotificationEvent();
		if (!e.DeserializeRPC(ctx))
			return false;

		// [TODO] find a better place for this and optimize it
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

			case 255: // Empty

				break;
			default:
				p.Insert(e.phonetics[i]);
			}
		}
		delete e.phonetics;
		e.phonetics = p;

		// Pump the event to all the radios near the client
		Event_RadioNotification.Invoke(e);
		return true;
	}
}

protected ref RadioNotificationClientHandler g_RadioNotificationClientHandler;
static RadioNotificationClientHandler GetRadioNotificationClientHandler() {
	return g_RadioNotificationClientHandler;
}
#endif