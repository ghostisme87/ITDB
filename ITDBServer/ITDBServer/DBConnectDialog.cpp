// CBConnectDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ITDBServer.h"
#include "DBConnectDialog.h"
#include "afxdialogex.h"


// CCBConnectDialog dialog

IMPLEMENT_DYNAMIC(CDBConnectDialog, CDialog)

CDBConnectDialog::CDBConnectDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DBCONNECT, pParent)
	, m_strDSN(_T(""))
{

}

CDBConnectDialog::~CDBConnectDialog()
{
}

void CDBConnectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBDBNAME, m_cbDSN);
	DDX_Text(pDX, IDC_EDSN, m_strDSN);
	DDV_MaxChars(pDX, m_strDSN, 50);

}


BEGIN_MESSAGE_MAP(CDBConnectDialog, CDialog)
END_MESSAGE_MAP()


// CCBConnectDialog message handlers
