// test1View.cpp : implementation of the CTest1View class
//

#include "stdafx.h"
#include "test1.h"

#include "test1Doc.h"
#include "test1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1View

IMPLEMENT_DYNCREATE(CTest1View, CView)
BEGIN_MESSAGE_MAP(CTest1View, CView)
	//{{AFX_MSG_MAP(CTest1View)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1View construction/destruction

CTest1View::CTest1View()
{
	// TODO: add construction code here
	dirta=5;
}

CTest1View::~CTest1View()
{
}

BOOL CTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View drawing

void CTest1View::OnDraw(CDC* pDC)
{
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	Redraw();
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(m_MapBMP);
	pDC->BitBlt(0,0,680,680,&dc,0,0,SRCCOPY);
	CBitmap BoxBMP;//ÍÆµÃÊ±ºòÓÃÀ´»­Ïä×Ó
	CBitmap BlockBMP;

	CBitmap MaskBMP;
	CDC BlockDC,MaskDC;
	BlockDC.CreateCompatibleDC(pDC);
	MaskDC.CreateCompatibleDC(pDC);
	MaskBMP.CreateBitmap(50,80,1,1,NULL);
	MaskDC.SelectObject(&MaskBMP);

	DrawBomb(pDC);


	if (!pDoc->mainset->Player1->IsPushing())
	{
		DrawCharacterEdge(pDC,pDoc->mainset->Player1);
	} 
	else
	{
		BoxBMP.LoadBitmap(GetResID(BMP_BOX));
		switch(pDoc->mainset->Player1->m_picturestate/6)
		{
		case 1:
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player1->GetCoordinate().x,
				pDoc->mainset->Player1->GetCoordinate().y-40);
			DrawCharacterEdge(pDC,pDoc->mainset->Player1);
			break;
		case 3:
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player1->GetCoordinate().x-40,
				pDoc->mainset->Player1->GetCoordinate().y);
			DrawCharacterEdge(pDC,pDoc->mainset->Player1);
			break;
		case 4:
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player1->GetCoordinate().x+40,
				pDoc->mainset->Player1->GetCoordinate().y);
			DrawCharacterEdge(pDC,pDoc->mainset->Player1);
			break;
		case 2:
			DrawCharacterEdge(pDC,pDoc->mainset->Player1);
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player1->GetCoordinate().x,
				pDoc->mainset->Player1->GetCoordinate().y+40);
			break;
		}
		BoxBMP.DeleteObject();
	}
	if (!pDoc->mainset->Player2->IsPushing())
	{
		DrawCharacterEdge(pDC,pDoc->mainset->Player2);
	} 
	else
	{
		BoxBMP.LoadBitmap(GetResID(	BMP_BOX ));
		switch(pDoc->mainset->Player2->m_picturestate/6)
		{
		case 1:
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player2->GetCoordinate().x,
				pDoc->mainset->Player2->GetCoordinate().y-40);
			DrawCharacterEdge(pDC,pDoc->mainset->Player2);
			break;
		case 3:
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player2->GetCoordinate().x-40,
				pDoc->mainset->Player2->GetCoordinate().y);
			DrawCharacterEdge(pDC,pDoc->mainset->Player2);
			break;
		case 4:
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player2->GetCoordinate().x+40,
				pDoc->mainset->Player2->GetCoordinate().y);
			DrawCharacterEdge(pDC,pDoc->mainset->Player2);
			break;
		case 2:
			DrawCharacterEdge(pDC,pDoc->mainset->Player2);
			DrawRec(pDC,&BoxBMP,pDoc->mainset->Player2->GetCoordinate().x,
				pDoc->mainset->Player2->GetCoordinate().y+40);
			break;
		}
		BoxBMP.DeleteObject();
	}
	BlockDC.DeleteDC();
	MaskDC.DeleteDC();
	MaskBMP.DeleteObject();
	dc.DeleteDC();
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View printing

BOOL CTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View diagnostics

#ifdef _DEBUG
void CTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1Doc* CTest1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1Doc)));
	return (CTest1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1View message handlers

void CTest1View::OnDestroy() 
{
	CView::OnDestroy();
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	// TODO: Add your message handler code here
}

void CTest1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTest1Doc* pDoc = GetDocument();
	int i,j;
	switch(nIDEvent)
	{
	case 1:
		pDoc->mainset->Player1->Run();
		pDoc->mainset->Player2->Run();
		for (i=1;i<pDoc->mainset->dim-1;i++)
		for (j=1;j<pDoc->mainset->dim-1;j++)
		{
			pDoc->mainset->pBlock[i][j]->bomb.OnTime();
		}
		{
/*			CString cs;CPoint point1=pDoc->mainset->Player1->GetCoordinate();
			cs.Format("%d %d\n",point1.x,point1.y);
			TRACE(cs);
*/		}
		break;
	case 2:show();break;	
	case 3: GetDocument()->mainset->Player2->OnTime();break;
	}
	CView::OnTimer(nIDEvent);
}

