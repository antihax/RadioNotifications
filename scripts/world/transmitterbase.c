/**
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2022 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 **/

#ifndef SERVER
modded class TransmitterBase {
	protected ref RadioNotificationTransmitterContext m_RNTC;

	void TransmitterBase() {
		if (GetGame().IsClient())
			m_RNTC = new RadioNotificationTransmitterContext(this);
	}

	void ~TransmitterBase() { delete m_RNTC; }

	override void OnWorkStart() {
		if (m_RNTC)
			m_RNTC.OnWorkStart();
		super.OnWorkStart();
	}

	override void OnWorkStop() {
		if (m_RNTC)
			m_RNTC.OnWorkStop();
		super.OnWorkStop();
	}
}
#endif