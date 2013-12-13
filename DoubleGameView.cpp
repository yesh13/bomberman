// DoubleGameView.cpp : implementation file
//

#include "stdafx.h"
#include "test1.h"
#include "DoubleGameView.h"
#include "test1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CDoubleGameView

IMPLEMENT_DYNCREATE(CDoubleGameView, CView)

CDoubleGameView::CDoubleGameView()
{
}

CDoubleGameView::~CDoubleGameView()
{
}


BEGIN_MESSAGE_MAP(CDoubleGameView, CView)
	//{{AFX_MSG_MAP(CDoubleGameView)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDoubleGameView drawing

void CDoubleGameView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CDoubleGameView diagnostics

#ifdef _DEBUG
void CDoubleGameView::AssertValid() const
{
	CView::AssertValid();
}

void CDoubleGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDoubleGameView message handlers

//////////////////////////////////////////////////////////////////////////
//Key
void CDoubleGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CTest1Doc *pDoc=(CTest1Doc *)GetDocument();

	if(nChar==pDoc->keyset.DP1up)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_UP);
	else if(nChar==pDoc->keyset.DP1down)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_DOWN);
	else if(nChar==pDoc->keyset.DP1left)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_LEFT);
	else if(nChar==pDoc->keyset.DP1right)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_RIGHT);

	else if(nChar==pDoc->keyset.DP1bomb)
		pDoc->mainset->Player1->Dropbomb();
	else if(nChar==pDoc->keyset.DP1skill)
		;

	else if(nChar==pDoc->keyset.DP2up)
		 pDoc->mainset->Player2->OnKeyDown(MyDrctn_UP);
	else if(nChar==pDoc->keyset.DP2down)
		pDoc->mainset->Player2->OnKeyDown(MyDrctn_DOWN);
	else if(nChar==pDoc->keyset.DP2left)
		pDoc->mainset->Player2->OnKeyDown(MyDrctn_LEFT);
	else if(nChar==pDoc->keyset.DP2right)
		pDoc->mainset->Player2->OnKeyDown(MyDrctn_RIGHT);

	else if(nChar==pDoc->keyset.DP2bomb)
		pDoc->mainset->Player2->Dropbomb();
	else if(nChar==pDoc->keyset.DP2skill)
		;

		else ;

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDoubleGameView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CTest1Doc *pDoc=(CTest1Doc *)GetDocument();

	if(nChar==pDoc->keyset.DP1up)
		pDoc->mainset->Player1->OnKeyUp(MyDrctn_UP);
	else if(nChar==pDoc->keyset.DP1down)
		pDoc->mainset->Player1->OnKeyUp(MyDrctn_DOWN);
	else if(nChar==pDoc->keyset.DP1left)
		pDoc->mainset->Player1->OnKeyUp(MyDrctn_LEFT);
	else if(nChar==pDoc->keyset.DP1right)
		pDoc->mainset->Player1->OnKeyUp(MyDrctn_RIGHT);
	
	else if(nChar==pDoc->keyset.DP2up)
		pDoc->mainset->Player2->OnKeyUp(MyDrctn_UP);
	else if(nChar==pDoc->keyset.DP2down)
		pDoc->mainset->Player2->OnKeyUp(MyDrctn_DOWN);
	else if(nChar==pDoc->keyset.DP2left)
		pDoc->mainset->Player2->OnKeyUp(MyDrctn_LEFT);
	else if(nChar==pDoc->keyset.DP2right)
		pDoc->mainset->Player2->OnKeyUp(MyDrctn_RIGHT);
			
	else ;

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
