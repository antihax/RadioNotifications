/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2022 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

#ifdef SERVER
modded class BuildingBase {
	private int m_RadioNotificationID;
	override void EEInit() {
		super.EEInit();
		// Shut up the script errors... Some statics are crawling through here very early.
		if (GetRadioNotificationManager())
			m_RadioNotificationID = GetRadioNotificationManager().GetNewTransmissionID(GetType(), GetPosition());
		else
			Print("BuildingBase::EEInit Warning! Manager Unavailable " + GetType() + " " + GetPosition());
	}

	override void EEDelete(EntityAI parent) {
		if (m_RadioNotificationID > 0)
			GetRadioNotificationManager().Remove(m_RadioNotificationID);
		super.EEDelete(parent);
	}
}
#endif