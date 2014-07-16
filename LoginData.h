//LoginData.h : Declaration of the CLoginData

#pragma

class CLoginData: public CRecordset
{
public:
	CLoginData(CDatabase = NULL);
	DECLARE_DYNAMIC(CLoginData)

//Field/Param data
//The String typed below (if present) reflect the actual data type of the 
//database field - CStringA for ANSI datatype and CStringW for Unicode
//datatypes.This is to prevent the ODBC driver from performing potential
// unncessary conversation.If you wish, you may change these members to 
//CString types and the ODBC driver Will perform  all necessary conversion
//(Note: You must use an ODBC driver version that si version 3.5 or great
// to support both Unicode and these conversions).

	long m_sl;
	CStringW m_FirstName;
	CStringW m_LastName;
	CStringW m_LoginID;
	CStringW m_Password;
	CStringW m_Designation;
	CStringW m_Institution;
	long m_Age;
	long m_NoOfSurgeries;
	CStringW m_Add;
	CStringW m_CIty;
	long m_PostalCode;
	CStringW m_Sate;
	CStringW m_Country;
	long m_Experience;
	long m_Ph;
	long m_AreaCode;
	CStringW m_eMail;

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