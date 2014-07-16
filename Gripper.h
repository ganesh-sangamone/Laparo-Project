#pragma once
#include "3dsmodel.h"

class CGripper:
	public C3dsModel
{
public:
	CGripper(void);
	~CGripper(void);

	bool CGripper::Import();
	void CGripper::renderModel(int ViewMode);
};