
// ComputerGraphicsMFC2024View.cpp : implementation of the CComputerGraphicsMFC2024View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ComputerGraphicsMFC2024.h"
#endif

#include "ComputerGraphicsMFC2024Doc.h"
#include "ComputerGraphicsMFC2024View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComputerGraphicsMFC2024View

IMPLEMENT_DYNCREATE(CComputerGraphicsMFC2024View, CView)

BEGIN_MESSAGE_MAP(CComputerGraphicsMFC2024View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CComputerGraphicsMFC2024View construction/destruction

CComputerGraphicsMFC2024View::CComputerGraphicsMFC2024View() noexcept
{
	// TODO: add construction code here

}

CComputerGraphicsMFC2024View::~CComputerGraphicsMFC2024View()
{
}

BOOL CComputerGraphicsMFC2024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CComputerGraphicsMFC2024View drawing

void CComputerGraphicsMFC2024View::OnDraw(CDC* pDC)
{
	CComputerGraphicsMFC2024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	CRect rect;
	GetClientRect(rect);
	CString str;
	int w = rect.Width();
	int h = rect.Height();

	str.Format(_T("width: %d,height: %d\n"), w,h);
	OutputDebugString(str);

	// clear background to black
	COLORREF black = RGB(0, 0, 0);
	pDC->FillSolidRect(rect,black);

	COLORREF white = RGB(255, 255, 255);
	COLORREF red = RGB(255, 0, 0);
	pDC->SetPixel(10, 10, white);
	pDC->SetPixel(30, 30, red);

	POINT  P0 = { 50, 50 };
	POINT P1 = { 100, 100 };
	CPen whitePen(PS_SOLID,1,white);
	CPen redPen(PS_SOLID, 1, red);
	//pDC->SelectObject(&whitePen);
	pDC->SelectObject(&redPen);

	pDC->MoveTo(P0);
	pDC->LineTo(P1);

	CBrush redBrush(red);
	pDC->SelectObject(&redBrush);
	pDC->Rectangle(50,50,100,100);

	pDC->Ellipse(150,150,200,200);


}


// CComputerGraphicsMFC2024View printing

BOOL CComputerGraphicsMFC2024View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CComputerGraphicsMFC2024View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CComputerGraphicsMFC2024View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CComputerGraphicsMFC2024View diagnostics

#ifdef _DEBUG
void CComputerGraphicsMFC2024View::AssertValid() const
{
	CView::AssertValid();
}

void CComputerGraphicsMFC2024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComputerGraphicsMFC2024Doc* CComputerGraphicsMFC2024View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComputerGraphicsMFC2024Doc)));
	return (CComputerGraphicsMFC2024Doc*)m_pDocument;
}
#endif //_DEBUG


// CComputerGraphicsMFC2024View message handlers


void CComputerGraphicsMFC2024View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CView::OnLButtonDown(nFlags, point);
	// TODO: Add your message handler code here and/or call default

	
	this->P0 = point;
	this->isLBPressed = true;
	OutputDebugString(_T("left button down"));
	
}


void CComputerGraphicsMFC2024View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CView::OnLButtonUp(nFlags, point);
	// TODO: Add your message handler code here and/or call default

	
	this->isLBPressed = false;
	this->P1 = point;
	CDC * pDC = GetDC();
	pDC->SelectObject(new CPen(PS_SOLID,1,RGB(255,0,0)));
	pDC->MoveTo(P0);
	pDC->LineTo(P1);
	ReleaseDC(pDC);
	OutputDebugString(_T("left button up"));
	
}


void CComputerGraphicsMFC2024View::OnMove(int x, int y)
{
	CView::OnMove(x, y);

	// TODO: Add your message handler code here





}


void CComputerGraphicsMFC2024View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnMouseMove(nFlags, point);
	if (isLBPressed == true)
	{
		if (isNeedErase == true) {
			CDC *pDC = GetDC();
			pDC->SelectObject(new CPen(PS_SOLID, 1, RGB(0, 0, 0)));
			pDC->MoveTo(this->P0);
			pDC->LineTo(this->oldP1);
			ReleaseDC(pDC);
			this->isNeedErase = false;
		}
		this->moveP1 = point;
		CDC *pDC = GetDC();
		pDC->SelectObject(new CPen(PS_SOLID, 1, RGB(0, 255, 0)));
		pDC->MoveTo(this->P0);
		pDC->LineTo(this->moveP1);
		ReleaseDC(pDC);
		this->isNeedErase = true;
		this->oldP1 = moveP1;
		OutputDebugString(_T("mouse is moving\n"));
	
	}


}
