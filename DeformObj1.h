#pragma once
#include "3dsModel.h"

#include".../common/phy/ParticleSystem.h"
#include "Pos.h"

class CDeformObj1:
	public C3dsModel
{
	CDeformObj1(void);
	~CDeformObj1(void);

	bool Import();
	void renderModel(int ViewMode);
	//the ID of cavity texture
	int texID;

	void drawWireGrid(int rows, int cols);

	void render (void);
	void getExts(void);
	ParticleSystem *psys;
	vec3f spherePos;
	vec3f vert[2500];
	//int fc[2500][32];
	vec3f m_fc[80000];
	typedef struct {
		float ambient[3],diffuse[3],specular[3],exp;
	} BlinnProperties;

protected:

	GLboolean toggle[256];
	float m_fHookRadius;

public:
	bool initCG(void);
	///////////////////////////////////////////////////Particle system
public:

	void ParticleSystem(int nVert,int iterations);

	int GetWidth() {return m_w;};
	int GetHeight() { return m_h;}

	void SetSphere(vec3f pos);
	void InitCg();
	void InitGrid(vec3f start,vec3f du, vec3f dv);
	void InitGrid(vec3f *start);
	void TimeStep(float dt);
	void ReadBack();

	void Display();
	void DisplayShaded();
	void DrawQuad();
	void DrawImage();

	void DrawQuad(int w, int h);
	void DrawImage(int w, int h);
	//Display float texture using texturing

	void DisplayTexture(PBuffer *pbuffer, GLuint tex);

	CPos m_coll1, m_coll2;

	int m_w,m_h;   // size of grid
	int m_iterations

		vec3f *m_x, *m_c;
	float *m_debug;

	float m_damping;
	vec3f m_gravity;

	PBuffer *m_pbuffer[6];
	GLuint m_pbuffer_tex[5];
	PBuffer *m_normal_pbuffer;
	//PBuffer *m_cons_pbuffer;
	GLuint m_normal_pbuffer_tex;

	int m_current, m_previous, m_dest, m_ori,m_col,m_cons;
	GLuint m_cloth_tex;

	//fragment programs
	CGprogram m_fprog,m_fprog2, m_fprog3,m_copy_fprog;
	CGprogram m_passthru_fprog, m_normal_fprog, m_shader_fprog,m_shader_ //code missing

	//program parameters
	CGparameter m_x_tex_param,m_ox_tex_param;
	CGparameter m_orix_tex_param,m_colx_tex_param, m_cons_tex_param;
	CGparameter m_timestep_param,m_damping_param,m_gravity_param;

	CGparameter m_constraintDist_param,m_constraintDist3_param;
	CGparameter m_spherePos_param, m_spherePos3_param,m_sphereRadius_param //code missing
		m_sphereRadius3_param;

	CGparameter m_t1_param,m_t2_param,m_t3_param,m_t4_param,m_t5_param,m_t7_param,m_t8_param,m_t9_param;

	CGparameter m_P3t1_param,m_P3t2_param,m_P3t3_param,m_P3t4_param /*code missing*/,m_P3t5_param,m_P3t6_param,m_P3t7_param,m_P3t8_param,m_P3t9_param;

	CGparameter m_10_param,m_11_param,m_12_param,m_13_param;
	CGparameter m_14_param,m_15_param,m_16_param,m_17_param;

	CGparameter m_r0_param,m_r1_param,m_r2_param,m_r3_param;
	CGparameter m_r4_param,m_r5_param,m_r6_param,m_r7_param;
	CGparameter m_c1_param,m_c2_param,m_c3_param;
	CGparameter m_r4_param,m_r5_param,m_r6_param;

	CGparameter m_clip1_param,m_clip2_param,m_clip3_param;
	CGparameter m_clipIndex_param;

	CGparameter m_hookRadius_param, m_hookRadius3_param;
	CGparameter m_scale_param, m_bias_param;
	CGparameter m_burntX_param,m_burntY_param;

	void setClipCol(CPos t1, CPost2);
	void setGripperCubeLowerParam(CPos,CPos,CPos,CPos,CPos,CPos,CPos.//code missing
	void setGripperCubeTopJawParam(CPos,CPos,CPos,CPos,CPos,CPos,CPos//code missing

	void freezeObject(bool fr);
	void setBlinnProperties(CGparameter b, BlinnProperties &p);
	void loadCgPrograms1();
	UINT texID1[2];


	int clipStartPos[4], clipEndPos[4], clipCount[4], numClips;
	float clipTrans[4][2][3];
	int count[50];
	bool m_bEndOfEx;
	int m_nNS;
	CPos m_vClipTemp[9];
	float m_fvClipRot[5][2];

	protected:
		int once;
		CPos m_fSpPos;
		int m_nClipRegStart[4],m_nClipRegEnd[4];
		float m_vClip[3][27];
		int m_nClipIndex[3];

		public:
			bool m_bClipDeform;
			};





























