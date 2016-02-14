
// ITDBServer.h : main header file for the ITDBServer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CITDBServerApp:
// See ITDBServer.cpp for the implementation of this class
//

class CITDBServerApp : public CWinApp
{
public:
	CITDBServerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSettingsDbconnect();
};

extern CITDBServerApp theApp;
