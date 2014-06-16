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
		wxButton* m_btnRefresh;
		wxStaticText* m_stPluginList;
		wxScrolledWindow* m_swPlugins;
		wxPanel* m_panelPlugin;
		wxStaticLine* m_staticline1;
		wxPanel* m_panelPlugin1;
		wxStaticLine* m_staticline2;
		wxPanel* m_panelPlugin2;
		wxStaticLine* m_staticline21;
		wxPanel* m_panelPlugin21;
		wxStaticText* m_stTotals;
		wxButton* m_btnInstall;
		wxButton* m_btnClose;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRefresh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInstall( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PluginMgrDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plugin Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 641,490 ), long style = wxDEFAULT_DIALOG_STYLE ); 
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
		wxCheckBox* m_cbComponent1;
		wxCheckBox* m_cbComponent2;
		wxCheckBox* m_cbComponent3;
		wxStaticBitmap* m_bmpScreenshot;
		wxStaticText* m_stAuthor;
		wxHyperlinkCtrl* m_hlnkWebsite;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheckInstall( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckData( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenWebsite( wxHyperlinkEvent& event ) { event.Skip(); }
		
	
	public:
		
		PluginPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,394 ), long style = wxTAB_TRAVERSAL ); 
		~PluginPanel();
	
};

#endif //__GUI_H__
