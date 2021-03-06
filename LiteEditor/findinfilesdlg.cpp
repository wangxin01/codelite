//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : findinfilesdlg.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include "FindInFilesLocationsDlg.h"
#include "clWorkspaceManager.h"
#include "dirpicker.h"
#include "event_notifier.h"
#include "findinfilesdlg.h"
#include "findresultstab.h"
#include "frame.h"
#include "macros.h"
#include "manager.h"
#include "replaceinfilespanel.h"
#include "search_thread.h"
#include "windowattrmanager.h"
#include <algorithm>
#include <wx/fontmap.h>
#include <wx/tokenzr.h>
#include "sessionmanager.h"
#include "workspace.h"
#include <project.h>

FindInFilesDialog::FindInFilesDialog(wxWindow* parent, const wxString& dataName,
                                     const wxArrayString& additionalSearchPaths)
    : FindInFilesDialogBase(parent, wxID_ANY)
{
    m_data.SetName(dataName);
    m_customPaths.insert(additionalSearchPaths.begin(), additionalSearchPaths.end());

    // Store the find-in-files data
    clConfig::Get().ReadItem(&m_data);
    wxString filemask = SessionManager::Get().GetFindInFilesMaskForCurrentWorkspace();
    if(!filemask.IsEmpty()) { m_data.SetSelectedMask(filemask); }
    wxArrayString paths;
    if(m_customPaths.empty()) {
        paths = m_data.GetSearchPaths();
    } else {
        std::for_each(m_customPaths.begin(), m_customPaths.end(), [&](const wxString& path) { paths.Add(path); });
    }

    DoAddSearchPaths(paths);

    // Search for
    m_findString->Clear();
    m_findString->Append(m_data.GetFindStringArr());
    m_findString->SetValue(m_data.GetFindString());
    m_replaceString->Append(m_data.GetReplaceStringArr());
    m_replaceString->SetValue(m_data.GetReplaceString());
    m_fileTypes->SetSelection(0);

    m_matchCase->SetValue(m_data.GetFlags() & wxFRD_MATCHCASE);
    m_matchWholeWord->SetValue(m_data.GetFlags() & wxFRD_MATCHWHOLEWORD);
    m_regualrExpression->SetValue(m_data.GetFlags() & wxFRD_REGULAREXPRESSION);
    m_checkBoxSaveFilesBeforeSearching->SetValue(m_data.GetFlags() & wxFRD_SAVE_BEFORE_SEARCH);
    m_checkBoxPipeForGrep->SetValue(m_data.GetFlags() & wxFRD_ENABLE_PIPE_SUPPORT);
    // Set encoding
    wxArrayString astrEncodings;
    wxFontEncoding fontEnc;
    int selection(0);

    size_t iEncCnt = wxFontMapper::GetSupportedEncodingsCount();
    for(size_t i = 0; i < iEncCnt; i++) {
        fontEnc = wxFontMapper::GetEncoding(i);
        if(wxFONTENCODING_SYSTEM == fontEnc) { // skip system, it is changed to UTF-8 in optionsconfig
            continue;
        }
        wxString encodingName = wxFontMapper::GetEncodingName(fontEnc);
        size_t pos = astrEncodings.Add(encodingName);

        if(m_data.GetEncoding() == encodingName) { selection = static_cast<int>(pos); }
    }

    m_choiceEncoding->Append(astrEncodings);
    if(m_choiceEncoding->IsEmpty() == false) { m_choiceEncoding->SetSelection(selection); }

    // Set the file mask
    DoSetFileMask();
    SetName("FindInFilesDialog");

    // Fit the initial size and set it as the default minimum size
    GetSizer()->Fit(this);
    SetMinSize(GetSize());

    // Load the last size and position, but not on GTK
    WindowAttrManager::Load(this);
    CentreOnParent();
}

FindInFilesDialog::~FindInFilesDialog()
{
    m_data.SetFlags(GetSearchFlags());
    m_data.SetFindString(m_findString->GetValue());
    m_data.SetReplaceString(m_replaceString->GetValue());
    m_data.SetEncoding(m_choiceEncoding->GetStringSelection());
    wxString value = m_fileTypes->GetValue();
    value.Trim().Trim(false);

    wxArrayString masks = m_fileTypes->GetStrings();
    if(masks.Index(value) == wxNOT_FOUND) { masks.Insert(value, 0); }

    m_data.SetSelectedMask(value);
    m_data.SetFileMask(masks);

    // If the search paths were provided by the user, dont store them
    wxArrayString searchPathsArr;
    if(m_customPaths.empty()) {
        wxArrayString searchPathsArr = m_listPaths->GetStrings();
        m_data.SetSearchPaths(searchPathsArr);
    }

    clConfig::Get().WriteItem(&m_data);
    SessionManager::Get().UpdateFindInFilesMaskForCurrentWorkspace(m_data.GetSelectedMask());

    // Notify about the dialog dismissal
    clCommandEvent event(wxEVT_CMD_FIND_IN_FILES_DISMISSED, GetId());
    event.SetEventObject(this);
    event.SetString(m_data.GetSelectedMask());
    EventNotifier::Get()->AddPendingEvent(event);
}

