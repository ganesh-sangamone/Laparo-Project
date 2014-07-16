#include "StdAfx.h"
#include "CGWnd.h"
#include <assert.h>
#include <math.h>

float CCGWnd::st_OvaryTwist;
CPos CCGWnd::transMovement;

CGcontext CCGWnd:: context;
CGprofile CCGWnd::vertexProfile;
CGprofile CCGWnd::fragmentProfile;
CGprogram CCGWnd::vertexProg;
CGprogram CCGWnd::lightProg;
CGprogram CCGWnd::teapotProg;
CGprogram CCGWnd::cystProg;
CGprogram CCGWnd::groundProg;
CGprogram CCGWnd::jawProg;
CGprogram CCGWnd::sqlProg;
CGprogram CCGWnd::stoneHighProg;
CGprogram CCGWnd::stoneProg;
CGprogram CCGWnd::sq2Prog;
CGprogram CCGWnd::sqHighProg;
CGprogram CCGWnd::sqSelProg;
CGprogram CCGWnd::toolProg;
CGprogram CCGWnd::cavityProg;
CGprogram CCGWnd::ductProg;
CGprogram CCGWnd::cylProg;
CGprogram CCGWnd::omentumProg;

CGparameter CCGWnd:: lArray;
CGparameter CCGWnd::texParam;
CGparameter CCGWnd:: texParam1;

LightInfo CCGWnd::lights[2];
int CCGWnd::numLights; //=sizeof(lights)/sizeof(LightInfo);
int CCGWnd::numSelections;//=numLights +1;

