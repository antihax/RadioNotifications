/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */

#ifdef SERVER
class RadioNotificationManager {
	protected int m_TransmissionID = 1;
	protected autoptr map<int, ref RadioNotificationEvent> m_ActiveEvents = new map<int, ref RadioNotificationEvent>();
	protected autoptr map<int, ref RadioNotificationStaticAlarmPair> m_ActiveAlarms = new map<int, ref RadioNotificationStaticAlarmPair>();
	protected int m_EventPointer;
	protected int m_AlarmPointer;
	protected autoptr Timer m_NotificationPump;
	protected autoptr Timer m_AlarmPump;
	protected autoptr array<int> m_EventIDs = {};
	protected autoptr array<int> m_AlarmIDs = {};
	protected int m_RPC_CONFIGURATION, m_RPC_RADIONOTIFICATION, m_RPC_RADIONOTIFICATIONALARM;

	void RadioNotificationManager() {
		// Cache RPCs
		m_RPC_CONFIGURATION = GetBitWiseManager().GetIndexForKeyword("RadioNotifications", "CONFIGURATION");
		m_RPC_RADIONOTIFICATION = GetBitWiseManager().GetIndexForKeyword("RadioNotifications", "RADIONOTIFICATION");
		m_RPC_RADIONOTIFICATIONALARM = GetBitWiseManager().GetIndexForKeyword("RadioNotifications", "RADIONOTIFICATIONALARM");

		// Add static events and add position
		for (int i = 0; i < RadioNotificationSettings.GetSettings().staticEvents.Count(); i++) {
			RadioNotificationSettings.GetSettings().staticEvents[i].anEvent.position = RadioNotificationSettings.GetSettings().staticEvents[i].position;
			AddEvent(RadioNotificationSettings.GetSettings().staticEvents[i].anEvent);
		}

		// Add static alarms and add position
		for (i = 0; i < RadioNotificationSettings.GetSettings().staticAlarms.Count(); i++) {
			RadioNotificationSettings.GetSettings().staticAlarms[i].anEvent.position = RadioNotificationSettings.GetSettings().staticAlarms[i].position;
			AddAlarm(RadioNotificationSettings.GetSettings().staticAlarms[i]);
		}
	}

	void ~RadioNotificationManager() {
		if (m_NotificationPump) {
			m_NotificationPump.Stop();
		}
		if (m_AlarmPump) {
			m_AlarmPump.Stop();
		}
	}

	// StartNotificationPump has to performed after server is live.
	void StartNotificationPump() {
		m_NotificationPump = new Timer(CALL_CATEGORY_SYSTEM);
		m_NotificationPump.Run(1.0, this, "RunNotificationPump", null, true);

		m_AlarmPump = new Timer(CALL_CATEGORY_SYSTEM);
		m_AlarmPump.Run(1.0, this, "RunAlarmPump", null, true);
	}

	// Run events
	protected void RunNotificationPump() {
		if (m_EventIDs.Count() == 0) {
			return;
		}

		++m_EventPointer;
		if (m_EventPointer >= m_EventIDs.Count())
			m_EventPointer = 0;

		auto e = m_ActiveEvents.Get(m_EventIDs[m_EventPointer]);
		if (e) {
			if (!e.lastTime || (GetGame().GetTime() - e.lastTime) / 1000 > e.delay) {
				SendRadioNotificationEvent(e);
				e.lastTime = GetGame().GetTime();

				// Delete the event if it has repeats expires
				if (e.repeat > 0) {
					++e.ticks;
					if (e.ticks > e.repeat) {
						RemoveEvent(m_EventIDs[m_EventPointer]);
						return;
					}
				}
			}
		} else {
			RemoveEvent(m_EventIDs[m_EventPointer]);
		}
	}

	// Run alarms
	protected void RunAlarmPump() {
		if (m_AlarmIDs.Count() == 0) {
			return;
		}

		++m_AlarmPointer;
		if (m_AlarmPointer >= m_AlarmIDs.Count())
			m_AlarmPointer = 0;

		auto e = m_ActiveAlarms.Get(m_AlarmIDs[m_AlarmPointer]);
		if (e) {
			if (!e.lastTime || (GetGame().GetTime() - e.lastTime) / 1000 > e.delay) {
				SendRadioNotificationAlarmEvent(e.anEvent);
				e.lastTime = GetGame().GetTime();
			}
		}
	}

	void SendConfiguration(notnull Man player) {
		autoptr BitWiseScriptRPC rpc = BitWiseScriptRPC.NewFromID(m_RPC_CONFIGURATION);
		RadioNotificationSettings.GetSettings().SerializeRPC(rpc);
		rpc.Send(player, true, player.GetIdentity());
	}

	void SendRadioNotificationEvent(RadioNotificationEvent e) {
		autoptr BitWiseScriptRPC rpc = BitWiseScriptRPC.NewFromID(m_RPC_RADIONOTIFICATION);
		if (!e.SerializeRPC(rpc)) {
			Print("Failed to serialize RPC");
		}
		rpc.Send(null, true);
	}

	void SendRadioNotificationAlarmEvent(RadioNotificationAlarmEvent e) {
		autoptr BitWiseScriptRPC rpc = BitWiseScriptRPC.NewFromID(m_RPC_RADIONOTIFICATIONALARM);
		e.SerializeRPC(rpc);
		rpc.Send(null, true);
	}

	// Get a unique ID for a transmission
	// Returns zero if the transmission is ignored.
	int GetNewTransmissionID(string type, vector position) {
		auto a = RadioNotificationSettings.GetSettings().GetAlarm(type);
		if (a) {
			a.position = position;
			SendRadioNotificationAlarmEvent(a);
		}

		auto e = RadioNotificationSettings.GetSettings().GetEvent(type);
		if (!e)
			return 0;

		// Pin this to memory
		ref RadioNotificationEvent newEvent = e.Clone();
		newEvent.position = position;

		return AddEvent(newEvent);
	}

	// Add a new RadioNotificationEvent to the queue.
	// Get a unique ID for a transmission
	int AddEvent(RadioNotificationEvent e) {
		++m_TransmissionID;
		m_ActiveEvents.Insert(m_TransmissionID, e);
		m_EventIDs.Insert(m_TransmissionID);
		return m_TransmissionID;
	}

	// Add a new RadioNotificationAlarmEvent to the queue.
	// Get a unique ID for a transmission
	int AddAlarm(RadioNotificationStaticAlarmPair e) {
		++m_TransmissionID;
		m_ActiveAlarms.Insert(m_TransmissionID, e);
		m_AlarmIDs.Insert(m_TransmissionID);
		return m_TransmissionID;
	}

	void UpdateEventPosition(int id, vector position, vector direction) {
		auto e = m_ActiveEvents.Get(id);
		if (e) {
			e.position = position;

			// Calculate heading
			vector dir = direction - position;
			dir[1] = 0;
			dir.Normalize();
			vector north = "0 0 1";
			vector east = "1 0 0";
			vector heading = north * dir;
			float angle = Math.Acos(vector.Dot(east, heading)) * Math.RAD2DEG;
			if (vector.Dot(north, heading) < 0) {
				angle = 360 - angle;
			}
			e.heading = angle;
		}
	}

	void RemoveEvent(int id) {
		m_EventIDs.RemoveItem(id);
		m_ActiveEvents.Remove(id);
	}
}

protected ref RadioNotificationManager g_RadioNotificationManager;
static RadioNotificationManager GetRadioNotificationManager() {
	return g_RadioNotificationManager;
}

#endif