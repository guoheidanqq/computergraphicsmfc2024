
// ComputerGraphicsMFC2024.h : main header file for the ComputerGraphicsMFC2024 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CComputerGraphicsMFC2024App:
// See ComputerGraphicsMFC2024.cpp for the implementation of this class
//

class CComputerGraphicsMFC2024App : public CWinApp
{
public:
	CComputerGraphicsMFC2024App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CComputerGraphicsMFC2024App theApp;
