//MainFrm.cpp: implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Lapro.h"
#include "LaproView.h"
#include "ControlPannel.h"
#include "MainFrm.h"

#include "LoginFormView.h"
#include ".\loginformview.h"
#include "NewUserFormView.h"
#include "EndOfExFormView.h"
#include "GraphFormView.h"
#include "TestDialog.h"

#include "Perspective.h"
#include "OpeningScene.h"
#include "ExBase.h"
#include "Ex1Rt.h"
#include "Ex2.h"
#include "Ex3.h"
#include "Ex4.h"
#include "Ex5.h"
#include "CuttingEx.h"
#include ".\mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

	BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
		ON_WM_CREATE()
		ON_WM_SIZE()
		END_MESSAGE_MAP()
		static UINT indicators[]=
		{
			ID_SEPARATOR,
			ID_INDICATOR_CAPS,
			ID_INDICATOR_NUM,
			ID_INDICATOR_SCRL,
		};

		//CMainFrame construction/destruction

		CMainFrame construction/destruction

			CMainFrame::CMainFrame()
			:m_bEndOfEx(false)
		{
			//TODO: add member initialization code here
			m_initSplitters=FALSE;
			m_strCurrentLoginName="sud";
			m_nCurrentExerciseNumber=2;
			
			return -1;
			/*
			if(!m_wndToolBar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLY | CBRS_SIZE_DYNAMIC)
			!m_wndToolBar.LoadToolBar(IDR_MINFRAME))
			{
				TRACE0("Failed to create toolbar\n");
				return -1;     //fail to create
			}

			*/
			if(!m_wndStatusBar.Create(this) ||
				!m_wndStatusBar.SetIndicators(indicators,sizeof(indicators)/sizeof(UINT)))
			{
				TRACE0("Failed to create status bar\n");
				return -1;   //fail to create
			}
			/* TODO: Delete these lines if you don't want the toolbar to b //Missing code


			m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
			EnableDocking(CBRS_ALIGN_ANY);
			DockContrlBar(&m_wndToolBar);
			*/
			return 0;
		}

		BOOL CMainFrame:: PreCreateWindow(CREATESTRUCT& cs)
		{
			if(!CFrameWnd::PreCreateWindow(cs))
				return FALSE;
			//TODO: Modify the Window class or styles here by modifying
			//the CREATESTRUCT cs

			return TRUE;
		}

		//CMainFrame diagnostics

#ifdef _DEBUG
		void CMainFrame::AssertValid() const
		{
			CFrameWnd::AssertValid();
		}

		void CMainFrame::Dump(CDumpContext& dc) const
		{
			CFrameWnd::Dump(dc);
		}
