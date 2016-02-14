// CBConnectDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ITDBServer.h"
#include "DBConnectDialog.h"
#include "afxdialogex.h"

#include "Connector.h"
#include "FileRW.h"


// CCBConnectDialog dialog

IMPLEMENT_DYNAMIC(CDBConnectDialog, CDialog)

CDBConnectDialog::CDBConnectDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DBCONNECT, pParent)
	, m_strDSN(_T(""))
	, m_strPWD(_T(""))
	, m_strUID(_T(""))
{

}

CDBConnectDialog::~CDBConnectDialog()
{
}

void CDBConnectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CBDBNAME, m_cbDSN);
	DDX_Text(pDX, IDC_EDSN, m_strDSN);
	DDV_MaxChars(pDX, m_strDSN, 50);
	//DDV_Empty(pDX, m_strDSN);
	DDX_Text(pDX, IDC_EPASSWORD, m_strPWD);
	DDV_MaxChars(pDX, m_strPWD, 50);
	DDX_Text(pDX, IDC_EUID, m_strUID);
	DDV_MaxChars(pDX, m_strUID, 50);
	//DDV_Empty(pDX, m_strUID);

	DDX_Control(pDX, IDC_LSDSN, m_lbDSN);
	DDX_Control(pDX, IDC_CBDBNAME, m_cbDBName);
	DDX_Control(pDX, IDOK, m_bnOK);
	DDX_Control(pDX, IDC_BNTESTCONN, m_bnTestConnect);
	DDX_Control(pDX, IDC_CHECKAUTOCONN, m_chbAutoConnect);
	DDX_Control(pDX, IDC_EDSN, m_editDSN);
	DDX_Control(pDX, IDC_EUID, m_editUID);
}


BEGIN_MESSAGE_MAP(CDBConnectDialog, CDialog)
	ON_CBN_DROPDOWN(IDC_CBDBNAME, &CDBConnectDialog::OnDropdownCbdbname)
	ON_BN_CLICKED(IDC_BNTESTCONN, &CDBConnectDialog::OnClickedBntestconn)
	ON_EN_CHANGE(IDC_EDSN, &CDBConnectDialog::OnChangeEdsn)
	ON_EN_UPDATE(IDC_EDSN, &CDBConnectDialog::OnUpdateEdsn)
	ON_EN_CHANGE(IDC_EUID, &CDBConnectDialog::OnChangeEuid)
	ON_BN_CLICKED(IDC_CHECKAUTOCONN, &CDBConnectDialog::OnClickedCheckautoconn)
END_MESSAGE_MAP()


// CCBConnectDialog message handlers


void CDBConnectDialog::OnDropdownCbdbname()
{	
}

struct data
{
	CString DSN;
	CString UID;
	CString PWD;
};

void CDBConnectDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	CITDBServerApp *pApp = dynamic_cast<CITDBServerApp*>(AfxGetApp());
	ASSERT_VALID(pApp);

	m_lbDSN.ResetContent();

	UpdateData(TRUE);

	pApp->WriteProfileStringW(L"Settings\\DB", L"DSN", m_strDSN);
	pApp->WriteProfileStringW(L"Settings\\DB", L"UID", m_strUID);
	pApp->WriteProfileStringW(L"Settings\\DB", L"PWD", m_strPWD);
	pApp->WriteProfileInt(L"Settings\\DB", L"AutoConnect", m_chbAutoConnect.GetCheck() ? 1 : 0);

	m_lbDSN.AddString(m_strDSN);

	m_bnOK.EnableWindow(FALSE);
	m_bnTestConnect.EnableWindow(TRUE);
	//CDialog::OnOK();
}


//Testing connection to DB func
void CDBConnectDialog::OnClickedBntestconn()
{
	CConnector connect;
	CString strConnect = L"DSN=" + m_strDSN + L";UID=" + m_strUID + L";PWD=" + m_strPWD;
	if(connect.Connect(strConnect))
	{
		AfxMessageBox(L"Connection successful");
	}
	else
	{
		AfxMessageBox(L"Can't connect to DB");
	}
	m_bnTestConnect.EnableWindow(FALSE);
}

void PASCAL DDV_Empty(CDataExchange *pDX, CString str)
{
	if (pDX->m_bSaveAndValidate && str.IsEmpty())
	{
		AfxMessageBox(L"Can't be empty");
		pDX->Fail();
	}
}

void CDBConnectDialog::OnChangeEdsn()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	IsEditEmpty();
}


void CDBConnectDialog::OnUpdateEdsn()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.

	// TODO:  Add your control notification handler code here

	
}

void CDBConnectDialog::IsEditEmpty()
{
	UpdateData(TRUE);
	if (!m_strDSN.IsEmpty() && !m_strUID.IsEmpty())
	{
		m_bnOK.EnableWindow(TRUE);
	}
	else
	{
		m_bnOK.EnableWindow(FALSE);
	}
}


void CDBConnectDialog::OnChangeEuid()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	IsEditEmpty();
}


BOOL CDBConnectDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	CITDBServerApp *pApp = dynamic_cast<CITDBServerApp*>(AfxGetApp());
	ASSERT_VALID(pApp);
	
	m_strDSN = pApp->GetProfileString(L"Settings\\DB", L"DSN", L"");
	m_strUID = pApp->GetProfileString(L"Settings\\DB", L"UID", L"");
	m_strPWD = pApp->GetProfileString(L"Settings\\DB", L"PWD", L"");
	m_chbAutoConnect.SetCheck((BOOL)pApp->GetProfileIntW(L"Settings\\DB", L"AutoConnect", 0));

	UpdateData(FALSE);
	m_lbDSN.AddString(m_strDSN);
	if (!m_strDSN.IsEmpty() && !m_strUID.IsEmpty())
	{
		m_bnTestConnect.EnableWindow(TRUE);
	}

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CDBConnectDialog::OnClickedCheckautoconn()
{
	// TODO: Add your control notification handler code here
	IsEditEmpty();
}
