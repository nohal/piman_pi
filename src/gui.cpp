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
	this->SetSizeHints( wxSize( 620,450 ), wxDefaultSize );
	
	wxBoxSizer* bSizerPluginMgr;
	bSizerPluginMgr = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerLastUpdate;
	bSizerLastUpdate = new wxBoxSizer( wxHORIZONTAL );
	
	m_stLastUpdate = new wxStaticText( this, wxID_ANY, _("Last update:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stLastUpdate->Wrap( -1 );
	bSizerLastUpdate->Add( m_stLastUpdate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_stLastUpdateVal = new wxStaticText( this, wxID_ANY, _("01.01.2014"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stLastUpdateVal->Wrap( -1 );
	m_stLastUpdateVal->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerLastUpdate->Add( m_stLastUpdateVal, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_stUpdatesAvailable = new wxStaticText( this, wxID_ANY, _("Updates available:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stUpdatesAvailable->Wrap( -1 );
	bSizerLastUpdate->Add( m_stUpdatesAvailable, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_stUpdatesAvailableVal = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stUpdatesAvailableVal->Wrap( -1 );
	m_stUpdatesAvailableVal->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerLastUpdate->Add( m_stUpdatesAvailableVal, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
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
	bSizerPlugins = new wxBoxSizer( wxVERTICAL );
	
	
	m_swPlugins->SetSizer( bSizerPlugins );
	m_swPlugins->Layout();
	bSizerPlugins->Fit( m_swPlugins );
	bSizerPluginMgr->Add( m_swPlugins, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizerPluginMgr->Add( 0, 0, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTotals;
	bSizerTotals = new wxBoxSizer( wxHORIZONTAL );
	
	m_stToInstall = new wxStaticText( this, wxID_ANY, _("Selected for installation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stToInstall->Wrap( -1 );
	bSizerTotals->Add( m_stToInstall, 0, wxALL, 5 );
	
	m_stToInstallVal = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stToInstallVal->Wrap( -1 );
	m_stToInstallVal->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTotals->Add( m_stToInstallVal, 0, wxALL, 5 );
	
	m_stToDownload = new wxStaticText( this, wxID_ANY, _("Total to download:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stToDownload->Wrap( -1 );
	bSizerTotals->Add( m_stToDownload, 0, wxALL, 5 );
	
	m_stToDownloadVal = new wxStaticText( this, wxID_ANY, _("10MB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stToDownloadVal->Wrap( -1 );
	m_stToDownloadVal->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerTotals->Add( m_stToDownloadVal, 0, wxALL, 5 );
	
	
	bSizerPluginMgr->Add( bSizerTotals, 0, wxEXPAND, 5 );
	
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
	
	m_stVerAvailable = new wxStaticText( this, wxID_ANY, _("%i.%i (%s)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerAvailable->Wrap( -1 );
	m_stVerAvailable->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizerVersions->Add( m_stVerAvailable, 0, wxALL, 5 );
	
	m_stVerInstalledLabel = new wxStaticText( this, wxID_ANY, _("Version Installed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerInstalledLabel->Wrap( -1 );
	fgSizerVersions->Add( m_stVerInstalledLabel, 0, wxALL, 5 );
	
	m_stVerInstalled = new wxStaticText( this, wxID_ANY, _("%i.%i"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stVerInstalled->Wrap( -1 );
	m_stVerInstalled->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizerVersions->Add( m_stVerInstalled, 0, wxALL, 5 );
	
	
	bSizerPluginInfo->Add( fgSizerVersions, 0, wxEXPAND, 5 );
	
	m_stDescription = new wxStaticText( this, wxID_ANY, _("%s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDescription->Wrap( 300 );
	bSizerPluginInfo->Add( m_stDescription, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizerDependencies;
	fgSizerDependencies = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizerDependencies->SetFlexibleDirection( wxBOTH );
	fgSizerDependencies->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_stDepends = new wxStaticText( this, wxID_ANY, _("Depends on:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDepends->Wrap( -1 );
	fgSizerDependencies->Add( m_stDepends, 0, wxALL, 5 );
	
	m_stDepValue = new wxStaticText( this, wxID_ANY, _("%s\n%s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDepValue->Wrap( -1 );
	fgSizerDependencies->Add( m_stDepValue, 0, wxALL, 5 );
	
	m_stRecommends = new wxStaticText( this, wxID_ANY, _("Recommends:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stRecommends->Wrap( -1 );
	fgSizerDependencies->Add( m_stRecommends, 0, wxALL, 5 );
	
	m_stRecValue = new wxStaticText( this, wxID_ANY, _("%s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stRecValue->Wrap( -1 );
	fgSizerDependencies->Add( m_stRecValue, 0, wxALL, 5 );
	
	
	bSizerPluginInfo->Add( fgSizerDependencies, 1, wxEXPAND, 5 );
	
	m_cbInstall = new wxCheckBox( this, wxID_ANY, _("Install (Download size: %i kB)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbInstall->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizerPluginInfo->Add( m_cbInstall, 0, wxALL, 5 );
	
	m_btnUninstall = new wxButton( this, wxID_ANY, _("Uninstall"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPluginInfo->Add( m_btnUninstall, 0, wxALL, 5 );
	
	bSizerComponents = new wxBoxSizer( wxVERTICAL );
	
	
	bSizerPluginInfo->Add( bSizerComponents, 0, wxEXPAND, 5 );
	
	
	bSizerPlugin->Add( bSizerPluginInfo, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerScreenshot;
	bSizerScreenshot = new wxBoxSizer( wxVERTICAL );
	
	m_bmpScreenshot = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../../../../Pictures/Climatology.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( 240,180 ), 0 );
	bSizerScreenshot->Add( m_bmpScreenshot, 0, wxALL, 5 );
	
	m_stAuthor = new wxStaticText( this, wxID_ANY, _("by %s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stAuthor->Wrap( -1 );
	bSizerScreenshot->Add( m_stAuthor, 0, wxALL, 5 );
	
	m_hlnkWebsite = new wxHyperlinkCtrl( this, wxID_ANY, _("%s"), wxT("%s"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizerScreenshot->Add( m_hlnkWebsite, 0, wxALL, 5 );
	
	
	bSizerPlugin->Add( bSizerScreenshot, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerPlugin );
	this->Layout();
	
	// Connect Events
	m_cbInstall->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckInstall ), NULL, this );
	m_btnUninstall->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginPanel::OnUninstall ), NULL, this );
	m_hlnkWebsite->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( PluginPanel::OnOpenWebsite ), NULL, this );
}

PluginPanel::~PluginPanel()
{
	// Disconnect Events
	m_cbInstall->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanel::OnCheckInstall ), NULL, this );
	m_btnUninstall->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PluginPanel::OnUninstall ), NULL, this );
	m_hlnkWebsite->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( PluginPanel::OnOpenWebsite ), NULL, this );
	
}

PimanSettingsDlg::PimanSettingsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerSettings;
	bSizerSettings = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerListUrl;
	bSizerListUrl = new wxBoxSizer( wxHORIZONTAL );
	
	m_stListUrl = new wxStaticText( this, wxID_ANY, _("Plugin manifest list"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stListUrl->Wrap( -1 );
	bSizerListUrl->Add( m_stListUrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_tPluginListUrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerListUrl->Add( m_tPluginListUrl, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerSettings->Add( bSizerListUrl, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerUpdateCheck;
	bSizerUpdateCheck = new wxBoxSizer( wxHORIZONTAL );
	
	m_cbStartupCheck = new wxCheckBox( this, wxID_ANY, _("Check for updates at startup"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbStartupCheck->SetValue(true); 
	bSizerUpdateCheck->Add( m_cbStartupCheck, 0, wxALL, 5 );
	
	m_stEvery = new wxStaticText( this, wxID_ANY, _("every"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stEvery->Wrap( -1 );
	m_stEvery->Enable( false );
	
	bSizerUpdateCheck->Add( m_stEvery, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_spStartupCheckPeriod = new wxSpinCtrl( this, wxID_ANY, wxT("30"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 7, 365, 0 );
	m_spStartupCheckPeriod->Enable( false );
	
	bSizerUpdateCheck->Add( m_spStartupCheckPeriod, 0, wxALL, 5 );
	
	m_stDays = new wxStaticText( this, wxID_ANY, _("days"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stDays->Wrap( -1 );
	m_stDays->Enable( false );
	
	bSizerUpdateCheck->Add( m_stDays, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizerSettings->Add( bSizerUpdateCheck, 0, wxEXPAND, 5 );
	
	m_cbDownloadPictures = new wxCheckBox( this, wxID_ANY, _("Download icons and screenshots"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerSettings->Add( m_cbDownloadPictures, 0, wxALL, 5 );
	
	m_cbAutoUpdate = new wxCheckBox( this, wxID_ANY, _("Install updates automatically"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerSettings->Add( m_cbAutoUpdate, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerBlacklist;
	bSizerBlacklist = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerBlacklist->Add( 25, 0, 0, 0, 5 );
	
	wxBoxSizer* bSizerInnerBlacklist;
	bSizerInnerBlacklist = new wxBoxSizer( wxVERTICAL );
	
	m_stAutoUpdateBlacklist = new wxStaticText( this, wxID_ANY, _("Ignore automatic updates for"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stAutoUpdateBlacklist->Wrap( -1 );
	m_stAutoUpdateBlacklist->Enable( false );
	
	bSizerInnerBlacklist->Add( m_stAutoUpdateBlacklist, 0, wxALL, 5 );
	
	wxString m_clAutoUpdateBlacklistChoices[] = { _("aaa") };
	int m_clAutoUpdateBlacklistNChoices = sizeof( m_clAutoUpdateBlacklistChoices ) / sizeof( wxString );
	m_clAutoUpdateBlacklist = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_clAutoUpdateBlacklistNChoices, m_clAutoUpdateBlacklistChoices, 0 );
	m_clAutoUpdateBlacklist->Enable( false );
	
	bSizerInnerBlacklist->Add( m_clAutoUpdateBlacklist, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerBlacklist->Add( bSizerInnerBlacklist, 1, wxEXPAND, 5 );
	
	
	bSizerSettings->Add( bSizerBlacklist, 1, wxEXPAND, 5 );
	
	m_btnPurgeData = new wxButton( this, wxID_ANY, _("Purge cached data"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerSettings->Add( m_btnPurgeData, 0, wxALL, 5 );
	
	
	bSizerSettings->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_sdbSButtons = new wxStdDialogButtonSizer();
	m_sdbSButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSButtons->AddButton( m_sdbSButtonsOK );
	m_sdbSButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSButtons->AddButton( m_sdbSButtonsCancel );
	m_sdbSButtons->Realize();
	
	bSizerSettings->Add( m_sdbSButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizerSettings );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_cbStartupCheck->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnCheckAtStartupCheck ), NULL, this );
	m_cbDownloadPictures->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnDownloadPicturesCheck ), NULL, this );
	m_cbAutoUpdate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnAutoInstallCheck ), NULL, this );
	m_clAutoUpdateBlacklist->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( PimanSettingsDlg::OnBlacklistCheck ), NULL, this );
	m_btnPurgeData->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnPurgeData ), NULL, this );
}

PimanSettingsDlg::~PimanSettingsDlg()
{
	// Disconnect Events
	m_cbStartupCheck->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnCheckAtStartupCheck ), NULL, this );
	m_cbDownloadPictures->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnDownloadPicturesCheck ), NULL, this );
	m_cbAutoUpdate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnAutoInstallCheck ), NULL, this );
	m_clAutoUpdateBlacklist->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( PimanSettingsDlg::OnBlacklistCheck ), NULL, this );
	m_btnPurgeData->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PimanSettingsDlg::OnPurgeData ), NULL, this );
	
}
