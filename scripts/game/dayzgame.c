// Why are we still here? Just to suffer?
const int RPC_ANTIHAX_RADIONOTIFICATIONS = -1456746572;

modded class DayZGame {
	void DayZGame() {
#ifdef SERVER
		g_RadioNotificationManager = new RadioNotificationManager();
#else
		g_RadioNotificationClientHandler = new RadioNotificationClientHandler();
#endif
	}

	void ~DayZGame() {
#ifdef SERVER
		g_RadioNotificationManager = null;
#else
		g_RadioNotificationClientHandler = null;
#endif
	}

#ifndef SERVER
	// Eat our RPC calls, because we don't need to tell 200 plugins we got an RPC call
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		if (rpc_type == RPC_ANTIHAX_RADIONOTIFICATIONS) {
			if (!GetRadioNotificationClientHandler().OnRPC(sender, target, ctx))
				Print("RadioNotificationClientHandler::OnRPC failed!");
		} else {
			super.OnRPC(sender, target, rpc_type, ctx);
		}
	}
#endif
};