
// ComputerGraphicsMFC2024Doc.cpp : implementation of the CComputerGraphicsMFC2024Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ComputerGraphicsMFC2024.h"
#endif

#include "ComputerGraphicsMFC2024Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CComputerGraphicsMFC2024Doc

IMPLEMENT_DYNCREATE(CComputerGraphicsMFC2024Doc, CDocument)

BEGIN_MESSAGE_MAP(CComputerGraphicsMFC2024Doc, CDocument)
END_MESSAGE_MAP()


// CComputerGraphicsMFC2024Doc construction/destruction

CComputerGraphicsMFC2024Doc::CComputerGraphicsMFC2024Doc() noexcept
{
	// TODO: add one-time construction code here

}

CComputerGraphicsMFC2024Doc::~CComputerGraphicsMFC2024Doc()
{
}

BOOL CComputerGraphicsMFC2024Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CComputerGraphicsMFC2024Doc serialization

void CComputerGraphicsMFC2024Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CComputerGraphicsMFC2024Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CComputerGraphicsMFC2024Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CComputerGraphicsMFC2024Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CComputerGraphicsMFC2024Doc diagnostics

#ifdef _DEBUG
void CComputerGraphicsMFC2024Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CComputerGraphicsMFC2024Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CComputerGraphicsMFC2024Doc commands
