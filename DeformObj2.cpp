#include "stdafx.h"
#include "DeformObj2.h"

#include<Cg/cgGL.h>
#include<glh/glh_linear.h>
#include<glh/glh_extensions.h>
#include <string>
#include "shared/pbuffer.h"
#include "shared/nv_png.h"
#include "shared/array_texture.h"
//#include "rendertova.h"

#include<math.h>
#include<CGWnd.h>

using namespace glh;

CDeformObj2::CDeformObj2(void)
{
	CString str;
	vec3f sp(0.0, 6.5, 0.0);
	spherePos=sp;
	m_freeze=false;
	m_HookRadius=HOOK_MIN_RADIUS;
}
CDeformObj2::~CDeformObj2(void)
{
	delete m_pbuffer[4];
	delete m_pbuffer[3];
	delete m_pbuffer[2];
	delete m_pbuffer[1];
	delete m_pbuffer[0];

	delete [] m_x;
	delete [] m_c;
	delete [] m_debug;
	delete [] m_normal_pbuffer;
}

bool CDe CDeformObj2::Import()
{
	char *strFileName="../common/models/pcm/ovary1.3ds";//models/cyl1
	char strMessage[255]={0};
	tChunk currentChunk={0};

	//open the 3DS file
	m_FilePointer=fopen(strFileName,"rb");
	//make sure we have a valid file pointer(we found the file)
	if(!m_FilePointer)
	{
		sprintf(strMessage, "Unable to find the file: %s!",strFileName);
		MessageBox(NULL,strMessage,"Error",MB_OK);
		return false;
	}
	//once we have the files open, we need to read the very first data chunk//code missing
	// to see if it's a 3DS file. That way we don't read an invalid file.
	MessageBox(NULL,strMessage,"Error",MB_OK);
	return false;
}

//Now we actually start reading int he data.ProcessNextChunk() is //code missing

//Begin loading objects, by calling this recursive function
ProcessNextChunk(&currentChunk);

//After we have read the whole 3DS file, we want to calculate our own normals.
ComputeNormals();

//clean up after everything
CleanUp();

//////////////////////////////////////////////////////////////////

//Depending on how many textures we foundload each one//code missing
CreateTexture(();

for(int i=0;i<numOfMaterials;i++)
{
	if(strlen(pMaterials[i].strFile)>0)
	{
		AfxMessageBox(pmaterials[i].strFile)
			CreateTexture(g_Texture,PMaterials[i].strFile,i);
	}
	//set the texture ID for this material
	texID=pMaterials[i].textureId=i;
}
//////////////////////////////////////////////num of vertices

int n=0;
for(int i=0; i<numOfObjects;i++)
{
	if(pObject.size() <=0) break;
	//Get the current object that we are displaying
	C3dsObject *pObj=&pObject[i];
}
}
nvert=n;
ParticleSystem(nVert,2);
CString str;
str.Format("Number of vertices in df1=%d",n)
	//AfxMessageBox(str);

	//CreateTexture(texID1,"FLESH.bmp",1);
	return true;
}

//Renders the model
void CDeformObj2::renderModel(int viewMode)
{
	glPushMatrix();

	for(int i=0; i<numOfObjects;i++)
	{
		if(pObject.size()<=0) break;
		glPushMatrix();
		//Get the current object that we are displaying
		C3dsObject *pObj=&pObject[i];

		if(pObj->bHasTexture)
		{
			//Turn on texture mapping and turn off color
			glEnable(GL_TEXTURE_2D);

			//Reset the color to normal again
			glColor3ub(255,255,255);

			//Bind the texture map to the object by its material ID
			glBindTexture(GL_TEXTURE_2D, g_Texture[pObj->materialID]);
		} else {
			//Turn off texture mapping and turn on color
			glDisable(GL_TEXTURE_2D);

			//Reset the color to normal again
			glColor3ub(2255,255,255);
		}

		int index=pObj->pFaces[j].vertIndex[whichVertex];

		//Give OpenGL the normal for this vertex.
		glNormal3f(pObj->pNormals[index].x,pObj->pNormals//code missing
			pObj->pNormals[index].z);

		if(pObj->bHasTexture) {
			if(pObj->pTexVerts) {
				glTexCoord2f(pObj->pTexVerts[index].x,pObj//code missing
					index].y);
			}else {

				if(pMaterials.size() && pObj->materialsID >=0)
				{
					BYTE *pcolor=pMaterials[pObj->materialID]//code missing
					//Assign the current color to this model
					glColor3ub(pColor[0],pColor[1],pColor[2]);
				}
			}

			glVertex3f(pObj->pVerts[index].x,pObj->pVerts[// code missing
				->pVerts[index].z);
		}
	}
	glEnd();
	glPopMatrix();
}
glPopMatrix();
}

