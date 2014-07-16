#pragma once

//>---Primary Chunk, at the beginning of each file
#define PRIMARY      0x4D4D

//>------Main Chunks
#define OBJECTINFO   0x3D3D

#define VERSION      0x0002
#define EDITKEYFRAME 0xB000

//>-------sub defines of OBJECTINFO
#define MATERIAL     0xAFFF
#define OBJECT       0x4000

//>--sub defines of MATERIAL

#define MATNAME      0xA000
#define MATDIFFUSE   0xA020

#define MATMAP		 0xA200
#define MATMAPFILE   0xA300

#define OBJECT_MESH  0x4100

//>------sub defines of OBJECT_MESH
#define OBJECT_VERTICES  0x4100
#define OBJECT_FACES     0x4120
#define OBJECT_MATERIAL  0x4130
#define OBJECT_UV        0x4140

//#include "LaproDoc.h"

#include <math.h>
#include "3dsModel.h"
#include <vector>

using namespace std;
/*
struct t3DObject
{
	int numOfVerts;
	int numOfFaces;
	int numTexVertex;
	int materialID;
	bool bHastexture;
	char strName[255];
	CVector3 *pVerts;
	CVector3 *pNormals;
	CVector2 *pTexVerts;
	tFace *pFaces;

	};

	*/
unsigned short int ID;
unsigned int length;
unsigned int bytesRead;
};

class C3dsModel
{
public:
	C3dsModel(void);
	~C3dsModel(void);

	//This is the function that you call to load the 3DS

	bool Import(char *strFileName);
	virtual bool Import(void);
	bool Import(CArchive ar);

public: /////Attributes

	int numOfObjects;
	int nVert;
	int numOfMaterials;
	vector<tMaterialInfo> pMaterials;
	UINT g_Texture[100]; //[MAX_TEXTURES]={0};

	static float jawOpening;
	static float rightGripperOpening;
	static bool isRightGripperOpen;
	//inline CLaproDoc* GetDocument() const
	//{ return reinterpret_cast<CLaproDoc*>(m_pDocument);}

protected:
	////reads the texture file  into a texture array
	void CreateTexture(UINT textureArray[], LPSTR strFileName, int texture //missing code

		//This reads in a string and saves it in the char array passed in 
		int GetString(char *);

	//This reads the next chunk
	void ReadChunk(tChunk *);


	//This reads the next large chunk
	void ProcessNextChunk(tChunk *);

	//This reads the object chunks
	void ProcessNextObjectChunk(tChunk *)'

		//This reads the RGB value for the object's color
		void ReadColorChunk(tMaterialInfo *pMaterial, tChunk * pChunk);
	
	//This reads the objects vertices
	void ReadVertices(C3dsObject *pObject, tChunk*);

	//This reads the objects face information
	//Code missing

	//This frees memory and closes the file
	void CleanUp();
	//The file pointer
	FILE *m_FilePointer;

public:
	//Renders the model
	virtual void renderModel(int ViewMode);
};