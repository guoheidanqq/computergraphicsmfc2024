
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
	CPoint P0;
	CPoint P1;
	CPoint moveP1;
	bool isLBPressed = false;

	bool isNeedErase = false;
	CPoint oldP1;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ComputerGraphicsMFC2024View.cpp
inline CComputerGraphicsMFC2024Doc* CComputerGraphicsMFC2024View::GetDocument() const
   { return reinterpret_cast<CComputerGraphicsMFC2024Doc*>(m_pDocument); }
#endif

