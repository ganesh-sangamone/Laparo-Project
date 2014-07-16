#include "stdafx.h"
#include "3dsModel.h"
#include <assert.h>

//Global
int gBuffer[50000]={0};
float C3dsModel::rightGripperOpening;
bool C3dsModel::isRightGripperOpen;
C3dsModel::C3dsModel(void)
{
	m_FilePointer=NULL;
	numofObjects=0;
	numOfMaterials=0;
}
C3dsModel::~C3dsModel(void)
{
	if(m_FilePointer)
		delete m_FilePointer;
	pMaterials.clear();
	pObject.clear();
}

////////////////////////////////IMPORT 3DS////////////////////////////////////////////////////////
///// This is called by the client to open the .3ds file,read it, then
/////////////////////////////// IMPOR 3DS////////////////////////////////////////////////////////

bool C3dsModel::Import(char &strFileName)
{
	char strMessage[255]={0};
	tChunk currentChunk={0};
	//Open the 3DS file
	m_FilePointer=fOpen(strFileName,"rb");
	//Make Sure we have a valoid pointer(we found the file)
	if(!m_FilePointer)
	{
		sprintf(strMessage,"Unable to find the file: %s!",strFileName);
		MessageBox(NULL,strMessage,"Error",MB_OK);
		return false;
	}

	//once we have the files open, we need to read the very first data chunk to
	//see if it's a 3DS file. That way we don't read an invalid file//If it is a 3DS file, then the first chunk ID
	//will be equal to // code missing

	//Read the firat chuck of the file to see if it's a 3DS file
	ReadChunk(&currentChunk);

	//Begin loading objects, by calling this recursive function
	ProcessNextChunk(&currentChunk);

	//After we have read the whole 3DS file, we we want to calculate //code missing//
	ComputeNormals();

	CleanUp();

	for(int i=0;i<numOfMaterials;i++)
	{
		//check to see if there is a file name to load in this material
		if(strlen(pMaterials[i].strFile)>0)
		{
			//Use the name of the texture file to load the bitmap with (i).
			//We pass in our global texture array, the name of the texture to reference it.

			CreateTexture(g_Texture,pMaterials[i].strFile,i)
		}

		//Set the texture ID for this material
		pMaterials[i].textureId=i;
	}
	return true;
}

