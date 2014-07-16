//MainFrm.h : interface of the CMainFrame class
//
#include "DB.h"

#pragma once

#define INFOBAR_SIZE 150     //constant for creating splitter windows

class CMainFrame : public CFrameWnd
{
protected: //create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

	//Attributes
public:
	BOOL m_initSplitters;        //Have the splitters been initialized?

	CString m_strCurrentLoginName;
	int m_nCurrentExerciseNumber;
	int m_nCurrentLevelNumber;

	CSplitterWnd m_mainSplitter, m_viewportSplitter;

	//operations
public:
	//overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	//Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public: //control bar embedded members
	CStatusBar m_wndStatusBar;
	CToolBar m_wndToolBar;

	//Generated message map functions

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs,CCreateContext* pCon// code missing

public:
	afx_msg void OnSize(UINT nType, int cx , int cy);

	void endOfEx(void);
	bool displayMsg(CString msgString);
	void changeExercise(int EXno);
	void  newUserFormView(void);
	void updateMetricDisplay(CString, CString, CString);
	bool m bEndOfEx;


