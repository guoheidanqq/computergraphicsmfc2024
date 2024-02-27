
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

void CComputerGraphicsMFC2024View::OnDraw(CDC* /*pDC*/)
{
	CComputerGraphicsMFC2024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
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
