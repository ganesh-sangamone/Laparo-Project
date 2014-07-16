//NewUserFormVIew.cpp

#include "stdafx.h"
#include " Lapro.h"
#include "NewUserFormView.h"
#include ".\newuserformview.h"

//CNewUserFOrmView

IMPLEMENT_DYNCREATE(CNewUserFormVIew,CFormVIew)

	CNewUserFormVIew::CNewUserFormView()
	:CFormView(CNewUserFormVIew::IDD),
	m_nNumberOfSurgeries(0),
	m_strEmail(_T("")),
	m_strLastName(_T("")),
	m_strFirstName(_T("")),
	m_nAge(0),
	m_strLoginID(_T("")),
	m_strDesignation(_T("")),
	m_strInstitute(_T("")),
	m_strAddress(_T("")),
	m_strCity(_T("")),
	m_strState(_T("")),
	m_strCountry(_T("")),
	m_nPostalCode(0);
	m_nPhoneNumber(0);
	{
	}

	CNewUserFormVIew::~CNewUserFormView()
	{
	}
	void CNewUserFormVIew::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LAST_NAME,m_ctrlLastName);
	DDX_Control(pDX, IDC_FIRST_NAME,m_ctrlFirstName);
	DDX_Control(pDX, IDC_AGE,m_ctrlAge);
	DDX_Control(pDX, IDC_LOGIN_ID,m_ctrlLogin);
	DDX_Control(pDX, IDC_DESIGNATION,m_ctrlDesignation);
	DDX_Control(pDX, IDC_INSTITUTE,m_ctrlInstitute);
	DDX_Control(pDX, IDC_ADDRESS,m_ctrlAddress)
	DDX_Control(pDX, IDC_CITY,m_ctrlCity);
	DDX_Control(pDX, IDC_STATE,m_ctrlState);
	DDX_Control(pDX, IDC_COUNTRY,m_ctrlCountry);
	DDX_Control(pDX, IDC_POSTAL_CODE,m_ctrlPostalCode);
	DDX_Control(pDX, IDC_NUMBER_OF_SURGERIES_BUT1,m_ctrlNumberOfSurgeries);
	DDX_Radio(pDX, IDC_NUMBER_OF_SURGERIES_BUT1,m_nNumberOfSurgeries);
	DDX_Text(pDX, IDC_EMAIL,m_strEmail);
	DDX_Text(pDX, IDC_LAST_NAME,m_strLastName);
	DDX_Text(pDX, IDC_First_NAME,m_strFirstName);
	DDX_Text(pDX, IDC_AGE,m_nAge);
	DDX_Text(pDX, IDC_LOGIN_ID,m_strLoginID);
	DDX_Text(pDX, IDC_DESIGNATION,m_strDesignation);

	//Code missing

	// ON_BN_CLICKED(IDC_NUMBER_OF_SURGERIES_BUT2,OnBNClickedNumberOfSUrgeries...//Code missing
		ON_BN_CLICKED(IDOK,OnBnClickedOk)
	// ON_BN_CLICKED(IDC_NUMBER_OF_SURGERIES_BUT1,OnBNClickedNumberOfSUrgeries...//Code missing
	END_MESSAGE_MAP()

	//CNewUserFormView diagnostics

#ifdef _DEBUG
	void CNewUserFormVIew:: AssertValid() const
	{
		CFormView::AssertValid();
	}
	void CNewUserFormVIew::Dump(CDumpContext& dc) const
	{
		CFormVIew::Dump(dc);
	}

#endif //_DEBUG
//CNewUserFormVIew message handlers

	void CNewUserFormVIew::OnBnClickedOk()
	{
		//TODO:Add your control notification handlers code here
		UpdateData(TRUE);
		if(m_strLoginID==_T(""))
		{
			AfxMessageBox("Please enter a Login ID);
				return;
		}
		bool bLoginIDExists=db.checkLoginID(m_strLoginID);
		if(bLoginIDExists)
		{
			AfxMessageBox("The LoginID Entered  exists");
			return;
		}
		db.setNewUserData(m-strLastName,m_First_name,m_nAge,m_strLoginID,\
			m_strDesignation,m_strInstitue,m_strAddress,m_strCity,m_strState,\
			m_strCountry,m_nPostalCode,m_nNumberOfSurgeries,m_nPhoneNumber,m_....//code missing

	}











