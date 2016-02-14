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
	CButton m_bnOK;
	CButton m_bnTestConnect;
	afx_msg void OnClickedBntestconn();
	CButton m_chbAutoConnect;
	CEdit m_editDSN;
	CEdit m_editUID;
	afx_msg void OnChangeEdsn();
	afx_msg void OnUpdateEdsn();
	void IsEditEmpty();
	afx_msg void OnChangeEuid();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedCheckautoconn();
};

void PASCAL DDV_Empty(CDataExchange *pDX, CString str);