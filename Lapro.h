//Lapro.h : main header file for the Lapro application
//

#pragma once

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH

#endif

#include "resource.h" //main symbols

//CLaproApp:
//See Lapro.cpp for the implementation if this class
//

class CLaproApp: public  CWinAPp
{
	public CLaproApp();

	//overrides
public:
	virtual BOOL InitInstance();

	//Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP();
	virtual BOOL OnIdle(LONG 1Count);
};

extern CLaproApp theApp;