bool C3dsModel::Import()
{
	char *strFileName=".../common/models/face.3ds";
	char strMessage[255]={0};
	tChunk currentChunk={0};

	//open the 3DS file
	m_FilePointer=fopen(strFileName,"rb");

	//Make sure we have a valid file pointer(we found the file)

if(!m_FilePointer)
	{
		sprintf(strMessage,"Unable to find the file: %s!",strFileName);
		MessageBox(NULL,strMessage,"Error",MB_OK);
		return false;
	}

	//once we have the files open, we need to read the very first data chunk to
	//see if it's a 3DS file. That way we don't read an invalid file//If it is a 3DS file, then the first chunk ID
	//will be equal to // code missing
}
	
	//Begin loading objects, by calling this recursive function
	ProcessNextChunk(&currentChunk);

	//After we have read the whole 3DS file, we we want to calculate //code missing//
	ComputeNormals();

	CleanUp();

	CreateTexture();
	//Below we go through all of the materials and check if they have a//code missing//

	for(int i=0;i<numOfMaterials;i++)
	{
		//check to see if there is a file name to load in this material
		if(strlen(pMaterials[i].strFile)>0)
		{
			//Use the name of the texture file to load the bitmap with (i).
			//We pass in our global texture array, the name of the texture to reference it.

			CreateTexture(g_Texture,pMaterials[i].strFile,i)
		}

		//Set the texture ID for this material
		pMaterials[i].textureId=i;
	}
	return true;
}
bool C3dsModel::Import(CArchive ar)
{
	return true;
}
//Renders the Model
void C3dsModel::renderModel(int ViewMode)
{
	//Since we know how many objects our Model has// Code Missing

	for(int i=0;i<numOfObjects;i++)
	{
		glPushMatrix();
		//Make sure we have valid objects just in case. (size() is the class)

		//Reset the color to normal again
		glColor3ub(255,255,255);

		//Bind the texture mapmto the object by its materialID
		glBindTexture(GLTexture_2D,g_Texture[pObj->materialID])'
	}else{

		//Turn off texture mapping and turn on color
		glDisable(GL_Texture_2D);
		//Reset the color to normal again
		glColor3ub(255,255,255);
	}
	glBegin(ViewMode);

	for(int j=0;j<pObj->numOfFaces;j++)
	{
		for(int whichVertex=0; whichVertex<3;whichVertex++)
		{
			int index=pObj->pFaces[j].vertexIndex[whichVertex];
			glNormal3f(pObj->pNormals[index].x,pObj->pNormals[//code missing
				pObj->pNormals[index].z);

				if(pObj->bHasTexture)
				{
					if(pObj->pTexverts)
					glTexCoord2f(pObj->pTexverts[index].x, pObj..//code missing
					index].y);
				}
		}else{

			if(pMateruals.size() && pObj->materialID >=0)
			{
				BYTE*pColor=pMaterials[pObj->materialID].//ccode missing
					glColor3ub(pColor[0],pColor[1].pColor[2]);
				glPopMatrix();
			}
		}

		///////////////////// CREATE TEXTURE/////////////////////////////////

		//////This creates a texture in OpenGL that we can texture map//////

		//////////////////////CREATE TEXTURE///////////////////////////////

		void C3dsModel::CreateTexture(UINT textureArray[],LPSTR, int//code missing//
		{
			AUX_RGBImageRec *pBitmap=NULL;

			if(!strFileName)
				return;
			pBitmap=auxDIBImageLoad(strFileName);
			if(pBitmap==NULL)
				exit(0);

			glGenTextures(1, &textureArray[textureID]);
			glPixelStorei(GL_UNPACK_ALIGNMENT,1);
			glBindTexture(GL_TEXTURE_2D,textureArray[textureID]);

			/*CString str;
			str.Format("tex id gen tex=%d",textureArray[textureID]);
			AfxMessageBox(str);
			*/

			gluBuild2DMipmaps(GL_TEXTURE_2D,3,pBitmap->sizeX,pBitmap->sizeY// code missing//
				GL_UNSIGNED_BYTE,pBitmap->data);
			GL_LINEAR_MIPMAP_LINEAR,
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER<GL_LINEAR_MIPMAP_//code missing
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER<GL_LINEAR_MIPMAP_//code missing

				if(pBitmap)
				{
					if(pBitmap->data)

//code missing

void C3dsModel::CleanUp()

	{
	   if(m_FilePointer) {
		   fClose(m_FilePointer);
		   m_FilePointer=NULL;
	   }
	}

void C3dsModel::ProcessNextChunk(tChunk *pPreviousChunk)
{
	C3dsObject newObject;
	tMaterialInfo newTexture={0};
	tChunk currentChunk={0};
	tChunk tempChunk={0};

	while(pPreviousChunk->bytesRead<pPreviousChunk->length)
	{
		ReadChunk(&currentChunk);
		switch(currentChunk.ID)
		{

		case VERSION:
			currentChunk.bytesRead +=fread(gBuffer,1,currentChunk.length//code missing
				currentChunk.bytesRead,m_FilePointer);
			
		currentChunk.bytesRead += tempChunk.bytesRead;

		ProcessNextChunk(&currentChunk);
		break;
		}


		case MATERIAL:

			numOfMaterials++;
			pMaterials.push_back(newTexture);
			ProcessNextMaterialChunk(&currentChunk);
			break;
		case OBJECT:
			numOfObjects++;
			pObjects.push_back(newObject);

			memset(&(pObject[numOfObjects-1]),0,sizeof(C3dsObject));

			currentChunk.bytesRead+= GetString(pObject[noOfObjects-1}
	ProcessNextObjectChunk(&(pObject[numOfObjects-1]), &current//code missing
		break;

	case EDITKEYFRAME:
		currentChunk.bytesRead,m_FilePointer);
		break;
	default:

		currentChunk.bytesRead +=fread(gBuffer,1,currentChunk.length//code missing
				currentChunk.bytesRead,m_FilePointer);
		break;
}
pPreviousChunk->bytesRead+=currentChunk.bytesRead;
				}
		}

///////////////////// PROCESS NEXT OBJECT CHUNK/////////////////////////////////

		void C3dsModel::ProcessnextObjectChunk(C3dsObject *pObject, tChunk *pPrev// code missing
		{
			tChunk currentChunk={0};
			while(pPreviousChunk->bytesRead<pPreviousChunk->length)
			{
				ReadChunk(&currentChunk);

				switch(currentChunk.ID)
				{
				case OBJECT_MESH:

					ProcessNextObjectChunk(pObject, &currrentChunk);
					break;

				case OBJECT_VERTICES:
					ReadVertices(pObject,&CurrentChunk);
					brak;

				case OBJECT_MATERIAL:
					ReadObjectMaterial(pObject,&currentChunk);
					break;

				case OBJECT_UV:

					ReadUVCoordinates(pObject, &currentChhunk);
					break;
				default: currentChunk.bytesRead +=fread(gBuffer,1,currentChunk//code missing
							 currentChunk.bytesRead,m_Filepointer);
					break;
				}
				pPreviousChunk->bytesRead+=currentchunk.bytesRead;
			}
		}

		/////////////PROCESS NEXT MATERIAL CHUNK///////////////////

		void C3dsModel::ProcessNextMaterialChunk(tChunk *pPreviousChunk)
		{
			tChunk currentChunk={0};
			while(pPreviousChunk->bytesRead<pPreviousChunk->length)
			{
				ReadChunk(&currentChunk);

				switch(currentChunk.ID)
				{
				case MATNAME:
					currentChunk.bytesRead +=fread(pMaterials[numOfMaterials-1] //code misssing
					currentChunk.length-currentChunk.bytesRead, m_FilePointer);
					
					break;

				case MATDIFFUSE:
					ReadColorChunk(&pMaterials[numOfMaterials-1]), &currentChunk//code missing
					break;
					currentChunk.bytesRead+= fread(pMaterials[numOfmaterials-1//code missing
						currentChunk.length-currentChunk.bytesRead,m_FilePointer);
					break;

				default: currentChunk.bytesRead +=fread(gBuffer,1,currentChunk//code missing
							 currentChunk.bytesRead,m_Filepointer);
					break;
				}
				pPreviousChunk->bytesRead+=currentChunk.bytesRead;
			}
		}


		/////////////////////READ CHUNK/////////////////////////////////////////////

		void C3dsModel::ReadChunk(tChunk *pChunk)
		{
			pChunk->bytesRead=fread(&pChunk->ID,1,2,m_File_Pointer);
		pChunk->bytesRead+=fread(&pChunk->length,1,4,m_FilePointer);
		}

		int C3dsModel::GetString(char *pBuffer)
		{
			int index=0;
			fread(pBuffer,1,1,m_FilePointer);
			while(*(pBuffer+index++)!=0) {
				fread(pBuffer+index,1,1,m_FilePointer);
			}

			return strlen(pBuffer)+1;
		}
		ReadChunk(&tempChunk);

		tempChunk.bytesRead+=fread(pMaterial->color,1,tempChunk.length-//code missing
			bytesRead,m_FilePointer);

		pChunk->bytesRead+=tempChunk.bytesRead;
		}

		///////////////////////READ VERTEX INDICES//////////////////////////////////////////////

		void C3dsModel::ReadVertexIndices(C3dsObject *pObject, tChunk *pPrevious// code missing
		{
			unsigned short index=0;
			pPreviousChunk->bytesRead += fread(&pObject ->numOfFaces,1,2,m_File//code missing
				pObject->pFaces=new tFace[pObject->numOfFaces];

			memset(pObject->pFaces,0,sizeof(tFace)*pObject->numofFaces);

			
for(int j=0;j<pObj->numOfFaces;j++)
	{
		for(intj=0;j<4;j++)
		{
			pPreviousChunk->bytesRead += fread(&index,1,sizeof(index), m_FilePointer);
			if(j<3)
			{
				pObject->pFaces[i].vertexIndex[j]=index;
			}
		}
}
		}

		pPreviousChunk->bytesRead+=fread(&pObject->numTexVertex,1,2,m_Fi..//code missing
			pObject->pTexVerts=new CV2 [pObject->numTexVertex];
		pPreviousChunk->bytesRead+=fread(pObject->pTexVerts,1,pPreviousCh.//code missing
pPreviousChunk->bytesRead,m_FilePointer);
		}

		//////////////////////READ VERTICES////////////////////////////////////////////////////////
		//////This func reads in the vertices for the objects
		/////////////////////READ VERTICES////////////////////////////////////////////////////////

		void C3dsModel::ReadVertices(C3dsObject *pObject,tChunk *pPreviousChunk)
		{
			pPreviousChunk->bytesRead +=fread(&(pObject->numOfVerts),1,2,m_//code missing

				pObject->pVerts=new CV3[pObject->numOfverts)1,2,//code missing
				memset(pObject-pVerts,0,sizeof(CV3)* pObject->numOfVerts);

			pPreviousChunk->bytesRead+=fread(pObject->pVerts,1,pPreviousChunk..//code missing
				pPreviousChunk->bytesRead,m_FilePointer);


			for(int i=0;i<pObject->numOfVerts;i++)
			{
				float fTempY=pObject->pVerts[i].y;
				pObject->pVerts[i].y=pObject->pVerts[i].z;

				pObject->pVerts[i].z=-fTempY;
				{
					char strMaterial[255]={0};

					pPreviousChunk->bytesRead+=GetString(strMaterial);
					for(int i=0;i<numOfMaterials;i++)
					{
						if(strcmp(strMaterial,pMaterials[i].strName)==0)
						{
							pObject->materialID=i;
							if(strlen(pMaterials[i].strFile)>0) {
								pObject->bHasTexture=true;
							}
							break;
						}else
						{
							pObject->materialID=-1;
						}
					}
					pPreviousChunk->bytesRead +=fread(gBuffer,1,pPreviousChunk->length//code missing
						pPreviousChunk->bytesRead,m_FilePointer);
				}

				CV3 Vector(CV3 vPoint1, CV3 vPoint2)
				{
					CV3 vVector;

					vVector.x=vPoint1.x - vPoint2.x;
					vVector.y=vPoint1.y - vPoint2.y;
					vVector.z=vPoint1.z - vPoint2.z;

					return vVector;
				}
				//This adds 2 vectors and then returns the result

				CV3 AddVector(CV3 vVector1,CV3 vVector2)
				{
					CV3 vResult;

					vResult.x=vVector2.x - vVector1.x;
					vResult.y=vVector2.y - vVector1.y;
					vResult.z=vVector2.z - vVector1.z;

					return vResult;
				}
				//This divides a vector by a single number(scalar) and returns the result
				CV3 DivideVectorByScalar(CV3 vVector1, float Scalar)
				{
					CV3 vResult;

					vResult.x=vVector1.x/Scalar
					vResult.y=vVector1.y /Scalar;
					vResult.z=vVector1.z /Scalar;

					return vResult;
				}

//This returns the cross product betwwen the two vectors

	CV3 Cross(CV3 vVector1,CV3 vVector2)
				{
					CV3 vCross;
					vCross.x=((vVector1.y * vVector2.z)-(vVector1.z * vVector2.y));
					vCross.y=((vVector1.z * vVector2.x)-(vVector1.x * vVector2.z));
					vCross.z=((vVector1.x * vVector2.y)-(vVector1.y * vVector2.x));
					
					return vCross;
				
	
	}
	//This returns the normal of a vector
	CV3 Normalize(CV3 vNormal)
	{
		double Magnitude;

	////////////////////COMPUTER NORMALS//////////////////////////////////////

		void CsdsModel::ComputeNormals()
		{
			CV3 vVector1,vVector2,vNormal, vPoly[3];

			if(numOfObjects <=0)
				return;

			for(int index=0;index<numOfObjects;index++)
			{
				C3dsObject *pObj=&(pObject[index]);

				CV3 *pNormals=new CV3[pObj->numOfFaces];
				CV3 *pTempNormals=new CV3[pObj->numOfFaces];
				pObj->pNormals=new CV3[pObj->numOfVerts];

				//Go through all the faces of this object
				for(int i=0;i<pObj->numOfFaces;i++)
				{
					vPoly[0]=pObj->pVerts[pObj->pFaces[i].vertIndex[0]];
					vPoly[1]=pObj->pVerts[pObj->pFaces[i].vertIndex[1]];
					vPoly[2]=pObj->pVerts[pObj->pFaces[i].vertIndex[2]];

					vVector1=Vector(vPoly[0], vPoly[2]);
					vVector2=Vector(vPoly[2], vPoly[1]);
					vNormal=Cross(vVector1,vVector2);
					pTempNormals[i]=vNormal;
					vNormal=Normalize(vNormal);

					for(int i=0;i<pObj->numOfVerts;i++)
				{
					for(int j=0;j<pObj->numOfFaces;j++)
					{
						if(pObj ->pFaces[j].vertexIndex[0]==i ||
							pObj->pFaces[j].vertIndex[1]==i ||
							pObj->PFaces[j].vertexIndex[2]==i)
						{
							vSum=AddVector(vSum,pTempNormals[j]);
							shared++;
						}
					}

					pObj->pNormals[i]=DivideVectorByScalar(vSum, float(-shared)//code missing

						pObj->pNormals[i]=Normalize(pObj->pNormals[i]);
					vSum=vZero;
					shared=0;
					}
					//Free our memory and start over on the next object

					delete [] pTempNormals;
					delete [] pNormals;