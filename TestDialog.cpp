//TestDialog.cpp: Implemnetation file


#include"stdafx.h"
#include"Lapro.h"
#include"TestDialog.h"


//CtestDialog

IMPLEMENT_DYNCREATE(CTestDIalog,CFormVIew)

CTestDialog::CTestDialog()
	: CFormVIew(CTestDialog::IDD)
{
}

CTestDialog::~CTestDialog()
{
}

void CTestDialog:: DoDataExchange(CDataExchange* pDX)
{
	CFormView:: DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDialog, CFormView)
	END_MESSAGE_MAP()

//CTestDialog diagnostics

#ifdef _DEBUG

void CTestDialog::AssertValid() const
{
	CFormView:: AssertValid();
}

void CTestDialog:: Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

#endif //_DEBUG

//CTestDialog message handlers

