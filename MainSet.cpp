// MainSet.cpp: implementation of the MainSet class.
//
//////////////////////////////////////////////////////////////////////

/*
坐标架：
block中心位于SLength的整数倍处
人的标记点位于人的中心
边缘处不能走，故人的活动范围（40，**）（40，**）
*/
#include <ctime>
#include <cstdlib>
#include "stdafx.h"
#include "test1.h"
#include "MainSet.h"
#include "AI.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;              
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainSet::MainSet(Map map,int ar_gamemode,int P1Type,int P2Type)
{
	    srand(time(NULL));
	int i,j;
	gamemode=ar_gamemode;
	dim=map.m_Rank+2;
	Player1=new Character(map.m_P1Position,this,P1Type,"1P");
	if (ar_gamemode==SINGLEMODE)
	{
		Player2=new AI(map.m_P2Position,this,P2Type,"2P");
	}
	else Player2=new Character(map.m_P2Position,this,P2Type,"2P");
	for (i=1;i<dim-1;i++)
	for (j=1;j<dim-1;j++)
	{	
		switch (map.blocktype[(j-1)*map.m_Rank+i-1].type)
		{
		case 1: pBlock[i][j]=new Stone(map.blocktype[(j-1)*map.m_Rank+i-1],this);
		    	pBlock[i][j]->setlocation(i,j);
				break;
		case 3: pBlock[i][j]=new Rock(map.blocktype[(j-1)*map.m_Rank+i-1],this); 
			    pBlock[i][j]->setlocation(i,j);
				break;
		case 2: pBlock[i][j]=new Box(map.blocktype[(j-1)*map.m_Rank+i-1],this); 
		    	pBlock[i][j]->setlocation(i,j);
		    	break;		
		}
	}
	//四条边为默认stone作为边界，不显示
	BlockType defaultblocktype={0,0,1,1};
	for (i=0;i<dim;i++)
	{
		pBlock[0][i]=new Rock(defaultblocktype,this);
		pBlock[dim-1][i]=new Rock(defaultblocktype,this);
	}
	for (i=1;i<dim-1;i++)
	{
		pBlock[i][0]=new Rock(defaultblocktype,this);
		pBlock[i][dim-1]=new Rock(defaultblocktype,this);
	}
	for (i=1;i<dim-1;i++)
	for (j=1;j<dim-1;j++)
	{
		m_GroundStyle[i][j]=map.blocktype[(j-1)*map.m_Rank+i-1].blank;
	}
}

MainSet::~MainSet()
{
	delete Player1,Player2;
	for (int i=0;i<dim;i++)
	for (int j=0;j<dim;j++)
	{
		delete pBlock[i][j];
	}

}