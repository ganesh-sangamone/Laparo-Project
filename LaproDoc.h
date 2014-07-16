//LaproDoc.h: interface of the CLaproDoc class
//


#pragma once

#include "3dsModel.h"
#include "Gripper.h"

class CLaproDoc: public CDocument
{
protected:// create from serialization only
	CLaproDoc();
	DECLARE_DYNCREATE(CLaproDoc)

	//Attributes

public:
	
	C3dsModel *m_currentModel;
	float m_fJawOpening;
	int m_nCurrentExerNo;
	//Operations

public:
	//Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

	//Implementation
public:
	virtual ~CLaproDoc();
#ifdef_DEBUG

	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};