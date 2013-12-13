#if !defined(AFX_DOUBLEGAMEVIEW_H__A8A5B138_918E_4C49_8A75_699E550BFA1F__INCLUDED_)
#define AFX_DOUBLEGAMEVIEW_H__A8A5B138_918E_4C49_8A75_699E550BFA1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DoubleGameView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDoubleGameView view

class CDoubleGameView : public CView
{
protected:
	CDoubleGameView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDoubleGameView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDoubleGameView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDoubleGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDoubleGameView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOUBLEGAMEVIEW_H__A8A5B138_918E_4C49_8A75_699E550BFA1F__INCLUDED_)
