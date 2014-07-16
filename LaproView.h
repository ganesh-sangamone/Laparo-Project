//LaproView.h : interface of the CLaproView class
//

#pragma once

#include "LaproDoc.h"

class CLaproView: public CView
{
protected: //create from serialization only
	CLaproView();
	DECLARE_DYNCREATE(CLaproView)

	//Attributes
	public CLaproDoc* GetDocument() const;

	//Operations
public:
	//Overrides
public:
	virtual void OnDraw(CDC* pDC); //overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	//Implementation
public:
	virtual ~CLaproView();
#ifdef_DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDUmpContext& dc) const;
#endif

	protected

		//generated message Map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG //debug version in laproView.cpp
inline CLaproDoc* CLaproView:: GetDocument() const
{ return reinterpret_cast<CLaproDoc*>(m_pDocument);}
#endif