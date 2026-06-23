///-----------------------------------------------------------------
///
/// @file      zod_launcherFrm.cpp
/// @author    Mike
/// Created:   8/14/2010 6:01:04 PM
/// @section   DESCRIPTION
///            zod_launcherFrm class implementation
///
///------------------------------------------------------------------

#include "zod_launcherFrm.h"
#include "store_settings.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// zod_launcherFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(zod_launcherFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(zod_launcherFrm::OnClose)
	EVT_BUTTON(ID_WXBUTTON4,zod_launcherFrm::WxButton4Click)
	
	EVT_TEXT(ID_WXEDIT9,zod_launcherFrm::WxEdit9Updated)
	
	EVT_TEXT(ID_WXEDIT8,zod_launcherFrm::WxEdit8Updated)
	EVT_MENU(ID_MNU_QUIT_1005, zod_launcherFrm::Mnuquit1005Click)
	EVT_CHECKBOX(ID_WXCHECKBOX11,zod_launcherFrm::WxCheckBox11Click)
	EVT_CHECKBOX(ID_WXCHECKBOX10,zod_launcherFrm::WxCheckBox10Click)
	EVT_CHECKBOX(ID_WXCHECKBOX9,zod_launcherFrm::WxCheckBox9Click)
	EVT_CHECKBOX(ID_WXCHECKBOX8,zod_launcherFrm::WxCheckBox8Click)
	EVT_CHECKBOX(ID_WXCHECKBOX7,zod_launcherFrm::WxCheckBox7Click)
	EVT_CHECKBOX(ID_WXCHECKBOX6,zod_launcherFrm::WxCheckBox6Click)
	
	EVT_TEXT(ID_WXEDIT7,zod_launcherFrm::WxEdit7Updated)
	EVT_BUTTON(ID_WXBUTTON3,zod_launcherFrm::WxButton3Click)
	EVT_CHECKBOX(ID_WXCHECKBOX5,zod_launcherFrm::WxCheckBox5Click)
	EVT_CHECKBOX(ID_WXCHECKBOX4,zod_launcherFrm::WxCheckBox4Click)
	EVT_CHECKBOX(ID_WXCHECKBOX3,zod_launcherFrm::WxCheckBox3Click)
	
	EVT_TEXT(ID_WXEDIT5,zod_launcherFrm::WxEdit5Updated)
	
	EVT_TEXT(ID_WXEDIT4,zod_launcherFrm::WxEdit4Updated)
	EVT_CHOICE(ID_WXCHOICE1,zod_launcherFrm::WxChoice1Selected)
	
	EVT_TEXT(ID_WXEDIT3,zod_launcherFrm::WxEdit3Updated)
	
	EVT_TEXT(ID_WXEDIT2,zod_launcherFrm::WxEdit2Updated)
	EVT_CHECKBOX(ID_WXCHECKBOX2,zod_launcherFrm::WxCheckBox2Click)
	EVT_CHECKBOX(ID_WXCHECKBOX1,zod_launcherFrm::WxCheckBox1Click)
	
	EVT_TEXT(ID_WXEDIT1,zod_launcherFrm::WxEdit1Updated)
	EVT_BUTTON(ID_WXBUTTON2,zod_launcherFrm::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,zod_launcherFrm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

zod_launcherFrm::zod_launcherFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

zod_launcherFrm::~zod_launcherFrm()
{
}

void zod_launcherFrm::CreateGUIControls()
{
    form_loaded = false;

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Preset Settings
    wxStaticBoxSizer* presetSettingsSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "Preset Settings");
    WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Local Game"));
    presetSettingsSizer->Add(WxButton1, 0, wxALL, 5);
    WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("Nighsoft Server"));
    presetSettingsSizer->Add(WxButton2, 0, wxALL, 5);
    WxButton4 = new wxButton(this, ID_WXBUTTON4, wxT("Previous Settings"));
    presetSettingsSizer->Add(WxButton4, 0, wxALL, 5);
    mainSizer->Add(presetSettingsSizer, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* middleSizer = new wxBoxSizer(wxHORIZONTAL);

    // Connection Settings
    wxStaticBoxSizer* connectionSettingsSizer = new wxStaticBoxSizer(wxVERTICAL, this, "Connection Settings");
    wxFlexGridSizer* connectionGrid = new wxFlexGridSizer(3, 2, 5, 5);
    connectionGrid->AddGrowableCol(1, 1);
    connectionGrid->Add(new wxStaticText(this, wxID_ANY, "Connect Address::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, wxT(""));
    connectionGrid->Add(WxEdit1, 1, wxEXPAND);
    connectionGrid->Add(new wxStaticText(this, wxID_ANY, "Map Filename::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, wxT(""));
    connectionGrid->Add(WxEdit2, 1, wxEXPAND);
    connectionGrid->Add(new wxStaticText(this, wxID_ANY, "Settings Filename::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    WxEdit7 = new wxTextCtrl(this, ID_WXEDIT7, wxT(""));
    connectionGrid->Add(WxEdit7, 1, wxEXPAND);
    connectionSettingsSizer->Add(connectionGrid, 1, wxEXPAND | wxALL, 5);

    wxBoxSizer* dedicatedSizer = new wxBoxSizer(wxHORIZONTAL);
    WxCheckBox1 = new wxCheckBox(this, ID_WXCHECKBOX1, wxT("Is Dedicated"));
    dedicatedSizer->Add(WxCheckBox1, 0, wxALL, 5);
    WxCheckBox2 = new wxCheckBox(this, ID_WXCHECKBOX2, wxT("Filename is a Maplist"));
    dedicatedSizer->Add(WxCheckBox2, 0, wxALL, 5);
    connectionSettingsSizer->Add(dedicatedSizer, 0, wxEXPAND, 0);

    middleSizer->Add(connectionSettingsSizer, 1, wxEXPAND | wxALL, 5);

    // Engine Settings
    wxStaticBoxSizer* engineSettingsSizer = new wxStaticBoxSizer(wxVERTICAL, this, "Engine Settings");
    wxFlexGridSizer* engineGrid = new wxFlexGridSizer(5, 2, 5, 5);
    engineGrid->AddGrowableCol(1, 1);
    engineGrid->Add(new wxStaticText(this, wxID_ANY, "Player Name::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    WxEdit3 = new wxTextCtrl(this, ID_WXEDIT3, wxT(""));
    engineGrid->Add(WxEdit3, 1, wxEXPAND);
    engineGrid->Add(new wxStaticText(this, wxID_ANY, "Login Name::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    WxEdit8 = new wxTextCtrl(this, ID_WXEDIT8, wxT(""));
    engineGrid->Add(WxEdit8, 1, wxEXPAND);
    engineGrid->Add(new wxStaticText(this, wxID_ANY, "Login Password::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    WxEdit9 = new wxTextCtrl(this, ID_WXEDIT9, wxT(""));
    engineGrid->Add(WxEdit9, 1, wxEXPAND);
    engineGrid->Add(new wxStaticText(this, wxID_ANY, "Player Team::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    wxArrayString arrayStringFor_WxChoice1;
	arrayStringFor_WxChoice1.Add(wxT("null"));
	arrayStringFor_WxChoice1.Add(wxT("red"));
	arrayStringFor_WxChoice1.Add(wxT("blue"));
	arrayStringFor_WxChoice1.Add(wxT("green"));
	arrayStringFor_WxChoice1.Add(wxT("yellow"));
	WxChoice1 = new wxChoice(this, ID_WXCHOICE1, wxDefaultPosition, wxDefaultSize, arrayStringFor_WxChoice1);
    engineGrid->Add(WxChoice1, 1, wxEXPAND);
    engineGrid->Add(new wxStaticText(this, wxID_ANY, "Resolution::"), 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
    wxBoxSizer* resolutionSizer = new wxBoxSizer(wxHORIZONTAL);
    WxEdit4 = new wxTextCtrl(this, ID_WXEDIT4, wxT("800"));
    resolutionSizer->Add(WxEdit4, 1, wxEXPAND);
    resolutionSizer->Add(new wxStaticText(this, wxID_ANY, "x"), 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 5);
    WxEdit5 = new wxTextCtrl(this, ID_WXEDIT5, wxT("484"));
    resolutionSizer->Add(WxEdit5, 1, wxEXPAND);
    engineGrid->Add(resolutionSizer, 1, wxEXPAND);
    engineSettingsSizer->Add(engineGrid, 1, wxEXPAND | wxALL, 5);

    wxBoxSizer* engineCheckboxSizer = new wxBoxSizer(wxHORIZONTAL);
    WxCheckBox3 = new wxCheckBox(this, ID_WXCHECKBOX3, wxT("Is Windowed"));
    engineCheckboxSizer->Add(WxCheckBox3, 0, wxALL, 5);
    WxCheckBox7 = new wxCheckBox(this, ID_WXCHECKBOX7, wxT("No Music"));
    engineCheckboxSizer->Add(WxCheckBox7, 0, wxALL, 5);
    WxCheckBox4 = new wxCheckBox(this, ID_WXCHECKBOX4, wxT("No Sound"));
    engineCheckboxSizer->Add(WxCheckBox4, 0, wxALL, 5);
    engineSettingsSizer->Add(engineCheckboxSizer, 0, wxEXPAND, 0);

    wxBoxSizer* engineCheckboxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    WxCheckBox6 = new wxCheckBox(this, ID_WXCHECKBOX6, wxT("No OpenGL"));
    engineCheckboxSizer2->Add(WxCheckBox6, 0, wxALL, 5);
    WxCheckBox5 = new wxCheckBox(this, ID_WXCHECKBOX5, wxT("Bland Cursor"));
    engineCheckboxSizer2->Add(WxCheckBox5, 0, wxALL, 5);
    engineSettingsSizer->Add(engineCheckboxSizer2, 0, wxEXPAND, 0);

    middleSizer->Add(engineSettingsSizer, 1, wxEXPAND | wxALL, 5);
    mainSizer->Add(middleSizer, 0, wxEXPAND, 0);

    // AI Players
    wxStaticBoxSizer* aiPlayersSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "AI Players");
    WxCheckBox8 = new wxCheckBox(this, ID_WXCHECKBOX8, wxT("red"));
    aiPlayersSizer->Add(WxCheckBox8, 0, wxALL, 5);
    WxCheckBox9 = new wxCheckBox(this, ID_WXCHECKBOX9, wxT("blue"));
    aiPlayersSizer->Add(WxCheckBox9, 0, wxALL, 5);
    WxCheckBox10 = new wxCheckBox(this, ID_WXCHECKBOX10, wxT("green"));
    aiPlayersSizer->Add(WxCheckBox10, 0, wxALL, 5);
    WxCheckBox11 = new wxCheckBox(this, ID_WXCHECKBOX11, wxT("yellow"));
    aiPlayersSizer->Add(WxCheckBox11, 0, wxALL, 5);
    mainSizer->Add(aiPlayersSizer, 0, wxEXPAND | wxALL, 5);

    // Launch Game
    wxStaticBoxSizer* launchGameSizer = new wxStaticBoxSizer(wxVERTICAL, this, "Launch Game");
    launchGameSizer->Add(new wxStaticText(this, wxID_ANY, "--- Command Arguments ---"), 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);
    WxEdit6 = new wxTextCtrl(this, ID_WXEDIT6, wxT(""));
    launchGameSizer->Add(WxEdit6, 0, wxEXPAND | wxALL, 5);
    WxButton3 = new wxButton(this, ID_WXBUTTON3, wxT("Launch Zod Engine"));
    launchGameSizer->Add(WxButton3, 0, wxALIGN_CENTER | wxALL, 5);
    mainSizer->Add(launchGameSizer, 0, wxEXPAND | wxALL, 5);

    SetSizerAndFit(mainSizer);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILE_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_FILE_1001_Mnu_Obj->Append(ID_MNU_QUIT_1005, wxT("Quit"), wxT(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILE_1001_Mnu_Obj, wxT("File"));

	wxMenu *ID_MNU_ABOUT_1003_Mnu_Obj = new wxMenu(0);
	ID_MNU_ABOUT_1003_Mnu_Obj->Append(ID_MNU_ABOUT_1004, wxT("About"), wxT(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_ABOUT_1003_Mnu_Obj, wxT("About"));
	SetMenuBar(WxMenuBar1);

    form_loaded = true;
}

void zod_launcherFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Mnuquit1005Click
 */
void zod_launcherFrm::Mnuquit1005Click(wxCommandEvent& event)
{
	// insert your code here
	Destroy();
}

void zod_launcherFrm::ResetCommandLine()
{
    wxString message;
    
    if(!form_loaded) return;
    
#ifdef _WIN32
    message = wxT("zod_engine.exe");
#else
    message = wxT("./zod_engine/zod");
#endif
    
    if(WxEdit1->GetValue().length())
    {
        message += wxT(" -c ") + WxEdit1->GetValue();
    }
    else
    {
        if(WxCheckBox1->GetValue())
            message += wxT(" -d");
            
        if(WxEdit2->GetValue().length())
        {
            if(WxCheckBox2->GetValue())
                message += wxT(" -l ") + WxEdit2->GetValue();
            else
                message += wxT(" -m ") + WxEdit2->GetValue();
        }
        else
            message += wxT(" -m filename_needed");
            
        if(WxEdit7->GetValue().length())
            message += wxT(" -z ") + WxEdit7->GetValue();
        
    }
    
    if(WxEdit3->GetValue().length())
    {
    	wxString check = WxEdit3->GetValue();
    	
        for(unsigned int i=0;i<check.size();i++)
    	if(check.c_str()[i] == ' ')
        	check.replace(i,1,wxT("_"));
        	
        message += wxT(" -n ") + check;
    }
    else
        message += wxT(" -n zlover");
        
    if(WxEdit8->GetValue().length()) message += wxT(" -g ") + WxEdit8->GetValue();
    if(WxEdit9->GetValue().length()) message += wxT(" -i ") + WxEdit9->GetValue();
        
    message +=wxT( " -t ") + WxChoice1->GetStringSelection();
    
    message += wxT(" -r ") + WxEdit4->GetValue() + wxT("x") + WxEdit5->GetValue();
    
    if(WxCheckBox3->GetValue()) message += wxT(" -w");
    if(WxCheckBox4->GetValue()) message += wxT(" -s");
    if(WxCheckBox5->GetValue()) message += wxT(" -k");
    if(WxCheckBox6->GetValue()) message += wxT(" -o");
    if(WxCheckBox7->GetValue()) message += wxT(" -u");
    
    if(WxCheckBox8->GetValue()) message += wxT(" -b red");
    if(WxCheckBox9->GetValue()) message += wxT(" -b blue");
    if(WxCheckBox10->GetValue()) message += wxT(" -b green");
    if(WxCheckBox11->GetValue()) message += wxT(" -b yellow");
    
    WxEdit6->SetValue(message);
}

/*
 * WxButton1Click
 */
void zod_launcherFrm::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
	WxEdit1->SetValue(wxT(""));
	WxCheckBox1->SetValue(false);
	WxCheckBox2->SetValue(true);
	WxEdit2->SetValue(wxT("map_list.cfg"));
	
	//set default bot setup
	WxCheckBox8->SetValue(false);
	WxCheckBox9->SetValue(true);
	WxCheckBox10->SetValue(false);
	WxCheckBox11->SetValue(false);
	
	ResetCommandLine();
}

/*
 * WxButton2Click
 */
void zod_launcherFrm::WxButton2Click(wxCommandEvent& event)
{
	// insert your code here
	WxEdit1->SetValue(wxT("hestia.nighsoft.net"));
	WxCheckBox1->SetValue(false);
	WxCheckBox2->SetValue(false);
	WxEdit2->SetValue(wxT(""));
	
	//set default bot setup
	WxCheckBox8->SetValue(false);
	WxCheckBox9->SetValue(false);
	WxCheckBox10->SetValue(false);
	WxCheckBox11->SetValue(false);
	
	ResetCommandLine();
}

/*
 * WxEdit1Updated
 */
void zod_launcherFrm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox1Click
 */
void zod_launcherFrm::WxCheckBox1Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox2Click
 */
void zod_launcherFrm::WxCheckBox2Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxEdit2Updated
 */
void zod_launcherFrm::WxEdit2Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxEdit3Updated
 */
void zod_launcherFrm::WxEdit3Updated(wxCommandEvent& event)
{
    //take the spaces out
	
	// insert your code here
	ResetCommandLine();	
}

/*
 * WxChoice1Selected
 */
void zod_launcherFrm::WxChoice1Selected(wxCommandEvent& event )
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxEdit4Updated
 */
void zod_launcherFrm::WxEdit4Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxEdit5Updated
 */
void zod_launcherFrm::WxEdit5Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox3Click
 */
void zod_launcherFrm::WxCheckBox3Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox4Click
 */
void zod_launcherFrm::WxCheckBox4Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox5Click
 */
void zod_launcherFrm::WxCheckBox5Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxButton3Click
 */
void zod_launcherFrm::WxButton3Click(wxCommandEvent& event)
{
	// insert your code here
#ifdef _WIN32
	system(wxString(wxT("start ") + WxEdit6->GetValue()).mbc_str());
#else
	system(wxString(wxT("cd .. && ") + WxEdit6->GetValue() + wxT(" &")).mbc_str());
#endif
	
	//save settings
	g_settings.connect_address = WxEdit1->GetValue().mbc_str();
	g_settings.map_name = WxEdit2->GetValue().mbc_str();
	g_settings.player_name = WxEdit3->GetValue().mbc_str();
	g_settings.resolution_w = WxEdit4->GetValue().mbc_str();
	g_settings.resolution_h = WxEdit5->GetValue().mbc_str();
	g_settings.settings_filename = WxEdit7->GetValue().mbc_str();
	g_settings.login_name = WxEdit8->GetValue().mbc_str();
	g_settings.login_password = WxEdit9->GetValue().mbc_str();
	
	g_settings.team = WxChoice1->GetStringSelection().mbc_str();
	
    g_settings.is_dedicated = WxCheckBox1->GetValue();
    g_settings.f_isa_m = WxCheckBox2->GetValue();
    g_settings.red = WxCheckBox8->GetValue();
    g_settings.blue = WxCheckBox9->GetValue();
    g_settings.green = WxCheckBox10->GetValue();
    g_settings.yellow = WxCheckBox11->GetValue();
    g_settings.windowed = WxCheckBox3->GetValue();
    g_settings.no_music = WxCheckBox7->GetValue();
    g_settings.no_sound = WxCheckBox4->GetValue();
    g_settings.no_opengl = WxCheckBox6->GetValue();
    g_settings.bland_cursor = WxCheckBox5->GetValue();
	
	StoreSettings();
}

/*
 * WxEdit7Updated
 */
void zod_launcherFrm::WxEdit7Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox6Click
 */
void zod_launcherFrm::WxCheckBox6Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox7Click
 */
void zod_launcherFrm::WxCheckBox7Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox8Click
 */
void zod_launcherFrm::WxCheckBox8Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox9Click
 */
void zod_launcherFrm::WxCheckBox9Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox10Click
 */
void zod_launcherFrm::WxCheckBox10Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxCheckBox11Click
 */
void zod_launcherFrm::WxCheckBox11Click(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxEdit8Updated
 */
void zod_launcherFrm::WxEdit8Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxEdit9Updated
 */
void zod_launcherFrm::WxEdit9Updated(wxCommandEvent& event)
{
	// insert your code here
	ResetCommandLine();
}

/*
 * WxButton4Click
 */
void zod_launcherFrm::WxButton4Click(wxCommandEvent& event)
{
	// insert your code here
	LoadSettings();
	
	WxEdit1->SetValue(wxString::FromAscii(g_settings.connect_address.c_str()));
	WxEdit2->SetValue(wxString::FromAscii(g_settings.map_name.c_str()));
	WxEdit3->SetValue(wxString::FromAscii(g_settings.player_name.c_str()));
	WxEdit4->SetValue(wxString::FromAscii(g_settings.resolution_w.c_str()));
	WxEdit5->SetValue(wxString::FromAscii(g_settings.resolution_h.c_str()));
	WxEdit7->SetValue(wxString::FromAscii(g_settings.settings_filename.c_str()));
	WxEdit8->SetValue(wxString::FromAscii(g_settings.login_name.c_str()));
	WxEdit9->SetValue(wxString::FromAscii(g_settings.login_password.c_str()));
	
	WxCheckBox1->SetValue(g_settings.is_dedicated);
	WxCheckBox2->SetValue(g_settings.f_isa_m);
	WxCheckBox3->SetValue(g_settings.windowed);
	WxCheckBox4->SetValue(g_settings.no_sound);
	WxCheckBox5->SetValue(g_settings.bland_cursor);
	WxCheckBox6->SetValue(g_settings.no_opengl);
	WxCheckBox7->SetValue(g_settings.no_music);
	WxCheckBox8->SetValue(g_settings.red);
	WxCheckBox9->SetValue(g_settings.blue);
	WxCheckBox10->SetValue(g_settings.green);
	WxCheckBox11->SetValue(g_settings.yellow);
	
	if(g_settings.team == "null") WxChoice1->SetSelection(0);
	else if(g_settings.team == "red") WxChoice1->SetSelection(1);
	else if(g_settings.team == "blue") WxChoice1->SetSelection(2);
	else if(g_settings.team == "green") WxChoice1->SetSelection(3);
	else if(g_settings.team == "yellow") WxChoice1->SetSelection(4);
	
	ResetCommandLine();
}
