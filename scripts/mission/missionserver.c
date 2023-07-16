#ifdef SERVER
modded class MissionServer {
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		super.InvokeOnConnect(player, identity);
		if (player)
			GetRadioNotificationManager().SendConfiguration(player);
	}
}
#endif