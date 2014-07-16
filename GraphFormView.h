#pragma once
#include "chart.h"
#include "mainfram.h"
#include "afxwin.h"
//CGraphForView form view
class CGraphFormView:public CFormView
{
	DECLARE_DYNCREATE(CGraphFormView)
protected:
	CGraphFormView();  //protected constructor used by dynamic
	virtual ~CGraphFormView();
public:
	enum{IDD=IDD_GRAPH_FORM_VIEW);
#idef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); //DDX/DDV support
	DECLARE MESSAGE_MAP()
public:
	CMschart1 m_ctrlChart;
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CMainFrame *pFrame;
	CMschart1 m_ctrlChart2;
	CMschart1 m_ctrlChart3;
	CStatic m_ctrlNumOfAttempts;
	CString m_strNumOfAttempts;
};


