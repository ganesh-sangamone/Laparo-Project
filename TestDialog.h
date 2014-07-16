#pragma once

//CTestDialog form View

class CTestDialog: public CFormView
{
	DECLARE_DYNCREATE(CTestDialog)

protected;
	CTestDialog();   //protected constructor used by dynamic creation
	virtual ~CTestDialog();

public:
	enum{IDD=IDD_DIALOG1};
#ifdef _DEBUG
	virtual void AsserValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected;
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};
