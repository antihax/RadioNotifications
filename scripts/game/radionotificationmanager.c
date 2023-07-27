/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

#ifdef SERVER
class RadioNotificationManager {
	protected int m_TransmissionID = 1;
	ref RadioNotificationSettings m_Settings;
	protected ref map<int, RadioNotificationEvent> m_ActiveEvents = new map<int, RadioNotificationEvent>();
	protected int m_EventPointer;
	protected ref Timer m_NotificationPump;
	protected ref array<int> m_EventIDs = {};

	void RadioNotificationManager() {
		m_Settings = new RadioNotificationSettings();
		m_Settings.Load();
		// Add static events and add position
		for (int i = 0; i < m_Settings.staticEvents.Count(); i++) {
			m_Settings.staticEvents[i].anEvent.position = m_Settings.staticEvents[i].position;
			AddEvent(m_Settings.staticEvents[i].anEvent);
		}
	}

	void ~RadioNotificationManager() {
		// Don't save settings, it's annoying for the inexperienced admins
		// m_Settings.Save();
		delete m_Settings;

		delete m_ActiveEvents;

		if (m_NotificationPump) {
			m_NotificationPump.Stop();
			delete m_NotificationPump;
		}
	}

	// StartNotificationPump has to performed after server is live.
	void StartNotificationPump() {
		m_NotificationPump = new Timer(CALL_CATEGORY_SYSTEM);
		m_NotificationPump.Run(1.0, this, "RunNotificationPump", null, true);
	}

	// Run events
	void RunNotificationPump() {
		if (m_EventIDs.Count() == 0) {
			return;
		}

		if (m_EventPointer > m_EventIDs.Count() - 1)
			m_EventPointer = 0;

		auto e = m_ActiveEvents.Get(m_EventIDs[m_EventPointer]);
		if (e) {
			if ((GetGame().GetTime() - e.lastTime) / 1000 > e.delay) {

				SendRadioNotificationEvent(e);
				e.lastTime = e.GetGame().GetTime();

				// Delete the event if it has repeats expires
				if (e.repeat > 0) {
					e.ticks++;
					if (e.ticks > e.repeat) {
						RemoveEvent(m_EventIDs[m_EventPointer]);
						return;
					}
				}
			}
		} else {
			RemoveEvent(m_EventIDs[m_EventPointer]);
		}
		m_EventPointer++;
	}

	void SendConfiguration(notnull Man player) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.CONFIGURATION);
		m_Settings.SerializeRPC(rpc);
		rpc.Send(player, RPC_ANTIHAX_RADIONOTIFICATIONS, true, player.GetIdentity());
		delete rpc;
	}

	void SendRadioNotificationEvent(RadioNotificationEvent e) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.RADIONOTIFICATION);
		e.SerializeRPC(rpc);
		rpc.Send(null, RPC_ANTIHAX_RADIONOTIFICATIONS, true);
		delete rpc;
	}

	void SendRadioNotificationAlarmEvent(RadioNotificationAlarmEvent e) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.RADIONOTIFICATIONALARM);
		e.SerializeRPC(rpc);
		rpc.Send(null, RPC_ANTIHAX_RADIONOTIFICATIONS, true);
		delete rpc;
	}

	// Get a unique ID for a transmission
	// Returns zero if the transmission is ignored.
	int GetNewTransmissionID(string type, vector position) {
		auto a = m_Settings.GetAlarm(type);
		if (a) {
			a.position = position;
			SendRadioNotificationAlarmEvent(a);
		}

		auto e = m_Settings.GetEvent(type);
		if (!e)
			return 0;
		e.position = position;

		return AddEvent(e);
	}

	// Add a new RadioNotificationEvent to the queue.
	// Get a unique ID for a transmission
	int AddEvent(RadioNotificationEvent e) {
		m_TransmissionID++;
		m_ActiveEvents.Insert(m_TransmissionID, e);
		m_EventIDs.Insert(m_TransmissionID);
		return m_TransmissionID;
	}

	void UpdateEventPosition(int id, vector position, vector direction) {
		//("Updating position " + id + " to " + position);
		auto e = m_ActiveEvents.Get(id);
		if (e) {
			e.position = position;

			// Calculate heading
			position[1] = 0;
			direction[1] = 0;
			position.Normalize();
			direction.Normalize();
			vector cross = position * direction;

			e.heading = Math.Acos(vector.Dot(position, direction)) * Math.RAD2DEG;
			if (cross[1] < 0)
				e.heading = -e.heading;
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