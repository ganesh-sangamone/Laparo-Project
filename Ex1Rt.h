#pragma once

#include "exbase.h"

//CEx1Rt view
class CEx1Rt : public CExBase
{
	DECLARE_DYNCREATE(CEx1Rt)

protected:
	CEx1Rt();        //protected constructor used by dynamic creation
	int first
    virtual ~CEx1Rt();
	virtual bool InitOpenGL();
	virtual void RenderScene(void);
	CToolBase *RLtool;

public:
	CEx1Rt(int tRL);
	int toolRL;


	virtual void OnDraw(CDC *pDC);       //overridden to draw this view
#ifdef_DEBUG
	virtual void AssertValid() const;
	virtual void DUMP(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	int drawSquare(int sqNUm, bool highlight);
	void loadSqProg(void);
	int tm,td;
	int seq_lev[65],selSq[65];


	int m_nHigh;
	int m_nPrev;
	bool m_bSqSelected;
	bool m_bMinusOne;
	bool m_bMinusTwo;
	int m_nSqCount;
	void renderEndOfEx(void);
	CGprogram sqProgs[64];
private:
	typedef struct {
		float ambient[3],diffuse[3],specular[3],exp;
	}BlinnProperties;
	void setBlinnProperties(CGparameter b,BlinnProperties &p);
	int rand_col();
	int rand_num(int mod);
};




