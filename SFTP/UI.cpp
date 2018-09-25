//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "UI.h"

// Declare the bitmap loading function
extern void wxC32BEInitBitmapResources();

static bool bBitmapLoaded = false;

SFTPStatusPageBase::SFTPStatusPageBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size,
                                       long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);

    m_stcOutput = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    // Configure the fold margin
    m_stcOutput->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_stcOutput->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_stcOutput->SetMarginSensitive(4, true);
    m_stcOutput->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_stcOutput->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_stcOutput->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_stcOutput->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_stcOutput->SetMarginWidth(2, 0);
    m_stcOutput->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_stcOutput->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcOutput->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_stcOutput->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcOutput->SetMarginMask(3, 0);
    m_stcOutput->SetMarginWidth(3, 0);
    // Select the lexer
    m_stcOutput->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcOutput->StyleClearAll();
    m_stcOutput->SetWrapMode(0);
    m_stcOutput->SetIndentationGuides(0);
    m_stcOutput->SetKeyWords(0, wxT(""));
    m_stcOutput->SetKeyWords(1, wxT(""));
    m_stcOutput->SetKeyWords(2, wxT(""));
    m_stcOutput->SetKeyWords(3, wxT(""));
    m_stcOutput->SetKeyWords(4, wxT(""));

    boxSizer2->Add(m_stcOutput, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    SetName(wxT("SFTPStatusPageBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    // Connect events
    m_stcOutput->Connect(wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(SFTPStatusPageBase::OnContentMenu), NULL, this);
}

SFTPStatusPageBase::~SFTPStatusPageBase()
{
    m_stcOutput->Disconnect(wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(SFTPStatusPageBase::OnContentMenu), NULL,
                            this);
}

SFTPImages::SFTPImages()
    : wxImageList(16, 16, true)
    , m_imagesWidth(16)
    , m_imagesHeight(16)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_ok"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_ok"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_ok@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_ok@2x"), bmp));
        }
    }

    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_error"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_error"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_error@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_error@2x"), bmp));
        }
    }

    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_info"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_info"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_info@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_info@2x"), bmp));
        }
    }

    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_tab"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_tab"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_tab@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_tab@2x"), bmp));
        }
    }

    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_connected"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_connected"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_connected@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_connected@2x"), bmp));
        }
    }

    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_disconnected"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_disconnected"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("sftp_disconnected@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())) {
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("sftp_disconnected@2x"), bmp));
        }
    }
}

SFTPImages::~SFTPImages() {}

SFTPTreeViewBase::SFTPTreeViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer16 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer16);

    m_toolbar = new clToolBar(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTB_FLAT);
    m_toolbar->SetToolBitmapSize(wxSize(16, 16));

    boxSizer16->Add(m_toolbar, 0, wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer43 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer43->SetFlexibleDirection(wxBOTH);
    flexGridSizer43->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer43->AddGrowableCol(1);

    boxSizer16->Add(flexGridSizer43, 0, wxEXPAND, WXC_FROM_DIP(5));

    m_staticText49 =
        new wxStaticText(this, wxID_ANY, _("Go to:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer43->Add(m_staticText49, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlQuickJump = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                         wxTE_PROCESS_ENTER);
    m_textCtrlQuickJump->SetToolTip(_("Type a path and hit ENTER"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlQuickJump->SetHint(wxT(""));
#endif

    flexGridSizer43->Add(m_textCtrlQuickJump, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_treeCtrl = new clThemedTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                      wxTR_DEFAULT_STYLE | wxTR_MULTIPLE);

    boxSizer16->Add(m_treeCtrl, 1, wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("SFTPTreeViewBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    // Connect events
    m_staticText49->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPTreeViewBase::OnGotoLocationUI), NULL, this);
    m_textCtrlQuickJump->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(SFTPTreeViewBase::OnGotoLocation),
                                 NULL, this);
    m_textCtrlQuickJump->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPTreeViewBase::OnGotoLocationUI), NULL,
                                 this);
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(SFTPTreeViewBase::OnItemActivated), NULL,
                        this);
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_ITEM_EXPANDING, wxTreeEventHandler(SFTPTreeViewBase::OnItemExpanding), NULL,
                        this);
    m_treeCtrl->Connect(wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(SFTPTreeViewBase::OnContextMenu), NULL, this);
}

SFTPTreeViewBase::~SFTPTreeViewBase()
{
    m_staticText49->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPTreeViewBase::OnGotoLocationUI), NULL, this);
    m_textCtrlQuickJump->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(SFTPTreeViewBase::OnGotoLocation),
                                    NULL, this);
    m_textCtrlQuickJump->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPTreeViewBase::OnGotoLocationUI), NULL,
                                    this);
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler(SFTPTreeViewBase::OnItemActivated),
                           NULL, this);
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_ITEM_EXPANDING, wxTreeEventHandler(SFTPTreeViewBase::OnItemExpanding),
                           NULL, this);
    m_treeCtrl->Disconnect(wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(SFTPTreeViewBase::OnContextMenu), NULL, this);
}

