// test1Doc.h : interface of the CTest1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1DOC_H__59B0A6DF_81C6_40CC_B808_09823976E3CD__INCLUDED_)
#define AFX_TEST1DOC_H__59B0A6DF_81C6_40CC_B808_09823976E3CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainSet.h"
#include "Map.h"
#include <vector>

struct KeySetting
{
	KeySetting();
	int Sup,Sdown,Sleft,Sright,Sbomb,Sskill;
	int DP1up,DP1down,DP1left,DP1right,DP1bomb,DP1skill;
	int DP2up,DP2down,DP2left,DP2right,DP2bomb,DP2skill;
};

class CTest1Doc : public CDocument
{
protected: // create from serialization only
	CTest1Doc();
	DECLARE_DYNCREATE(CTest1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation

public:
	virtual ~CTest1Doc();
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
public:
	int m_Mode;
	KeySetting keyset;
	Map m_CurrentMap;
	MainSet *mainset;
	void Move();
	std::vector<CString> m_mapNameVector;
	bool LoadMapNameVector();
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1DOC_H__59B0A6DF_81C6_40CC_B808_09823976E3CD__INCLUDED_)
