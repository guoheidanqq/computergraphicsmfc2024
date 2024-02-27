
// ComputerGraphicsMFC2024View.h : interface of the CComputerGraphicsMFC2024View class
//

#pragma once


class CComputerGraphicsMFC2024View : public CView
{
protected: // create from serialization only
	CComputerGraphicsMFC2024View() noexcept;
	DECLARE_DYNCREATE(CComputerGraphicsMFC2024View)

// Attributes
public:
	CComputerGraphicsMFC2024Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CComputerGraphicsMFC2024View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ComputerGraphicsMFC2024View.cpp
inline CComputerGraphicsMFC2024Doc* CComputerGraphicsMFC2024View::GetDocument() const
   { return reinterpret_cast<CComputerGraphicsMFC2024Doc*>(m_pDocument); }
#endif

