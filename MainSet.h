// MainSet.h: interface for the MainSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MainSet_H__90FA643D_5B35_4EA9_AF2A_0AB42B4715D1__INCLUDED_)
#define AFX_MainSet_H__90FA643D_5B35_4EA9_AF2A_0AB42B4715D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SINGLEMODE 0
#define DOUBLEMODE 1
class Character;
class Block;
#include "Map.h"
#include "Character.h"
#include "Block.h"
#include <list.h>
class MainSet  
{
public:
	MainSet(Map map,int ar_gamemode/*”Œœ∑»À ˝*/,int P1Type,int P2Type);
	virtual ~MainSet();
	int gamemode;
	int dim;
	Block* pBlock[17][17];
	Character *Player1,*Player2;
	int m_GroundStyle[17][17];
	std::list<CPoint> m_RedrawDeque;

};

#endif // !defined(AFX_MainSet_H__90FA643D_5B35_4EA9_AF2A_0AB42B4715D1__INCLUDED_)
