//ExBase.cpp:implementation file
#include "stdafx.h"
#include "Lapro.h"
#include "ExBase.h"
#include "Perspective.h"
#include "cgwnd.h"  //computer graphics window ?
#include "gripper.h"
#include "cavity.h"
#include "Cloth.h"
#include "DeformObj1.h"
#include "DeformObj2.h"
#include ".\ExBase.h"d
#include "home.h"

//CGprogram CCGWnd:vertexProg;
//CGprogram CCGWnd:lightProg;
//CExBase

IMPLEMENT DYNCREATE(CExBase,CPerspective)

CExBase::CExBase()
:m_nNS(0)
,m_bEndOfEx(false)
,m_nEndCount(0)
{
	pStatus=&pFrame->m_wndStatusBar;
	db=NULL;
	m_wavSoundFile.Load("kuiiii.wav");
	QueryPerformanceFrequency(&timerFrequency);
	QueryPerformanceCounter(&startTime);
	QueryPerformanceCounter(&startFpsTime);	
	first=true;
}
CExBase::CExBase()
{
	if(db)
	{
		db=NULL;
		delete db; //if no records in DB, delete ?
	}
	if (pStatus)
	{
		pStatus=NULL;

		//few lines are missing here. see page 2.69
void CExBase::OnDraw(CDC* pDC)
{
	CPerspective::OnDraw(pDC);
	LARGE_INTEGER currentTime;

	epp.poll();
	leftTool.pollValues(epp.lval); //left tool value
	epp.pollRight();
	rightTool.pollValues(epp.rval); //right tool value
	Invalidate();

	if(m_bMakeSound || rightTool.footSwitchPressed)
	{
		m_wavSoundFile.Play(0);
//AfxMessageBox("sound Played");  
	}
	static int nFrames=0;
	static float fps =0.0;
	QueryPerformanceCounter(&currentTime);

	float m_fExTime;  //final Experiment Time
	{
		m_fExTime=pFrame->m_Dur;  //Duration?
	}else{
		m_fExTime=((float)(currentTime.QuadPart - startTime.QuadPart)/(float)(timerFrequency.QuadPart/1000))/1000.0;

		CString timeStr, rdiststr, ldiststr, nsstr;  //right, left..
		timeStr.Format("Time=%0.3f",m_fExTime);
		rdiststr.Format("Right Dist = %0.3f", rightTool.getDist();
		ldiststr.Format("Left Dist= %0.3f", leftTool.getDist());
		nsStr.Format("Negative Score =%d", m_nNS);

		pFrame->m_fDist=rightTool.getDist()+leftTool.getDist(); //final distance is right+left
		pFrame->m_fDur=m_fExTime;
		pFrame->m_nNS = m_nNS;

		pFrame->m_strDur=timeStr;
		pFrame->m_strDistLt= ldiststr;
		pFrame->m_strDistRt= rdiststr;
		pFrame->m_strNS= nsStr;

		pFrame->updateMetricDisplay(timeStr, rdisstr, ldisstr);
	}
			nFrames++;
			AfxMessageBox("in paint");

			if(nFrames>100)

				//some code missing//


				//Display the fps
				//sprintf(CoutBuffer, "%0.1f", fps);
				cOutBuffer.Format("LAPRO FPS=%0.1f",fps);
				((CMainFrame*)AfxGetMainWnd())->SetWindowText(cOutBuffer);
		// AfxMessageBox(cOutBuffer);
				nFrames=0;

				//Resets thee timer
				QueryPerformanceCounter(&startFpsTime);
}
	//pFrame->displayMsg(rightTool.m_strPollMsg);
		static float redu=0.01;
		if(rightTool.footSwitchPressed){
			if(redu==0.01)
				hookRadius=0.9;
			redu+=0.002;
			if(hookRadius<HOOK_MAX_RADIUS)
				hookRadius=+=redu;
		}else{
			hookRadius=HOOK_MIN_RADIUS;
			redu=0.01;
		}
}

//CExBase diagnostics
#ifdef _DEBUG
void CExBase::AssertValid() const
{
	CPerspective::AssertValid();
}
void CExBase::Dump(CDumpContext& dc) const
{
	CPerspective::Dump(dc);
}
#endif //_DEBUG

bool CExBase::InitOpenGL()
{
	return true;
}
void CExBase::loadModels(void)
{
}
void CExBase::RenderScene(void)
{
/* if(hookRadius>3.0) dfl->freezeObject(true);
 
 code missing

 */

}
void CExBase::openOrCloseJaw(void)
{
}
void CExBase::drawTraj(void)
{
}

		


	


