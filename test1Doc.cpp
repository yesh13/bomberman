// test1Doc.cpp : implementation of the CTest1Doc class
//

#include "stdafx.h"
#include "test1.h"

#include "test1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
// KeySetting
KeySetting::KeySetting()
{
	Sup=VK_UP;
	Sdown=VK_DOWN;
	Sleft=VK_LEFT;
	Sright=VK_RIGHT;
	Sbomb=VK_SPACE;
	Sskill=VK_RSHIFT;
	DP1up=VK_UP;
	DP1down=VK_DOWN;
	DP1left=VK_LEFT;
	DP1right=VK_RIGHT;
	DP1bomb=VK_RCONTROL;
	DP1skill=VK_RSHIFT;
	DP2up='W';
	DP2down='S';
	DP2left='A';
	DP2right='D';
	DP2bomb=VK_LSHIFT;
	DP2skill=VK_LCONTROL;
}
/////////////////////////////////////////////////////////////////////////////
// CTest1Doc

IMPLEMENT_DYNCREATE(CTest1Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest1Doc, CDocument)
	//{{AFX_MSG_MAP(CTest1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1Doc construction/destruction

CTest1Doc::CTest1Doc()
{
	// TODO: add one-time construction code here
	LoadMapNameVector();
	if( m_CurrentMap.LoadMap( (LPCTSTR)("Maps\\"+m_mapNameVector[0]+".bhm") ) )MessageBox(NULL,"","",MB_OK);
	mainset=new MainSet(m_CurrentMap,SINGLEMODE,0,1);

}

CTest1Doc::~CTest1Doc()
{
	delete mainset;
}

BOOL CTest1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest1Doc serialization

void CTest1Doc::Serialize(CArchive& ar)
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

/////////////////////////////////////////////////////////////////////////////
// CTest1Doc diagnostics

#ifdef _DEBUG
void CTest1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1Doc commands

//LoadMapNameVector‘ÿ»ÎµÿÕº√˚
bool CTest1Doc::LoadMapNameVector()
{
	m_mapNameVector.clear();
	int exs;
	CFileFind filefind;
	exs=filefind.FindFile("Maps\\*.bhm");
	while (exs)
	{
		exs=filefind.FindNextFile();
		m_mapNameVector.push_back(filefind.GetFileTitle());
	}
	filefind.Close();
	return 0;
}
