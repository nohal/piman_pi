///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/scrolwin.h>
#include <wx/dialog.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/checkbox.h>
#include <wx/hyperlink.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/checklst.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class PluginMgrDlg
///////////////////////////////////////////////////////////////////////////////
class PluginMgrDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_stLastUpdate;
		wxStaticText* m_stLastUpdateVal;
		wxStaticText* m_stUpdatesAvailable;
		wxStaticText* m_stUpdatesAvailableVal;
		wxButton* m_btnRefresh;
		wxStaticText* m_stPluginList;
		wxScrolledWindow* m_swPlugins;
		wxBoxSizer* bSizerPlugins;
		wxPanel* m_panelPlugin;
		wxStaticLine* m_staticline1;
		wxStaticText* m_stToInstall;
		wxStaticText* m_stToInstallVal;
		wxStaticText* m_stToDownload;
		wxStaticText* m_stToDownloadVal;
		wxButton* m_btnInstall;
		wxButton* m_btnClose;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRefresh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInstall( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PluginMgrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plugin Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,450 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PluginMgrDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PluginPanel
///////////////////////////////////////////////////////////////////////////////
class PluginPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticBitmap* m_bmpIcon;
		wxStaticText* m_stPluginName;
		wxStaticText* m_stVerAvailableLabel;
		wxStaticText* m_stVerAvailable;
		wxStaticText* m_stVerInstalledLabel;
		wxStaticText* m_stVerInstalled;
		wxStaticText* m_stDescription;
		wxStaticText* m_stDepends;
		wxStaticText* m_stDepValue;
		wxStaticText* m_stRecommends;
		wxStaticText* m_stRecValue;
		wxCheckBox* m_cbInstall;
		wxBoxSizer* bSizerComponents;
		wxStaticBitmap* m_bmpScreenshot;
		wxStaticText* m_stAuthor;
		wxHyperlinkCtrl* m_hlnkWebsite;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheckInstall( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenWebsite( wxHyperlinkEvent& event ) { event.Skip(); }
		
	
	public:
		
		PluginPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,394 ), long style = wxTAB_TRAVERSAL ); 
		~PluginPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PimanSettingsDlg
///////////////////////////////////////////////////////////////////////////////
class PimanSettingsDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_stListUrl;
		wxTextCtrl* m_tPluginListUrl;
		wxCheckBox* m_cbStartupCheck;
		wxStaticText* m_stEvery;
		wxSpinCtrl* m_spStartupCheckPeriod;
		wxStaticText* m_stDays;
		wxCheckBox* m_cbDownloadPictures;
		wxCheckBox* m_cbAutoUpdate;
		wxStaticText* m_stAutoUpdateBlacklist;
		wxCheckListBox* m_clAutoUpdateBlacklist;
		wxStdDialogButtonSizer* m_sdbSButtons;
		wxButton* m_sdbSButtonsOK;
		wxButton* m_sdbSButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheckAtStartupCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDownloadPicturesCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAutoInstallCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBlacklistCheck( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PimanSettingsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plug-in Manager Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,450 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PimanSettingsDlg();
	
};

#endif //__GUI_H__