void FindInFilesDialog::DoSetFileMask()
{
    // Get the output
    wxArrayString fileTypes = m_data.GetFileMask();
    wxArrayString pluginsMask = clWorkspaceManager::Get().GetUnifiedFilesMask();

    // sort and merge arrays
    fileTypes.Sort();
    pluginsMask.Sort();
    wxArrayString mergedArr;
    std::merge(fileTypes.begin(), fileTypes.end(), pluginsMask.begin(), pluginsMask.end(),
               std::back_inserter(mergedArr));
    wxArrayString::iterator iter = std::unique(mergedArr.begin(), mergedArr.end());

    // remove the non unique parts
    mergedArr.resize(std::distance(mergedArr.begin(), iter));

    // Create a single mask array
    m_fileTypes->Clear();

    // Remove empty entries
    wxArrayString tempMaskArr;
    std::for_each(mergedArr.begin(), mergedArr.end(), [&](wxString& item) {
        item.Trim().Trim(false);
        if(!item.IsEmpty()) { tempMaskArr.Add(item); }
    });
    mergedArr.swap(tempMaskArr);

    if(!mergedArr.IsEmpty()) {
        m_fileTypes->Append(mergedArr);

        wxString selectedMask = m_data.GetSelectedMask();
        if(selectedMask.IsEmpty() && clWorkspaceManager::Get().IsWorkspaceOpened()) {
            // Let the active workspace set the find-in-files mask
            selectedMask = clWorkspaceManager::Get().GetWorkspace()->GetFilesMask();
        }

        if(!selectedMask.IsEmpty()) {
            int where = m_fileTypes->FindString(selectedMask);
            if(where == wxNOT_FOUND) {
                // Add it
                where = m_fileTypes->Append(selectedMask);
            }
            m_fileTypes->SetSelection(where);
        }
    }
}

void FindInFilesDialog::DoSearchReplace()
{
    SearchData data = DoGetSearchData();
    data.SetOwner(clMainFrame::Get()->GetOutputPane()->GetReplaceResultsTab());
    DoSaveOpenFiles();
    SearchThreadST::Get()->PerformSearch(data);
    EndModal(wxID_OK);
}

void FindInFilesDialog::DoSearch()
{
    SearchData data = DoGetSearchData();
    data.SetOwner(clMainFrame::Get()->GetOutputPane()->GetFindResultsTab());

    // check to see if we require to save the files
    DoSaveOpenFiles();
    SearchThreadST::Get()->PerformSearch(data);
    EndModal(wxID_OK);
}

