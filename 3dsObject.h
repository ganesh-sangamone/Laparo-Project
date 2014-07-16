#pragma once

class C3dsObject
{
public:
	C3dsObject(void);
	~C3dsObject(void);

	int numOfVerts;   //The number of verts in the model
	int numOfFaces;   //The number of faces in the model
	int numTextVertex; //The number of texture coordinates
	int materialID;    //The texture ID to use, which is the // Code missing
	//texture array
	bool bHasTexture;     //This is TRUE if there is a texture map object
	char strName[255];   //The name of the object
	CV3 *pVerts;        //The object's vertices
	CV3 *pNormals;        //The object's normals
	CV3 *pTexVerts;        //The textures UV coordinates
	tFace *pFaces;         //The faces information of the object
};


	