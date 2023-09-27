/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */

// [TODO] move if we need more actions

const int MENU_RADIONOTIFICATION_BOOKMENU = -551211;
const int IDC_ANTIHAX_RIP = 99564;

modded class ActionConstructor {
	override void RegisterActions(TTypenameArray actions) {
		super.RegisterActions(actions);
		actions.Insert(ActionOpenSIGINTBook);
	}
}

class ActionOpenSIGINTBook : ActionSingleUseBase {
	void ActionOpenSIGINTBook() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText() {
		return "#read";
	}

	override bool HasTarget() {
		return false;
	}

#ifndef SERVER
	override void OnExecuteClient(ActionData action_data) {
		if (!action_data.m_Player)
			return;

		InventoryItem book = action_data.m_Player.GetItemInHands();
		RadioNotificationBookMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_RADIONOTIFICATION_BOOKMENU, NULL));
	}
#endif

	override void OnExecuteServer(ActionData action_data) {
	}
}

class Book_RadioNotificationsSIGINT : ItemBase {
	override void SetActions() {
		super.SetActions();

		AddAction(ActionOpenSIGINTBook);
	}
}
#ifndef SERVER
class RadioNotificationBookTabber : ScriptedWidgetEventHandler {
	protected Widget m_Root;
	protected int m_TabsCount;
	protected int m_CurrentTabIndex;
	protected autoptr map<int, Widget> m_Tabs;

	void OnWidgetScriptInit(Widget w) {
		m_TabsCount = 0;
		m_Tabs = new map<int, Widget>;
		m_Root = w;
		while (w.FindAnyWidget("Tab_" + m_TabsCount)) {
			auto widget = w.FindAnyWidget("Tab_" + m_TabsCount);
			m_Tabs.Insert(m_TabsCount, widget);
			widget.Show(!m_TabsCount); // Show first tab
			++m_TabsCount;
		}
	}

	void PreviousTabPanel() {
		SelectTabPanel(m_CurrentTabIndex - 1);
	}

	void NextTabPanel() {
		SelectTabPanel(m_CurrentTabIndex + 1);
	}

	void SelectTabPanel(int index) {
		if (index < 0 || index >= m_TabsCount)
			index = 0;
		Widget tab = m_Tabs.Get(m_CurrentTabIndex);
		if (tab) {
			tab.Show(false);
		}

		tab = m_Tabs.Get(index);
		if (tab) {
			m_CurrentTabIndex = index;
			tab.Show(true);
		}
	}
}

class RadioNotificationBookMenu : UIScriptedMenu {
	protected Widget m_Root;
	protected RadioNotificationBookTabber m_Tabber;
	protected RichTextWidget m_Pad;
	protected RichTextWidget m_CipherText;
	protected RichTextWidget m_Key;
	protected RichTextWidget m_PlainText;

	override Widget Init() {
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("RadioNotifications/gui/radionotification_sigint_book.layout");
		m_Root = layoutRoot;
		m_Root.FindAnyWidget("Tabber").GetScript(m_Tabber);
		g_Game.SetKeyboardHandle(this);

		m_Pad = RichTextWidget.Cast(m_Root.FindAnyWidget("PadText"));
		m_CipherText = RichTextWidget.Cast(m_Root.FindAnyWidget("CipherTextText"));
		m_Key = RichTextWidget.Cast(m_Root.FindAnyWidget("KeyText"));
		m_PlainText = RichTextWidget.Cast(m_Root.FindAnyWidget("PlainTextText"));

		return layoutRoot;
	}

	private string PadFormat(string text) {
		string result = "";
		for (int i = 0; i < text.Length(); i++) {
			if (i > 0 && i % 5 == 0) {
				result += " ";
			}
			result += text.Get(i);
		}
		return result;
	}

	void UpdateText() {
		m_Pad.SetText(PadFormat(GetRadioNotificationClientHandler().GetPad()));
		m_CipherText.SetText(PadFormat(GetRadioNotificationClientHandler().GetCipherText()));
		m_Key.SetText(PadFormat(GetRadioNotificationClientHandler().GetKey()));
		m_PlainText.SetText(GetRadioNotificationClientHandler().GetPlainText());
	}

	// return true; idk why
	override bool OnKeyDown(Widget w, int x, int y, int key) {
		bool numpad, space;
		switch (key) {
		case KeyCode.KC_ESCAPE:
			Close();
			return true;

		case KeyCode.KC_BACK:
		case KeyCode.KC_DELETE:
			GetRadioNotificationClientHandler().RemoveLetter();
			UpdateText();
			return true;

		case KeyCode.KC_NUMPAD0:
		case KeyCode.KC_NUMPAD1:
		case KeyCode.KC_NUMPAD2:
		case KeyCode.KC_NUMPAD3:
		case KeyCode.KC_NUMPAD4:
		case KeyCode.KC_NUMPAD5:
		case KeyCode.KC_NUMPAD6:
		case KeyCode.KC_NUMPAD7:
		case KeyCode.KC_NUMPAD8:
		case KeyCode.KC_NUMPAD9:
		case KeyCode.KC_0:
		case KeyCode.KC_1:
		case KeyCode.KC_2:
		case KeyCode.KC_3:
		case KeyCode.KC_4:
		case KeyCode.KC_5:
		case KeyCode.KC_6:
		case KeyCode.KC_7:
		case KeyCode.KC_8:
		case KeyCode.KC_9:

			auto keyName = KeysToUIElements.GetKeyToUIElement(key);
			if (!keyName)
				break;

			string name = keyName.param1;
			if (name.Length() == 4)
				name = name[3];

			GetRadioNotificationClientHandler().AddLetter(name);
			UpdateText();
			return true;
		}

		return super.OnKeyDown(w, x, y, key);
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		switch (w.GetUserID()) {
		case IDC_BOOK_VIEWER_PREV:
			m_Tabber.PreviousTabPanel();
			return true;
		case IDC_BOOK_VIEWER_NEXT:
			m_Tabber.NextTabPanel();
			return true;
		case IDC_CANCEL:
			Close();
			return true;
		case IDC_ANTIHAX_RIP:
			GetRadioNotificationClientHandler().ClearLetters();
			UpdateText();
			return true;
		}

		return super.OnClick(w, x, y, button);
	}

	override void OnShow() {
		if (GetGame().GetMission())
			GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		super.OnShow();
	}

	override void OnHide() {
		super.OnHide();
		if (GetGame().GetMission())
			GetGame().GetMission().PlayerControlEnable(true);
	}
}
#endif