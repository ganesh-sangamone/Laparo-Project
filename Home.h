#pragma once

//CHome dialog

class CHome:public CDialog
{
	DECLARE_DYNAMIC(CHome)

public:
	CHome(CWnd* pParent=NULL); //standard constructor
	virtual ~CHome();

	//Dialog Data
	enum { IDD=IDD_HOME};
protected:
	virtual void DoDataExchange(CDataExchange* pDX); //DDX/DDV code missing
	DECLARE_MESSAGE_MAP()
};