#pragma once
#include "3dsModel.h"
#include ".../Common/phy/ParticleSystem.h"

class CCloth:
	public C3dsModel
{
public:
	CCloth(void);
	~CCloth(void);
	void CCloth::drawWireGrid(int rows, int cols);
	void render(void);
	void getExts(void);
	ParticleSystem *psys;
	vec3f spherePos;
protected:
	GLboolean toggle[256];

public:
	bool initCG(void);
	void setGripperParam(CPos t1,CPos t2, CPos t3);
	void setHookParam(CPos t1,CPos t2, CPos t3,CPos t4,CPos t5, float//code missing
	void setGripperCubeLowerJawParam(CPos ,CPos , CPos,CPos ,CPos , CPos,CPos //code missing
	void setGripperCubeTopJawParam(CPos ,CPos , CPos,CPos ,CPos , CPos,CPos //code missing
	void resetEx(void);
	bool m_EndOfEx;
	bool m_fExcessBurn;
	bool m_bFootSwitchPressed;
	int m_nNS;
};