SearchData FindInFilesDialog::DoGetSearchData()
{
    SearchData data;
    wxString findStr(m_data.GetFindString());
    if(!m_findString->GetValue().IsEmpty()) { findStr = m_findString->GetValue(); }

    data.SetFindString(findStr);
    data.SetReplaceWith(m_replaceString->GetValue());

    m_data.SetFlags(GetSearchFlags());
    size_t flags = m_data.GetFlags();

    // If the 'Skip comments' is ON, remove the
    // 'colour comments' flag
    if(flags & wxFRD_SKIP_COMMENTS) { flags &= ~wxFRD_COLOUR_COMMENTS; }

    data.SetMatchCase((flags & wxFRD_MATCHCASE) != 0);
    data.SetMatchWholeWord((flags & wxFRD_MATCHWHOLEWORD) != 0);
    data.SetRegularExpression((flags & wxFRD_REGULAREXPRESSION) != 0);
    data.SetDisplayScope((flags & wxFRD_DISPLAYSCOPE) != 0);
    data.SetEncoding(m_choiceEncoding->GetStringSelection());
    data.SetSkipComments(flags & wxFRD_SKIP_COMMENTS);
    data.SetSkipStrings(flags & wxFRD_SKIP_STRINGS);
    data.SetColourComments(flags & wxFRD_COLOUR_COMMENTS);
    data.SetEnablePipeSupport(flags & wxFRD_ENABLE_PIPE_SUPPORT);
    wxArrayString searchWhere = m_listPaths->GetStrings();
    wxArrayString files;
    wxArrayString rootDirs;

    for(size_t i = 0; i < searchWhere.GetCount(); ++i) {
        const wxString& rootDir = searchWhere.Item(i);
        if(rootDir.StartsWith("F: ")) {
            // a file
            files.Add(rootDir.Mid(3));
        } else if(rootDir.StartsWith("W: ")) {
            // Add all project files
            wxArrayString projects;
            clCxxWorkspaceST::Get()->GetProjectList(projects);
            for(size_t n = 0; n < projects.size(); ++n) {
                DoAddProjectFiles(projects.Item(n), files);
            }
        } else if(rootDir.StartsWith("V: ")) {
            // a virtual folder
            if(clCxxWorkspaceST::Get()->IsOpen()) {
                wxString vd = rootDir.Mid(3);
                vd.Replace("/", ":"); // Virtual directory is expecting colons as the separator
                wxString projectName = vd.BeforeFirst(':');
                vd = vd.AfterFirst(':');
                ProjectPtr p = clCxxWorkspaceST::Get()->GetProject(projectName);
                if(p) {
                    wxArrayString vdFiles;
                    p->GetFilesByVirtualDir(vd, vdFiles, true);
                    files.insert(files.end(), vdFiles.begin(), vdFiles.end());
                }
            }
        } else if(rootDir.StartsWith("P: ")) {
            // Project
            wxString projectName = rootDir.Mid(3);
            DoAddProjectFiles(projectName, files);

        } else if((rootDir == wxGetTranslation(SEARCH_IN_WORKSPACE_FOLDER)) &&
                  clWorkspaceManager::Get().IsWorkspaceOpened()) {
            // Add the workspace folder
            rootDirs.Add(clWorkspaceManager::Get().GetWorkspace()->GetFileName().GetPath());

        } else if((rootDir == wxGetTranslation(SEARCH_IN_WORKSPACE)) || (rootDir == SEARCH_IN_WORKSPACE)) {
            if(!clWorkspaceManager::Get().IsWorkspaceOpened()) { continue; }
            clWorkspaceManager::Get().GetWorkspace()->GetWorkspaceFiles(files);

        } else if((rootDir == wxGetTranslation(SEARCH_IN_PROJECT)) || (rootDir == SEARCH_IN_PROJECT)) {
            if(!clWorkspaceManager::Get().IsWorkspaceOpened()) continue;
            if(clWorkspaceManager::Get().GetWorkspace()->IsProjectSupported()) {
                // get the active project files
                clWorkspaceManager::Get().GetWorkspace()->GetProjectFiles("", files);
            } else {
                // search the entire workspace
                clWorkspaceManager::Get().GetWorkspace()->GetWorkspaceFiles(files);
            }

        } else if((rootDir == wxGetTranslation(SEARCH_IN_CURR_FILE_PROJECT)) ||
                  (rootDir == SEARCH_IN_CURR_FILE_PROJECT)) {

            if(!clWorkspaceManager::Get().IsWorkspaceOpened()) continue;
            IEditor* editor = clGetManager()->GetActiveEditor();
            if(!editor) continue;

            if(clWorkspaceManager::Get().GetWorkspace()->IsProjectSupported()) {
                wxString projectName =
                    clWorkspaceManager::Get().GetWorkspace()->GetProjectFromFile(editor->GetFileName());
                clWorkspaceManager::Get().GetWorkspace()->GetProjectFiles(projectName, files);
            } else {
                // search the entire workspace
                clWorkspaceManager::Get().GetWorkspace()->GetWorkspaceFiles(files);
            }

        } else if((rootDir == wxGetTranslation(SEARCH_IN_CURRENT_FILE)) || (rootDir == SEARCH_IN_CURRENT_FILE)) {
            clEditor* editor = clMainFrame::Get()->GetMainBook()->GetActiveEditor();
            if(editor) { files.Add(editor->GetFileName().GetFullPath()); }
        } else if((rootDir == wxGetTranslation(SEARCH_IN_OPEN_FILES)) || (rootDir == SEARCH_IN_OPEN_FILES)) {
            std::vector<clEditor*> editors;
            clMainFrame::Get()->GetMainBook()->GetAllEditors(editors, MainBook::kGetAll_IncludeDetached);

            for(size_t n = 0; n < editors.size(); ++n) {
                clEditor* editor = dynamic_cast<clEditor*>(*(editors.begin() + n));
                if(editor) { files.Add(editor->GetFileName().GetFullPath()); }
            }
        } else if(wxFileName::DirExists(searchWhere.Item(i))) {
            rootDirs.Add(searchWhere.Item(i));
        }
    }

    // Remove duplicates
    wxStringSet_t filesSet;
    wxArrayString uniqueFiles;
    // Unique files may contain up to files.size() elements
    uniqueFiles.Alloc(files.size());
    std::for_each(files.begin(), files.end(), [&](const wxString& file) {
        if(filesSet.count(file) == 0) {
            filesSet.insert(file);
            uniqueFiles.Add(file);
        }
    });

    // Release unused memory
    uniqueFiles.Shrink();
    files.swap(uniqueFiles);

    data.SetFiles(files);       // list of files
    data.SetRootDirs(rootDirs); // folders
    data.UseNewTab(false);
    data.SetExtensions(m_fileTypes->GetValue());
    return data;
}

