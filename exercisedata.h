//exercisedata.h : Declaration of the Cexercisedata

#pragma once

class Cexercisedata: piblic CRecordset
{
public:
	Cexercisedata(CDataBase* pDatabase=NULL);
	DECLARE_DYNAMIC(Cexercisedata)

	//
	//Field/Param data
	//The String typed below (if present) reflect the actual data type of the 
	//database field - CStringA for ANSI datatype and CStringW for Unicode
	//datatypes.This is to prevent the ODBC driver from performing potential
	// unncessary conversation.If you wish, you may change these members to 
	//CString types and the ODBC driver Will perform  all necessary conversion
	//(Note: You must use an ODBC driver version that si version 3.5 or great
	// to support both Unicode and these conversions).

	long m_ID;
	CStringW m_Name;
	long m_Level;
	long m_Exercise;
	float m-Duration;
	float m_Distance;
	CTime m_Date;
	CTime m_Time;
	int m_Score;
	float m_CummScore;
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