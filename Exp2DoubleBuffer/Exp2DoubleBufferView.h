
// Exp2DoubleBufferView.h : interface of the CExp2DoubleBufferView class
//

#pragma once
#include "MainFrm.h"

class CExp2DoubleBufferView : public CView
{
protected: // create from serialization only
	CExp2DoubleBufferView() noexcept;
	DECLARE_DYNCREATE(CExp2DoubleBufferView)

// Attributes
public:
	CExp2DoubleBufferDoc* GetDocument() const;

	//playing 
	bool isPlaying = false;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void BkOnDraw(CDC* bgCDC);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CExp2DoubleBufferView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer1s();
	afx_msg void OnTimer2s();
	afx_msg void OnTimer3s();
//	afx_msg void OnUpdateTimer1s(CCmdUI *pCmdUI);
//	afx_msg void OnUpdateTimer2s(CCmdUI *pCmdUI);
//	afx_msg void OnUpdateTimer3s(CCmdUI *pCmdUI);
	afx_msg void OnToolbarPlay();
	afx_msg void OnUpdateToolbarPlay(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in Exp2DoubleBufferView.cpp
inline CExp2DoubleBufferDoc* CExp2DoubleBufferView::GetDocument() const
   { return reinterpret_cast<CExp2DoubleBufferDoc*>(m_pDocument); }
#endif

