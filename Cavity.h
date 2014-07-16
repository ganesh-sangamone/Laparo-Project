#pragma once
#include "3dsModel.h"

class CCavity:
	public C3dsModel
{
public:
	CCavity(void);
	~CCavity(void);

	typedef struct {
		float ambient[3], diffuse[3], specular[3], exp;
	} BlinnProperties;

	//CGprogram cavityProg;
	CGparameter texParam;

	bool Import();
	void renderModel(int ViewMode);
	void loadCgPrograms1();
	void setBlinnProperties(CGparameter b, BlinnProperties &p);
	//the ID of cavity texture
	int texID;
};