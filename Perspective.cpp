//Perspective.cpp : implementation file
//
#include "stdafx.h"
#include "math.h"
#include "Lapro.h"
#include "Perspective.h"
#include "cgwnd.h"
#include "Cloth.h"
#include ".\perspective.h"

#define PI 3.1415926535897932384626433832795

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = _FILE_;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
\\ CPerspective

	IMPLEMENT_DYNCREATE(CPerspective, COpenGLWnd)

	CPerspective:: CPerspective(): step(5)
	,m_fCameraPivotX(0)
	,m_fCameraPivotY(0.0)//27.85
	,m_fCameraPivtotZ(0.0f)//63.0
	,m_bEnterKey(false)
	m_bMakeSound(false)
{
	m_xpos=0.0f;
	m_ypos=0.0f;//27.85
	m_zoom=80.0f;//63.0
	m_xrot=0.0f//4.0
    m_yrot=0.0f;//27.0
	Tool=  &rightTool;
	hookRadius=HOOK_MIN_Radius;
}

CPerspective""~CPerspective()
{
	Tool=NULL;
	delete TOOL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CPerspective drawing

void CPerspective::OnDraw(CDC* pDC)
{
	SetContext();
	glLoadIdentity();
	//Adjust viewport for md3 models which
	//use a different coordinate system-
	//3dsmax formate.
	//glRotatef( -90.0f,1.0f,0.0f,0.0f);

	//Position the camera
	glTranslatef(m_xpos, -mypos,-m_zoom);
	//Rotate the camera
	glRotatef(m_xrot,0.0f,1.0f,0.0f);
	glRotatef(m_yrot,1.0f,0.0f,0.0f);
}
//RenderScene();
//SwapGLBuffers();
/* CCGWnd::lights[0].view.from.r=m_zoom;
   CCGWnd::lights[0].view.from.phi= -m_yrot;
   CCGWnd::lights[0].view.from.theta= -m_xrot;
   CCGWnd::lights[0].view.target[0]= -m_xpos
   CCGWnd::lights[0].view.target[1]= m_ypos
   CCGWnd::lights[0].view.target[2]= m_zoom;	
*/
}

BEGIN_MESSAGE_MAP(CPerspective, COpenGLWnd)
	//{{AFX_MSG_MAP(CPerspective)
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_KEYUP()
	END_MESSAGE_MAP()
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	//CPerspective diagnostics

#ifdef _DEBUG
	void CPerspective::AssertValid() const
	{
		COpenGLWnd::AssertValid();
	}
	void CPerspective:: Dump(CDumpContext& dc) const
	{
		COpenGLWnd:: Dump(dc);
	}
