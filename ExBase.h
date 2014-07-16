#pragma once

#include "Perspective.h"
#include "MainFrm.h"
#include "DB.h"   //student database
#include "eppio.h"  //device driver
#include "WaveBox.h"
//CExBase view

class CExBase:public CPerspective
{
	DECLARE_DYNCREATE(CExBase)
protected:
	CExBase(); //protected constructor used by dynamic creation
	virtual ~CExBase();

	virtual bool InitOpenGL();
	virtual void loadModels(void);
	virtual void RenderScene(void);

	CStatusBar* pStatus;
	LARGE_INTEGER timerFrequency;
	LARGE_INTEGER startTime;
	LARGE_INTEGER startFpsTime;
	int nFrames;
	float m_fExTime;  //first Experiment ?
	bool first;
	CWaveBox m_wavSoundFile;

public;
	virtual void OnDraw(CDC* pDC);  //overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	CEppIO epp;
	void openOrCloseJaw(void);
	int m_nNS;  //Negative Score
	bool m_bEndOfEx;  //end of Experiment ?
	int m_nEndCount;
	CDB *db;
	void drawTraj(void); //draw Trajectory?
};
