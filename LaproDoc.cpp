// LaproDoc.cpp : implementation of the CLaproDoc class
//

#include "stdafx.h"
#include "Lapro.h"

#include "LaproDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CLaproDoc

IMPLEMENT_DYNCREATE(CLaproDoc, CDocument)

	BEGIN_MESSAGE_MAP(CLaproDoc,CDocument)
		END_MESSAGE_MAP()

//CLaproDoc::CLaproDoc()
		{
			//No model has been loaded yet.
			m_currentModel=NULL;

			//m_fJawOpening=15.0;
			
			//m_currentModel=new CGripper;//C3dsModel
			//m_currentModel ->Import("models/toolcroc.3ds");
			//m_currentModel->Import();
			//m_currentModel->jawOpening=m_fJawOpening;
		}

		CLaproDoc:: ~CLaproDoc()
		{
			//If a model is currently loaded
			//delete it.
			if(m_currentModel != NULL)
				delete m_currentModel;
		}

		BOOL CLaproDoc:: OnNewDocument()
		{
			if(!CDocument::OnNewDocument())
				return FALSE;

			//TODO: add reinstallation code here
			//(SDI documents will reuse this document)
			//if a model is currently loaded
			//delete it.
			/* if(m_currentModel !=NULL)
			{
				delete m_currentModel;
				m_currentModel=Null;

			}
			*/
			return TRUE;

			//TODO: add sorting code here
		}
		else
		{
			//TODO: add loading code here
			}
			else
			{
				//TODO:add loading code here
				//Load the 3ds file.

				if(m_currentModel !=NULL}
				delete m_currentModel;

				//m_currentModel=new CGripper;//C3dsModel
				//m_currentModel ->Import();
				/* if(!m_currentModel->Import(ar))
				{
					MessageBox(NULL, "Not a valid md3 file !", File Error!",
					MB_OK | MB_ICONERROR);
					return;
					} */
				}
				}
				
				}

				//CLaproDoc diagnostics
#ifdef _DEBUG
				void CLaproDoc::AssertValid() const
				{
					CDocument::AssertValid();
				}

				void CLaproDoc::Dump(CDumpContext& dc) const
				{
					CDOcument::Dump(dc);
				}
#endif //_DEBUG

				//CLaproDoc commands

