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

class RadioNotificationBookTabCreditsPage : ScriptedWidgetEventHandler {
	protected Widget m_Root;
	protected HtmlWidget m_PageText;

	void OnWidgetScriptInit(Widget w) {
		GetGame().GetWorkspace().CreateWidgets(GetLayoutName(), w);
		m_Root = w;
		m_PageText = HtmlWidget.Cast(m_Root.FindAnyWidget("PageText"));
		FileHandle file_handle = OpenFile("RadioNotifications/data/credits.html", FileMode.READ);
		string content;
		string line_content;
		while (FGets(file_handle, line_content) >= 0) {
			content += line_content;
		}
		CloseFile(file_handle);
		m_PageText.SetText(content);
	}

	override bool OnEvent(EventType eventType, Widget target, int parameter0, int parameter1) {

		PrintFormat("OnEvent: %1, %2, %3, %4", eventType, target, parameter0, parameter1);
		return super.OnEvent(eventType, target, parameter0, parameter1);
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