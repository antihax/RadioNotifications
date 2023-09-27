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
class RadioNotificationBookTabReportPage : ScriptedWidgetEventHandler {
	protected Widget m_Root;
	protected HtmlWidget m_PageText;

	void OnWidgetScriptInit(Widget w) {
		GetGame().GetWorkspace().CreateWidgets(GetLayoutName(), w);
		m_Root = w;
		m_PageText = HtmlWidget.Cast(m_Root.FindAnyWidget("PageText"));
		string text = Widget.TranslateString("#radionotification_sigint_report_page1");
		text.Replace("\\n", "\n");
		m_PageText.SetText(text);
	}

	string GetLayoutName() {
		return "RadioNotifications/gui/radionotification_sigint_htmlpagescroll.layout";
	}
}

class RadioNotificationBookTabCodePage : ScriptedWidgetEventHandler {
	protected Widget m_Root;
	protected HtmlWidget m_PageText;

	void OnWidgetScriptInit(Widget w) {
		GetGame().GetWorkspace().CreateWidgets(GetLayoutName(), w);
		m_Root = w;
		m_PageText = HtmlWidget.Cast(m_Root.FindAnyWidget("PageText"));
		// HACK: This is a hack to get the text to display properly.
		m_PageText.SetText(RadioNotificationSettings.GetSettings().GetOneTimePad().GetPadText() + "\n\n\n\n\n\n\n\n\n\n\n\n");
	}

	string GetLayoutName() {
		return "RadioNotifications/gui/radionotification_sigint_htmlpage.layout";
	}
}

class RadioNotificationBookTabWordPage : ScriptedWidgetEventHandler {
	protected Widget m_Root;
	protected HtmlWidget m_PageText;

	void OnWidgetScriptInit(Widget w) {
		GetGame().GetWorkspace().CreateWidgets(GetLayoutName(), w);
		m_Root = w;
		m_PageText = HtmlWidget.Cast(m_Root.FindAnyWidget("PageText"));
		// HACK: This is a hack to get the text to display properly.
		m_PageText.SetText(RadioNotificationSettings.GetSettings().GetOneTimePad().GetWordTableText() + "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}

	string GetLayoutName() {
		return "RadioNotifications/gui/radionotification_sigint_htmlpage.layout";
	}
}

class RadioNotificationBookTabTablePage : ScriptedWidgetEventHandler {
	protected Widget m_Root;
	protected HtmlWidget m_PageText;

	void OnWidgetScriptInit(Widget w) {
		GetGame().GetWorkspace().CreateWidgets(GetLayoutName(), w);
		m_Root = w;
	}

	string GetLayoutName() {
		return "RadioNotifications/gui/radionotification_sigint_codepage.layout";
	}
}
#endif