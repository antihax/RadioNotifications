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
modded class TransmitterBase {
	protected autoptr RadioNotificationTransmitterContext m_RNTC;

	void TransmitterBase() {
		m_RNTC = new RadioNotificationTransmitterContext(this);
	}

	void ~TransmitterBase() {
	}

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
#else
modded class TransmitterBase {
	void TransmitterBase() {
	}

	void ~TransmitterBase() {
	}

	void SwitchBroadcastAndReceiveEnabled(bool enable) {
		if (RadioNotificationSettings.GetSettings().disablePlayerBroadcast) {
			if (RadioNotificationSettings.GetSettings().radioChannel == GetTunedFrequencyIndex() % 8) {
				EnableBroadcast(false);
				EnableReceive(false);
				return;
			}
		}
		EnableBroadcast(enable);
		EnableReceive(enable);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version) {
		if (!super.OnStoreLoad(ctx, version))
			return false;
		SwitchBroadcastAndReceiveEnabled(IsOn());
		return true;
	}

	override void SetNextFrequency(PlayerBase player = NULL) {
		super.SetNextFrequency(player);
		SwitchBroadcastAndReceiveEnabled(IsOn());
	}

	override void OnWorkStart() {
		super.OnWorkStart();
		SwitchBroadcastAndReceiveEnabled(true);
	}

	override void OnWorkStop() {
		super.OnWorkStop();
		SwitchBroadcastAndReceiveEnabled(false);
	}
}
#endif