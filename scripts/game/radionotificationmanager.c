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
	}

	void ~RadioNotificationManager() {
		m_Settings.Save();
	}

	// StartNotificationPump has to performed after server is live.
	void StartNotificationPump() {
		m_NotificationPump = new Timer(CALL_CATEGORY_SYSTEM);
		m_NotificationPump.Run(15.0, this, "RunNotificationPump", null, true);
	}

	// Run events
	void RunNotificationPump() {
		if (m_EventIDs.Count() == 0)
			return;

		if (m_EventPointer > m_EventIDs.Count() - 1)
			m_EventPointer = 0;

		auto e = m_ActiveEvents.Get(m_EventIDs[m_EventPointer]);
		if (e)
			if ((GetGame().GetTime() - e.lastTime) / 1000 > e.delay) {
				SendRadioNotificationEvent(e);
				e.lastTime = e.GetGame().GetTime();

				// Delete the event if it has a lifetime
				if (e.lifetime) {
					e.ticks++;
					if (e.ticks > e.lifetime) {
						Remove(m_EventIDs[m_EventPointer]);
						return;
					}
				}
			}

		m_EventPointer++;
	}

	void SendConfiguration(notnull Man player) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.CONFIGURATION);
		m_Settings.SerializeRPC(rpc);
		rpc.Send(player, RPC_ANTIHAX_RADIONOTIFICATIONS, true, player.GetIdentity());
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
	int GetNewTransmissionID(string type, vector _position) {
		auto a = m_Settings.GetAlarm(type);
		if (a) {
			a.position = _position;
			SendRadioNotificationAlarmEvent(a);
		}

		auto e = m_Settings.GetEvent(type);
		if (!e)
			return 0;

		m_ActiveEvents.Insert(m_TransmissionID, e);
		m_EventIDs.Insert(m_TransmissionID);
		e.position = _position;

		return ++m_TransmissionID;
	}

	void Remove(int id) {
		m_EventIDs.RemoveItem(id);
		m_ActiveEvents.Remove(id);
	}
}

protected ref RadioNotificationManager g_RadioNotificationManager;
static RadioNotificationManager GetRadioNotificationManager() {
	return g_RadioNotificationManager;
}
#endif