SFTPManageBookmarkDlgBase::SFTPManageBookmarkDlgBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                                     const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer56 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer56);

    wxBoxSizer* boxSizer64 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer56->Add(boxSizer64, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxArrayString m_listBoxBookmarksArr;
    m_listBoxBookmarks = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                       m_listBoxBookmarksArr, wxLB_NEEDED_SB | wxLB_SINGLE);

    boxSizer64->Add(m_listBoxBookmarks, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer68 = new wxBoxSizer(wxVERTICAL);

    boxSizer64->Add(boxSizer68, 0, wxEXPAND, WXC_FROM_DIP(5));

    m_button70 = new wxButton(this, wxID_DELETE, _("Delete"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer68->Add(m_button70, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer58 = new wxStdDialogButtonSizer();

    boxSizer56->Add(m_stdBtnSizer58, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOk = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOk->SetDefault();
    m_stdBtnSizer58->AddButton(m_buttonOk);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer58->AddButton(m_buttonCancel);
    m_stdBtnSizer58->Realize();

    SetName(wxT("SFTPManageBookmarkDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button70->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SFTPManageBookmarkDlgBase::OnDelete), NULL,
                        this);
    m_button70->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPManageBookmarkDlgBase::OnDeleteUI), NULL, this);
}

SFTPManageBookmarkDlgBase::~SFTPManageBookmarkDlgBase()
{
    m_button70->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SFTPManageBookmarkDlgBase::OnDelete),
                           NULL, this);
    m_button70->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPManageBookmarkDlgBase::OnDeleteUI), NULL, this);
}

