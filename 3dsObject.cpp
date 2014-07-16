#include "stdafx.h"
#include  "3dsObject.h"
C3dsObject::C3dsObject(void)
{
	pVerts=NULL;        //The object's vertices
	pNormals=NULL;     //The object's normals
	pTexVerts=NULL;    //The textures's UV coordinates
	pFaces=NULL;      //The faces information of the object
}

C3dsObject::~C3dsObject(void)
{
}