void FindInFilesDialog::OnClose(wxCloseEvent& e) { Destroy(); }

void FindInFilesDialog::OnAddPath(wxCommandEvent& event)
{
#ifdef __WXOSX__
    // There is a bug in OSX that prevents popup menu from being displayed from dialogs
    // so we use an alternative way
    FindInFilesLocationsDlg dlg(this, m_listPaths->GetStrings());
    if(dlg.ShowModal() == wxID_OK) {
        m_listPaths->Clear();
        m_listPaths->Append(dlg.GetLocations());
    }
#else
    // Show a popup menu
    wxMenu menu;
    int firstItem = 8994;
    menu.Append(firstItem + 6, "Add Folder...");
    menu.AppendSeparator();
    menu.Append(firstItem + 0, SEARCH_IN_WORKSPACE_FOLDER);
    menu.Append(firstItem + 1, SEARCH_IN_WORKSPACE);
    menu.Append(firstItem + 2, SEARCH_IN_PROJECT);
    menu.Append(firstItem + 3, SEARCH_IN_CURR_FILE_PROJECT);
    menu.Append(firstItem + 4, SEARCH_IN_CURRENT_FILE);
    menu.Append(firstItem + 5, SEARCH_IN_OPEN_FILES);

    std::map<int, wxString> options;
    options.insert(std::make_pair(firstItem + 0, SEARCH_IN_WORKSPACE_FOLDER));
    options.insert(std::make_pair(firstItem + 1, SEARCH_IN_WORKSPACE));
    options.insert(std::make_pair(firstItem + 2, SEARCH_IN_PROJECT));
    options.insert(std::make_pair(firstItem + 3, SEARCH_IN_CURR_FILE_PROJECT));
    options.insert(std::make_pair(firstItem + 4, SEARCH_IN_CURRENT_FILE));
    options.insert(std::make_pair(firstItem + 5, SEARCH_IN_OPEN_FILES));

    // Menu will be shown in client coordinates
    wxRect size = m_btnAddPath->GetSize();
    wxPoint menuPos(0, size.GetHeight());
    int selection = m_btnAddPath->GetPopupMenuSelectionFromUser(menu, menuPos);

    if(selection == wxID_NONE) return;
    if(selection == (firstItem + 6)) {
        wxString folder = ::wxDirSelector();
        if(folder.IsEmpty()) return;
        DoAddSearchPath(folder);

    } else if(options.count(selection)) {
        DoAddSearchPath(options.find(selection)->second);
    }
#endif
}

int FindInFilesDialog::ShowDialog()
{
    // Update the combobox
    m_findString->Clear();
    m_findString->Append(m_data.GetFindStringArr());
    DoSetFileMask();
    m_findString->SetValue(m_data.GetFindString());

    clEditor* editor = clMainFrame::Get()->GetMainBook()->GetActiveEditor();
    if(editor) {
        // if we have an open editor, and a selected text, make this text the search string
        wxString selText = editor->GetSelectedText();
        if(!selText.IsEmpty()) { m_findString->SetValue(selText); }
    }

    m_findString->SetSelection(-1, -1); // select all
    m_findString->CallAfter(&wxTextCtrl::SetFocus);
    return wxDialog::ShowModal();
}

void FindInFilesDialog::DoSaveSearchPaths()
{
    wxArrayString paths = m_listPaths->GetStrings();
    m_data.SetSearchPaths(paths);
}

void FindInFilesDialog::DoSaveOpenFiles()
{
    if(m_checkBoxSaveFilesBeforeSearching->IsChecked()) { clMainFrame::Get()->GetMainBook()->SaveAll(false, false); }
}

