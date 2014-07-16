#include "StdAfx.h"
#include "Gripper.h"
#include "cgwnd.h"
float C3dsModel::jawOpening;
CGripper::CGripper(void)
{
}
CGripper::CGripper(void)
{
}
bool CGripper::Import()
{
	char *strFileName="../common/models/tc3.3ds"; //tc3
	char strMessage[255]={0};
	tChunk currentChunk={0};

	//Open the 3DSfile
	m_FilePointer = fopen(strFileName, "rb");

	//Make sure we have a valid file pointer (we found the file)

	if (!m_FilePointer)
	{
		sprintf(strMessage, "Unable to find the file: %s!", strFileName);
		MesageBox(NULL, strMessage, "Error",MB_OK);
		return false;
	}
	//Once we have the file open, we need to read the very first data chunk.
	//to see if its a 3DS file, That we don't read an invalid file
	//if it is a 3DS file, then the first chunk ID will be equal to PRIMARY num ??

	//Read the first chunk of the file to see if its a 3DS file
	ReadChunk(&currentChunk);

	//make sure this is a 3DS file
	if (currentChunk.ID!=PRIMARY)
	{
		sprintf(strMessage,"Unable to load PRIMARY chunk from file:%s!", strFileName);
		MessageBox(NULL, strMessage, "Error", MB_OK);
		retun false;
	}
	//Now we actually start reading in the data. ProcessNextChunk() is ....?
	//Begin loading objects, by calling this recursive function
	ProcessNextChunk(&currentChunk);

	//After we have read the whole 3DS file, we want to calculate our own normals
	ComputeNormals();

	//Clean up after everything
	CleanUp();

	//some code may be missing//
	for (int i=0; i<numOfMaterials; i++)
	{
		//Check to see if there is a file name to load in this material
		if(strlen(pMaterials[i].strFile)>0)
		{
			//use the name of the texture file to load the bitmap, with ....(i).
			//we pass in our global texture array, the name of the texture to reference it.
			CreateTexture(g_Texture, pMaterials[i].strFile, i);
		}
		//Set the texture ID for this material
		pMaterials[i].textureId=i;
	}
	return true;
}

//Render the model
void CGripper::renderModel(int ViewMode)
{
	g1PushMatrix();
	//Since we know how many objects our model has, go through each of them
	for (int=0; i<numOfObjects; i++)
	{
		//Make sure we have valid objects just in case. size() is in the ...class)
		if(pObject.size()<=0)break;
		g1PushMatrix();
		float trans=25.5;
		if (i==6)
		{
			glTranslatef(0.0,0.0,trans);
			glRotatef(jawOpening, 1.0, 0,0, 0.0);
			glTranslatef(0.0, 0.0,-trans);
		}
			CString str;
			str.Format("jawOpening=%f", jawOpening);
		//	AfxMessageBox(str);

			if(i==8)
			{
			glTranslatef(0.0,0.0,trans);
			glRotatef(-jawOpening, 1.0, 0,0, 0.0);
			glTranslatef(0.0, 0.0,-trans);
			}
			//get the current object that we are displaying
			C3dsObject *pObj = &pObject[i];
			//check to see if this object has a texture map, if so bind the object
			if(pObj->bHasTexture){
				//Turn on texture mapping and turn off color
				glEnable(GL_TEXTURE_2D);

				//some code may be missing//
				glColor3ub(255,255,255);
			}
			if(i==0)
				CCGWnd::bindPrograms(CCGWnd::vertexProg, CCGWnd::toolProg);
			else
				CCGWnd::bindPrograms(CCGWnd::vertexProg, CCGWnd::teapotProg);
			//this determines if we are in wireframe or normal mode
			glBegin(ViewMode);
			//begin drawing with our sel...triangles or lines)
			//Go through all of the faces (polygons) of the object and d...
			for(int j=0,j<pObj->numOfFaces;j++)
			{
				//Go through each corner of the triangle and draw it
				for(int whichVertex=0; whichVertex<3; whichVertex++)
				{
					//Get the index for each point of the face
					int index=pObj->pFaces[j].vertIndex[whichVertex];
					//Give OpenGl the normal for this vertex
					glNormal3f(pObj->pNormals[index].x,pObj->pNormals[index].y,pObj->pNormals[index].z);
					//if the object has a texture associated with it,, give...texture coordinate
					if(pObj->bHasTexture){
						//make sure there was a UVW map applied to the...it won't have tex coords

						if(pObj->pTexVerts){
							glTexCoord2f(pObj->pTexVerts[index].x, pObj->pTexVerts[index].y;
						}
					}else{
						//make sure there is a valid material/color assigned....object
						//you should always at least assign a material...object
						//but just in case we want to check the size of...list
						//if the size is at least one, adn the material then we have a valid material
						if(pMaterials.size() && pObj->materialID>=0
						{
							//get and set the colour that the object is....not have a texture
							BYTE *pColor = pMaterials[pObj->material[ID].  
								//Assign the current colour to this model

								glColor3ub(pColor[0], pColor[1], pColor[2]);
						}
					}
					//Pass in the current vertex of the object(Corner of....face)
					glVertex3f(pObj->pVerts[index].x,pObj->pVerts[index].y,pObj->pVerts[index].z);
				}


