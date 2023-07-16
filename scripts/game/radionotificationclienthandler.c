enum RadioNotificationRPC {
	CONFIGURATION = 0
}

#ifndef SERVER
class RadioNotificationClientHandler {
	protected ref RadioNotificationSettings m_Settings;
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
		}
		return true;
	}

	// Read our configuration from the server
	bool ConfigurationRPC(ParamsReadContext ctx) {
		Print("RadioNotificationClientHandler::ConfigurationRPC");
		if (!ctx.Read(m_Settings.maxDistance))
			return false;
		if (!ctx.Read(m_Settings.baseRadioMultiplier))
			return false;
		Print(m_Settings);
		return true;
	}
}

protected ref RadioNotificationClientHandler g_RadioNotificationClientHandler;
static RadioNotificationClientHandler GetRadioNotificationClientHandler() {
	return g_RadioNotificationClientHandler;
}
#endif