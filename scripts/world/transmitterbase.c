modded class TransmitterBase {

	protected ref RadioNotification_Transmitter_Context m_RNTC;

	void TransmitterBase() {
		if (GetGame().IsClient())
			m_RNTC = new RadioNotification_Transmitter_Context(this);
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