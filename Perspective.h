#pragma once
#include "OpenGLWnd.h"
#include "3dsModel.h"
//CPerspective view
//Implements COpenGLWnd to create a perspective viewport
class CPerspective:public COpenGLWnd
{
protected:
	CPerspective(); //protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPerspective)

	void getAngles(float xyz[], float &angx, float &angy);
	float sq(float number);
	float CosInverse(float cos_theta);
	bool m_bMakeSound;

//Attributes
public:
	float m_zoom,
		m_xpos,
	    m_ypos,
		m_xrot,  //x rotation
		m_yrot;  // y rotation

	float m_fCamZoom,
		  m_fCamXPos,
		  m_fCamYPos,
		  m_fCamXRot,
		  m_fCamYRot;

	int m_lastMouseX,
		m_lastMouseY;

	CPos spherePos;

	//Operations

public:
	//Overrides
	//ClassWizard generated virtual function overridees
protected:
	virtual void OnDraw(CDC*, pDC); //overridden to draw this view

//Implementation
protected:
	virtual ~CPerspective();
#ifdef _DEBUG
	virtual void AsserValid() const;

	//code may be missing"//
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);

	CToolBase *Tool; //for right and left tool movement interchange
	float m_fCameraPivotX;
	float m_fCameraPivotY;
	float m_fCameraPivotZ;
	bool moveCamera(void);
	float getDistance(float x1, float y1, float z1, float x2, float y2, float z2);
	bool m_bEnterKey;
	CString m_strVert;
};



