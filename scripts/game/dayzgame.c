/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

// Why are we still here? Just to suffer?

modded class DayZGame {
	void DayZGame() {
#ifdef SERVER
		GetBitWiseManager().RegisterEndpoint("RadioNotifications", "CONFIGURATION");
		GetBitWiseManager().RegisterEndpoint("RadioNotifications", "RADIONOTIFICATION");
		GetBitWiseManager().RegisterEndpoint("RadioNotifications", "RADIONOTIFICATIONALARM");
		g_RadioNotificationManager = new RadioNotificationManager();
#else
		g_RadioNotificationClientHandler = new RadioNotificationClientHandler();
#endif

		override void DeferredInit() {
			GetRadioNotificationSettings().DetectSoundSets();
			super.DeferredInit();
		}

		void ~DayZGame() {
#ifdef SERVER
			g_RadioNotificationManager = null;
#else
			g_RadioNotificationClientHandler = null;
#endif
		}
	};