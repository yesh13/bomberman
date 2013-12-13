// AI.cpp: implementation of the AI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test1.h"
#include "AI.h"
#include "MainSet.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AI::AI(CPoint& point,MainSet* mainset,int type,CString name):Character(point,mainset,type,name)
{
    spot=new SpotInfo*[myMainSet->dim];
    for (int i=0;i<(myMainSet->dim);i++) spot[i]=new SpotInfo[myMainSet->dim];
    commandfinish=TRUE;
	currentposition=point;
	busy=FALSE;
}

AI::~AI()
{
	for (int i=0;i<myMainSet->dim;i++)
	{
	    delete[]spot[i];
	}
	delete[]spot;
}
//////////////////////////////////////////////  AI所在连通区域的构建//////////////////////////
void AI::RemadeSpotInfo()
{
	for(int i=0;i<myMainSet->dim;i++)
		for(int j=0;j<myMainSet->dim;j++) 
			{
			spot[i][j].done=FALSE;
			spot[i][j].lastdrctn=MyDrctn_STOP;
			spot[i][j].myx=i;
			spot[i][j].myy=j;
			}
	CPoint *a=new CPoint[(myMainSet->dim)*(myMainSet->dim)];
	CPoint *b=new CPoint[(myMainSet->dim)*(myMainSet->dim)];
	bool c=0;
	int k=1,m,n=0,g=1,l=0;
	a[0]=GetPosition();
    while(g==1)
	{
	g=0;
	c=l;
	n=k;
	k=0;

	for(m=0;m<n;m++)
	{
		if (c==0)
		{
	    	for(i=-1;i<=1;i++) 
			    for(int j=-1;j<=1;j++)//4个方向
		    		if(i*j==0)
					{
			    		if(myMainSet->pBlock[a[m].x+i][a[m].y+j]->JudgeMove()==1&&spot[a[m].x+i][a[m].y+j].done==FALSE)
						{
							{
		                        switch(myMainSet->pBlock[a[m].x+i][a[m].y+j]->JudgeMove())
								{
     	                             case 1:spot[a[m].x+i][a[m].y+j].judgemove=1;break;
    	                             default:spot[a[m].x+i][a[m].y+j].judgemove=0;break;
								}
		                     	 if (myMainSet->pBlock[a[m].x+i][a[m].y+j]->OccupybyBomb) spot[a[m].x+i][a[m].y+j].judgemove=2;
							}//0不能走1能走2有炸弹
	                    	spot[a[m].x+i][a[m].y+j].done=TRUE;
			             	if(i==-1)	spot[a[m].x+i][a[m].y+j].lastdrctn=MyDrctn_LEFT;
			        		if(i==1)	spot[a[m].x+i][a[m].y+j].lastdrctn=MyDrctn_RIGHT;
			        		if(j==-1)	spot[a[m].x+i][a[m].y+j].lastdrctn=MyDrctn_UP;
			    		    if(j==1)	spot[a[m].x+i][a[m].y+j].lastdrctn=MyDrctn_DOWN;
							if(!(n==1&&i==0&&j==0)) 
							{
								b[k]=CPoint(a[m].x+i,a[m].y+j);
                                k++;
							}
			    			g=1;
						}
					}
		l=1;
		}
		if (c==1)
		{
			for(i=-1;i<=1;i++) 
				for(int j=-1;j<=1;j++)
					if(i*j==0)
					{
						if(myMainSet->pBlock[b[m].x+i][b[m].y+j]->JudgeMove()==1&&spot[b[m].x+i][b[m].y+j].done==FALSE)
						{
							{           
								switch(myMainSet->pBlock[b[m].x+i][b[m].y+j]->JudgeMove())
								{
								case 1:spot[b[m].x+i][b[m].y+j].judgemove=1;break;
								default:spot[b[m].x+i][b[m].y+j].judgemove=0;break;
								}
								if (myMainSet->pBlock[b[m].x+i][b[m].y+j]->OccupybyBomb) spot[b[m].x+i][b[m].y+j].judgemove=2;
							}//0不能走1能走2有炸弹
							spot[b[m].x+i][b[m].y+j].done=TRUE;
							if(i==-1)	spot[b[m].x+i][b[m].y+j].lastdrctn=MyDrctn_LEFT;
							if(i==1)	spot[b[m].x+i][b[m].y+j].lastdrctn=MyDrctn_RIGHT;
							if(j==-1)	spot[b[m].x+i][b[m].y+j].lastdrctn=MyDrctn_UP;
							if(j==1)	spot[b[m].x+i][b[m].y+j].lastdrctn=MyDrctn_DOWN;
							a[k]=CPoint(b[m].x+i,b[m].y+j);
                            k++;
							g=1;
						}
					}
		l=0;
		}
	}
	}
	delete []a;
	delete []b;
}
/////////进行小目标的处理/////////////////////////////////////////////////////////////////
void AI::ToDoHandler(MyDirection drctn)
{
	if (drctn==5)  Dropbomb();
		else   
	{
		OnKeyDown(drctn);
	    currentposition=GetPosition();
	    movingdrctn=drctn;
    	busy=TRUE;
	}
}
///////OnTime///////////////////////////////////////////////////////////////////
void AI::OnTime()
{
	RemadeSpotInfo();
	if(commandfinish=TRUE) {Commander();commandfinish=FALSE;}
	if (currentposition!=GetPosition()) {StopMoving();currentposition=GetPosition();}
    if(ToDoList.empty())  int a=1;//commandfinish=TRUE;
	else
	{
	if (!busy) {ToDoHandler(ToDoList.front()); ToDoList.pop_front();}
	}
}
///////非手动调用函数（辅助）///////////////////////////////////////////////////////////////////
void AI::StopMoving()
{
	OnKeyUp(movingdrctn);
	busy=FALSE;
}
////////大目标分解为小目标，塞到队列中//////////////////////////////////////////////////////////////////
bool AI::Analyser(Command cmd)
{
	if(spot[cmd.destination.x][cmd.destination.y].done=FALSE) return FALSE;
	MyDirection *a=new MyDirection[myMainSet->dim*2];
	int x=cmd.destination.x,y=cmd.destination.y,i;	
	if (cmd.dropbomb)
	{
		a[0]=MyDrctn_BOMB;
		for (i=1;i<(myMainSet->dim*2);i++)
		{
			a[i]=spot[x][y].lastdrctn;
			switch (spot[x][y].lastdrctn)
			{
			case MyDrctn_UP:y++;break;
			case MyDrctn_DOWN:y--;break;
			case MyDrctn_LEFT:x++;break;
			case MyDrctn_RIGHT:x--;break;
			}

			if(GetPosition()==CPoint(x,y)) break;
		}
	}
	if (!cmd.dropbomb)
	for (i=0;i<(myMainSet->dim*2);i++)
	{
		a[i]=spot[x][y].lastdrctn;
		switch (spot[x][y].lastdrctn)
		{
		case MyDrctn_UP:y++;break;
		case MyDrctn_DOWN:y--;break;
		case MyDrctn_LEFT:x++;break;
		case MyDrctn_RIGHT:x--;break;
		}
		if(GetPosition()==CPoint(x,y)) break;
	}
	int g=GetPosition().x;
	int h=GetPosition().y;
	for(int j=0;j<=i;j++)
		ToDoList.push_back(a[i-j-1]);
	delete []a;
	return TRUE;
}
////////Commander//////////////////////////////////////////////////////////////////
bool AI::Commander()
{
	Command cmd;
	cmd.destination=CPoint(11,11);
	cmd.dropbomb=0;
	if(Analyser(cmd)) return TRUE;
	return FALSE;
}