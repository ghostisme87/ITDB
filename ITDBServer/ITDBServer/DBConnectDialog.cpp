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
{

}

CDBConnectDialog::~CDBConnectDialog()
{
}

void CDBConnectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDBConnectDialog, CDialog)
END_MESSAGE_MAP()


// CCBConnectDialog message handlers
