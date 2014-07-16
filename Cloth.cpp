#include "StdAfx.h"
#include "Cloth.h"

#include<Cg/cgGL.h>
#include<glh/glh_extensions.h>
#include<glh/glh_linear.h>

#include "shared/nv_png.h"
#include "shared/array_texture.h"

#include "CGWnd.h"
using namespace glh;

CCloth::CCloth(void)
	:m_EndOfEx(false)
	,m_bEndOfEx(false)
	,m_fExcessBurn(0)
	,m_bFootSwitchPressed(false)
{
	CString str;
	vec3f sp(0.0,6.5,0.0);
	spherePos=sp;
	m_nNS=0;
	psys=new ParticleSystem(64,64,2);
}

CCloth::~CCloth(void)
{
}
//Draw a grid of lines
void CCloth::drawWireGrid(int rows, int cols)
{
	int i;
	glLineWidth(1.0);

	glBegin(GL_LINES);
	
		for(i=0;i<=rows;i++) {
			glVertex2f(0.0,(float) (i)/rows);
			glVertex2f(1.0,(float) (i)/rows);
		}
		for(i=0;i<=cols;i++)
		{
			glVertex2f((float) (i)/cols,0.0);
			glVertex2f((float) (i)/cols,1.0);
		}
		glEnd();
}
void CCloth::render(void);
{
cgGLDisableProfile(CCGWnd::fragmentProfile);
cgGLDisableProfile(CCGWnd::vertexProfile);

psys->m_bFootSwitchedPressed=m_bFootSwitchPressed;
psys->TimeStep(0.1);
if(psys->m_EndOfEx)
{
	m_bEndOfEx=true;
}
//psys->DisplayTextures();
}

bool CCloth::initCG(void)
{
	psys->InitGrid(vec3f(-20.0,-5.0,-20.0), vec3f(40.0/psys->GetWidth//Code missing
		0),vec3f(0.0,0.0,40.0/psys->GetHeight()));
	psys->InitGrid(vec3f(-20.0,3.0,-50.0), vec3f(40.0/psys->GetWidth()//Code missing
		vec3f(0.0,0.0,40.0/psys->GetHeight()));
	return true;
}

//get extension pointers
void CCloth::getExts(void)
{
	if(!glh_init_extensions("GL_ARB_multitexture"
							"GL_NV_vertex_program"
							"GL_NV_fragment_program"
							"WGL_ARB_pbuffer"
							"WGL_ARB_pixel_format"
							"WGL_ARB_render_texture"
							"GL_NV_float_buffer"
							"GL_NV_vertex_array_range"
							"GL_NV_pixel_data_range"
							"GL_NV_primitive_restart"
							)) {
								fprintf(stderr,"Error-required extensions were not supported:" %s//code missing
									glh_get_unsupported_extensions());
								exit(-1);
	}
}

void CCloth::setGripperParam(CPos t1, CPos t2, CPos t3)
{
	psys->setGripperParam(t1,t2,t3)
}


void CCloth::setHookParam(CPos t1,CPos t2, CPos t3, CPos t4 CPos t5, //code missing
{
	psys->setHookParam(t1,t2,t3,t4,t5,r);
}

void CCloth::setGripperCubeLowerJawParam(CPos t0, CPos t1, CPos t2,CPos t3, CPos t4, CPos t5,CPos t6,//code missing
	psys->setGripperCubeTopJawParam(t0,t1,t2,t3,t4,t5,t6,t7);
}

void CCloth::resetEx(void)
{
	delete psys;
	psys=new ParticleSystem(48,48,2);
}



