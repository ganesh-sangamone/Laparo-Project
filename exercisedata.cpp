//exercisedata.h : Implementation of the Cexercisedata class
//Cexercisedata implementation

#include "stdafx.h"
#include "exercisedata.h"

IMPLEMENTATION_DYNAMIC(Cexercisedata,CRecordset)

	Cexercisedata::Cexercisedata(CDatabase* pdb)
	:CRecordset(pdb)
{
	m_ID=0;
	m_Name=L"";
	m_Exercise = 0;
	m_Duration=0.0;
	m_Distance=0.0;
	m_Date;
	m_Time;
	m_Score=0;
	m_Customer=0.0;
	m_nFields=10;
	m_nDefaultType=dynaset;
}

//The connection string below may contain plain text passwords and/or
//other sensitive information. Please remove the #error after reviewing 
//the connection string for any security related issues.You may want to 
//store the password in some other form use a different user authentication
//:DBQ=E:\\Dev\\New Lapro\\Database\\NewLaproDB.mdb:DriverId=25;FIL=MS Acc

MaxBufferSize=2048;PageTimeout=5;UID=admin;
CString Cerxercisedata::GetDefaultConnect()
{
	return _T("ODBC;DSN=LaproDB");
}
CString Cexercisedata:GetDefaultSQL()
{
	return _T("[exercise data]");
}
void Cexercisedatat::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//Macros such as RFX_Text() and RFX_Int()are dependent on the 
	//tyoe of the number variab, not the tyoe of the field in the database
	//ODBC will try to automatically convert the column value to the requested 

	RFX_Long(pFX, _T("[ID]",m_ID);
	RFX_Text(pFX, _T("[Name]"),m_Name);
	RFX_Long(pFX, _T("[Exercise]"),m_Exercise);
	RFX_Long(pFX, _T("[Level]"),m_Level);
	RFX_Single(pFX, _T("[Duration]"),m_Duration);
	RFX_Single(pFX, _T("[Distance]"),m_Distance);
	RFX_Date(pFX, _T("[Date]"),m_Date);
	RFX_Date(pFX, _T("[Time]"),m_Time);
	RFX_Int(pFX, _T("[Score]"),m_Score);

	///Some code missing

	void Cexercisedata::Dump(CDumpContext& dc) const
	{
		CRecordset::Dump(dc);
	}

#endif//   _DEBUG