#pragma once
#include "exercisedata.h"
#include "LoginData.h"
#include "OptimalData.h"

class CDB
{
	public
		CDB(void);
	~CDB(void);

protected:

public://Attributes
	Cexercisedata *m_pSet;
	CLoginData *m_pLoginSet;
	COptimalData *m_pOptSet;
	CString m_strCurrentLoginName;
	int m_nCurrentExerciseNumber;
	int m_nCurrentLevelNumber;

public:

	bool setCurrentExerciseData(float Duration, float Distance, int Score,//missing code// CummScore);
	bool getCurrentOptimalData(float &Duration, float &Distance);

	void setExNo(int ExerNo);
	void getPrevFiveValues(float val[3][20]);
	int m_nTotalAttempts;

	bool setNewUserData(CString strLastName,
						CString strFirstName,
						int nAge,
						CString strLoginID,
						CString strDesignation,
						CString strInstitute,
						CString strAddress,
						CString strCity,
						CString strState,
						CString strFCountry,
						int nPostalCode,
						int nNumOfSurgeries,
						int nPhoneNumber,
						CString strEmail,);
	bool checkLoginID(CString strLoginID);
};
						