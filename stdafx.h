//stdafx.h :include file for standard system include files,
//or project specific include files that are used frequently,
//but are changed infrequently

#pragma once 

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN  //Exclude rarely-used stuff for Windows head //Missing code
#endif

//Modify the following defines if you have to target a platform prior to specified below.

//Refer to MSDN for the latest info on corresponding values for different..//Missing code

#ifndef WINVER  //Allow use of features specific to windows..//Missing code
Windows NT 4 or later.

#define WINVER 0x0400  //Change this to the appropriate value.//Missing code

#endif
#ifndef _WIN32_WINNT 

#define _WIN32_WINNT 0x0400
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0400
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTIONS
	// turns off MFC's hiding of some common and often safely ignored warning
#define _AFX_ALL_WARNINGS

#include <afxwin.h>
#include <afxext.h>
#include <afxdisp.h>

#include <afxdtctl.h>
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>
#endif //_AFX_NO_AFXCMN_SUPPORT

	/////opengl includes
#include <g1\g1.h>
#include <g1\glu.h>
#include <g1\glaux.h>
#include <gl\glut.h>

	////CG includes
#include <Cg/cg.h>
#include <Cg/cgGL.h>

	//////struct required by loaders

#define MAX_TEXTURES 100

class CV3
{
public:
	float x,y,z;
};

struct tFace
{
	int verIndex[3];
	int coordIndex[3];
};

struct tMaterialInfo
{
	char strName[255];
	char strFile[255];
	BYTE color[3];
	int textureId;
	float uTile;
	float vTile;
	float uOffset;
	float vOffset;
};

//read and interpret the driver bytes
typedef union
{
	unsigned short int i[5];
	unsigned char a[10];
}CHARTOSHORT;

#if defined(WIN32)
# include<windows.h>
#include <afxdb.h>
#include<afx.h>
# pragma warning (disable : 4786)
#endif


