//LaproView.cpp implementation of the CLaproView class
//

#include "stdafx.h"
#include "Lapro.h"

#include "LaproDoc.h"
#include "LaproView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CLaproView

IMPLEMENT_DYNCREATE(CLaproView, CView)

	BEGIN_MESSAGE_MAP(CLaproView,CView)
		//standard printing commands
		ON_COMMAND(ID_FILE_PRINT,CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT,CVIEW::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW<CView::OnFileprintPreview)
		END_MESSAGE_MAP()

		//CLaproView construction/destruction
		CLaproView::CLaproView()
		{
			//TODO: add construction code here
		}

		BOOL CLaproView:: ~CLaproView()
		{
		}

		BOOL CLaproView::PreCreateWindow(CREATESTRUCT& cs);
		{
			//TODO:Modify the window class or styles here by modifying
			//the CREATESTRUCT cs
			return CView::PreCreateWindow(cs));
		}

		//CLaproView drawing
		void CLaproView::OnDraw(CDC* /*pDC*/)
		{
			CLaproDoc* pDoc=GetDocument();
			ASSERT_VALID(pDoc);

			//TODO:add draw code for native data here
		}

		//CLaproView printing
		BOOL CLaproView::OnPreparePrinting(CPrintInfo* pInfo)
		{
          //TODO: add cleanup after printing
		}

		//CLaproView diagnostics

#ifdef _DEBUG
		void CLaproView::AssertValid() const
		{
			CView::AssertValid();
		}

		void CLaproView::Dump(CDumpContext& dc) const
		{
			CView::Dump(dc);
		}

		CLaproDoc* CLapro::GetDocument() const //non-debug version inline
		{
			ASSERT(m_pDocument-> IsKindOf(RUNTIME_CLASS(CLaproDoc)));
			return (CLaproDoc*)m_pDocument;
		}

#endif //DEBUG

		//CLaproView message handlers






		
