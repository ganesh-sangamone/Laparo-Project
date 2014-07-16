#pragma once

class CPros
{
public:
	CPos(void);
	CPos(float xpos, float ypos, float zpos);
	CPos(float xpos, float ypos, float zpos, float hori, float pori, float //code missing

	void setPos(float xpos, float ypos, float zpos);
	void setPos(float xpos, float ypos, float zpos, float hori, float pori //code missing

		float dist(float x,float y, floatz);
	float dist(CPos position);



	~CPos(void);

	float x;
	float y;
	float z;
	float h;
	float p;
	float r;
private:
};