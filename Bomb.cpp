// Bomb.cpp: implementation of the Bomb class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test1.h"
#include "Bomb.h"
#include "MainSet.h"
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bomb::Bomb(MainSet *mains)
{
	myMainSet=mains;
	timescount=0;
}
//////////////////////////////////////////////////////////////////////////
Bomb::~Bomb()
{

}
/////////StartBombing////////////////////////////////////////////////////////////////
void Bomb::StartBombing(int range,Character* player)
{
	mighty=range;
	timescount=100;
	origplayer=player;
	m_phase=0;
}
//////////////////////////////////////////////////////////////////////////
//OnTime
void Bomb::OnTime()
{
	if (timescount!=0)
	{
		timescount--;
		if (timescount==0)	Exploding();
	}
	if (bombingcount!=0)
	{
		bombingcount--;
		if (bombingcount==0)
		{
			myMainSet->pBlock[bomblocation.x][bomblocation.y]->SetBombingDrctn(-1);
			myMainSet->m_RedrawDeque.push_back(bomblocation);
		}
	}
	m_phase++;
}
//////////////////////////////////////////////////////////////////////////
void Bomb::Setbombingcount(int time)
{
       bombingcount=time;
}
////////setlocation//////////////////////////////////////////////////////////////////
void Bomb::setlocation(int x,int y)
{
	bomblocation.x=x;
	bomblocation.y=y;
}

/////////settimescount/////////////////////////////////////////////////////////////////
void Bomb::SetTimesCount(int time)
{
	timescount=time;
}
//////////////////////////////////////////////////////////////////////////
void Bomb::Exploding()
{
	PlaySound("TTaHit00.wav",NULL,SND_ASYNC|SND_NODEFAULT|SND_FILENAME);
		PlaySound("xiaoqu.wav",NULL,SND_ASYNC|SND_NODEFAULT|SND_FILENAME);
	int lrange=0,rrange=0,urange=0,drange=0;//决定左右有多少个空地要爆炸
	int i,x=bomblocation.x,y=bomblocation.y;
	for (i=1;i<=mighty;i++)
	{
		if(myMainSet->pBlock[x-i][y]->JudgeMove()==1) lrange++;
        else if ((myMainSet->pBlock[x-i][y]->JudgeMove()==0&&(!myMainSet->pBlock[x-i][y]->OccupybyBomb))||(myMainSet->pBlock[x-i][y]->JudgeMove()==2))  
		{
			myMainSet->pBlock[x-i][y]->Bombed();
	    	break;
		}
		else if (myMainSet->pBlock[x-i][y]->JudgeMove()==0&&(myMainSet->pBlock[x-i][y]->OccupybyBomb))
		{
			myMainSet->pBlock[x-i][y]->bomb.SetTimesCount(3);
			break;
		}
	}
    for (i=0;i<=lrange;i++)
    {
		myMainSet->pBlock[x-i][y]->Bombed();
		myMainSet->pBlock[x-i][y]->bomb.Setbombingcount(15);
        myMainSet->m_RedrawDeque.push_back(CPoint(x-i,y));
		myMainSet->pBlock[x-i][y]->SetBombingDrctn(3);
		if (i==0) myMainSet->pBlock[x-i][y]->SetBombingDrctn(0);
		if (i==mighty)  myMainSet->pBlock[x-i][y]->SetBombingDrctn(7);
    }
	
	
	for (i=1;i<=mighty;i++)
	{
		if(myMainSet->pBlock[x+i][y]->JudgeMove()==1) rrange++;
        else if ((myMainSet->pBlock[x+i][y]->JudgeMove()==0&&(!myMainSet->pBlock[x+i][y]->OccupybyBomb))||(myMainSet->pBlock[x+i][y]->JudgeMove()==2))  
		{
			myMainSet->pBlock[x+i][y]->Bombed();
		break;
		}
		else if (myMainSet->pBlock[x+i][y]->JudgeMove()==0&&(myMainSet->pBlock[x+i][y]->OccupybyBomb))
		{
			myMainSet->pBlock[x+i][y]->bomb.SetTimesCount(3);
		break;
		}
	}
    for (i=1;i<=rrange;i++)
    {
		myMainSet->pBlock[x+i][y]->Bombed();
		myMainSet->pBlock[x+i][y]->bomb.Setbombingcount(15);
        myMainSet->m_RedrawDeque.push_back(CPoint(x+i,y));
		myMainSet->pBlock[x+i][y]->SetBombingDrctn(4);
		if (i==mighty)  myMainSet->pBlock[x+i][y]->SetBombingDrctn(8);
    }
	
	
	for (i=1;i<=mighty;i++)
	{
		if(myMainSet->pBlock[x][y-i]->JudgeMove()==1) urange++;
        else if ((myMainSet->pBlock[x][y-i]->JudgeMove()==0&&(!myMainSet->pBlock[x][y-i]->OccupybyBomb))||(myMainSet->pBlock[x][y-i]->JudgeMove()==2)) 
		{	
			myMainSet->pBlock[x][y-i]->Bombed();
		break;
		}
		else if (myMainSet->pBlock[x][y-i]->JudgeMove()==0&&(myMainSet->pBlock[x][y-i]->OccupybyBomb))
		{
			myMainSet->pBlock[x][y-i]->bomb.SetTimesCount(3);
		break;
		}
	}
    for (i=1;i<=urange;i++)
    {
		myMainSet->pBlock[x][y-i]->Bombed();
		myMainSet->pBlock[x][y-i]->bomb.Setbombingcount(15);
        myMainSet->m_RedrawDeque.push_back(CPoint(x,y-i));
		myMainSet->pBlock[x][y-i]->SetBombingDrctn(1);
		if (i==mighty)  myMainSet->pBlock[x][y-i]->SetBombingDrctn(5);
    }
	
	
	for (i=1;i<=mighty;i++)
	{
		if(myMainSet->pBlock[x][y+i]->JudgeMove()==1) drange++;
        else if ((myMainSet->pBlock[x][y+i]->JudgeMove()==0&&(!myMainSet->pBlock[x][y+i]->OccupybyBomb))||(myMainSet->pBlock[x][y+i]->JudgeMove()==2)) 
		{	
			myMainSet->pBlock[x][y+i]->Bombed();
		break;
		}
		else if (myMainSet->pBlock[x][y+i]->JudgeMove()==0&&(myMainSet->pBlock[x][y+i]->OccupybyBomb))
		{	
			myMainSet->pBlock[x][y+i]->bomb.SetTimesCount(3);
		break;
		}
	}
    for (i=1;i<=drange;i++)
    {
		myMainSet->pBlock[x][y+i]->Bombed();
		myMainSet->pBlock[x][y+i]->bomb.Setbombingcount(15);
        myMainSet->m_RedrawDeque.push_back(CPoint(x,y+i));
		myMainSet->pBlock[x][y+i]->SetBombingDrctn(2);
		if (i==mighty)  myMainSet->pBlock[x][y+i]->SetBombingDrctn(6);
    }
	origplayer->presentbomb--;
	myMainSet->pBlock[bomblocation.x][bomblocation.y]->OccupybyBomb=false;
}
