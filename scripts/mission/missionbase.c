/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */
#ifndef SERVER
modded class MissionBase {
	override UIScriptedMenu CreateScriptedMenu(int id) {
		UIScriptedMenu menu = NULL;
		menu = super.CreateScriptedMenu(id);

		if (id == MENU_RADIONOTIFICATION_BOOKMENU) {
			menu = new RadioNotificationBookMenu;
			if (menu) {
				menu.SetID(id);
			}
		}

		return menu;
	}
};
#endif