//Draw a grid of lines
void CDeformObj2::drawWireGrid(int rows,int cols)
{
	int i;
	glLineWidth(1.0);
	glBegin(GL_LINES);
	for(i=0;i<=rows;i++) {
		/*
		glPushMatrix();
		glTranslateef(spherePos[0],spherePos[1], spherePos[2]);
		CCGWnd:: bindPrograms(CCGWnd::vertexProg,CCGWnd::groundProg);

		glutSolidSphere(7.95,30,30);
		cgGLUnbindProgram(CCGWnd::fragmentProfile);
		cgGLUnbindProgram(CCGWnd::vertexProfile);

		glPopMatrix();
		*/
		AfxMessageBox("time step 0");
		TimeStep(0.1);

		SetSphere(spherePos);
		if(m_freeze)
		{
			//m_pbuffer[m_ori]->Activate();
			//glRasterPos2i(0,0);
			glDrawPixels(m_w, m_h, GL_RGB,GL_FLOAT,m_x);

			m_pbuffer[m_ori]->Deactivate();
		}
		//draw particle system
		//CCGWnd::bindPrograms(CCGWnd::vertexProg,CCGWnd::groundProg);
		//////////for wire mesh
		glPushMatrix();
		//ReadBack();
		//Display();
		DisplayShaded();
		glPopMatrix();
		//DisplayTextures();
	}

	bool CDeformObj2::initCG(void)
	{
		InitCg();
		//psys->InitGrid(vec3f(-20.0,-5.0,-20.0),vec3f(40.0/psys->GetWidth//code missing
		0),vec3f(0.0,0.0,40.0/psys->GetHeight()));

		"WGL_ARB_pixel_format"
	    "WGL_ARB_render_texture"
		"GL_NV_float_buffer"
		"GL_NV_vertex_array_range"
		"GL_NV_pixel_data_range"
		"GL_NV_primitive_restart"
		)) {
			fprintf(stderr,"Error-required extensions were not supported: %s
				glh_get_unsupported_extensions());
			exit(-1);
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////

	void CDeformObj2::ParticleSystem(int nVert, int iterations)
	{
		m_w=nVert;
		m_h=1;
		m_iterations=iterations+1;
		m_x=new vec3f[m_w* m_h];
		m_c=new vec3f[m_w* m_h];
		m_debug=new float[m_w* m_h];

		m_pbuffer[0]=CreatePBuffer("float=32 textureRECT",m_pbuffer_tex[0],//code missing
        m_pbuffer[1]=CreatePBuffer("float=32 textureRECT",m_pbuffer_tex[0],//code missing
	    m_pbuffer[2]=CreatePBuffer("float=32 textureRECT",m_pbuffer_tex[0],//code missing
        m_pbuffer[3]=CreatePBuffer("float=32 textureRECT",m_pbuffer_tex[0],//code missing
        m_pbuffer[4]=CreatePBuffer("float=32 textureRECT",m_pbuffer_tex[0],//code missing

		//m_normal_pbuffer=CreatePBuffer("float=16 textureRECT",m_normal_//code missing
		//false);
		
		m_normal_pbuffer=CreatePBuffer("rgb textureRECT

