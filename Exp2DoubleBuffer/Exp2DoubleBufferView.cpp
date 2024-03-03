
// Exp2DoubleBufferView.cpp : implementation of the CExp2DoubleBufferView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Exp2DoubleBuffer.h"
#endif

#include "Exp2DoubleBufferDoc.h"
#include "Exp2DoubleBufferView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp2DoubleBufferView

IMPLEMENT_DYNCREATE(CExp2DoubleBufferView, CView)

BEGIN_MESSAGE_MAP(CExp2DoubleBufferView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_COMMAND(ID_TIMER_1S, &CExp2DoubleBufferView::OnTimer1s)
	ON_COMMAND(ID_TIMER_2S, &CExp2DoubleBufferView::OnTimer2s)
	ON_COMMAND(ID_TIMER_3S, &CExp2DoubleBufferView::OnTimer3s)
//	ON_UPDATE_COMMAND_UI(ID_TIMER_1S, &CExp2DoubleBufferView::OnUpdateTimer1s)
//	ON_UPDATE_COMMAND_UI(ID_TIMER_2S, &CExp2DoubleBufferView::OnUpdateTimer2s)
//	ON_UPDATE_COMMAND_UI(ID_TIMER_3S, &CExp2DoubleBufferView::OnUpdateTimer3s)
ON_COMMAND(ID_Toolbar_Play, &CExp2DoubleBufferView::OnToolbarPlay)
ON_UPDATE_COMMAND_UI(ID_Toolbar_Play, &CExp2DoubleBufferView::OnUpdateToolbarPlay)
END_MESSAGE_MAP()

// CExp2DoubleBufferView construction/destruction

CExp2DoubleBufferView::CExp2DoubleBufferView() noexcept
{
	// TODO: add construction code here

	//this->SetTimer(1,3000,NULL);

}

CExp2DoubleBufferView::~CExp2DoubleBufferView()
{
}

BOOL CExp2DoubleBufferView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void CExp2DoubleBufferView::BkOnDraw(CDC * bgCDC)
{

	CDC* pDC = bgCDC;
	CRect rect;
	GetClientRect(rect);
	if (rand() % 2 == 0)
	{
		pDC->FillSolidRect(rect, RGB(0, 0, 0));
	}
	else {
		pDC->FillSolidRect(rect, RGB(255, 255, 255));
	}

	int red = rand() % 256;
	int green = rand() % 256;
	int blue = rand() % 256;
	CBrush whiteBrush(RGB(red, green, blue));
	pDC->SelectObject(whiteBrush);
	pDC->Ellipse(0, 0, 100, 100);
	pDC->Ellipse(100, 0, 200, 100);

	int cx = 300;
	int cy = 300;
	int r = 50;
	CPoint p0(cx - r, cy - r);
	CPoint p1(cx + r, cy + r);
	pDC->Ellipse(CRect(p0, p1));
}

// CExp2DoubleBufferView drawing

void CExp2DoubleBufferView::OnDraw(CDC* pDC)
{
	CExp2DoubleBufferDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	
	//this->BkOnDraw(pDC);


	// double buffer 
	CRect curRect;
	this->GetClientRect(curRect);
	int width = curRect.Width();
	int height = curRect.Height();

	CDC bgCDC;
	bgCDC.CreateCompatibleDC(pDC);
	CBitmap bgBitmap;
	CBitmap* pOldBitmap;
	bgBitmap.CreateCompatibleBitmap(pDC, width, height);
	pOldBitmap = bgCDC.SelectObject(&bgBitmap);

	this->BkOnDraw(&bgCDC);
	pDC->BitBlt(0,0,width,height,&bgCDC,0,0,SRCCOPY);


	// to avoid memory leak
	bgCDC.SelectObject(pOldBitmap);
	bgBitmap.DeleteObject();
	bgCDC.DeleteDC();
	




	

	OutputDebugString(_T("redraw the client region\n"));

	//OutputDebugString(_T("1ms\n"));


}


// CExp2DoubleBufferView printing

BOOL CExp2DoubleBufferView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExp2DoubleBufferView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExp2DoubleBufferView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CExp2DoubleBufferView diagnostics

#ifdef _DEBUG
void CExp2DoubleBufferView::AssertValid() const
{
	CView::AssertValid();
}

void CExp2DoubleBufferView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp2DoubleBufferDoc* CExp2DoubleBufferView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp2DoubleBufferDoc)));
	return (CExp2DoubleBufferDoc*)m_pDocument;
}
#endif //_DEBUG


// CExp2DoubleBufferView message handlers


void CExp2DoubleBufferView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	OutputDebugString(_T("3000ms\n"));
	// update sphere position 


	// tell client to repaint itself

	this->Invalidate();



	CView::OnTimer(nIDEvent);


}


int CExp2DoubleBufferView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	//this->SetTimer(1,3000,NULL);

	return 0;
}


void CExp2DoubleBufferView::OnTimer1s()
{
	// TODO: Add your command handler code here
	OutputDebugString(_T("1S timer\n"));
}


void CExp2DoubleBufferView::OnTimer2s()
{
	// TODO: Add your command handler code here
	OutputDebugString(_T("2S timer\n"));

}


void CExp2DoubleBufferView::OnTimer3s()
{
	// TODO: Add your command handler code here
	OutputDebugString(_T("3S timer\n"));
}


//void CExp2DoubleBufferView::OnUpdateTimer1s(CCmdUI *pCmdUI)
//{
//	// TODO: Add your command update UI handler code here
//}


//void CExp2DoubleBufferView::OnUpdateTimer2s(CCmdUI *pCmdUI)
//{
//	// TODO: Add your command update UI handler code here
//}


//void CExp2DoubleBufferView::OnUpdateTimer3s(CCmdUI *pCmdUI)
//{
//	// TODO: Add your command update UI handler code here
//}


void CExp2DoubleBufferView::OnToolbarPlay()
{
	// TODO: Add your command handler code here
	if (this->isPlaying == false) {
		this->isPlaying = true;
		this->SetTimer(1,200,NULL);
	}
		
	else {
		this->isPlaying = false;
		this->KillTimer(1);
	}
		

	CString str;
	str.Format(_T("this->isPlaying: %d"), this->isPlaying);
	OutputDebugString(str);
	OutputDebugString(_T("playing animation \n"));
}


void CExp2DoubleBufferView::OnUpdateToolbarPlay(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	if (isPlaying == true) {
		pCmdUI->SetCheck(TRUE);
		pMain->GetToolBar()->LoadBitmapW(IDB_BITMAP_PLAYING);
	}
	else {
		pCmdUI->SetCheck(FALSE);
		pMain->GetToolBar()->LoadBitmapW(IDB_BITMAP_STOPPING);
	}
	
	
}