int CTest1View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
		SetTimer(1,30,NULL);
		SetTimer(2,30,NULL);//fps
		SetTimer(3,50,NULL);
	m_GroundBMP.CreateCompatibleBitmap(&CClientDC(this),680,680);
	DrawGround();
	m_MapBMP.CreateCompatibleBitmap(&CClientDC(this),680,680);
	DrawMap();
	return 0;
}

void CTest1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CTest1Doc* pDoc = GetDocument();

	if(nChar==pDoc->keyset.DP1up)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_UP);
	else if(nChar==pDoc->keyset.DP1down)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_DOWN);
	else if(nChar==pDoc->keyset.DP1left)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_LEFT);
	else if(nChar==pDoc->keyset.DP1right)
		pDoc->mainset->Player1->OnKeyDown(MyDrctn_RIGHT);

	else if(GetAsyncKeyState(pDoc->keyset.DP1bomb)&0xffff0000==0xffff0000)
		pDoc->mainset->Player1->Dropbomb();
	else if(GetAsyncKeyState(pDoc->keyset.DP1skill)&0xffff0000==0xffff0000)
		;

	else if(nChar==pDoc->keyset.DP2up)
		 pDoc->mainset->Player2->OnKeyDown(MyDrctn_UP);
	else if(nChar==pDoc->keyset.DP2down)
		pDoc->mainset->Player2->OnKeyDown(MyDrctn_DOWN);
	else if(nChar==pDoc->keyset.DP2left)
		pDoc->mainset->Player2->OnKeyDown(MyDrctn_LEFT);
	else if(nChar==pDoc->keyset.DP2right)
		pDoc->mainset->Player2->OnKeyDown(MyDrctn_RIGHT);
	
	else if(GetAsyncKeyState(pDoc->keyset.DP2bomb)&0xffff0000==0xffff0000)
		pDoc->mainset->Player2->Dropbomb();
	else if(GetAsyncKeyState(pDoc->keyset.DP2skill)&0xffff0000==0xffff0000)
		;


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTest1View::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CTest1Doc* pDoc = GetDocument();

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

void CTest1View::OnPaint() 
{
	CPaintDC dc(this);
	
	// Do not call CView::OnPaint() for painting messages
}
void CTest1View::show()
{
	CClientDC DC(this); // device context for painting
	//DO: Add your message handler code here
	CDC dcmem;
	CBitmap bmpmem;
	CRect rect; 
	GetClientRect(&rect);
/*
	DC.SetStretchBltMode(HALFTONE);
	DC.SetMapMode(MM_ANISOTROPIC);
	DC.SetWindowExt(700,700);
	DC.SetViewportExt(rect.Width(),rect.Height());*/

	dcmem.CreateCompatibleDC(&DC);
	bmpmem.CreateCompatibleBitmap(&DC,1000,1000);
	dcmem.SelectObject(&bmpmem);
	dcmem.FillSolidRect(0,0,1000,1000,DC.GetBkColor());
	OnDraw(&dcmem);

	DC.BitBlt(0,0,1000,1000,&dcmem,0,0,SRCCOPY);
	dcmem.DeleteDC();
	bmpmem.DeleteObject();

}


BOOL CTest1View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return 1;
	return CView::OnEraseBkgnd(pDC);
}

