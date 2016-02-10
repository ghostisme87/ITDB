// CBConnectDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ITDBServer.h"
#include "DBConnectDialog.h"
#include "afxdialogex.h"

#include "Connector.h"


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
	DDX_Text(pDX, IDC_EPASSWORD, m_strPWD);
	DDV_MaxChars(pDX, m_strPWD, 50);
	DDX_Text(pDX, IDC_EUID, m_strUID);
	DDV_MaxChars(pDX, m_strUID, 50);
	DDX_Control(pDX, IDC_LSDSN, m_lbDSN);
	DDX_Control(pDX, IDC_CBDBNAME, m_cbDBName);
}


BEGIN_MESSAGE_MAP(CDBConnectDialog, CDialog)
	ON_CBN_DROPDOWN(IDC_CBDBNAME, &CDBConnectDialog::OnDropdownCbdbname)
END_MESSAGE_MAP()


// CCBConnectDialog message handlers


void CDBConnectDialog::OnDropdownCbdbname()
{
	// TODO: Add your control notification handler code here
	//m_cbDBName.foc
	m_cbDBName.ResetContent();
	UpdateData(TRUE);

	if (m_strDSN != L"" && m_strUID != L"" && m_strPWD != L"")
	{

		CString str = L"DSN=" + m_strDSN + L";UID=" + m_strUID + L";PWD=" + m_strPWD;
		CConnector con;
		if (con.Connect(str))
		{
			wchar_t **ans = nullptr;
			ans = con.Request(L"select * from sys.databases");
			for (int i = 0; i < 4; ++i)
			{
				m_cbDBName.AddString(ans[i]);
				//m_lbDSN.AddString(ans[i]);
			}
			for (int i = 0; i < 4; ++i)
			{
				delete[] ans[i];
			}
			delete[] ans;
		}
		m_cbDBName.SetCurSel(0);
	}
	/*CDatabase cdb;
	cdb.OpenEx(str, 0);
	
	CRecordset rc(&cdb);

	rc.Open(CRecordset::dynamic, L"select * from sys.databases", CRecordset::none);

	while (!rc.IsEOF())
	{
		CString s;
		rc.GetFieldValue(L"name", s);
		m_cbDBName.AddString(s);
		rc.MoveNext();
	}
	rc.Close();
	cdb.Close();*/

	
}


void CDBConnectDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	CITDBServerApp *pApp = dynamic_cast<CITDBServerApp*>(AfxGetApp());
	ASSERT_VALID(pApp);

	CString str;

	/*int i = m_cbDBName.GetCurSel();
	m_cbDBName.GetWindowTextW(str);

	pApp->WriteProfileStringW(L"Settings\\DB" + str, L"DSN", m_strDSN);
	pApp->WriteProfileStringW(L"Settings\\DB" + str, L"UID", m_strUID);
	pApp->WriteProfileStringW(L"Settings\\DB" + str, L"PWD", m_strPWD);
	pApp->WriteProfileStringW(L"Settings\\DB" + str, L"DBNAME", str);*/

	HKEY key;

	RegOpenKey(HKEY_CURRENT_USER, L"Software\\KVA\\Settings", &key);
	DWORD ccc = 0;
	DWORD val = 0;
	DWORD asd = 0;
	RegQueryInfoKey(key, NULL, NULL, NULL, &asd, NULL, NULL, &val, NULL, NULL, NULL, NULL);
	wchar_t aaa[255];
	for (DWORD i = 0; i < val; ++i)
	{
		RegEnumKey(key, i, aaa, ccc);
		AfxMessageBox(aaa);
	}
	RegCloseKey(key);
	
	//pApp->WriteProfileStringW(L"Settings/DB" + m_strDSN, L"DSN", m_strDSN);
	//CDialog::OnOK();
}
