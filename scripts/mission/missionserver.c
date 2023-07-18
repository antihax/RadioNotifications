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
modded class MissionServer {
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		super.InvokeOnConnect(player, identity);
		if (player)
			GetRadioNotificationManager().SendConfiguration(player);
	}
	override void OnInit() {
		super.OnInit();
		GetRadioNotificationManager().StartNotificationPump();
	}
}
#endif