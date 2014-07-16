#include "StdAfx.h"
#include "pos.h"

CPos::CPos(void)
{
	x=0.0;
	y=0.0;
	z=0.0;
	h=0.0;
	p=0.0;
	r=0.0;
}

CPos::CPos(float xpos,float ypos, float zpos)
{
	x=xpos;
	y=ypos;
	z=zpos;
	h=0.0;
	p=0.0;
	r=0.0;
}

CPos::CPos(float xpos,float ypos, float zpos, float hori,float pori, //missing code
{
	x=xpos;
	y=ypos;
	z=zpos;
	h=hori;
	p=pori;
	r=rori;
}
CPos::~CPos(void)
{
}
CPos::CPos(float xpos,float ypos, float zpos)
{
	x=xpos;
	y=ypos;
	z=zpos;
	h=0.0;
	p=0.0;
	r=0.0;
}

CPos::CPos(float xpos,float ypos, float zpos, float hori,float pori, //missing code
{
	x=xpos;
	y=ypos;
	z=zpos;
	h=hori;
	p=pori;
	//missing code
}

float CPos::dist(CPos position)
{
	float distance=0.0;
	return distance;
}