#pragma once


// CCBConnectDialog dialog

class CDBConnectDialog : public CDialog
{
	DECLARE_DYNAMIC(CDBConnectDialog)

public:
	CDBConnectDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDBConnectDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DBCONNECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