#endif //_DEBUG
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//CPerspective message handlers

	//Adjust the viewport after a window sizing.
	void CPerspective:: OnSize(UINT nType, int cx, int cy)
	{
		COpenGLWnd::OnSize(nType,cx,cy);
		if(0>=cx || 0>cy|| nType ==SIZE_MINIMIZED)
			return;

		//Change the perspective viewing volume to
		//reflect the new dimensions of the window.
		SetContext();
		glViewport(0,0,cx,cy);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f,(float) (cx)/(float)(cv),0.01f,10000.0f);

		//AfxMessageBox("Control");

		if(nFlags & MK_LBUTTON)
		{
			//Left mouse button is being
			//pressed. zrotate the camera.
			m_yrot +=point.y - m_lastMouseY;
			m_xrot +=point.x - m_lastMouseX;
			//Redraw the viewport.
			OnDraw(NULL);
		}
		m_lastMouseX= point.x;
		m_lastMouseY=point.y
	}
		
		else if (nFlags & MK_BUTTON)
		{
			//Midddle mouse button is being 
			//pressed.Zoom the camera.
			if(m_lastMouseY !=-1)
			{
				m_zoom +=point.y- m_lastMouseY;
				//Redraw the viewport.
				OnDraw(NULL);
			}
			m_lastMouseY=point.y;
			}
		else if(nFlags & MK_RButton)
		{
			//Right mouse button is being
			//pressed . Pan the camera.
			if(m_lastMouseX != -1)
			{
				m_xpos +=(point.x - m_lastMouseX) * 0.15f;
				m_ypos +=(point.y - m_lastMouseY) * 0.15f;
				//Redraw the viewport.
				OnDraw(NULL);
			}
			m_lastMouseX =point.x;
			m_lastMouseY=point.Y;
		}
		else
		{
			m_lastMouseX=-1;
			m_lastMouseY=-1;
		}
		/* }
		else
		{
		m_lastMouseX=-1;
		m_lastMouseY=-1;
		}
		}*/
		COpenGLWnd:: OnMouseMove(nFlags,point);
		}

		void CPerspective:: OnKeyDown(UINT nChar,UINT nrepCnt,UINT nFlags)
		{
			const float rstep=1.0;

			case VK_RIGHT:
				if(C3dsModel:: jawOpening<-25 + step)
					break;
				C3dsModel:: jawOpening-=step;
				Invalidate();

				break;

			case VK_DOWN:
				/* if(C3dsModel::rightGripperOpening >(0-step))
				break;
				C3dsModel::rightGripperOpening=0.0;
				*/
				Invalidate();
				break;

				case VK_UP:
				/*
				if(C3dsModel::rightGripperOpening <-25+step){
				C3dsModel::rightGripperOpening=-21;
				break;
				}
				C3dsModel::rightGripperOpening-=step;
				*/
					C3dsModel::rightGripperOpening=-21;
					Invalidate();
					break;

				case VK_END:
					//if(Tool ->xrot< -180)
					//break;
					Tool ->xrot -=rStep;
					Invalidate();
					break;

				case VK_HOME:
					//if(Tool ->xrot > 0.0)
					//break;
					Tool ->xrot += rStep;
					Invalidate();
					break;

				case VK_NEXT:
					//if(Tool ->yrot> -90.0)
					//break;
					Tool ->yrot -=rStep;
					Invalidate();
					break;

					Tool ->trans -= rStep;
					Invalidate();
					break;

				case VK_F11:
					if(Tool ->trans >180.0)
						break;
					Tool ->trans += rStep;
					Invalidate();
					break;

				case VK_F2:
					// if(Tool:endeffOri <rStep)
					//Tool ->endeffOri =360;

					Tool ->endeffOri -= rStep;
					Invalidate;
					break;

				case VK_F1:
					//if(Tool ->endeffOri >(360.0 -rStep))
					//Tool ->endeffOri=0.0;
					Tool ->endeffOri += rStep;
					Invalidate();
					break;

				case VK_CONTROL:
					Tool=&leftTool;
					Invalidate();
					break;

				case VK_TAB:
					m_bMakeSound = true;
					Invalidate();
					break;
					/* case VK_SELECT:
					AfxMessageBox("ENTER");
					break;
					*/ }

		COpenGLWnd:: OnKeyDown(nChar, nRepCnt, nFlags);
		}
		void Perspective:: OnKeyUp(UINT nChar, UINT nReCnt, UINT nFlags)
		{
			switch (nChar) {
			case VK_CONTROL:
				Tool=&rightTool;
				Invalidate();
				break();

			case ' ':
//Piece of code missing
				COpenGLWnd::OnKeyUp(nChar,nRepCnt, nFlags);
			}


void CPerspective ::OnChar(UINT nChar,UINT nrepCnt, UINT nFlags)
{
	CString str;
	const float spStep=0.25;
	switch(nChar) {
	case' ':
		if(hookRadius < HOOK_MAX_RADIUS)
		{
			hookRadius +=0.05;
		}

		Invalidate();
		break;
	case 'a':
	case 'A':
		spherePos.x -=spStep;
		break;
	case 'd':
	case 'D':
		spherePos.x += spStep;
		Invalidate();
		break;
	case 's':
	case 'S':
		spherePos.y +=spStep;
		Invalidate();
			break;
	case 't':
	case 'T':
		spherePos.z -=spStep;
		Invalidate();
			break;

	case 'g':
	case'G':
		spherePos.z += spStep;
		Invalidate();
		break;

	case 'p':
	case 'P':
		AfxMessageBox(m_strVert);
		break;

		case //Piece of code missing

	}

	COpenGLWnd:: OnChar(nChar, nRepCnt, nFlags);
}
void CPerspective:: getAngles(float xyz[], float &angx, float &angy)
{
	float h,h1,h_rod,l1,n1; //height, DC's --> cos theta
	float xx,yy,zz;
	double a,aa,b,cos_theta2; //co-ordinates & angles

	xx=(float)fabs(xyz[0] - xyz[3]); //DIRECTION RATIOS OF THE LINE
	yy=(float)fabs(xyz[1]-xyz[4]);
	zz=(float)fabs(xyz[2]-xyz[5]);
	h=(float)sqrt(sq(xx) +  sq(yy) + sq(zz));  //LENGTH OF VISIBLE ROD
	h1=(float)sqrt(sq(xx)+ sq(zz));           //LENGTH OF PROJECTION OF PLANE

    h_rod=h; // -cone_ht; //LENGTH OF ACTUAL ROD REQUIRED

	l1=xx/h1;  //X-DIRECTION COSINE OF PROJECTED LINE
	n1=zz/h1;  //Z_DIRECTION  COZINE OF PROJECTED LINE
				/*Y-DIRECTION  COZINE NOT REQUIRED BECAUSE THE PRJET /PIECE OF CODE MISSING
				*ON XZ PLANE. THEREFORE m1=0.
				*/
	cos_theta2=(11* xx +n1*zz)/h;// COSINE OF ANGLE MADE BY LINE TO.. //PIECE OF CODE MISSING

	aa=(float)atan2(xx,zz);
	a=aa*180/PI;
	b=CosInverse(cos_theta2);

	//TRACE("b=%f",b);
	if(!b)
	
	{
		b=0.0;
		// TRACE("in loop");
	}

	//TRACE("b= %f \n",b);
	if((xyz[0] - xyz[3]) >0) a=-a;
	if(xyz[1] - xyz[4] <0) b=-b;

	angx=b;
	angy=a;
}

float CPerspective ::sq(float number)// square of a number
{
	return number *number;
}

//return the angle of the direction cosine cos_theta in degrees

float CPerspective::CosInverse(float cos_theta)
{
	float sin_theta,theta;
	sin theta=(float)sqrt(1-sq(cos theta));

	float z1=0.0;
	float z2=-150;
	float len=30;
	if(rightTool.m_fX >x1 && rightTool.m_fX < x2)
		if(rightTool.m_fZ< z1 && rightTool.m_fZ > z2)
		{
			float d=getDistance(rightTool.m_fX,rightTool.m_fY, //piece of code missing
				m_fCameraPivotX,m_fCameraPivotY,m_fCameraPivotZ);

			if(d!=len)
			{
				float ratio=len/d;

				m_fCamXPos=ratio * (rightTool.m_fX-m_fCameraPivot //piece of code missing
			    m_fCamYPos=ratio * (rightTool.m_fY-m_fCameraPivot //piece of code missing
			    m_fCamZoom=ratio * (rightTool.m_fZ-m_fCameraPivot //piece of code missing

				float xyz[6];

				xyz[0]=rightTool.m_fX;
				xyz[1]=rightTool.m_fy;
				xyz[2]=rightTool.m_fZ;

	/*			xyz[3]= m_fCameraPivotX;
				xyz[4]= m_fCameraPivotY;
				xyz[5]= m_fCameraPivotZ;
*/
	/*			float ax,ay;
				getAngles(xyz,ay,ax);
				m_fCamXRot = -ax;
				m_fCamYRot = -ay;
			}
			return true;
		}
	*/	return false;
}


float CPerspective ::getDistance(float x1,float y1, float z1,float x2, //..piece of code missing
	float z2)
{
	float xx=x2-x1;
	float yy=y2=y1;
	float zz= z2-z1;

	return sqrt(sq(xx) + sq(yy)+sq(zz));
}






























			
		