//////////////////////////////////////////////////////////////////////////
//IconCopy
void CTest1View::IconCopy(CBitmap *destBitmap,int destX,int destY,CBitmap *srcBitmap,int srcX/* =0 */,int srcY/* =40 */)
{
	CDC *pDC=GetDC();
	CDC destDC,srcDC;
	destDC.CreateCompatibleDC(pDC);
	srcDC.CreateCompatibleDC(pDC);
	CBitmap *oldDestBitmap=destDC.SelectObject(destBitmap);
	CBitmap *oldSrcBitmap=srcDC.SelectObject(srcBitmap);

	destDC.SelectObject(oldDestBitmap);
	srcDC.SelectObject(oldSrcBitmap);
	destDC.DeleteDC();
	srcDC.DeleteDC();
	ReleaseDC(pDC);
}
//////////////////////////////////////////////////////////////////////////
//»æÖÆµØÃæ
void CTest1View::DrawGround()
{
	int i,j;
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC *pDC=GetDC();
	CDC GroundDC,IconDC;//´ý»æÖÆDC£¬·½¿éDC
	CBitmap IconBMP;//ÓÃÓÚÁÙÊ±ÔØÈëBMP
	GroundDC.CreateCompatibleDC(pDC);
	IconDC.CreateCompatibleDC(pDC);
	CBitmap *oldGroundBitmap=GroundDC.SelectObject(&m_GroundBMP);
	CBitmap *oldIconBitmap=IconDC.SelectObject(&IconBMP);
	for(i=1;i<pDoc->mainset->dim-1;i++)
	for(j=1;j<pDoc->mainset->dim-1;j++)
	{
		IconBMP.LoadBitmap(GetResID(pDoc->m_CurrentMap.GetPicture(i,j,1)));
		IconDC.SelectObject(&IconBMP);
		GroundDC.BitBlt(i*SLENGTH,j*SLENGTH,40,40,&IconDC,0,0,SRCCOPY);
		IconBMP.DeleteObject();	
	}
	//Ñ¡»Øbmp
	IconDC.SelectObject(oldIconBitmap);
	GroundDC.SelectObject(oldGroundBitmap);
	IconDC.DeleteDC();
	GroundDC.DeleteDC();
	ReleaseDC(pDC);
}
//////////////////////////////////////////////////////////////////////////
//»æÖÆµØÍ¼
void CTest1View::DrawMap()
{
	int i,j;
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC *pDC=GetDC();
	CDC MapDC;//´ý»æÖÆDC
	MapDC.CreateCompatibleDC(pDC);
	CBitmap BlockBMP,MaskBMP;
	CDC BlockDC,MaskDC;
	BlockDC.CreateCompatibleDC(pDC);
	MaskDC.CreateCompatibleDC(pDC);
	MaskBMP.CreateBitmap(40,80,1,1,NULL);
	MaskDC.SelectObject(&MaskBMP);
	CBitmap *oldMapBMP=MapDC.SelectObject(&m_MapBMP);
	CDC GroundDC;
	GroundDC.CreateCompatibleDC(pDC);
	GroundDC.SelectObject(m_GroundBMP);
	MapDC.BitBlt(0,0,680,680,&GroundDC,0,0,SRCCOPY);
	GroundDC.DeleteDC();
	for(j=0;j<pDoc->mainset->dim;j++)
		for(i=0;i<pDoc->mainset->dim;i++)
		{
			BlockBMP.LoadBitmap(GetResID(pDoc->m_CurrentMap.GetPicture(i,j)));
			BlockDC.SelectObject(&BlockBMP);
			//ÂÖÀª
			BlockDC.SetBkColor(RGB(255,255,255));
			MaskDC.BitBlt(0,0,40,80,&BlockDC,0,0,SRCCOPY);
			//±³¾°ÖÐÍÚÈ¥ÂÖÀª
			MapDC.SetBkColor(RGB(255,255,255));
			MapDC.SetTextColor(RGB(0,0,0));
			MapDC.BitBlt(i*SLENGTH,j*SLENGTH-40,40,80,&MaskDC,0,0,SRCAND);
			//BlockDC±³¾°Í¿ºÚ
			BlockDC.SetBkColor(RGB(0,0,0));
			BlockDC.SetTextColor(RGB(255,255,255));
			BlockDC.BitBlt(0,0,40,80,&MaskDC,0,0,SRCAND);
			//Á½Í¼Æ¬Õ³Ìù
			MapDC.BitBlt(i*SLENGTH,j*SLENGTH-40,40,80,&BlockDC,0,0,SRCPAINT);
			BlockBMP.DeleteObject();
		}
	MapDC.SelectObject(oldMapBMP);
	ReleaseDC(pDC);
	MapDC.DeleteDC();
	BlockDC.DeleteDC();
	MaskDC.DeleteDC();
	MaskBMP.DeleteObject();
	BlockBMP.DeleteObject();
}
//////////////////////////////////////////////////////////////////////////
//»æÖÆÈË
void CTest1View::DrawCharacter(CDC* pDC,Character *pCharacter)
{
	CPoint cp;
	cp.y=pCharacter->GetCoordinate().y%SLENGTH+SLENGTH;
	if ((pCharacter->GetCoordinate().x%SLENGTH<=5)||(pCharacter->GetCoordinate().x%SLENGTH>=SLENGTH-5))//»­3x4
	{
		cp.x=SLENGTH-pCharacter->GetPosition().x*SLENGTH+pCharacter->GetCoordinate().x;
	}
	else
	{
		cp.x=pCharacter->GetCoordinate().x%SLENGTH;
	}
	CBitmap ChBMP,ChMaskBMP;
	CDC ChDC,ChMaskDC;
	ChDC.CreateCompatibleDC(pDC);
	ChMaskDC.CreateCompatibleDC(pDC);
	ChMaskBMP.CreateBitmap(50,60,1,1,NULL);
	ChMaskDC.SelectObject(&ChMaskBMP);
	//½ÇÉ«1
	ChBMP.LoadBitmap(GetResID(	BMP_CHARACTER|
								(pCharacter->CharacterType<<8)|
								pCharacter->m_picturestate));

	ChDC.SelectObject(ChBMP);
	//ÂÖÀª
	ChDC.SetBkColor(RGB(255,255,255));
	ChMaskDC.BitBlt(0,0,50,60,&ChDC,0,0,SRCCOPY);
	//±³¾°ÖÐÍÚÈ¥ÂÖÀª
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetTextColor(RGB(0,0,0));
	pDC->BitBlt(cp.x-4,cp.y-26,50,60,&ChMaskDC,0,0,SRCAND);
	//ChDC±³¾°Í¿ºÚ
	ChDC.SetBkColor(RGB(0,0,0));
	ChDC.SetTextColor(RGB(255,255,255));
	ChDC.BitBlt(0,0,50,60,&ChMaskDC,0,0,SRCAND);
	//Á½Í¼Æ¬Õ³Ìù
	pDC->BitBlt(cp.x-4,cp.y-26,50,60,&ChDC,0,0,SRCPAINT);
	ChBMP.DeleteObject();

	ChDC.DeleteDC();
	ChMaskDC.DeleteDC();
	ChMaskBMP.DeleteObject();
	//Í·ÉÏ±êÊ¶
	CFont   font;   
	CFont   *poldFont;   
	font.CreateFont(20,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,   
		CLIP_DEFAULT_PRECIS,   DEFAULT_QUALITY,DEFAULT_PITCH   |   FF_SWISS,"Arial");         
	poldFont=pDC->SelectObject(&font);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(50,50,50));
	pDC->DrawText(pCharacter->m_Name,&CRect(cp.x,cp.y-43,cp.x+40,cp.y-23),DT_CENTER);
	pDC->SelectObject(poldFont);
	font.DeleteObject();	
}
void CTest1View::DrawCharacterEdge(CDC *pDC,Character *pCharacter)
{
	CTest1Doc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	int i,j;
	CDC ChEdDC;CBitmap ChEdBMP;
	CDC EdMaskDC;CBitmap EdMaskBMP;
	if ((pCharacter->GetCoordinate().x%SLENGTH<=5)||(pCharacter->GetCoordinate().x%SLENGTH>=SLENGTH-5))//»­3x4
	{
		ChEdDC.CreateCompatibleDC(pDC);
		ChEdBMP.CreateCompatibleBitmap(pDC,SLENGTH*3,SLENGTH*4);
		ChEdDC.SelectObject(&ChEdBMP);
		ChEdDC.BitBlt(0,0,SLENGTH*3,SLENGTH*4,&ChEdDC,0,0,NOTSRCCOPY);//ÑÕÉ«¸ÄÎª°×É«
		CBitmap BlockBMP,MaskBMP;
		CDC BlockDC,MaskDC;
		BlockDC.CreateCompatibleDC(pDC);
		MaskDC.CreateCompatibleDC(pDC);
		MaskBMP.CreateBitmap(40,80,1,1,NULL);
		MaskDC.SelectObject(&MaskBMP);
		for (j=0;j<4;j++)
		{
			for (i=0;i<3;i++)
			{
				if (pCharacter->GetCoordinate().y/SLENGTH-1+j>=pDoc->mainset->dim)
				{
					BlockBMP.LoadBitmap(GetResID(BMP_BLANK));
				}
				else
				BlockBMP.LoadBitmap(GetResID(pDoc->mainset->pBlock[pCharacter->GetPosition().x-1+i]
														[pCharacter->GetCoordinate().y/SLENGTH-1+j]->PictureParameter()));
				BlockDC.SelectObject(&BlockBMP);
				//ÂÖÀª
				BlockDC.SetBkColor(RGB(255,255,255));
				MaskDC.BitBlt(0,0,40,80,&BlockDC,0,0,SRCCOPY);
				//±³¾°ÖÐÍÚÈ¥ÂÖÀª
				ChEdDC.SetBkColor(RGB(255,255,255));
				ChEdDC.SetTextColor(RGB(0,0,0));
				ChEdDC.BitBlt(i*SLENGTH,j*SLENGTH-40,40,80,&MaskDC,0,0,SRCAND);
				//BlockDC±³¾°Í¿ºÚ
				BlockDC.SetBkColor(RGB(0,0,0));
				BlockDC.SetTextColor(RGB(255,255,255));
				BlockDC.BitBlt(0,0,40,80,&MaskDC,0,0,SRCAND);
				//Á½Í¼Æ¬Õ³Ìù
				ChEdDC.BitBlt(i*SLENGTH,j*SLENGTH-40,40,80,&BlockDC,0,0,SRCPAINT);
				BlockBMP.DeleteObject();	
			}
			//»­ÈË
			if (pCharacter->GetCoordinate().y%SLENGTH==0)
			{
				if (j==1)
				{
					DrawCharacter(&ChEdDC,pCharacter);
				}
			}
			else
				if (j==2)
				{
					DrawCharacter(&ChEdDC,pCharacter);
				}
		}

		//Õ³Ìùµ½pDCÉÏ
		EdMaskBMP.CreateBitmap(SLENGTH*3,SLENGTH*4,1,1,NULL);
		EdMaskDC.CreateCompatibleDC(pDC);
		EdMaskDC.SelectObject(&EdMaskBMP);
		//ÂÖÀª
		ChEdDC.SetBkColor(RGB(255,255,255));
		EdMaskDC.BitBlt(0,0,SLENGTH*3,SLENGTH*3,&ChEdDC,0,0,SRCCOPY);
		//±³¾°ÖÐÍÚÈ¥ÂÖÀª
		pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor(RGB(0,0,0));
		pDC->BitBlt(pCharacter->GetPosition().x*SLENGTH-SLENGTH,pCharacter->GetCoordinate().y/SLENGTH*SLENGTH-SLENGTH,
					SLENGTH*3,SLENGTH*3,&EdMaskDC,0,0,SRCAND);
		//ChEdDC±³¾°Í¿ºÚ
		ChEdDC.SetBkColor(RGB(0,0,0));
		ChEdDC.SetTextColor(RGB(255,255,255));
		ChEdDC.BitBlt(0,0,SLENGTH*3,SLENGTH*3,&EdMaskDC,0,0,SRCAND);
		//Á½Í¼Æ¬Õ³Ìù
		pDC->BitBlt(pCharacter->GetPosition().x*SLENGTH-SLENGTH,
			pCharacter->GetCoordinate().y/SLENGTH*SLENGTH-SLENGTH,
			SLENGTH*3,SLENGTH*3,&ChEdDC,0,0,SRCPAINT);

	}
	else//»­2x4
	{
		ChEdDC.CreateCompatibleDC(pDC);
		ChEdBMP.CreateCompatibleBitmap(pDC,SLENGTH*2,SLENGTH*4);
		ChEdDC.SelectObject(ChEdBMP);
		ChEdDC.BitBlt(0,0,SLENGTH*2,SLENGTH*4,&ChEdDC,0,0,NOTSRCCOPY);//ÑÕÉ«¸ÄÎª°×É«
		CBitmap BlockBMP,MaskBMP;
		CDC BlockDC,MaskDC;
		BlockDC.CreateCompatibleDC(pDC);
		MaskDC.CreateCompatibleDC(pDC);
		MaskBMP.CreateBitmap(40,80,1,1,NULL);
		MaskDC.SelectObject(&MaskBMP);
		for (j=0;j<4;j++)
		for (i=0;i<2;i++)
		{
			if (pCharacter->GetCoordinate().y/SLENGTH-1+j>=pDoc->mainset->dim)
			{
				BlockBMP.LoadBitmap(GetResID(BMP_BLANK));
			}
			else
			BlockBMP.LoadBitmap(GetResID(pDoc->mainset->pBlock[pCharacter->GetCoordinate().x/SLENGTH+i]
													[pCharacter->GetCoordinate().y/SLENGTH-1+j]->PictureParameter()));
			BlockDC.SelectObject(&BlockBMP);
			//ÂÖÀª
			BlockDC.SetBkColor(RGB(255,255,255));
			MaskDC.BitBlt(0,0,40,80,&BlockDC,0,0,SRCCOPY);
			//±³¾°ÖÐÍÚÈ¥ÂÖÀª
			ChEdDC.SetBkColor(RGB(255,255,255));
			ChEdDC.SetTextColor(RGB(0,0,0));
			ChEdDC.BitBlt(i*SLENGTH,j*SLENGTH-40,40,80,&MaskDC,0,0,SRCAND);
			//BlockDC±³¾°Í¿ºÚ
			BlockDC.SetBkColor(RGB(0,0,0));
			BlockDC.SetTextColor(RGB(255,255,255));
			BlockDC.BitBlt(0,0,40,80,&MaskDC,0,0,SRCAND);
			//Á½Í¼Æ¬Õ³Ìù
			ChEdDC.BitBlt(i*SLENGTH,j*SLENGTH-40,40,80,&BlockDC,0,0,SRCPAINT);
			BlockBMP.DeleteObject();
			//»­ÈË
			if (pCharacter->GetCoordinate().y%SLENGTH==0)
			{
				if (j==1)
				{
					DrawCharacter(&ChEdDC,pCharacter);
				}
			}
			else
				if (j==2)
				{
					DrawCharacter(&ChEdDC,pCharacter);
				}
		}
		BlockDC.DeleteDC();
		MaskDC.DeleteDC();
		MaskBMP.DeleteObject();
		//Õ³Ìùµ½pDCÉÏ
		EdMaskBMP.CreateBitmap(SLENGTH*2,SLENGTH*3,1,1,NULL);
		EdMaskDC.CreateCompatibleDC(pDC);
		EdMaskDC.SelectObject(&EdMaskBMP);
		//ÂÖÀª
		ChEdDC.SetBkColor(RGB(255,255,255));
		EdMaskDC.BitBlt(0,0,SLENGTH*2,SLENGTH*3,&ChEdDC,0,0,SRCCOPY);
		//±³¾°ÖÐÍÚÈ¥ÂÖÀª
		pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor(RGB(0,0,0));
		pDC->BitBlt(pCharacter->GetCoordinate().x/SLENGTH*SLENGTH,
			pCharacter->GetCoordinate().y/SLENGTH*SLENGTH-SLENGTH,
			SLENGTH*2,SLENGTH*3,&EdMaskDC,0,0,SRCAND);
		//ChEdDC±³¾°Í¿ºÚ
		ChEdDC.SetBkColor(RGB(0,0,0));
		ChEdDC.SetTextColor(RGB(255,255,255));
		ChEdDC.BitBlt(0,0,SLENGTH*2,SLENGTH*3,&EdMaskDC,0,0,SRCAND);
		//Á½Í¼Æ¬Õ³Ìù
		pDC->BitBlt(pCharacter->GetCoordinate().x/SLENGTH*SLENGTH,
			pCharacter->GetCoordinate().y/SLENGTH*SLENGTH-SLENGTH,
			SLENGTH*2,SLENGTH*3,&ChEdDC,0,0,SRCPAINT);

	}
}
//////////////////////////////////////////////////////////////////////////
//Í¸Ã÷´¦Àíº¯Êý ¸¨Öú»æÖÆBlock
void CTest1View::DrawRec(CDC *pDC,CBitmap *bmp,long x,long y)
{
	CBitmap MaskBMP;
	CDC dc,MaskDC;
	dc.CreateCompatibleDC(pDC);
	MaskDC.CreateCompatibleDC(pDC);
	MaskBMP.CreateBitmap(40,80,1,1,NULL);
	MaskDC.SelectObject(&MaskBMP);

	dc.SelectObject(bmp);
	//ÂÖÀª
	dc.SetBkColor(RGB(255,255,255));
	MaskDC.BitBlt(0,0,40,80,&dc,0,0,SRCCOPY);
	//±³¾°ÖÐÍÚÈ¥ÂÖÀª
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetTextColor(RGB(0,0,0));
	pDC->BitBlt(x,y-40,40,80,&MaskDC,0,0,SRCAND);
	//dc±³¾°Í¿ºÚ
	dc.SetBkColor(RGB(0,0,0));
	dc.SetTextColor(RGB(255,255,255));
	dc.BitBlt(0,0,40,80,&MaskDC,0,0,SRCAND);
	//Á½Í¼Æ¬Õ³Ìù
	pDC->BitBlt(x,y-40,40,80,&dc,0,0,SRCPAINT);
	
	dc.DeleteDC();
	MaskDC.DeleteDC();
	MaskBMP.DeleteObject();
	
}
//////////////////////////////////////////////////////////////////////////
//»æÖÆµØ¿é
void CTest1View::DrawBlock(CDC* pDC,Block *pBlock)
{
	CBitmap bmp;
	DrawRec(pDC,&bmp,0,0);
	bmp.DeleteObject();
}
//////////////////////////////////////////////////////////////////////////
//»­Õ¨µ¯
void CTest1View::DrawBomb(CDC* pDC)
{
	CTest1Doc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CDC BombDC;CBitmap BombBMP;
	CDC MaskDC;CBitmap MaskBMP;
	BombDC.CreateCompatibleDC(pDC);
	MaskDC.CreateCompatibleDC(pDC);
	MaskBMP.CreateBitmap(50,60,1,1,NULL);
	MaskDC.SelectObject(&MaskBMP);
	int i,j;
	for (i=1;i<pDoc->mainset->dim-1;i++)
	for (j=1;j<pDoc->mainset->dim-1;j++)
	{
		if (pDoc->mainset->pBlock[i][j]->OccupybyBomb)
		{
			BombBMP.LoadBitmap(GetResID(pDoc->mainset->pBlock[i][j]->BombPicture()|BMP_BOMB));
			BombDC.SelectObject(&BombBMP);
			//ÂÖÀª
			BombDC.SetBkColor(RGB(255,255,255));
			MaskDC.BitBlt(0,0,50,60,&BombDC,0,0,SRCCOPY);
			//±³¾°ÖÐÍÚÈ¥ÂÖÀª
			pDC->SetBkColor(RGB(255,255,255));
			pDC->SetTextColor(RGB(0,0,0));
			pDC->BitBlt(i*SLENGTH-5,j*SLENGTH-20,50,60,&MaskDC,0,0,SRCAND);
			//dc±³¾°Í¿ºÚ
			BombDC.SetBkColor(RGB(0,0,0));
			BombDC.SetTextColor(RGB(255,255,255));
			BombDC.BitBlt(0,0,50,60,&MaskDC,0,0,SRCAND);
			//Á½Í¼Æ¬Õ³Ìù
			pDC->BitBlt(i*SLENGTH-5,j*SLENGTH-20,50,60,&BombDC,0,0,SRCPAINT);
			BombBMP.DeleteObject();
			BombBMP.LoadBitmap(GetResID(pDoc->mainset->pBlock[i][j+1]->PictureParameter()));
			BombDC.SelectObject(&BombBMP);
			//ÂÖÀª
			BombDC.SetBkColor(RGB(255,255,255));
			MaskDC.BitBlt(0,0,50,60,&BombDC,0,0,SRCCOPY);
			//±³¾°ÖÐÍÚÈ¥ÂÖÀª
			pDC->SetBkColor(RGB(255,255,255));
			pDC->SetTextColor(RGB(0,0,0));
			pDC->BitBlt(i*SLENGTH,j*SLENGTH,40,40,&MaskDC,0,0,SRCAND);
			//dc±³¾°Í¿ºÚ
			BombDC.SetBkColor(RGB(0,0,0));
			BombDC.SetTextColor(RGB(255,255,255));
			BombDC.BitBlt(0,0,50,60,&MaskDC,0,0,SRCAND);
			//Á½Í¼Æ¬Õ³Ìù
			pDC->BitBlt(i*SLENGTH,j*SLENGTH,40,40,&BombDC,0,0,SRCPAINT);
			BombBMP.DeleteObject();
		}
	}
	BombDC.DeleteDC();
	MaskDC.DeleteDC();
	MaskBMP.DeleteObject();
}
//////////////////////////////////////////////////////////////////////////
//ÖØ»­µØÍ¼
void CTest1View::Redraw()
{
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->mainset->m_RedrawDeque.empty()) return;
	CPoint cp;
	CDC *pDC=GetDC();
	CDC MapDC;//´ý»æÖÆDC
	MapDC.CreateCompatibleDC(pDC);
	CBitmap BlockBMP,MaskBMP;
	CDC BlockDC,MaskDC;
	CDC ChEdDC;CBitmap ChEdBMP;
	CDC EdMaskDC;CBitmap EdMaskBMP;
	
	ChEdDC.CreateCompatibleDC(pDC);
	BlockDC.CreateCompatibleDC(pDC);
	MaskDC.CreateCompatibleDC(pDC);
	MaskBMP.CreateBitmap(40,80,1,1,NULL);
	MaskDC.SelectObject(&MaskBMP);
	CBitmap *oldMapBMP=MapDC.SelectObject(&m_MapBMP);

	EdMaskBMP.CreateBitmap(SLENGTH,SLENGTH*3,1,1,NULL);
	EdMaskDC.CreateCompatibleDC(pDC);
	EdMaskDC.SelectObject(&EdMaskBMP);
	while(!pDoc->mainset->m_RedrawDeque.empty())
	{
		ChEdBMP.CreateCompatibleBitmap(pDC,SLENGTH,SLENGTH*3);
		ChEdDC.SelectObject(&ChEdBMP);
		ChEdDC.BitBlt(0,0,SLENGTH,SLENGTH*3,&ChEdDC,0,0,NOTSRCCOPY);//ÑÕÉ«¸ÄÎª°×É«

		cp=pDoc->mainset->m_RedrawDeque.front();
		pDoc->mainset->m_RedrawDeque.pop_front();
		//ÖØ»­µ¥Ôª
		BlockBMP.LoadBitmap(GetResID(pDoc->m_CurrentMap.GetPicture(cp.x,cp.y-1,1)));
		BlockDC.SelectObject(&BlockBMP);
		ChEdDC.BitBlt(0,0,40,40,&BlockDC,0,0,SRCCOPY);
		BlockBMP.DeleteObject();
		BlockBMP.LoadBitmap(GetResID(pDoc->m_CurrentMap.GetPicture(cp.x,cp.y,1)));
		BlockDC.SelectObject(&BlockBMP);
		ChEdDC.BitBlt(0,40,40,40,&BlockDC,0,0,SRCCOPY);
		BlockBMP.DeleteObject();
		BlockBMP.LoadBitmap(GetResID(pDoc->m_CurrentMap.GetPicture(cp.x,cp.y+1,1)));
		BlockDC.SelectObject(&BlockBMP);
		ChEdDC.BitBlt(0,80,40,40,&BlockDC,0,0,SRCCOPY);
		BlockBMP.DeleteObject();
		for (int j=-1;j<2;j++)
		{
			if (cp.y+j>=pDoc->mainset->dim)
			{
				BlockBMP.LoadBitmap(GetResID(BMP_BLANK));
			}
			else
			BlockBMP.LoadBitmap(GetResID(pDoc->mainset->pBlock[cp.x][cp.y+j]->PictureParameter()));
			BlockDC.SelectObject(&BlockBMP);
			//ÂÖÀª
			BlockDC.SetBkColor(RGB(255,255,255));
			MaskDC.BitBlt(0,0,40,80,&BlockDC,0,0,SRCCOPY);
			//±³¾°ÖÐÍÚÈ¥ÂÖÀª
			ChEdDC.SetBkColor(RGB(255,255,255));
			ChEdDC.SetTextColor(RGB(0,0,0));
			ChEdDC.BitBlt(0,j*SLENGTH,40,80,&MaskDC,0,0,SRCAND);
			//BlockDC±³¾°Í¿ºÚ
			BlockDC.SetBkColor(RGB(0,0,0));
			BlockDC.SetTextColor(RGB(255,255,255));
			BlockDC.BitBlt(0,0,40,80,&MaskDC,0,0,SRCAND);
			//Á½Í¼Æ¬Õ³Ìù
			ChEdDC.BitBlt(0,j*SLENGTH,40,80,&BlockDC,0,0,SRCPAINT);
			BlockBMP.DeleteObject();
		}
		//Õ³Ìùµ¥Ôª
		//ÂÖÀª
		ChEdDC.SetBkColor(RGB(255,255,255));
		EdMaskDC.BitBlt(0,0,SLENGTH,SLENGTH*2,&ChEdDC,0,0,SRCCOPY);
		//±³¾°ÖÐÍÚÈ¥ÂÖÀª
		MapDC.SetBkColor(RGB(255,255,255));
		MapDC.SetTextColor(RGB(0,0,0));
		MapDC.BitBlt(cp.x*SLENGTH,cp.y*SLENGTH-SLENGTH,SLENGTH,SLENGTH*2,&EdMaskDC,0,0,SRCAND);
		//ChEdDC±³¾°Í¿ºÚ
		ChEdDC.SetBkColor(RGB(0,0,0));
		ChEdDC.SetTextColor(RGB(255,255,255));
		ChEdDC.BitBlt(0,0,SLENGTH,SLENGTH*2,&EdMaskDC,0,0,SRCAND);
		//Á½Í¼Æ¬Õ³Ìù
		MapDC.BitBlt(cp.x*SLENGTH,cp.y*SLENGTH-SLENGTH,SLENGTH,SLENGTH*2,&ChEdDC,0,0,SRCPAINT);
		ChEdBMP.DeleteObject();
	}
	ChEdDC.DeleteDC();
	MapDC.SelectObject(oldMapBMP);
	MapDC.DeleteDC();
	BlockDC.DeleteDC();
	MaskDC.DeleteDC();
	MaskBMP.DeleteObject();
	BlockBMP.DeleteObject();
	ReleaseDC(pDC);
	
}
