#include "stdafx.h"
#include "Cavity.h"
#include "CGWnd.h"
#include <assert.h>

CCavity::~CCavity(void)
{
	cgDestroyProgram(CCGWnd::cavityProg);
	cgDestroyParameter(texParam);
	cgDestroyParameter(CCGWnd::texParam);
}
bool CCavity::Import()
{
	char *strFileName="../common/models/flatcavity.3ds";
	char strMessage[255]={0};
	tChunk currentChunk={0};

	//Open the 3DS file
	m_FilePointer=fOpen(strFileName,"rb");

	//make sure we have a valid file pointer(we found the file)
	if(!m_FilePointer)
	{
		sprintf(strMessage,"Unable to find the file"%s!",strFileName);
			MessageBox(NULL,strMessage,"Error",MB_OK);
		return false;
	}

	ReadChunk(&currentChunk)
		if(currentChunk.ID !=PRIMARY)
	{
		sprintf(strMessage,"Unable to load PRIMARY chunk from file: %s!", strFileName);
		MessageBox(NULL,strMessage,"Error",MB_OK);
		return false;
		}

		ProcessNextChunk(&CurrentChunk);
		ComputeNormals();
		CreateTexture();

		for(int i=0;i<numOfMaterials;i++)
		{
			if(strlen(pMaterials[i].strFile)>0)
			{
				CreateTexture(g_Texture,pMaterials[i].strFile,i);
			}
			texID=pMaterials[i].textureId=i;
		}

		int n=0;
		for(int i=0;i<numOfObjects;i++)
		{
			if(pObject.size()<=0) break;
			C3dsObject *pObj= &pObject[i];
			n+=pObj->numOfVerts;
		}
		nVert=n;
		/* CString str;
		str.Format("Number of vertices in cavity=%d",n);
		AfxMessageBox(str);
		*/
		loadCgPrograms1();
		return true;
}

void CCavity::setBlinnProperties(CGparameter b,BlinnProperties &p)
{
	cgSetParameter3fv(cgGetNamedStructParameter(b,"ambient"),p.ambient)
	cgSetParameter3fv(cgGetNamedStructParameter(b,"diffuse"),p.diffuse)
	cgSetParameter3fv(cgGetNamedStructParameter(b,"specular"),p.specular)
	cgSetParameter3fv(cgGetNamedStructParameter(b,"sexp"),p.exp);
	//if(literalMode)
	cgSetParameterVariability(b,CG_LITERAL);
}
void CCavity::loadCgPrograms1()
{
	CCGWnd::CavityProg=cgCreateProgramFromFile(CCGWnd::context,CG_SOURCE//code missing
		CCGWnd::fragmentProfile,"main",NULL);

	CString str;
	str.Format("num=&d",texID);
	CCGWnd::texParam=cgGetNamedProgramParameter(CCGWnd::cavityProg, CG_//code missing
		"sample2d");

	cgGLSetTextureParameter(CCGWnd::texParam,g_Texture[1]);
	////////////////set tm1 uniform parameters

	cgConnectParameter(CCGWnd::lArray,cgGetNamedProgram(CCGWnd://code missing
	CG_PROGRAM,"lights"));

	cgGLSetParameter3f(cgGetNamedProgramParameter(CCGWnd::cavityProg,CG//code missing
		"ambient"),

				a[0],a[1],a[2]);
	cgGLSetParameter3f(cgGetNamedProgramParameter(CCGWnd::cavityProg,CG//code missing
		"diffuse"),

				d[0],d[1],d[2]);

	cgGLSetParameter3f(cgGetNamedProgramParameter(CCGWnd::cavityProg,CG//code missing
		"specular"),

				s[0],s[1],s[2]);
cgGLSetParameter3f(cgGetNamedProgramParameter(CCGWnd::cavityProg,CG//code missing
		"sexp")

		////////////////////////////end tm1 parameters

		cgCompileProgram(CCGWnd::cavityProg);
cgGLLoadProgram(CCGWnd::cavityProg);
cgGEnableTextureParameter(CCGWnd::texParam);
}

//Renders the model
void CCavity::renderModel(int ViewMode)
{
	glPushMatrix();

	for(int i=0;i<numOfObjects;i++)
	{
		if(pObject.size() <=0) break;
		if(i==3)
		{
			CCGWnd::bindPrograms(CCGWnd::vertexProg,CCGWndoment//code missing
		}else{
			CCGWnd::bindPrograms(CCGWnd::vertexProg,CCGWnd:://code missing
		}
		glPushMatrix();

		//Get the current object that we are displaying
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,g_Texture[pObj->materialID]);
	} else {

		glDisable(GL_TEXTURE_2D);
		//Reset the color to normal again
	glColor3ub(255,255,255);

	}

	//This determines if we are in wireframe or normal mode
	glBegin(ViewMode);

	for(int j=0;j<pObj->numOfFaces;j++)
	{
		for(int whichVertex=0;whichVertex<3; whichVertex++)
			int index=pObj->pFaces[j].vertIndex[whichVertex];

		glNormal3f(pObj->pNormals[index].x,pObj->pNormals//code missing
			pObj->pNormals[index].z);
		if(pObj->bHasTexture) {
			if(pObj->pTexVerts) {
				glTexCoord2f(pObj->pTexVerts[index].x,pObj//code missing
					index].y);
			}
		}else{
			if(pMaterials,size() && pObj->materialID>=0)
			{
				BYTE *pColor=pMaterials[pObj->materialID]./code missing
					glEnd();
				glPopMatrix();
			}
			glPopMatrix();
		}


