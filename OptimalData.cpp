//OptimalData: Implementation of the COptimalData class

#include "stdafx..h"
#include "OptimalData.h"

IMPLEMENT_DYNAMIC(COptimalData, CRecordset)

	COptimalData::OptimalData(CDatabase* pdb)
	:CRecordset(pdb)
{
	m_sl=0;
	m_ExerciseNo=0;
	m_LevelNo=0;
	m_Duration=0.0;
	m_Distance=0.0;
	m_nFields=5;
	m_nDefaultType=dynaset;
}


//The connection string below may contain plain text passwords and/or
//other sensitive information. Please remove the #error after reviewing 
//the connection string for any security related issues.You may want to 
//store the password in some other form use a different user authentication
//:DBQ=E:\\Dev\\New Lapro\\Database\\NewLaproDB.mdb:DriverId=25;FIL=MS Acc

MaxBufferSize=2048;PageTimeout=5;UID=admin;
CString COptimalData::GetDefaultConnect()
{
	return _T("ODBC;DSN=LaproDB);
}
CString COptimalData::GetDefaultSQL()
{
	return _T("[Optimal]");
}

void COptimalData:: DoFIeldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//Macros such as RFX_Text() and RFX_Int()are dependent on the 
	//tyoe of the number variab, not the tyoe of the field in the database
	//ODBC will try to automatically convert the column value to the requested 

	RFX_Long(pFX, _T("[sl]"),m_sl);
	RFX_Long(pFX, _T("[ExerciseNo]"),m_ExerciseNo);
	RFX_Long(pFX, _T("[LevelNo]"),m_LevelNo);
	RFX_Single(pFX, _T("[Duration]"),m_Duration);
	RFX_Single(pFX, _T("[Distance]"),m_Distance);
}

//COptimalData diagnostics

#ifdef _DEBUG
void COptimalData::AssertValid() const
{
	CRecordset::Assertvalid();




	//Some code is missing
}

