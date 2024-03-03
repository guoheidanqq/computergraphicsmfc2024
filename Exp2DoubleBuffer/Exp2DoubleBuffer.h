
// Exp2DoubleBuffer.h : main header file for the Exp2DoubleBuffer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExp2DoubleBufferApp:
// See Exp2DoubleBuffer.cpp for the implementation of this class
//

class CExp2DoubleBufferApp : public CWinApp
{
public:
	CExp2DoubleBufferApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnTimer1s();
//	afx_msg void OnTimer2s();
//	afx_msg void OnTimer3s();
};

extern CExp2DoubleBufferApp theApp;
