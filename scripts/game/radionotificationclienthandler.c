enum RadioNotificationRPC {
	CONFIGURATION = 0,
	RADIONOTIFICATION
}

#ifndef SERVER
class RadioNotificationClientHandler {
	protected ref RadioNotificationSettings m_Settings;
	ref ScriptInvoker Event_RadioNotification = new ScriptInvoker();
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
		}
		return true;
	}

	// Read our configuration from the server
	bool ConfigurationRPC(ParamsReadContext ctx) {
		if (!m_Settings.DeserializeRPC(ctx))
			return false;
		return true;
	}

	// Server sent a notification
	bool RadioNotificationEventRPC(ParamsReadContext ctx) {
		RadioNotificationEvent e = new RadioNotificationEvent();
		if (!e.DeserializeRPC(ctx))
			return false;

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