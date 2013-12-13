// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__02726682_391C_4BD0_94E2_9F0A4C27C803__INCLUDED_)
#define AFX_STDAFX_H__02726682_391C_4BD0_94E2_9F0A4C27C803__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers


#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

enum MyDirection{MyDrctn_STOP,MyDrctn_UP,MyDrctn_DOWN,MyDrctn_LEFT,MyDrctn_RIGHT,MyDrctn_BOMB};
enum Item{Item_NONE,Item_BOMB,Item_RANGE,Item_SPEED,Item_ULTRANGE,Item_ULTSPEED};
#define SLENGTH 40
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__02726682_391C_4BD0_94E2_9F0A4C27C803__INCLUDED_)
