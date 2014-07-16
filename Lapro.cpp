//Lapro.cpp : Defines the class behaviours for the application.

#include "stdafx.h"
#include "Lapro.h"
#include "MainFrm.h"

#include"LaproDoc.h"
#include"LaproView.h"
#include "\.lapro.h"

#ifdef _DEBUG_NEW
#endif

//CLAproApp

BEGIN_MESSAGE_MAP(CLaproApp,CWinApp)
	ON_COMMAND(ID_APP_ABOUT,OnAppAbout)
	//Standard file based document commands)
	ON_COMMAND(ID_FILE_NEW,CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN,CWinApp::OnFileOpen)
	//Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP,CWinApp::OnFilePrintSetup)
	END_MESSAGE_MAP()

	//CLaproApp construction

	CLaproApp::CLaproApp()
	{
		//TODO: add construction code here,
		//Place all significant initialization in InitInstance
	}

	//The one and only CLaproApp object

	CLaproApp theApp;

	//CLaproApp initialization

	BOOL CLaproApp::InitInstance()
	{
		//InitCommonControls() is required on Windows XP if an application 
		//manifest specifies use of ComCt132.dll version 6 or later to enabled
		//visual styles. Otherwise, any window creation will fail.

		InitCommonControls();
		CWinApp::InitInstance();
		//Initialize OLE libraries
		if(!AfxOleInit())
		{
			AfxMessageBox(IDP_OLE_INIT_FAILED);
			return FALSE;
		}
		AfxEnableControlContainer();
		//Standard initialization
		pDocTemplate=new CSingleDocTemplate(
			IDR_MAINFRAME,
			RUNTIME_CLASS(CLaproDoc),
			RUNTIME_CLASS(CMain_Frame),
			RUNTIME_CLASS(CLaproView));
		AddDocTemplate(pDocTemplate);
		//Parse command line for standard shell commands, DDE,file open
		CCommandLineInfo cmdInfo;
		ParseCommandline(cmdInfo))
		//Dispatch commands specified on the command line. Will return FALSE.
		//app was launched with /RegServer, /Register, /Unregserver or // Piece of code missing

		return FALSE;
		m_pMainWnd -> ShowWindow(SW_SHOW)
			m_pMainWnd ->UpdateWindow();
		//call DragAcceptableFiles only if there's a suffix
		//In an SDI app, this should occur after ProcessShellCommand
		return TRUE;
	}

	//CAboutDlg dialog  sed for App About

	class CAbout:public CDialog
	{
	public:
		CAboutDlg();

		//Dialog Data
		enum { IDD=IDD_ABOUTBOX};
	protected:
		virtual void DODataExchange(CDataExchange* pDX);

		//Implementation
	protected:
		DECLARE_MESSAGE_MAP()
	};

	CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
	{
	}

	void CAbout::DoDataExchange(CDataExchange* pDX)
	{
		CDialog::DoDataExchange(pDX);
	}
	BEGIN_MESSAGE_MAP(CAbout,CDialog)
		END_MESSAGE_MAP()

		//App command to run the dialog
		void CLaproApp::OnAppAbout()
		{
			CAboutDlg aboutDlg;
			aboutDlg.DoModal();
		}
		pFrame ->endofEx();

		}
		return CWInApp::OnIdle(1Count);
		}

	