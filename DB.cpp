#include "StdAfx.h"
#include ".\db.h"

CDB::CDB(void)
	:m_nTotalAttempts(0)
{
	m_pSet=new Cexercisedata;
	m_pLoginSet=new CLoginData;
	m_pOptSet=new COptimalData;

	m_strCurrentLoginName="sud";
	m_nCurrentExerciseNumber=3;
	m_nCurrentLevelNumber=1;
}

CDB::CDB(void)
{
	if(m_pSet->IsOpen()) {
		m_pSet ->Close();
	}
	if(m_pLoginSet->IsOpen()) {
		m_pLoginSet ->Close();
	}
	if(m_pOptSet->IsOpen()) {
		m_pOptSet ->Close();
	}
}
bool CDB::setCurrentExerciseData(float Duration, float Distance, int Sco// code missing)
{
	if(m_pSet->IsOpen())
		m_pSet ->AddNew();
	
	m_pSet->m_Name=m_strCurrentLoginName;
	m_pSet->m_Exercise=m_nCurrentExerciseNumber;
	m_pSet->m_Level=m_nCurrentLevelNumber;
	m_pSet->m_Distance=Distance;
	m_pSet->m_Name=Duration;
	m_pSet->m_Name=Score;
	m_pSet->m_Name=CummScore;
	
	if(m_pSet->CanUpdate())
	{
		m_pSet->Update();
	}else{
		AfxMessageBox("DataBase ERROR: CANNOT UPDATE Exercise Table");
	}
	if(!m_pSet-> IsEOF())
	{
		m_pSet->MoveLast();
		//code missing
	}
	 bool CDB::getCurrentOptimalData(float &Duration, float &Distance)
	 {
		 CString dummystr;
		 if(m_nCurrentExerciseNumber==0)
			 return false;
		 if(m_pOptSet->IsOpen()) {
			 m_pOptSet->Close();
		 }

dummystr=m_strCurrentLoginName;
m_strCurrentLoginName="Guest";

m_pOptSet->Open();
if(m_pOptSet->IsBOF()) { //detects empty recordset

	AfxMessageBox("Optimal table empty");
}
m_pOptSet->MoveLast();   //fails if recordset is empty

int n=0;

while(!m_pOptSet->IsBOF() && n<1) {
	Duration=m_pOptSet-> m_Duration;
	Duration=m_pOptSet-> m_Distance;
	m_pOptSet-> MovePrev();
	n++;
}
if(m_pOptSet->IsOpen()) {
	m_pOptSet->Close();
}
m_strCurrentLoginName=dummystr;
return true;
	 }
	 void CDB::setExNo(int ExerNo)
		 {
			 m_nCurrentExerciseNumber=ExerNo;
	 }
	 void CDB::getprevFiveValues(float val[3][20])
	 {
		 if(m_pSet->IsBOF()) { // detects empty recordset

			 AfxMessageBox("table empty");
			 return;
		 }
		 m_pSet->MoveLast(); //fails if recordset is empty

		 int n=0;
		 while(!m_pSet->IdBOF(){
			 dtr.Format("%s%d%f%f",m_pSet->m_Name,m_pSet->m_Exercise,m_pSet->m_pSet->m_Duration,m_pSet->m_Distance);

			 if(n<20) {
				 val[0][n]=m_pSet->m_Duration;
				  val[1][n]=m_pSet->m_Distance;
				   val[2][n]=m_pSet->m_Score;
			 }

			 m_pSet->MovePrev();
			 n++;
		 }

		 m_nTotalAttempts=n;
		 str.Format("num attempts=%d",n);
		 if(m_pSet->IsOpen()) {
			 m_pSet->Close();
		 }
	 }

	 bool CDB::setnewUserData(CString strLastName,
		 CString strFirstName,
		 int nAge,
		 CString strLoginID,
		 CString strDesignation,
		 CString strInstitute,
		 CString strAddress,
		 CString strCity,
		 CString strState,
		 CString strCountry,
		 int nPostalCode,
		 int nNumOfSurgeries,
		 int nPhoneNumber,
		 CString strEmail)
	 {
		 if(m_pLoginSet->IsOpen())
			 m_pLoginSet->Close();
		 m_pLoginSet->Open();
		 m_pLoginSet->AddNew();
		  m_pLoginSet->m_Country=strCountry;
		 m_pLoginSet->m_PostalCode=nPostalCode;
		  m_pLoginSet->m_NoOfSurgeries=nNumOfSurgeries;
		 m_pLoginSet->m_Ph=nPhoneNumber;
		  m_pLoginSet->m_eMail=strEmail;


		if(m_pLoginSet->CanUpdate())
	{
		m_pLoginSet->Update();
	}else{
		AfxMessageBox("DataBase ERROR: CANNOT UPDATE New User Table");
	}
	if(!m_pLoginSet-> IsEOF())
	{
		m_pLoginSet->MoveLast();
		
	}
	m_pLoginSet->Requery(); //for sorted sets
	if(m_pLoginSet->IsOpen()) {
		m_pLoginSet->Close();
	}
	return false;
	 }

	 bool CDB::checkLoginID(CString strLoginID)
	 {
		 m_pLoginSet->m_strFilter.Format("LoginId='%s'",(LPCSTR) strLoginId);

		 //m_pSet->m_strFilter="";
		 if(m_pSet->IsOpen()){
			 m_pLoginSet->Close();
		 }

		 m_pLogin->Open();
		 if(m_pLoginSet->IsBOF()) { //detects empty recordset
			 //AfxMessageBOX("Login ID does not exist");
			 return false;
		 }
		 return true;
	 }
