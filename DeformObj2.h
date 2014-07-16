#pragma once
#include "3dsModel.h"

#include "../common/phy/ParticleSystem.h"
#include "Pos.h"

class CDeformObj2:
	public C3dsModel
{
public:
	CDeformObj2(void);
	~CDeformObj2(void);

	bool Import();
	void renderModel(int ViewMode);
	//the ID od cavity texture
	int texID;

	void drawWireGrid(int rows, int cols);

	void render(void);
	void getExts(void);
	ParticleSystem *psys;
	vec3f spherePos;
	vec3f vert[2500];

	typedef struct {
		float ambient[3], diffuse[3], specular[3], exp;
	} BlinnProperties;

protected:
	GLboolean toggle[256];
	float m_fHookRadius;

public:
	void ParticleSystem(int nVert, int iterations);

	int GetWidth() {return m_w;}
	int GetHeight() {return m_h;}

	void SetSphere(vec3f pos);
	void Initcg();
	void InitGrid(vec3f start, vec3f du, vec3f dv);
	void InitGrid(vec3f *start)
		void TimeStep(float dt);
	void ReadBack();
	void Display();
	void DisplayShaded();

	//display float texture using texturing
	void DisplayTexture(PBuffer *pbuffer,GLuint tex);

	int m_w,m_h;
	int m_iterations;
	vec *m_x,**m_c;
	float m_damping;
	vec3f m_gravity;

	PBuffer *m_pbuffer[5];
	GLuint m_pbuffer_tex[5];
	PBuffer *m_normal_pbuffer;
	GLuint m_normal_pbuffer_tex;

	int m_current, m_previous, m_dest, m_ori, m_col;
	GLuint m_cloth_tex;

	//fragment programs

	CGprogram m_fprog,m_fprog2, m_fprog3,m_copypassthru_fprog;
	CGprogram m_passthru_fprog,m_normal_fprog,m_shader_fprog,m_shader//code missing

		//program parameters
		CGparameter m_x_tex_param, m_ox_tex_param;
	CGparameter m_orix_tex_param,m_colx_tex_param;
	CGparameter m_timestep_param, m_damping_param, m_gravity_param;

	CGparameter m_constraintDist_param,m_constraint_Dist3_param;
	CGparameter m_SpherePos_param,m_spherePos3_param,m_P3t4_param,m//code missing
		m_SphereRadius3_param;

	CGparameter m_t1_param,m_t2_param,m_t3_param,m_t4,m_t5_param//code missing
	CGparameter m_P3t1_param,m_P3t2_param,m_P3t3_param,m_P3t4,//code missing
	CGparameter m_10_param,m_11_param,m_12_param,m_13_param;
	CGparameter m_14_param,m_15_param,m_16_param,m_17_param;

	CGparameter m_r0_param,m_r1_param,m_r2_param,m_r3_param;
	CGparameter m_r4_param,m_r5_param,m_r6_param,m_r7_param;

	CGparameter m_hookRadius_param,m_hookradius3_param;
	CGparameter m_scale_param, m_bias_param;

	CGCGparameter m_burntX_param, m_burntY_param;

	CGparameter m_modelViewProj_param, m_modelView_param, m_modelViewInv_//code missing

		//RenderableVertexArray *m_vertexArray;
		short *m_indices;
	int m_nindices;
	bool m_freeze;

public:
	void setGripperParam(CPos t1, CPost2, CPos t3);
	void setHookParam(CPos t1, CPos t2, CPos t3, CPos t4, CPos t5, float//code missing
	void setGripperCubeLowerJawParam(CPos,CPos,CPos,CPos,CPos,CPos//code missing
	void freezeObject(bool fr);

