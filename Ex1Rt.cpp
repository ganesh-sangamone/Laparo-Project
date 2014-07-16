//Ex1Rt.cpp:implementation file
//

#include "stdafx.h"
#include "Lapro.h"
#include "Ex1Rt.h"
#include ".\ex1Rt.h"
#include <math.h>
#include "cgwnd.h"

//CEx1Rt
#define LIMIT 65

IMPLIMENT_DYNCREATE(CEx1Rt,CExBase)

	CEx1Rt::CEx1Rt()
	:m_nHigh(0)
	,m_nPrev(0)
	,m_bSqSelected(false)
	,m_bMinusOne(false)
	,m_bMinusTwo(false)
	,m_nSqCount(0)
{
	// toolRL = 0;
	RLtool = NULL
		first = 1;
	int seql_levl1[]={
		34,56,45,40,64,
		42,51,2,24,55,28,12,4,6,18,
		38,10,54,48,58,16,52,41,50,17,
		9,35,30,49,8,60,46,19,26,
		22,5,44,25,13,15,43,53,37,36,
		1,14,33,59,31,47,27,21,23,20,
		3,11,7,63,61,29,32,57,39,62,0
	};

memcpy(seq_levl, seq_levl, sizeof seql_levl);

}

	CEx1Rt::CEx1Rt(int tRL)
	{
		toolRL=tRL;
		RLtool=NULL;
		int seql_lev[]={
			8,56,45,40,64,
			42,51,2,24,55,28,12,4,6,18,
			38,10,54,48,58,16,52,41,50,17,
			9,35,30,49,34,60,46,19,26,
			22,5,44,25,13,15,43,53,37,36,
			1,14,33,59,31,47,27,21,23,20,
			3,11,7,63,61,29,32,57,39,62,0
		};
		memcpy(seq_levl,seql_levl,sizeof seql_levl);
	}
	CEx1Rt::~CEx1Rt()
	{
		if(RLtool()
		{
			//piece of code missing

			void CEx1Rt::OnDraw(CDC* pDC)
			{
				CDocument*pDoc=GetDocument();
				//TODO: add draw code here

				CExBase::OnDraw(pDc);

				if(m_bEndOfEx)
				{
					glClearColor(0.0f,1.0f,1.0f,0.0f);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
					renderEndOfEx();
					SwapGLBuffers();

					Invalidate(true);
				}else{

					if(m_bMinusOne || bMinusTwo)
					{
						if(m_bMinusOne)
							glClearColor(0.0f,1.0f,1.0f,0.0f);

						if(m_bMinusTwo)
							glClearColor(1.0f,0.0f,1.0f,0.0f);
					}else{
						glClearColor((1.0f,0.0f,0.0f,0.0f);
					}
					/*
					if(m_bMinusTwo)
							glClearColor(1.0f,0.0f,1.0f,0.0f);

						else
							glClearColor(0.0f,0.0f,0.0f,0.0f);
							*/
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

					RenderScene();
					SwapGLBufffers();

					if(m_nSqlCount ==64)
					{
						m_nEndCount++;
						if(m_nEndCount==100) {
							m_bEndOfEx=true;
							pFrame->db.setCurrentExerciseData(pFrame->m_fDur,pFrame->//piece of code missing
							pFrame->m_nNS,0.0);
						}else{

						
								if(m_nEndCount>1000){
									m_nEndCount=110;
								}
						}else{
							Invalidate();
						}
						}
						delete pDoc;



						void CEx1Rt::DUMP(CDumpContext& dc) const
						{
							CView:: Dump(dc);
						}
#endif //_DEBUG

							//CEx1Rt message handlers

							bool CEx1Rt::InitOpenGL()
							{
								if(! COpenGLWnd::InitOpenGL())
									return false;
								glClearCOlor(0.0f,1.0f,0.0f,0.0f);
								CCGWnd::initCG();

								//RLtool->loadTool(NEEDLE_EX1);
								//RLtool->setPivotPos(0.0,-15.0,75.0);

								m_nHigh=seq_levl[0];
								loadsSqProg();


								return true;
							}
							void CEx1Rt::RenderScene(void)
							{
								if(first==1)
								{
									/////////////////////////////////////////////////////////////////////////////////////////////////////

									/////////////////////////////////Foot Switch Homing

									////////////////////////////////////////////////////////////////////////////////////////////////////

									CString strnum1;
									epp.poll();
									rightTool.pollValues(epp.rval);
									bool press=rightTool.footSwitchPressed;


									strnum1.Format("Home the Tools and Press Foot Switch");
									pStatus->SetPaneText(0,strnum1);

									while (press == rightTool.footSwitchPressed)
									{
										first=0;
										if(toolRL==0)
										{
											rightTool.loadTool(NEEDLE_EX1);
											rightTool.setPivotPos(10.0,-15.0,75.0);
											RLtool = &rightTool;

											// AfxMessageBox("rightTool");
										}else{
											leftTool.loadTool(Needle_EX1);
											leftTool.setPivotPos(-10.0,-15.0,75.0);
											RLtool = &leftTool;
											AfxMessageBox("leftTool");
										}
									}int i=1;
									int calcSqNo=0;


////////////////////////////////////////////////////////////////////////////////////////////////////////// PLAY
									if(m_bSqSelected)
									{
										m_bSqSelected=false;
										m_nSqCount++;
										m_nPrev=m_nHigh;
										selSq[m_nHigh]=m_nHigh;
										m_nHigh=seq_lev1[m_nSqCount];
									}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

									CCGWnd:: updateLights();

									glPushMatrix();
									RLtool->renderEX1(GL_TRIANGLES);

									CString disStr;

									disStr.Format("xrot=%f,yrot=%f      %f %f %f",RLtool->xrot,RLtool-> //Piece of code missing
										->m_fX,RLtool->m_fY, RLtool->m_fZ);

									pStatus->SetPaneText(0,disStr);
									glPopMatrix();

									glPushMatrix();

									const float w=8.0;
									const float w2=(w*w)/2.0;
									
									int toolx=(int)(RLtool->m_fx)+8.0;
									int tooly=(int)Rltool->m_fY;

									tm=(tool+w2)/w;
									td=(tooly+w2)/w;

									if(tm==0)
										m_bSqlSelected=true;
									else
										m_bSqlSelected=false;
									float hm,hd,pm,pd;
									int scr=0;
									if(m_nPrev >0)
									{
										pm=m_nPrev%8;
										pd=m_nPrev/8;
										hm=m_nHigh%8;
										hd=m_nHigh/8;
									if(pm==0) {
										pm=8;
										pd--;
									}
									if(hm==0)
									{
										hm=8;hd--;
									}

									if(pm>hm)
									{
										if(tm>pm)
											scr++;
										if(tm<hm)//hm-1
											scr++;
									}else{
										if(tm<pm)//pm-1
											scr++;
										if(tm>hm)
											scr++;
										
									}

									if(pd>hd)
										{
											if(td>pd)
												scr++;
											if(td<hd)
												scr++;
										}else{

											if(td<pd)
												scr++;
											if(td>hd)
												scr++;
										}
										if(!m_bMinusOne && !m_bMinusTwo)
											m_nNS +=scr;

										if(!m_bMinusOne && !m_bMinusTwo & scr==2)
											m_nNS++;
									}
		////////////////////////////////////////////////////////////////////////////////////////////

									/*CGParameter param;
									cgGLEnableProfile(CCgWnd::vertexProfile);
									cgGLEnableProfile(CCGWnd::fragmentProfile);
									cgBlindProgram(CCGWnd::vertexProg);

									param=cgGetNamedProgramParameter(CCGWnd::vertexProg,CG_PROGRAM,"M // Part of code missing
									cgGLSetStateMatrixParameter(param,CG_GL_MODELVIEW_MATRIX,CG_GL_MATR//Part of coder missing

									param=cgGetNamedProgramParameter(CCGWnd::vertexProg,CG_PROGRAM,"M // Part of code missing
									cgGLSetStateMatrixParameter(param,CG_GL_MODELVIEW_MATRIX,CG_GL_MATRIX INVERSE TRANSPOSE);

									param= cgGetNamedProgramParameter(CCGWnd:: vertexProgram,CG Program,"// Part of code Missing
									);
									cgGLSetStateMatrixParameter(param,CG_GL_MODELVIEW_PROJECTION_MATRIX,CG_GL_MATRIX_IDENTITY);
									*/
	////////////////////////////////////////////////////////////////////////////////////////////////

										while(i<LIMIT)
										{
											//if
											cgGLBindProgram(sqProgs[i-1]);
											CCGWnd::bindPrograms(CCGWnd::vertexProg,sqProgs[i-1]);
											if(selSq[i] !=i && m_nHigh !=i)
											{
												glBegin(GL_QUADS);
												drawSquare(i,false);
												glEnd();
											}
											i++;
										}
								/*

								CCGWnd::bindPrograms(CCGWnd::vertexProg,CCGWnd::sqlProg);
								glBegin(GL_QUADS);
								while(i<LIMIT)
								{
								  if(selsq[i] !=i&& m_nHigh !=i)
								  drawSquare(i,false);
				//				  if((i%16)==0)
				//				  i--;
								  i++;
								  i++;
								  if((i%8)==1)
										
								 while(i<LIMIT)
								 {
								    if(selSq[i] !=i && m_nHigh !=i)
									drawSquare(i,false);

									i++;
									i++;


									if((i%8)==2)
									i--;
									if((i%16)==1)
									i++;
									}
									glEnd();

									
									*/
										CCgWnd:: bindPrograms(CCGWnd:: vertexProg,CCGWnd:: sqSelProg);
										i=1;
										glBegin(GL_QUADS);
										while(i<LIMIT)
										{
											if(selSq[i]==i)
												drawSquare(i,false);
										}
										glEnd();

										CCGWnd::bindPrograms(CCGWnd:: vertexProg,CCGWnd::sqHighProg);
										
										glBegin(GL_QUADS);

										drawSquare(m_nHigh,false);
										glEnd();
										RLtool->drawTraj();
										glPopMatrix();
										}
										int CEx1Rt ::drawSquare(int SqNum, bool Highlight)
										{
											const float w=8.0;
											const float w2=(w*w)/2.0;

											int h=m_nHigh;
											int p=m_nPrev;

											float z=0.0;

											int d=sqNum/8;
											int m=sqNum%8;

											if(m==0)
											{
												m=8;
												d--;
											}
											float x1=m*w-w2;

											hd=h/8;
											if(pm==0) {
												pm=8;
												pd--;
											}
											if(hm==0) {
												hm=8;
												hd--;
											}
											if(pm>hm)
											{
												if(m>pm)
													xt=MOVE;
												if(m<hm)//hm-1
													xt= -MOVE;
											}else{

												if(m<pm)//pm-1
													xt= -MOVE;
												if(m>hm)
													xt=MOVE;
											}
											if(pd>hd)
											{
												if(d>pd)
													yt=MOVE;
												if(d<hd)
													yt= -MOVE;
											}else{
												if(d<pd)
													yt=-MOVE;
												if(d>hd)
													yt=MOVE;
											}
										}


glVertex3f(x1+xt,y1+yt,0.0+z);
glVertex3f(x1+xt,y1+w+yt,0.0+z);
glVertex3f(x1-w+xt,y1+w+yt,0.0+z);
glVertex3f(x1-w+xt,y1+yt,0.0+z);

return 0;
}

void CEx1Rt::renderEndOfEx(void)
{
	glPushMatrix();

	int i;
	CCGWnd::bindPrograms(CCGWnd::vertexProg, CCGWnd::sqSelProg);
	i=1;
	RLtool->drawFullTraj();
}
int CEx1Rt::rand_col()
{
	int i;
	i=rand()%350;
	return i;
}

int CEx1Rt::rand_num(int mod)
{
	srand((unsigned)time(NULL));
	return(rand()%mod);
}

void CEx1Rt::loadSqProg(void)
{
	const int sqCount=64;
	int n=0;
	CGparameter metal;
	CGparameter param;
	BlinnProperties sqProperties;

///////////////////////////////////////////////////////////////////////////////////////////// Sowmya prog

	/* int row=0, col=0;
	int a;
	const int max=150;;
	int j[64*3];
	int num=0;

	srand((unassigned) time (NULL));
	int num_array[255]={false};
	for(int i=0;i<64*3;i++)
	{
		a=rand()%max;
		a++;
		if(!num_array[a-1])
		{
			j[num]=a;
			num++;
			num_array[a-1]=true;
			}else{
			i--;
			}
		}
		for(i=0;i<64*3;i++)
		{
			if(col>=3)
			{
				row++;
				col=0;
            }
			color[row][col]=j[i];

			// Part of code missing

			
	for(int i=0;i<sqCount;i++)
	{
		do{
			f=rand_col()/350.0f;
			g=0.466f*f; //LOW GREEN COMPONENT TO AVOID GREEN SQUARE IN GRID

			f=rand_col()/350.0f;
			b=f;
			f=rand_col()/350.0f;
			r=f;
			color[i][0]=r;
			color[i][2]=b;
			if(r==1.0 && g==1.0 && b==1.0)
				color[i][1]=g;
		}while (r==1.0 && g==1.0 && b==0.0);
	}

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	assert(cgIsContext(CCGWnd::context));

	//Turn on manual compilation so the runtime won't try to compile
	//incomplete programs.
	cgSetAutoComplile(CCGWnd::context, CG_COMPILE_MANUAL);

	while(n<sqCount)
	{
		sqProperties.ambient[0]=(float) color[n][0];
		sqProperties.ambient[1]=(float) color[n][1];
		sqProperties.ambient[2]=(float) color[n][2];

		sqProperties.diffuse[0]=(float) color[n][0];
		sqProperties.diffuse[1]=(float) color[n][1];
		sqProperties.diffuse[2]=(float) color[n][2];

		sqProperties.specular[0]=1.0;
		sqProperties.specular[1]=1.0;
		sqProperties.specular[2]=1.0;

		sqProperties.exp=100;

		//Create sq fragment program

		sqProgs[n]= cgCreateProgramFromFile(CCGWnd::context,CG_Source, //Part of code missing
			.cg", CCGWnd::fragmentProfile,"main", NULL);
			// Create metal material for teapot.

			metal=cgCreateParameter(CCGWnd::context,cgGetNamedUserType(// Part of code missing)

			cgGLLoadProgram(sqprograms[n]);
		n++;
	}
}

void CEx1Rt::setBlinnProperties(CGparameter b, BlinnProperties &p)
{
	cgSetParameter3fv(cgGetNamedStructParameter(b,"ambient"),p.ambient);
	cgSetParameter3fv(cgGetNamedStructParameter(b,"diffuse"),p.diffuse);
	cgSetParameter3fv(cgGetNamedStructParameter(b,"specular"),p.specular);
	cgSetParameter1f(cgGetNamedStructParameter(b,"sexp"),p.exp);
// if(literalMode)
	cgSetParameterVariability(b,CG_LITERAL);
}













































