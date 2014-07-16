//OptimalData.h:Declaration of the COptimalData

#pragma once

class COptimalData : public CRecordset
{
public:
	OptimalData(CDatabase* pDatabase= NULL);
	DECLARE_DYNAMIC(COptimalData)
//Field/Param Data
//The String typed below (if present) reflect the actual data type of the 
//database field - CStringA for ANSI datatype and CStringW for Unicode
//datatypes.This is to prevent the ODBC driver from performing potential
// unncessary conversation.If you wish, you may change these members to 
//CString types and the ODBC driver Will perform  all necessary conversion
//(Note: You must use an ODBC driver version that si version 3.5 or great
// to support both Unicode and these conversions).

	 long m_sl;  //dummy key field
	 long m_ExerciseNo;
	 long m_LevelNo;
	 float m_Duration;
	 float m_Distance;

//Overrides
	 //Wizard generated virtual function overired
public:
	virtual CString GetDefaultConnect();  ///Default connection string

	virtual CString GetDefaultSQL(); //Default SQL for Recordset
	virtual void DoFIeldExchange(CFiledExchange* pFX);  //RFX support

//implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};