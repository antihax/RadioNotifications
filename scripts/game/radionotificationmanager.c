
#ifdef SERVER
class RadioNotificationManager {
	protected int m_TransmissionID = 1;
	protected ref RadioNotificationSettings m_Settings;
	protected ref map<int, RadioNotificationEvent> m_ActiveEvents = new map<int, RadioNotificationEvent>();
	protected int m_EventPointer;
	protected ref Timer m_NotificationPump;

	void RadioNotificationManager() {
		m_Settings = new RadioNotificationSettings();
		m_Settings.Load();

		m_NotificationPump = new Timer(CALL_CATEGORY_SYSTEM);
		m_NotificationPump.Run(30.0, this, "RunNotificationPump", null, true);
	}

	void ~RadioNotificationManager() {
		m_Settings.Save();
	}

	// [TODO] Refactor with an array of event IDs so we are not using GetElement
	void RunNotificationPump() {
		if (m_ActiveEvents.Count() == 0)
			return;

		if (m_EventPointer > m_ActiveEvents.Count())
			m_EventPointer = 0;

		// RPC OUT
		m_EventPointer++
	}

	void SendConfiguration(notnull Man player) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.CONFIGURATION);
		m_Settings.SerializeRPC(rpc);
		rpc.Send(player, RPC_ANTIHAX_RADIONOTIFICATIONS, true, player.GetIdentity());
	}

	void SendRadioNotificationEvent(RadioNotificationEvent e) {
		// [TODO] Refactor to reuse ScriptRPC
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.RADIONOTIFICATION);
		e.SerializeRPC(rpc);
		rpc.Send(null, RPC_ANTIHAX_RADIONOTIFICATIONS, true);
	}

	// Get a unique ID for a transmission
	// Returns zero if the transmission is ignored.
	int GetNewTransmissionID(string type, vector position) {
		return ++m_TransmissionID;
	}

	void Remove(int id) { m_ActiveEvents.Remove(id); }
}

protected ref RadioNotificationManager g_RadioNotificationManager;
static RadioNotificationManager GetRadioNotificationManager() {
	return g_RadioNotificationManager;
}
#endif