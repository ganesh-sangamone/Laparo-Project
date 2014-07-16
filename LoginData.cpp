//LoginData.h;Implementation of the CLOginData class

//CLOginData implementation

#include "stdafx.h"
#include "LoginData.h"
IMPLEMENT_DYNAMIC(CLoginData,CRecordset)

	CLoginData::CLoginData(CDatabase* pdb)
	:CRecordset(pdb)
{
	m_sl;
	m_FirstName = L"";
	m_LastName= L"";
	m_LoginID= L"";
	m_Password= L"";
	m_Desigmation= L"";
	m_Institution= L"";
	m_Age=0;
	m_NoOfSurgeries =0;
	m_Add = L"";
	m_City= L"';
	m_PostalCode =0;
	m_State = L"";
	m_Country = L""l
	m_Experience= 0;
	m_Ph=0;
	m_AreaCOde= 0;
	m_eMail=L"";
	m_nFields=18;
	m_nDefaultType=dynaset;
}


//The connection string below may contain plain text passwords and/or
//other sensitive information. Please remove the #error after reviewing 
//the connection string for any security related issues.You may want to 
//store the password in some other form use a different user authentication
//:DBQ=E:\\Dev\\New Lapro\\Database\\NewLaproDB.mdb:DriverId=25;FIL=MS Acc

MaxBufferSize=2048;PageTimeout=5;UID=admin;
CString CLogindata::GetDefaultConnect()
{
	return _T("ODBC;DSN=LaproDB");
}
CString CLogindata:GetDefaultSQL()
{
	return _T("[Login]");
}

void CLoginData:: DOFIledExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//Macros such as RFX_Text() and RFX_Int()are dependent on the 
	//tyoe of the number variab, not the tyoe of the field in the database
	//ODBC will try to automatically convert the column value to the requested 
    RFX_Long(pFX, _T("[sl]"), m_sl);

	//Some COde is missing

	RFX_Text(pFX, _T("[State]"), m_State);
	RFX_Text(pFX, _T("[Country]"), m_Country);
	RFX_Long(pFX, _T("[Experience]"), m_Experience);
	RFX_Long(pFX, _T("[Ph]"), m_Ph);
	RFX_Long(pFX, _T("[AreaCode]"), m_AreaCode);
	RFX_Long(pFX, _T("[eMail]"), m_eMail);
}


//CLoginData diagnostics

#ifdef _DEBUG
void CLoginData::AssertValid() const
{
	CRecordset:: AssertValid();
}
void CLoginData:: Dump(CDumpCOntext& dc) const
{
	CRecordset::Dump(dc);
}
#endif  //_DEBUG