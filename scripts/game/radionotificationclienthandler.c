/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */

enum RadioNotificationRPC {
	CONFIGURATION = 0,
	RADIONOTIFICATION,
	RADIONOTIFICATIONALARM,
}

#ifndef SERVER
class RadioNotificationClientHandler {
	autoptr ScriptInvoker Event_RadioNotification = new ScriptInvoker();
	protected autoptr array<vector> m_PAS = {};
	protected static const string GRID_SIZE_CFG_PATH = "CfgWorlds %1 Grid Zoom1 stepX";

	protected string m_PadString;
	protected string m_CipherTextString;
	protected string m_KeyString;
	protected string m_PlainTextString;

	protected int m_KeyCursor;
	protected int m_PadIndex;
	protected bool m_ValidPad;

	void RadioNotificationClientHandler() {
		GetBitWiseManager().ConnectEndpoint("RadioNotifications", "CONFIGURATION", ScriptCaller.Create(ConfigurationRPC));
		GetBitWiseManager().ConnectEndpoint("RadioNotifications", "RADIONOTIFICATION", ScriptCaller.Create(RadioNotificationEventRPC));
		GetBitWiseManager().ConnectEndpoint("RadioNotifications", "RADIONOTIFICATIONALARM", ScriptCaller.Create(RadioNotificationAlarmEventRPC));
	}

	void ~RadioNotificationClientHandler() {
	}

	void RegisterPAS(vector loc) {
		m_PAS.Insert(loc);
	}

	// Read our configuration from the server
	bool ConfigurationRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		if (!RadioNotificationSettings.GetSettings().DeserializeRPC(new BitStreamReader(ctx)))
			return false;

		return true;
	}

	// Server sent alarm
	bool RadioNotificationAlarmEventRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		autoptr RadioNotificationAlarmEvent e = new RadioNotificationAlarmEvent();
		if (!e.DeserializeRPC(new BitStreamReader(ctx))) {
			return false;
		}
		EffectSound alarm;
		if (e.fixed) {
			alarm = SEffectManager.PlaySound("RadioNotification_Alarm" + e.alarm.ToString(), e.position);
			alarm.SetAutodestroy(true);
		} else {
			for (int i = 0; i < m_PAS.Count(); i++) {
				if (vector.Distance(m_PAS[i], e.position) < e.radius) {
					alarm = SEffectManager.PlaySound("RadioNotification_Alarm" + e.alarm.ToString(), m_PAS[i]);
					alarm.SetAutodestroy(true);
					// Don't flood with sounds
					if (i > 4)
						break;
				}
			}
		}
		return true;
	}

	// Server sent a notification
	bool RadioNotificationEventRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		autoptr RadioNotificationEvent e = new RadioNotificationEvent();

		if (!e.DeserializeRPC(new BitStreamReader(ctx))) {
			return false;
		}

		// [TODO] find a better place for this and optimize it
		if (e.position[0] <= 0.0)
			e.position[0] = 0.1;
		if (e.position[2] <= 0.0)
			e.position[2] = 0.1;

		int gridX, gridZ;
		float GRID_SIZE = GetGame().ConfigGetFloat(string.Format(GRID_SIZE_CFG_PATH, GetGame().GetWorldName()));
		GetGame().GetWorld().GetGridCoords(e.position, GRID_SIZE, gridX, gridZ);
		if (gridX < 0) {
			gridX = 0;
			Error("RadioNotifications: GridX is less than 0");
		}
		if (gridZ < 0) {
			gridZ = 0;
			Error("RadioNotifications: GridZ is less than 0");
		}
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
		return true;
	}

	/*
	*	Encryption Code
	*/
	void RemoveLetter() {
		if (!!m_CipherTextString.Length()) {
			m_CipherTextString = m_CipherTextString.Substring(0, m_CipherTextString.Length() - 1);
		} else {
			m_PadString = m_PadString.Substring(0, m_PadString.Length() - 1);
		}
	}

	void AddLetter(string l) {
		if (m_PadString.Length() >= 5) {
			m_CipherTextString += l;
			m_PadIndex = RadioNotificationSettings.GetSettings().GetOneTimePad().GetKeyFromPad(m_PadString);
			if (m_PadIndex >= 0) {
				DecodeMessage();
				m_ValidPad = true;
			} else {
				m_ValidPad = false;
			}
		} else {
			m_PadString += l;
			m_PadIndex = -1;
			m_ValidPad = false;
		}
	}

	void DecodeMessage() {
		m_KeyString = RadioNotificationSettings.GetSettings().GetOneTimePad().GetKey(m_PadIndex, m_CipherTextString.Length());
		m_PlainTextString = RadioNotificationSettings.GetSettings().GetOneTimePad().DecodeMessage(m_KeyString, m_CipherTextString);
	}

	void ClearLetters() {
		m_PadString = "";
		m_CipherTextString = "";
		m_KeyString = "";
		m_PlainTextString = "";
	}

	string GetPad() {
		return m_PadString;
	}

	string GetCipherText() {
		return m_CipherTextString;
	}

	string GetKey() {
		return m_KeyString;
	}

	string GetPlainText() {
		return m_PlainTextString;
	}
}

protected ref RadioNotificationClientHandler g_RadioNotificationClientHandler;
static RadioNotificationClientHandler GetRadioNotificationClientHandler() {
	return g_RadioNotificationClientHandler;
}

#endif