#pragma once
#include "afxwin.h"


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
public:
//	CComboBox m_cbDSN;
	CString m_strDSN;
	CString m_strPWD;
	CString m_strUID;
	CListBox m_lbDSN;
	afx_msg void OnDropdownCbdbname();
	CComboBox m_cbDBName;
	//void addd(CString);
	virtual void OnOK();
};