#endif //_DEBUG

		//CMainFrame message handlers

		BOOL CMAinFrame:: OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pCon //Missing code
		{
			CRect cr;  //client rectangle-
			//used to calculate client sizes
			CSize(INFOBAR_SIZE,cr.Height() ), pContext))
			{
				MessageBox("Error setting up splitter frames!", "Init Error!", MB_OK | MB_ICONERROR);

				return FALSE;
			}
			if(!m_mainSplitter.CreateView(0,0,RUNTIME_CLASS(COpeningScene),CSize(cr.Width() - INFOBAR_SIZE, cr.Height() ), pContext))
			{

				MessageBox("Error setting up splitter frames!", "Init Error!", MB_OK | MB_ICONERROR);

				return FALSE;
			}

			//SetUp a pointer to the viewport splitter to be
			//used later by the information bar to change
			//viewports.

			((CControlPannel*) (m_mainSplitter.GetPane(0,1))) ->m_exerViewPort=m_mainSplitter;
			((CControlPannel*) (m_mainSplitter.GetPane(0,1))) ->db= &db;
			((CLoginFormView*) (m_mainSplitter.GetPane(0,0))) ->m_exerViewPort=m_mainSplitter;

			/* if(!m_viewportSplitter.CreateStatic(&m_mainSplitter,2,2,WS_CHIL //code missing
			WS_VISIBLE,m_mainSplitter.IdFromRowCol(0,0)))
			{
				MessageBox("Error setting up splitter frames!","Init Error!", MB_OK | MB_ICONERROR);
				return FALSE;
			}

			//Top view port
			if(!m_viewportSplitter.CreateView(0,0,RUNTIME_CLASS(CPerspective),CSize((cr.Width() - INFOBAR_SIZE)/2, cr.Height()/2 ), pContext))
			{

				MessageBox("Error setting up splitter frames!", "Init Error!", MB_OK | MB_ICONERROR);

				return FALSE;
			}
			//Front view port

			if(!m_viewportSplitter.CreateView(0,1,RUNTIME_CLASS(CLaproView),CSize((cr.Width() - INFOBAR_SIZE)/2, cr.Height()/2 ), pContext))
			{

				MessageBox("Error setting up splitter frames!", "Init Error!", MB_OK | MB_ICONERROR);

				return FALSE;
			}

			//Side viewport

				if(!m_viewportSplitter.CreateView(1,0,RUNTIME_CLASS(CLaproView),CSize((cr.Width() - INFOBAR_SIZE)/2, cr.Height()/2 ), pContext))
			{

				MessageBox("Error setting up splitter frames!", "Init Error!", MB_OK | MB_ICONERROR);

				return FALSE;
			}

			//that occur before the splitters have been
			//created.

			m_initSplitters=TRUE;

			//We return TRUE rather than the parent method
			//as is suggested by the wizard. If the parent
			//method is called all our hard work is undone.

			return TRUE;

			//return CFrameWnd::OnCreateClient(lpcs, pContext);
			}

			void CMainFrame::OnSize(UINT nType, int cx, int cy);
			{
				CFrameWnd::OnSize( nType, cx,  cy)
				{
					CRect cr;   //client rectangle-
					//used to calculate client sizes

					//Don't adjust the splitters if the application
					//is mimimized or the splitters have not been
					//initialized.

					if(m_initSplitters && nType != SIZE_MINIMIZED)
					{
						//Adjust the row/column info to compensate for 
						//the new size

						m_mainSplitter.SetRowInfo(0,cy,0);
						m_mainSplitter.SetColumnInfo(0,cx-INFOBAR_SIZE,0);
						m_mainSplitter.SetColumnInfo(1, INFOBAR_SIZE,0);

						//get the client Rectangle for the viewports
						/* m_viewportSplitter.getClientRect(&cr);

						//Use the viewport client height rather than
						//the Onsize param cy to get an accurate look.

						m_mainSplitter.SetRowInfo(0, cr.Height()/2,0);
						m_mainSplitter.SetRowInfo(1, cr.Height()/2,0);
						m_mainSplitter.SetColumnInfo(0,(cx-INFOBAR_SIZE)/2,
						m_mainSplitter.SetColumnInfo(0,cx-INFOBAR_SIZE)/2,
						*/
			
			//Apply our changes to to the splitters
			m_mainSplitter.RecalcLayout();
			// m_viewportSplitter.RecalcLayout();
			}
			}

			void CMainFrame::endOfEx()
			{
				UpdateData(TRUE);

				//Delete the view in the appropriate
				//splitter pane and create a new one
				//based on the dropdown selection.

				db.setCurrentExerciseData(m_fDur, m_fDist, m_nNS, 0.0);
				/* CRuntimeClass *newViewClass;
				CRect cr;  //client rectangle
				((CEndOfExFormView*) (m_mainSplitter.GetPane(0,0)))->displayMsg(m_//missing code
				m_strDistLt, m_strDistRt, m_strNS);
				*/

				bool CMainFrame::displayMsg(CString msgString)
				{
					((CControlPannel*) (m_mainSplitter.GetPane(0,1)))->displayErrorMsg(msg //code missing
						return true;
				}
				void CMainFrame::changeExercise(int Exno)
				{
					UpdateData(TRUE);

					//Delete the view in the appropriate
				//splitter pane and create a new one
				//based on the dropdown selection.

					CRuntimeClass *newViewClass;
					CRect cr;            //client rectangle

					switch (Exno)
					{
					case 0:
						newViewClass=RUNTIME_CLASS(CEx1Rt);
						break;

					case 1:
						newViewClass=RUNTIME_CLASS(CEx1Rt);
						break;

					case 2:
						newViewClass=RUNTIME_CLASS(CEx2);
						break;

					case 3:
						newViewClass=RUNTIME_CLASS(CCuttingEx);
						break;
						
					case 4:
						newViewClass=RUNTIME_CLASS(CEx5);
						break;

					
					case 5:
						newViewClass=RUNTIME_CLASS(CEx4);
						break;
					}

					m_mainSplitter.GetClientRect(&cr);
					m_mainSplitter.DeleteView(0,0);
					
					m_mainSplitter.CreateView(0,0,newViewClass,CSize(cr.Width()-INFOBAR_SIZE,cr.Height()),NULL);

					//Recalculate the splitter window so the
					//changes are displayed.

					m_mainSplitter.RecalcLayout();
					if(Exno==0 || Exno ==1)
						//splitter pane and create a new one
						//based on the dropdown selection.

						CRuntimeClass *newViewClass;
					CRect cr;      // client rectangle

					newViewClass=RUNTIME_CLASS(CNewUserFormView);

					m_mainSplitter.GetClientRect(&cr);

					m_mainSplitter.DeleteView(0,0);
					
					m_mainSplitter.CreateView(0,0,newViewClass,CSize(cr.Width()-INFOBAR_SIZE,cr.Height()),NULL);
					//Recalculate the splitter window so the
					//changes are displayed.

					m_mainSplitter.RecalcLayout();
				}

				void CMainFrame::updateMetricDisply(CString timestr, CString rdiststr, 1diststr)
				{
					((CControlPannel*) (m_mainSplitter.GetPane(0,1)))->updateMetricDisp// code missing
						rdiststr, ldiststr, m_strNS);
				}