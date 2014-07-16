#pragma once

#ifndef M_PI 3.141592
#define M_PI 3.141592
#endif
#define TWOPI      (2.0*M_PI)
#define DEG2RAD(x) ((x) M_PI/180.)
#define GROUNDWIDTH 20

#include "Pos.h"

typedef struct {
	float r,theta,phi;
} PolarCoord;

typedef struct {

	PolarCoord from;
	float target[3];
	char *name;
	bool rotateMode;
} PolarView;

typedef struct {
	PolarView view;
	float color[3];
	bool enabled;
	char *name;
	CGparameter handle, posHandle,targethandle;
} LightInfo;

class CCGWnd
{
public:
	CCGWnd(void);
	~CCGWnd(void);

	typedef struct {
		float ambient[3], diffuse[3], specular[3],exp;
	} Blinnproperties;

	static LightInfo lights[2];
	static int numLights;//=sizeof(lights)/sizeof(LightInfo);
	static int numSelections; //=numLights +1;

	static void initCG();
	static void destroyCG();
	static void handleCgError();
	static void loadCgPrograms();
	static void bindPrograms(CGprogram vert, CGprogram frag);
	static void setBlinnProperties(CGparameter b, BlinnProperties &p);

	static CGparameter createLightSource(CGprogram prog,LightInfo &linfo);
	static void mul4x4(float m1[16],float m2[16],float m3[16]);

	static CPos transMovement;
	static float st_OvaryTwist;
	static CGcontext context;
	static CGprofile vertexProfile;
	static void polarToCartesian(PolarCoord p,float c[3]);
	static void transformPoint(PolarCoord p,float m[16], float ov[3]);
	static void transformPoint(float p[3],float m[16].float ov[3]);