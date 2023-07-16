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
		GetRadioNotificationManager().Remove(m_RadioNotificationID);
		super.EEDelete(parent);
	}
}
#endif