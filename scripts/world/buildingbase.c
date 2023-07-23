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
modded class BuildingBase {
	protected int m_RadioNotificationID;
	protected ref Timer m_RadioNotificationUpdateTimer;

	override void EEInit() {
		super.EEInit();
		// Shut up the script errors... Some statics are crawling through here very early.
		if (GetRadioNotificationManager()) {
			m_RadioNotificationID = GetRadioNotificationManager().GetNewTransmissionID(GetType(), GetPosition());
			//	Print("BuildingBase::EEInit " + GetType() + " " + GetPosition() + " " + m_RadioNotificationID);
			if (m_RadioNotificationID > 0) {
				m_RadioNotificationUpdateTimer = new Timer(CALL_CATEGORY_SYSTEM);
				m_RadioNotificationUpdateTimer.Run(0.25, this, "EOnRadioNotificationUpdate", null, true);
			}
		} else {
			Print("BuildingBase::EEInit Warning! Manager Unavailable " + GetType() + " " + GetPosition());
		}
		Print("BuildingBase::EEInit " + GetType() + " " + GetPosition() + " " + m_RadioNotificationID);
	}

	void EOnRadioNotificationUpdate() {
		// Print("BuildingBase::EOnRadioNotificationUpdate " + GetType() + " " + GetPosition() + " " + m_RadioNotificationID);
		GetRadioNotificationManager().UpdatePosition(m_RadioNotificationID, GetPosition(), GetDirection());
	}

	override void EEKilled(Object killer) {
		if (m_RadioNotificationID > 0)
			GetRadioNotificationManager().Remove(m_RadioNotificationID);
		super.EEKilled(killer);
	}

	override void EEDelete(EntityAI parent) {
		if (m_RadioNotificationID > 0)
			GetRadioNotificationManager().Remove(m_RadioNotificationID);
		super.EEDelete(parent);
	}
}
#else
modded class AdvancedCommunication {
	override void EEInit() {
		super.EEInit();

		if (GetRadioNotificationClientHandler()) {
			if (!IsInventoryVisible()) // Only PASReceivers
				GetRadioNotificationClientHandler().RegisterPAS(GetPosition());
		} else {
			Print("BuildingBase::EEInit Warning! Handler Unavailable " + GetType() + " " + GetPosition());
		}
	}
}
#endif