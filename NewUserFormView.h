#pragma once
#include"afxwin.h"
#include"DB.h"

//CNewUSerFormVIew form view

class CNewUserFormVIew: public CFormView
{
	DECLARE_DYNCREATE(CNewUserFormVIew)

protected;
	CNewUserFormVIew();
	virtual ~CNewUserFormVIew();
public:
	enum(IDD=IDD_NEW_USER_FORM_VIEW);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	CDB db;
	CEdit m_ctrlLastName;
	CEdit m_ctrlFisrtName;
	CEdit m_ctrlAge;
	CEdit m_ctrlLoginID;
	CEdit m_ctrlDesignation;
	CEdit m_ctrlInstitute;
	CEdit m_ctrlAddress;
	CEdit m_ctrlCity;
	CEdit m_ctrlState;
	CEdit m_ctrlCountry;
	CEdit m_ctrlPostalCode;
	CButton m_ctrlNumberOfSurgeries;
	afc_msg void OnBnClickedOk();
	int m_nNumberOfSurgeries;
	CString m_strEmail;
	CString m_strLastName;
	CString m_strFirstName;
	int m_nAge;

	CString m_strLoginID;
	CString m_strDesignation;
	CString m_strInstitute;
	CString m_strAddress;
	CString m_strCity;

	CString m_strState;
	CString m_strCountry;
	int m_PostalCode;
	int m_nPhoneNumber;

	//Code missing
};