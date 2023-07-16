
#ifdef SERVER
class RadioNotificationManager {
	protected int m_TransmissionID = 1;
	protected ref RadioNotificationSettings m_Settings;
	protected ref map<int, RadioNotificationEvent> m_ActiveEvents = new map<int, RadioNotificationEvent>();

	void RadioNotificationManager() {
		m_Settings = new RadioNotificationSettings();
		m_Settings.Load();
	}

	void ~RadioNotificationManager() {
		m_Settings.Save();
	}

	void SendConfiguration(notnull Man player) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(RadioNotificationRPC.CONFIGURATION);
		rpc.Write(m_Settings.maxDistance);
		rpc.Write(m_Settings.baseRadioMultiplier);
		rpc.Send(player, RPC_ANTIHAX_RADIONOTIFICATIONS, true, player.GetIdentity());
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