void FindInFilesDialog::OnFindWhatUI(wxUpdateUIEvent& event)
{
    event.Enable(!m_findString->GetValue().IsEmpty() && !m_listPaths->IsEmpty());
}

void FindInFilesDialog::OnUseDiffColourForCommentsUI(wxUpdateUIEvent& event)
{
    // event.Enable(m_checkBoxSkipMatchesFoundInComments->IsChecked() == false);
}

void FindInFilesDialog::OnFind(wxCommandEvent& event)
{
    wxUnusedVar(event);
    DoSearch();
}

void FindInFilesDialog::OnReplace(wxCommandEvent& event)
{
    wxUnusedVar(event);
    DoSearchReplace();
}

void FindInFilesDialog::OnStop(wxCommandEvent& event) { SearchThreadST::Get()->StopSearch(); }

void FindInFilesDialog::OnButtonClose(wxCommandEvent& event) { EndModal(wxID_CANCEL); }

size_t FindInFilesDialog::GetSearchFlags()
{
    size_t flags = 0;
    if(m_matchCase->IsChecked()) flags |= wxFRD_MATCHCASE;
    if(m_matchWholeWord->IsChecked()) flags |= wxFRD_MATCHWHOLEWORD;
    if(m_regualrExpression->IsChecked()) flags |= wxFRD_REGULAREXPRESSION;
    if(m_checkBoxSaveFilesBeforeSearching->IsChecked()) flags |= wxFRD_SAVE_BEFORE_SEARCH;
    if(m_checkBoxPipeForGrep->IsChecked()) flags |= wxFRD_ENABLE_PIPE_SUPPORT;
    return flags;
}

void FindInFilesDialog::SetSearchPaths(const wxArrayString& paths)
{
    m_listPaths->Clear();
    m_customPaths.clear();
    DoAddSearchPaths(paths);
}

void FindInFilesDialog::OnClearSelectedPath(wxCommandEvent& event)
{
    wxUnusedVar(event);
    DoDeletedSelectedPaths();
}

void FindInFilesDialog::OnClearSelectedPathUI(wxUpdateUIEvent& event)
{
    wxArrayInt selections;
    m_listPaths->GetSelections(selections);
    event.Enable(!selections.IsEmpty());
}

void FindInFilesDialog::DoAddSearchPath(const wxString& path)
{
    wxArrayString strings = m_listPaths->GetStrings();
    if(strings.Index(path) == wxNOT_FOUND) { m_listPaths->Append(path); }
}

void FindInFilesDialog::DoAddSearchPaths(const wxArrayString& paths)
{
    for(size_t i = 0; i < paths.size(); ++i) {
        DoAddSearchPath(paths.Item(i));
    }
}
void FindInFilesDialog::OnReplaceUI(wxUpdateUIEvent& event)
{
    event.Enable(!m_findString->GetValue().IsEmpty() && !m_listPaths->IsEmpty());
}

void FindInFilesDialog::OnLookInKeyDown(wxKeyEvent& event)
{
    event.Skip();
    if(event.GetKeyCode() == WXK_DELETE || event.GetKeyCode() == WXK_NUMPAD_DELETE) {
        // Delete the selected entry
        event.Skip(false);
        CallAfter(&FindInFilesDialog::DoDeletedSelectedPaths);
    }
}

void FindInFilesDialog::DoDeletedSelectedPaths()
{
    wxArrayInt selections;
    m_listPaths->GetSelections(selections);
    int selectionsCount = selections.GetCount();
    if(!selections.IsEmpty()) {
        for(int i = (selectionsCount - 1); i >= 0; --i) {
            m_listPaths->Delete(selections.Item(i));
        }
    }
}

void FindInFilesDialog::DoAddProjectFiles(const wxString& projectName, wxArrayString& files)
{
    if(!clCxxWorkspaceST::Get()->IsOpen()) { return; }
    ProjectPtr p = clCxxWorkspaceST::Get()->GetProject(projectName);
    if(p) {
        const Project::FilesMap_t& filesMap = p->GetFiles();
        if(!filesMap.empty()) {
            wxArrayString tmpArr;
            tmpArr.Alloc(filesMap.size());
            std::for_each(filesMap.begin(), filesMap.end(),
                          [&](const Project::FilesMap_t::value_type& vt) { tmpArr.Add(vt.second->GetFilename()); });
            files.insert(files.end(), tmpArr.begin(), tmpArr.end());
        }
    }
}