SFTPSettingsDialogBase::SFTPSettingsDialogBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                               const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer83 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer83);

    wxFlexGridSizer* flexGridSizer91 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer91->SetFlexibleDirection(wxBOTH);
    flexGridSizer91->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer91->AddGrowableCol(1);

    boxSizer83->Add(flexGridSizer91, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticSSHClient =
        new wxStaticText(this, wxID_ANY, _("SSH Client:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer91->Add(m_staticSSHClient, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_sshClientPath =
        new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*"), wxDefaultPosition,
                             wxDLG_UNIT(this, wxSize(-1, -1)), wxFLP_DEFAULT_STYLE | wxFLP_USE_TEXTCTRL | wxFLP_OPEN);

    flexGridSizer91->Add(m_sshClientPath, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer85 = new wxStdDialogButtonSizer();

    boxSizer83->Add(m_stdBtnSizer85, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button87 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button87->SetDefault();
    m_stdBtnSizer85->AddButton(m_button87);

    m_button89 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer85->AddButton(m_button89);
    m_stdBtnSizer85->Realize();

    SetName(wxT("SFTPSettingsDialogBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button87->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SFTPSettingsDialogBase::OnOK), NULL, this);
}

SFTPSettingsDialogBase::~SFTPSettingsDialogBase()
{
    m_button87->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SFTPSettingsDialogBase::OnOK), NULL,
                           this);
}

SFTPUploadDialogBase::SFTPUploadDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                           const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer102 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer102);

    m_staticText110 = new wxStaticText(this, wxID_ANY, _("Upload the files to this folder:"), wxDefaultPosition,
                                       wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer102->Add(m_staticText110, 0, wxALL, WXC_FROM_DIP(5));

    m_textCtrlRemoteFolder =
        new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(400, -1)), 0);
#ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to
    // wxFONTFAMILY_TELETYPE
    wxFont m_textCtrlRemoteFolderFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_textCtrlRemoteFolderFont.SetFamily(wxFONTFAMILY_TELETYPE);
#else
    wxFont m_textCtrlRemoteFolderFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_textCtrlRemoteFolderFont.SetFamily(wxFONTFAMILY_TELETYPE);
#endif
    m_textCtrlRemoteFolder->SetFont(m_textCtrlRemoteFolderFont);
    m_textCtrlRemoteFolder->SetToolTip(_("Set the remote folder path"));
    m_textCtrlRemoteFolder->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlRemoteFolder->SetHint(wxT(""));
#endif

    boxSizer102->Add(m_textCtrlRemoteFolder, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    boxSizer102->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_stdBtnSizer104 = new wxStdDialogButtonSizer();

    boxSizer102->Add(m_stdBtnSizer104, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer104->AddButton(m_buttonOK);

    m_button108 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer104->AddButton(m_button108);
    m_stdBtnSizer104->Realize();

    SetName(wxT("SFTPUploadDialogBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPUploadDialogBase::OnOKUI), NULL, this);
}

SFTPUploadDialogBase::~SFTPUploadDialogBase()
{
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPUploadDialogBase::OnOKUI), NULL, this);
}

SFTPQuickConnectBaseDlg::SFTPQuickConnectBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title,
                                                 const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC32BEInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer121 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer121);

    m_checkBoxChooseAccount = new wxCheckBox(this, wxID_ANY, _("Connect to an existing account"), wxDefaultPosition,
                                             wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxChooseAccount->SetValue(true);

    boxSizer121->Add(m_checkBoxChooseAccount, 0, wxALL, WXC_FROM_DIP(5));

    wxArrayString m_choiceAccountArr;
    m_choiceAccount =
        new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceAccountArr, 0);
    m_choiceAccount->SetToolTip(_("Choose an account to connect to"));

    boxSizer121->Add(m_choiceAccount, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticLine135 =
        new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxLI_HORIZONTAL);

    boxSizer121->Add(m_staticLine135, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkBoxQuickConnect =
        new wxCheckBox(this, wxID_ANY, _("Quick connect"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxQuickConnect->SetValue(false);

    boxSizer121->Add(m_checkBoxQuickConnect, 0, wxALL, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer141 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer141->SetFlexibleDirection(wxBOTH);
    flexGridSizer141->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer141->AddGrowableCol(1);

    boxSizer121->Add(flexGridSizer141, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText143 =
        new wxStaticText(this, wxID_ANY, _("Host:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer141->Add(m_staticText143, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlHost = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_textCtrlHost->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlHost->SetHint(wxT(""));
#endif

    flexGridSizer141->Add(m_textCtrlHost, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText147 =
        new wxStaticText(this, wxID_ANY, _("Port:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer141->Add(m_staticText147, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlPort = new wxTextCtrl(this, wxID_ANY, wxT("22"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPort->SetHint(wxT(""));
#endif

    flexGridSizer141->Add(m_textCtrlPort, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText151 =
        new wxStaticText(this, wxID_ANY, _("User:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer141->Add(m_staticText151, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlUsername =
        new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlUsername->SetHint(wxT(""));
#endif

    flexGridSizer141->Add(m_textCtrlUsername, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText155 =
        new wxStaticText(this, wxID_ANY, _("Password:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer141->Add(m_staticText155, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlPassword =
        new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTE_PASSWORD);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPassword->SetHint(wxT(""));
#endif

    flexGridSizer141->Add(m_textCtrlPassword, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer123 = new wxStdDialogButtonSizer();

    boxSizer121->Add(m_stdBtnSizer123, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(10));

    m_button125 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button125->SetDefault();
    m_stdBtnSizer123->AddButton(m_button125);

    m_button127 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer123->AddButton(m_button127);
    m_stdBtnSizer123->Realize();

    SetName(wxT("SFTPQuickConnectBaseDlg"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) { GetSizer()->Fit(this); }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_checkBoxChooseAccount->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                                     wxCommandEventHandler(SFTPQuickConnectBaseDlg::OnCheckboxChooseAccount), NULL,
                                     this);
    m_choiceAccount->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnChooseAccountUI), NULL,
                             this);
    m_checkBoxQuickConnect->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                                    wxCommandEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnect), NULL, this);
    m_staticText143->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                             this);
    m_textCtrlHost->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                            this);
    m_staticText147->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                             this);
    m_textCtrlPort->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                            this);
    m_staticText151->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                             this);
    m_textCtrlUsername->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                NULL, this);
    m_staticText155->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                             this);
    m_textCtrlPassword->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                NULL, this);
    m_button125->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnOKUI), NULL, this);
}

SFTPQuickConnectBaseDlg::~SFTPQuickConnectBaseDlg()
{
    m_checkBoxChooseAccount->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                                        wxCommandEventHandler(SFTPQuickConnectBaseDlg::OnCheckboxChooseAccount), NULL,
                                        this);
    m_choiceAccount->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnChooseAccountUI),
                                NULL, this);
    m_checkBoxQuickConnect->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED,
                                       wxCommandEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnect), NULL, this);
    m_staticText143->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                NULL, this);
    m_textCtrlHost->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                               this);
    m_staticText147->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                NULL, this);
    m_textCtrlPort->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI), NULL,
                               this);
    m_staticText151->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                NULL, this);
    m_textCtrlUsername->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                   NULL, this);
    m_staticText155->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                NULL, this);
    m_textCtrlPassword->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnQuickConnectUI),
                                   NULL, this);
    m_button125->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(SFTPQuickConnectBaseDlg::OnOKUI), NULL, this);
}
