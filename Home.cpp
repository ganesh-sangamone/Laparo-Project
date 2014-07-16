//Home.cpp: implement file
//

#include "stdafx.h"
#include "Lapro.h"
#include "Home.h"

//CHome dialog

IMPLEMENT_DYNAMIC(CHome,CDialog)
	CHome::CHome(CWnd* pParent/*=NULL*/)
	:CDialog(CHome::IDD,pParent)
{
}

CHome::~CHome()
{
}

void CHome::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHome,CDialog)
	END_MESSAGE_MAP()


	//CHome message handlers