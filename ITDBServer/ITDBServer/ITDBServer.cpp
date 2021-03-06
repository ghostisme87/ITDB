
// ITDBServer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "ITDBServer.h"
#include "MainFrm.h"

#include "ITDBServerDoc.h"
#include "ITDBServerView.h"

#include "DBConnectDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CITDBServerApp

BEGIN_MESSAGE_MAP(CITDBServerApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CITDBServerApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_SETTINGS_DBCONNECT, &CITDBServerApp::OnSettingsDbconnect)
END_MESSAGE_MAP()


// CITDBServerApp construction

CITDBServerApp::CITDBServerApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ITDBServer.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CITDBServerApp object

CITDBServerApp theApp;


// CITDBServerApp initialization

BOOL CITDBServerApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("KVA"));
	LoadStdProfileSettings(0);  // Load standard INI file options (including MRU)

	// Check for first run
	if (1 == (int)GetProfileInt(L"Settings", L"FirstRun", 1))
	{
		//AfxMessageBox(L"First run");

		CDBConnectDialog *pDlg = new CDBConnectDialog();
		pDlg->DoModal();
		
		delete pDlg;

		WriteProfileInt(L"Settings", L"FirstRun", 0);
	}

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CITDBServerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CITDBServerView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CITDBServerApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CITDBServerApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateEdsn(CCmdUI *pCmdUI);
	afx_msg void OnSettingsDbconnect();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_UPDATE_COMMAND_UI(IDC_EDSN, &CAboutDlg::OnUpdateEdsn)
	ON_COMMAND(ID_SETTINGS_DBCONNECT, &CAboutDlg::OnSettingsDbconnect)
END_MESSAGE_MAP()

// App command to run the dialog
void CITDBServerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CITDBServerApp message handlers





void CAboutDlg::OnUpdateEdsn(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


void CAboutDlg::OnSettingsDbconnect()
{
	// TODO: Add your command handler code here
	
}


void CITDBServerApp::OnSettingsDbconnect()
{
	// TODO: Add your command handler code here
	CDBConnectDialog *pDlg = new CDBConnectDialog();
	pDlg->DoModal();
	delete pDlg;
}