CCGWnd::CCGWnd(void)
{
}
CCGWnd::~CCGWnd(void)
{
}
void CCGWnd::CCGWnd(void)
{
	cgSetErrorCallback(handleCgError);
	context=cgCreateContext();

	vertexProfile=cgGLGetLatestProfile(CG_GL_VERTEX);
	fragmentProfile=cgGLGetLatestProfile(CG_GL_FRAGMENT);

	LightInfo lights1[]={
		//{{{200,DEG2RAD( 0),DEG2RAD(0)},{0,0,0},"Sport"},{1.0,1.0,1.0},"SpotLight"},
		{{{200,DEG2RAD(0),DEG2RAD(60)},{0,0,0},"Point"}, {.8,.8,.8},"PointLight"}
	}



	void CCGWnd::destroyCG(void)
	{
		cgDestroyProgram(vertexProg);
		cgDestroyProgram(lightProg);
		cgDestroyProgram(teapotProg);
		cgDestroyProgram(toolProg);
		cgDestroyProgram(groundProg);
		cgDestroyProgram(sqlProg);
		cgDestroyProgram(sq2Prog);
		cgDestroyProgram(sqHighProg);
		cgDestroyProgram(sqSelProg);
		cgDestroyProgram(stoneHighProg);
		cgDestroyProgram(stoneProg);
		cgDestroyProgram(omentumProg);
		
		cgDestroyContext(context);




	}

	void CCGWnd::handleCgError()
	{
		CGerror err=cgGetError();
		TRACE("Cg error: %s\n",cgGetErrorString (err));
		if(err==1)
      TRACE("last listing:\n%s\n", cgGetLastListing(context));
		//fflush(stderr);
		AfxMessageBox(cgGetErrorString(err));
		if(err==1)
	AfxMessageBox(cgGetLastListing(context));
		exit(2);
	}
	void CCGWnd::bindPrograms(CGprogram vert, CGprogram frag)
	{
		CGparameter param;
		cgGLEnableProfile(vertexProfile);
		cgGLEnableProfile(fragmentProfile);
		cgGLBindProgram(vert);
		cgGLBindProgram(frag);
		param=cgGetNamedProgramParameter(vert, CG_Program,"ModelView");

		cgGlSetStateMatrixParameter(param, CG_GL_MODELVIEW_MATRIX,CG_GL_MATRIX_IDENTITY);

		param=cgGetNamedProgramParameter(vert,CG_PROGRAM,"ModelViewIT");
		cgGLSetStateMatrixParameter(param, CG_GL_MODELVIEW_MATRIX,CG_GL_MATRIX_INVERSE_TRANSPOSE);
		param=cgGetNamedProgramParameter(vert, CG_Program,"ModelViewProj")
		cgGLSetStateMatrixParameter(param, CG GL MODELVIEW PROJECTION MATRIX,// PART OF CODE MISSING

		BlinnProperties cystproperties={
			{.5,.5,.05},{.6,.8,.4},{1.0,1.0,1.0},100.};
		BlinnProperties sqHighProperties={
			{1.0,1.0,.0},{1.0,1.0,.0},{1.0,1.0,.0},100.};

		BlinnProperties omentumProperties={{.4,.3,.0},{.8,.7,.0},{1.0,1.0,.0},10.};

		BlinnProperties stoneHighProperties ={
			{.4,.4,.4},{.7,.7,.7},{.4,.4,.4},80.};

		BlinnProperties stoneProperties={
			{1.0,1.0,.0},{1.0,1.0,.0},{1.0,1.0,.0},100};

		BlinnProperties sqSelProperties={{.0,.5,.5},{.0,.6,.6},{.0,.9,.9},100.};

		BlinnProperties sq1Properties ={
			{.9,.0,.0},{.9,.0,.0},{.9,.0,.0},100.};

		BlinnProperties sq2Properties ={
			{.0,.0,.9},{.0,.0,.9},{.0,.0,.9},100.};

		BlinnProperties jawProperties={{.5,.5,.5},{.8,.8,.8},{.4,.4,.4},10.};

		BlinnProperties toolProperties={
			{.05,.05,.05},{.2,.2,.2},{.8,.8,.8},20.};

		BlinnProperties cavityProperties={{.05,.05,.05},{.8,.2,.2},{.8,.8,.8},20.};

		BlinnProperties brightProperties ={
			{.05,.05,.05},{1.9,1.9,1.9},{.1,.1,.1},20.};

		BlinnProperties darkProperties ={
			{0.05,.05,.05},{.1,.1,.1},{.4,.4,.4},40.};

			//create and wireup a handful of programs.
			CGparameter param;
			assert(cgIsContext(context));

			//First, create programs that don't make use
			//of shared instances, and thus can be compiled

			lightProg=cgCreateProgramFromFile(context,CG_SOURCE,"constant.cg"fragmentProfile,"main",NULL);
			assert(lightProg);
			//printProg(lightProg);
			CgGLLoadProgram(lightProg);

			//Next, create shared instances and the programs that use them.

			//Turn on manual compilation so the runtime won't try to compile
			//incomplete programs.
			cgSetAutoCompile(context, CG_COMPILE_MANUAL);

			//create teapot fragment program
			teapotProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain"// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			CGparameter metal= cgCreateParmeter(context,cgGetNamedUserType(//code missing
            "Blinn"));
			setBlinnProperties(metal,teapotProperties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(teapot /*missing code */ CG_PROGRAM,"material"));

			/////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//create teapot fragment program
			stoneProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain"// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType(stoneProg//code missing
				 setBlinnProperties(metal,stoneProperties);
            
			
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(stonePro /*missing code */ ,"material"));
			//////////////////////////////////////////////////////////////////////////////////////////////////
			// Create teapot fragment program

			cystProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType( cystProg,
            "Blinn"//code missing));
			setBlinnProperties(metal,cystProperties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(cystprog /*missing code */ ,"material"));

			////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Create teapot fragment program
			stoneHighProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType( stoneHighProg,
            //code missing));
			setBlinnProperties(metal,stoneHighProperties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(omentum /*missing code */CG_PROGRAM ,"material"));

			//////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////
			//Create teapot fragment program
			sq1Prog=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType( sq1Prog,
            "Blinn"//code missing));
			setBlinnProperties(metal,sq1Properties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(sq1Prog /*missing code */ ,"material"));
			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////////////////////////////
			//Create teapot fragment program
			sq2Prog=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType( sq2Prog,
            "Blinn"//code missing));
			setBlinnProperties(metal,sq2Properties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(sq2prog /*missing code */ ,"material"));
			///////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Create teapot fragment program
			sqHighProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType( sqHighProg,
            "Blinn"//code missing));
			setBlinnProperties(metal,sqHighProperties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(sqHighProg /*missing code */  CG_PROG,"material"));

			///////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Create teapot fragment program
			sqSelProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create metal material for teapot.
			 metal= cgCreateParmeter(context,cgGetNamedUserType( sqSelProg,
            "Blinn"//code missing));
			setBlinnProperties(metal,sqSelProperties);
			//connect material parameter of teapot program to metal material

			cgConnectParameter(metal,param=cgGetNamedProgramParameter(sqSelProg /*missing code */ ,"material"));
			
////////////////////////////////////////////////////////////////////////////////////////////
			
			//Create teapot fragment program
			toolProg=cgCreateProgramFromFile(context, CG_SOURCE,"materialmain."// Missing code
				fragmentProfile,"main",NULL);
			//create checker material
			CGparameter checker= cgCreateParmeter(context,cgGetNamedUserType( teapotProg,
            "Checker"//code missing));
			param=cgGetNamedStructParameter(checker,"csize");
			cgSetParameter1f(param,1.);
			//if(literalMode)
			cgSetParameterVariability(param, CG_LITERAL);

			param=cgGetNamedStructParameter(checker,"mats");
			setBlinnProperties(cgGetArrayParameter(param,0), brightProperties);
			setBlinnProperties(cgGetArrayParameter(param,1), darkProperties);

			//Associate checker material with material parameter of ground prog
			cgConnectParameter(checker,cgGetNamedProgramParameter(groundProg,CG //code missing
				"material"));

			//Next, create shared sources
			//Get type handles from any program that includes the appropriate type definition.

			lArray=cgCreateParameterArray(context,cgGetNamedUserType(teapotPro//Missing Prog
				numLights);

			for(i=0;i<numLights;i++)
				//We pass teapotProg here, but could pass any program(compiled uncompiled) whose

				//source define the types.

				lights[i].handle= createLightSource(teapotProg, lights[i]);
			if(lights[i].handle==0)
				exit(2);
			cgConnectParameter(lights[i].handle, cgArrayParameter(lArray,
}

//connect the light source array to each material.

cgConnectParameter(lArray, cgGetNamedProgramParameter(teapotProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(cystProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(groundProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(toolProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(sq1Prog,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(sq2tProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(sqHighProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(sqSelProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(stoneHighProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(stoneProg,CG_/*code Missing*/ "lights"));
cgConnectParameter(lArray, cgGetNamedProgramParameter(omentumProg,CG_/*code Missing*/ "lights"));

 cgCompileProgram(sq2Prog);
 cgCompileProgram(sqHighProg);
 cgCompileProgram(sqSelProg);
 cgCompileProgram(stoneHighProg);
 cgCompileProgram(stoneProg);
 cgCompileProgram(omentumProg);

 cgGLLoadProgram(teapotProg);
 cgGLLoadProgram(cystProg);
 cgGLLoadProgram(toolProg);
 cgGLLoadProgram(groundProg);
 cgGLLoadProgram(sq1Prog);
 cgGLLoadProgram(sq2Prog);
 cgGLLoadProgram(sqHighProg);
 cgGLLoadProgram(sqSelProg);
 cgGLLoadProgram(stoneHighProg);
 cgGLLoadProgram(stoneProg);
 cgGLLoadProgram(omentumProg);
 }

 void CCGWnd:: setBlinnProperties(CGparameter b, BlinnProperties &p)
 {
    cgSetParameter3fv(cgGetNamedStructParameter(b,"ambient"),p.ambient);
	cgSetParameter3fv(cgGetNamedStructParameter(b,"diffuse"),p.diffuse);
	cgSetParameter3fv(cgGetNamedStructParameter(b,"specular"),p.specular);
	cgSetParameter1f(cgGetNamedStructParameter(b,"sexp"),p.exp);
// if(literalMode)
	cgSetParameterVariability(b,CG_LITERAL);
}

 CGparameter CCGWnd::createLightSource(CGprogram prog, LightInfo &linfo)
 {
	 //Get handle to user-defined type
	 CGtype lightType= cgGetNamedUserType(prog, linfo.name);
	 //create parameter of that type
	 CGparameter light= cgCreateParameter(context, lightType);
	 if(light==0)
		 return 0;
	 //Stash handles to position, target parameters
	 linfo.posHandle=cgGetNamedStructParameter(light,"Plight");
	 linfo.targetHandle= cgGetNamedStructParameter(light,"Clight");
	 //Set light color

	 CGparameter param = cgGetNamedStructParameter(light"Clight");
	 if(param==0)
		 return 0;
	 cgSetParameter3fv(param, linfo.color);
	 //if(literalMode)

	 cgSetParameterVariability(param, CG_LITERAL);
	 return light;
 }

 void CCGWnd::polarToCartesian(PolarCoord p, float c[3]);
 {
	 c[0]=p.r*sin(p.phi)*sin(p.theta);
	 c[1]=p.r*sin(p.phi)*cos(p.theta);
	 c[2]=p.r*cos(p.phi);
 }

 void CCGWnd::transformPoint(float p[3], float m[16], float ov[3])
 {
	 float c[3];
	 polarToCartesian(p,c);
	 transformPoint(c,m,ov);
 }

 void CCGWnd::updateLights(void);
 {
	 float modelViewMat[16], lightPosEye[3], lightTargetEye[3];
	 glGetFloatv(GL_MODELVIEW_MATRIX,modelViewMat);
	 //Compute eye-space coords of each light source's
	 //position and (if applicable) target
	 for(int i=0;i<numLights;i++)
	 {
		 CCGWnd::transformPoint(lights[i].view.target, modelViewMat, light //code missing
		  cgSetParameter3fv(lights[i].posHandle,lightposEye);
		 if(lights[i].targetHandle) {
			 CCGWnd::transformPoint(lights[i].view.from,modelViewMat,//code missing
cgSetParameter3fv(lights[i].targetHandle,lightTargetEye);
		 }
	 }


	 for(int i=0;i<numLights;i++) {
		 CCGWnd::transformPoint(lights[i].view.from, modelViewMat, //code missing
			  cgSetParameter3fv(lights[i].posHandle,lightposEye);
		 if(lights[i].targetHandle) {
			 CCGWnd::transformPoint(lights[i].view.target , modelViewMat,lightTargetEye);
cgSetParameter3fv(lights[i].targetHandle,lightTargetEye);
		 }
	 }
 }

 void CCGWnd::toggleLight(int which)
 {
	 lights[which].enabled=!lights[which].enabled;
	 CGparameter param= cgGetNamedStructParameter(lights[which].handle,// code missing
		 cgSetParameter1f(param, lights[which].enabled ? 1.f:0.f);
 }

 void CCGWnd ::mul4x4(float m1[16], float m2[16], float m3[16]) {
	 m3[0]= m1[0] *m2[0] + m1[1]*m2[4]+ m1[2]*m2[8]+m1[3]*m2[12];
	 m3[1]= m1[0] *m2[1] + m1[1]*m2[5]+ m1[2]*m2[9]+m1[3]*m2[13];
	 m3[2]= m1[0] *m2[2] + m1[1]*m2[6]+ m1[2]*m2[10]+m1[3]*m2[14];
	 m3[3]= m1[0] *m2[3] + m1[1]*m2[7]+ m1[2]*m2[11]+m1[3]*m2[15];
	 m3[4]= m1[0] *m2[0] + m1[5]*m2[4]+ m1[6]*m2[8]+m1[7]*m2[12];
	 m3[5]= m1[0] *m2[1] + m1[5]*m2[5]+ m1[6]*m2[9]+m1[7]*m2[13];
	 m3[6]= m1[0] *m2[2] + m1[5]*m2[6]+ m1[6]*m2[10]+m1[7]*m2[14];
	 m3[7]= m1[0] *m2[3] + m1[5]*m2[7]+ m1[6]*m2[11]+m1[7]*m2[15];
	 m3[8]= m1[0] *m2[0] + m1[9]*m2[4]+ m1[10]*m2[8]+m1[11]*m2[12];
	 m3[9]= m1[0] *m2[1] + m1[9]*m2[5]+ m1[10]*m2[9]+m1[11]*m2[13];
	 m3[10]= m1[0] *m2[2] + m1[9]*m2[6]+ m1[10]*m2[10]+m1[11]*m2[14];
	 m3[11]= m1[0] *m2[3] + m1[9]*m2[7]+ m1[10]*m2[11]+m1[11]*m2[15];
	 m3[12]= m1[0] *m2[0] + m1[13]*m2[4]+ m1[14]*m2[8]+m1[15]*m2[12];
	 m3[13]= m1[0] *m2[1] + m1[13]*m2[5]+ m1[14]*m2[9]+m1[15]*m2[13];
	 m3[14]= m1[0] *m2[2] + m1[13]*m2[6]+ m1[14]*m2[10]+m1[15]*m2[14];
	 m3[15]= m1[0] *m2[3] + m1[13]*m2[7]+ m1[14]*m2[11]+m1[15]*m2[15];