///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

PluginMgrDlg::PluginMgrDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerPluginMgr;
	bSizerPluginMgr = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerLastUpdate;
	bSizerLastUpdate = new wxBoxSizer( wxHORIZONTAL );
	
	m_stLastUpdate = new wxStaticText( this, wxID_ANY, _("Last update:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stLastUpdate->Wrap( -1 );
	bSizerLastUpdate->Add( m_stLastUpdate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_stLastUpdateVal = new wxStaticText( this, wxID_ANY, _("01.01.2014 14:30:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stLastUpdateVal->Wrap( -1 );
	m_stLastUpdateVal->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerLastUpdate->Add( m_stLastUpdateVal, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerLastUpdate->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnRefresh = new wxButton( this, wxID_ANY, _("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerLastUpdate->Add( m_btnRefresh, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	bSizerPluginMgr->Add( bSizerLastUpdate, 0, wxEXPAND, 5 );
	
	m_stPluginList = new wxStaticText( this, wxID_ANY, _("Available Plugins"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stPluginList->Wrap( -1 );
	m_stPluginList->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerPluginMgr->Add( m_stPluginList, 0, wxALL, 5 );
	
	m_swPlugins = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_swPlugins->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizerPlugins;
	bSizerPlugins = new wxBoxSizer( wxVERTICAL );
	
	m_panelPlugin = new wxPanel( m_swPlugins, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxTAB_TRAVERSAL );
	bSizerPlugins->Add( m_panelPlugin, 0, wxEXPAND | wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_swPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerPlugins->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_panelPlugin1 = new wxPanel( m_swPlugins, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxTAB_TRAVERSAL );
	bSizerPlugins->Add( m_panelPlugin1, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( m_swPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerPlugins->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	m_panelPlugin2 = new wxPanel( m_swPlugins, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxTAB_TRAVERSAL );
	bSizerPlugins->Add( m_panelPlugin2, 1, wxEXPAND | wxALL, 5 );
	
	m_staticline21 = new wxStaticLine( m_swPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerPlugins->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );
	
	m_panelPlugin21 = new wxPanel( m_swPlugins, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxTAB_TRAVERSAL );
	bSizerPlugins->Add( m_panelPlugin21, 1, wxEXPAND | wxALL, 5 );
	
	
	m_swPlugins->SetSizer( bSizerPlugins );
	m_swPlugins->Layout();
	bSizerPlugins->Fit( m_swPlugins );
	bSizerPluginMgr->Add( m_swPlugins, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizerPluginMgr->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_stTotals = new wxStaticText( this, wxID_ANY, _("Total to download: 10MB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stTotals->Wrap( -1 );
	bSizerPluginMgr->Add( m_stTotals, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnInstall = new wxButton( this, wxID_ANY, _("Install / Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( m_btnInstall, 0, wxALL, 5 );
	
	m_btnClose = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( m_btnClose, 0, wxALL, 5 );
	
	
	bSizerPluginMgr->Add( bSizerButtons, 0, wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPluginMgr );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnRefresh->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginMgrDlg::OnRefresh ), NULL, this );
	m_btnInstall->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginMgrDlg::OnInstall ), NULL, this );
	m_btnClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginMgrDlg::OnClose ), NULL, this );
}

PluginMgrDlg::~PluginMgrDlg()
{
	// Disconnect Events
	m_btnRefresh->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginMgrDlg::OnRefresh ), NULL, this );
	m_btnInstall->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginMgrDlg::OnInstall ), NULL, this );
	m_btnClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginMgrDlg::OnClose ), NULL, this );
	
}

PluginPanel::PluginPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizerPlugin;
	bSizerPlugin = new wxBoxSizer( wxHORIZONTAL );
	
	m_bmpIcon = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../../../../Pictures/watchdog_pi_icon.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 32,32 ), 0 );
	bSizerPlugin->Add( m_bmpIcon, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerPluginInfo;
	bSizerPluginInfo = new wxBoxSizer( wxVERTICAL );
	
	m_stPluginName = new wxStaticText( this, wxID_ANY, _("Some Plugin"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stPluginName->Wrap( -1 );
	m_stPluginName->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerPluginInfo->Add( m_stPluginName, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizerVersions;
	fgSizerVersions = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizerVersions->SetFlexibleDirection( wxBOTH );
	fgSizerVersions->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_stVerAvailableLabel = new wxStaticText( this, wxID_ANY, _("Version available:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerAvailableLabel->Wrap( -1 );
	fgSizerVersions->Add( m_stVerAvailableLabel, 0, wxALL, 5 );
	
	m_stVerAvailable = new wxStaticText( this, wxID_ANY, _("0.10 (2014-03-01)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerAvailable->Wrap( -1 );
	m_stVerAvailable->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizerVersions->Add( m_stVerAvailable, 0, wxALL, 5 );
	
	m_stVerInstalledLabel = new wxStaticText( this, wxID_ANY, _("Version Installed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerInstalledLabel->Wrap( -1 );
	fgSizerVersions->Add( m_stVerInstalledLabel, 0, wxALL, 5 );
	
	m_stVerInstalled = new wxStaticText( this, wxID_ANY, _("None"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerInstalled->Wrap( -1 );
	m_stVerInstalled->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizerVersions->Add( m_stVerInstalled, 0, wxALL, 5 );
	
	
	bSizerPluginInfo->Add( fgSizerVersions, 0, wxEXPAND, 5 );
	
	m_stDescription = new wxStaticText( this, wxID_ANY, _("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDescription->Wrap( 300 );
	bSizerPluginInfo->Add( m_stDescription, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizerDependencies;
	fgSizerDependencies = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizerDependencies->SetFlexibleDirection( wxBOTH );
	fgSizerDependencies->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_stDepends = new wxStaticText( this, wxID_ANY, _("Depends on:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDepends->Wrap( -1 );
	fgSizerDependencies->Add( m_stDepends, 0, wxALL, 5 );
	
	m_stDepValue = new wxStaticText( this, wxID_ANY, _("Plugin 1\nPlugin 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDepValue->Wrap( -1 );
	fgSizerDependencies->Add( m_stDepValue, 0, wxALL, 5 );
	
	m_stRecommends = new wxStaticText( this, wxID_ANY, _("Recommends:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stRecommends->Wrap( -1 );
	fgSizerDependencies->Add( m_stRecommends, 0, wxALL, 5 );
	
	m_stRecValue = new wxStaticText( this, wxID_ANY, _("Plugin 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stRecValue->Wrap( -1 );
	fgSizerDependencies->Add( m_stRecValue, 0, wxALL, 5 );
	
	
	bSizerPluginInfo->Add( fgSizerDependencies, 1, wxEXPAND, 5 );
	
	m_cbInstall = new wxCheckBox( this, wxID_ANY, _("Install (Download size: 1MB)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbInstall->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerPluginInfo->Add( m_cbInstall, 0, wxALL, 5 );
	
	m_cbComponent1 = new wxCheckBox( this, wxID_ANY, _("Needed data (200KB)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbComponent1->SetValue(true); 
	m_cbComponent1->Enable( false );
	
	bSizerPluginInfo->Add( m_cbComponent1, 0, wxLEFT, 15 );
	
	m_cbComponent2 = new wxCheckBox( this, wxID_ANY, _("Recommended data 1 (1MB)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPluginInfo->Add( m_cbComponent2, 0, wxLEFT, 15 );
	
	m_cbComponent3 = new wxCheckBox( this, wxID_ANY, _("Recommended data 2 (10MB)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPluginInfo->Add( m_cbComponent3, 0, wxLEFT, 15 );
	
	
	bSizerPlugin->Add( bSizerPluginInfo, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerScreenshot;
	bSizerScreenshot = new wxBoxSizer( wxVERTICAL );
	
	m_bmpScreenshot = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../../../../Pictures/Climatology.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 240,180 ), 0 );
	bSizerScreenshot->Add( m_bmpScreenshot, 0, wxALL, 5 );
	
	m_stAuthor = new wxStaticText( this, wxID_ANY, _("by John Doe"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stAuthor->Wrap( -1 );
	bSizerScreenshot->Add( m_stAuthor, 0, wxALL, 5 );
	
	m_hlnkWebsite = new wxHyperlinkCtrl( this, wxID_ANY, _("Website"), wxT("http://www.wxformbuilder.org"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizerScreenshot->Add( m_hlnkWebsite, 0, wxALL, 5 );
	
	
	bSizerPlugin->Add( bSizerScreenshot, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPlugin );
	this->Layout();
	
	// Connect Events
	m_cbInstall->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckInstall ), NULL, this );
	m_cbComponent2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckData ), NULL, this );
	m_cbComponent3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckData ), NULL, this );
	m_hlnkWebsite->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( PluginPanel::OnOpenWebsite ), NULL, this );
}

PluginPanel::~PluginPanel()
{
	// Disconnect Events
	m_cbInstall->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckInstall ), NULL, this );
	m_cbComponent2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckData ), NULL, this );
	m_cbComponent3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckData ), NULL, this );
	m_hlnkWebsite->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( PluginPanel::OnOpenWebsite ), NULL, this );
	
}
