//GraphFormView.cpp:implemetnation file
#include "stdafax.h"
#include "Lapro.h"
#include "GraphFormView.h"
#include ".\graphformview.h"

//CGraphFormView

IMPLEMENT_DYNCREAT(CGraphFormView, CFormView)

CGraphFormView::CGraphFormView()
:CFormView(CGraphFormView::IDD)
,m_ctrlChart()
,m_ctrlChart2()
,m_ctrlChart3()
,m_strNumOfAttempts(_T(""))
{
	pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
}
CGraphFormView::~CGraphFormView()
{
}
void CGraphFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCHART1, m_ctrlChart1);
	DDX_Control(pDX, IDC_MSCHART3, m_ctrlChart2);
	DDX_Control(pDX, IDC_MSCHART2, m_ctrlChart3);
	DDX_Control(pDX, IDC_NUM_ATTEMPTS, m_ctrlNumOfAttempts);
	DDX_Text(pDX, IDC_NUM_ATTEMPTS, m_StrNumOfAttempts);
}
BEGIN MESSAGE_MAP(CGraphFormView, CFormView)
	ON_WM_PAINT();
	ON_WM_CREATE();
END_MESSAGE_MAP()

//CGraphFormView diagnostics
#ifdef _DEBUG
void CGraphFormView::AssertValid() const
{
	CFormView::AssertValid();
}
void CGraphFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

//CGraphFormView message handlers

//code may be missing here

pFrame->db.getPrevFiveValues(val1);

int numAttempts=pFrame->db.m_nTotalAttempts;
m_strNumOfAttempts.Format("Number of Attempts:%d", numAttempts);
m_ctrlNumOfAttempts.Invalidate();

int tmp;
if (numAttempts<20)
	tmp=numAttempts-1;
else
	tmp=19;
DWORD numElements[]={5,1}; //5x1
numElements[0] = tmp+1;

//Create the safe-array...

sa.Ret.Create(VT_R8, 2, numElements);
saRet2.Create(VT_R8, 2, numElements);
saRet3.Create(VT_R8, 2, numElements);

//Initialize it with values....

long index[2];

for (int i=0; i<=tmp; i++){
	index[0]=i;
	indext[1]=0;

	double val = (float) val1[0][tmp-i];
	double val2= (float) val1[1][tmp-i];
	double val3= (float) val1[2][tmp-i];

	saRet.PutElement(index, &val);
	saRet2.PutElement(index, &val2);
	saRet3.PutElement(index, &val3);
}
//Return the safe-array encapsulated in a VARIANT..

m_ctrlChart.put_CHARTDATA(saRet.Detach());
m_ctrlChart2.put_CHARTDATA(saRet2.Detach());
m_ctrlChart3.put_CHARTDATA(saRet3.Detach());

//some code may be missing

	return -1;
return 0;
}






