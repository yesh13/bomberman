// test1View.h : interface of the CTest1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1VIEW_H__D5A543B3_BF26_4D66_B394_FDD62F223EBE__INCLUDED_)
#define AFX_TEST1VIEW_H__D5A543B3_BF26_4D66_B394_FDD62F223EBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Character.h"

class CTest1View : public CView
{
protected: // create from serialization only
	CTest1View();
	DECLARE_DYNCREATE(CTest1View)

// Attributes
public:
	CTest1Doc* GetDocument();
	SYSTEMTIME m_temptime1,m_temptime2,m_temptime3;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest1View();
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
private:
	CBitmap m_GroundBMP;
	CBitmap m_MapBMP;
	void IconCopy(CBitmap *destBitmap,int destX,int destY,CBitmap *srcBitmap,int srcX=0,int srcY=40);
	void DrawRec(CDC *pDC,CBitmap *bmp,long x,long y);
	void DrawGround();
	void DrawMap();
	void DrawBlock(CDC* pDC,Block *pBlock);
	void DrawBomb(CDC* pDC);
	void DrawCharacter(CDC* pDC,Character *pCharcter);
	void DrawCharacterEdge(CDC *pDC,Character *pCharcter);
	void Redraw();
public:
	int dirta;
	void show();
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest1View)
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test1View.cpp
inline CTest1Doc* CTest1View::GetDocument()
   { return (CTest1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1VIEW_H__D5A543B3_BF26_4D66_B394_FDD62F223EBE__INCLUDED_)
