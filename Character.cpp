// Character.cpp: implementation of the Character class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test1.h"
#include "Character.h"
#include "MainSet.h"
#include "Block.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Character::Character(CPoint& point,MainSet* mainset,int type,CString name)
{
	presentbomb=0;
	CharacterType=type;
	m_speed=6;
	m_bombnumber=3;
	m_range=1;
	m_max_speed=10;
	m_max_bombnumber=10;
	m_max_range=10;

	coordinate=CPoint(point.x*SLENGTH,point.y*SLENGTH);
	myMainSet=mainset;
	m_pushing=0;
	m_picturestate=12;
	movelist.push_back(MyDrctn_STOP);
	m_Name=name;
}

Character::~Character()
{

}

//////////////////////////////////////////////////////////////////////////
//Run
void Character::Run()
{
	if (m_pushing>30)
	{
		PushMove();		
	}
	else
	{
		switch (*(--movelist.end()))//移动
		{
		case MyDrctn_UP:Move_Y(1);break;
		case MyDrctn_DOWN:Move_Y(-1);break;
		case MyDrctn_LEFT:Move_X(1);break;
		case MyDrctn_RIGHT:Move_X(-1);break;
		case MyDrctn_STOP:m_pushing=0;break;//停下时m_pushing清零
		}
		Pick();//捡物品
	}
	if (*(--movelist.end())!=MyDrctn_STOP)//在移动
	{
		ChangePicture();
	}
}
///////////////////////////////////////////////////////////////////////
//丢炸弹
void Character::Dropbomb()
{
	if (presentbomb<m_bombnumber)
	{
	    Character *player=this;
	    if (myMainSet->pBlock[GetPosition().x][GetPosition().y]->JudgeMove()==1)
		{
		    myMainSet->pBlock[GetPosition().x][GetPosition().y]->CreateBomb(m_range,player);
	    	presentbomb++;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// 拣物品
void Character::Pick()
{
	Item the_item=Item_NONE;
	if ((GetPosition().x*SLENGTH-coordinate.x)*(GetPosition().x*SLENGTH-coordinate.x)+
		(GetPosition().y*SLENGTH-coordinate.y)*(GetPosition().y*SLENGTH-coordinate.y)<SLENGTH*SLENGTH/16)
	{
		the_item=myMainSet->pBlock[GetPosition().x][GetPosition().y]->PickItem();
	}
	switch (the_item)
	{
	case Item_NONE:
		break;
	case Item_BOMB:
		m_bombnumber++;break;
	case Item_RANGE:
		m_range++;break;
	case Item_SPEED:
		m_speed++;break;
	}
}
//////////////////////////////////////////////////////////////////////////
//PicturestateChange
void Character::ChangePicture()
{
	const int countTop=2;
	static int count=0;
	switch(m_picturestate%6)
	{
		case 0:											//正中
			if (count>= countTop)
			{
				m_picturestate=*(--movelist.end())*6+1;
				count=0;return;
			}	
			break;
		case 1:											//左脚
			if (count>=countTop)
			{
				m_picturestate=*(--movelist.end())*6+2;
				count=0;return;
			}	
			break;
		case 2:											//正中
			if (count>=  countTop)
			{
				m_picturestate=*(--movelist.end())*6+3;
				count=0;return;
			}	
			break;
		case 3:											//右脚
			if (count>=countTop)
			{
				m_picturestate=*(--movelist.end())*6+4;
				count=0;return;
			}	
			break;
		case 4:											//右脚
			if (count>=countTop)
			{
				m_picturestate=*(--movelist.end())*6+5;
				count=0;return;
			}	
			break;
		case 5:											//右脚
			if (count>=countTop)
			{
				m_picturestate=*(--movelist.end())*6;
				count=0;return;
			}	
			break;
		default: break;
	}
	CString cs;cs.Format("%d\n",m_picturestate);
	TRACE(cs);
	count++;
}




//////////////////////////////////////////////////////////////////////////
//获得位置
CPoint Character::GetEdgePosition()
{
	switch (*(--movelist.end()))
	{
	case MyDrctn_UP:return CPoint(coordinate.x/SLENGTH,coordinate.y/SLENGTH);
	case MyDrctn_DOWN:
		if (coordinate.y%SLENGTH==0)
		{
			return CPoint(coordinate.x/SLENGTH,coordinate.y/SLENGTH);
		}
		else
		{
			return CPoint(coordinate.x/SLENGTH,coordinate.y/SLENGTH+1);
		}
	case MyDrctn_LEFT:return CPoint(coordinate.x/SLENGTH,coordinate.y/SLENGTH);
	case MyDrctn_RIGHT:
		if (coordinate.x%SLENGTH)
		{
			return CPoint(coordinate.x/SLENGTH+1,coordinate.y/SLENGTH);
		}
		else
		{
			return CPoint(coordinate.x/SLENGTH,coordinate.y/SLENGTH);
		}
	default: 
		TRACE("Character::GetEdgePosition()    Request Move function when Stop\n");
		ASSERT(0);
		return CPoint(coordinate.x/SLENGTH,coordinate.y/SLENGTH);
	}
}

CPoint Character::GetPosition()
{
	bool dx=0,dy=0;
	if (coordinate.x%SLENGTH>SLENGTH/2)dx=1;
	if (coordinate.y%SLENGTH>SLENGTH/2)dy=1;
	return CPoint(coordinate.x/SLENGTH+dx,coordinate.y/SLENGTH+dy);
}
CPoint Character::GetCoordinate()
{
	return coordinate;
}
bool Character::InBlock(long i,long j)
{
	bool b;
	b=	(coordinate.x<(i+1)*SLENGTH)&&
		(coordinate.x>(i-1)*SLENGTH)&&
		(coordinate.y<(j+1)*SLENGTH)&&
		(coordinate.y>(j-1)*SLENGTH);
	return b;
}

//////////////////////////////////////////////////////////////////////////
//移动

void Character::Move_Y(int bsign)
{
	int rest_speed=m_speed;//走了几个1后还能走的数量，中间变量
	if ((coordinate.y-GetEdgePosition().y*SLENGTH)*bsign>=m_speed)  
	{
		coordinate.y-=m_speed*bsign;//
	}
	else
	{	
			short left_judge,right_judge;
			//计算left_judge,right_judge
			if (myMainSet->pBlock[GetEdgePosition().x][GetEdgePosition().y-bsign]->JudgeMove()!=2)//左边能不能走
				left_judge=myMainSet->pBlock[GetEdgePosition().x][GetEdgePosition().y-bsign]->JudgeMove();
			else if ((myMainSet->pBlock[GetEdgePosition().x][GetEdgePosition().y-2*bsign]->JudgeMove()==1)&&
					(!myMainSet->Player1->InBlock(GetEdgePosition().x,GetEdgePosition().y-2*bsign))&&
					(!myMainSet->Player2->InBlock(GetEdgePosition().x,GetEdgePosition().y-2*bsign)))
			{
				left_judge=2;
			}
			else left_judge=0;
			if (myMainSet->pBlock[GetEdgePosition().x+1][GetEdgePosition().y-bsign]->JudgeMove()!=2)//右边能不能走
				right_judge=myMainSet->pBlock[GetEdgePosition().x+1][GetEdgePosition().y-bsign]->JudgeMove();
			else if ((myMainSet->pBlock[GetEdgePosition().x+1][GetEdgePosition().y-2*bsign]->JudgeMove()==1)&&
				(!myMainSet->Player1->InBlock(GetEdgePosition().x+1,GetEdgePosition().y-2*bsign))&&
				(!myMainSet->Player2->InBlock(GetEdgePosition().x+1,GetEdgePosition().y-2*bsign)))
			{
				right_judge=2;
			}
			else right_judge=0;

			if (left_judge==1&&right_judge==1)			//都能走
			{
				coordinate.y-=bsign*m_speed;//
			}
			else if (left_judge==0&&right_judge==0)		//都不能走
			{
				coordinate.y=GetEdgePosition().y*SLENGTH;
			}
			else if (left_judge==2&&right_judge==2)		//都能推
			{
				if (coordinate.x%SLENGTH<=SLENGTH/2)	//往左移推箱子
				{
					rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
					if (rest_speed>coordinate.x-GetEdgePosition().x*SLENGTH)
					{	
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x-=rest_speed;
					}
				}
				else if (coordinate.x%SLENGTH>SLENGTH/2)		//往右移推箱子
				{
					rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
					if (rest_speed>(-coordinate.x+GetEdgePosition().x*SLENGTH+SLENGTH))
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH+SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x+=rest_speed;
					}
				}
				else
				{
					coordinate.y=GetEdgePosition().y*SLENGTH;
				}
			}
			else if (left_judge==1&&right_judge==2)
			{
				if (coordinate.x%SLENGTH<=SLENGTH/2)//往左、走
				{
					rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
					if (rest_speed>coordinate.x-GetEdgePosition().x*SLENGTH)
					{
						coordinate.y=GetEdgePosition().y*SLENGTH-bsign*(rest_speed-(coordinate.x-GetEdgePosition().x*SLENGTH));
						coordinate.x=GetEdgePosition().x*SLENGTH;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x-=rest_speed;
					}
				}
				else if (coordinate.x%SLENGTH>SLENGTH/2)//往右、推
				{
					rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
					if (rest_speed>(-coordinate.x+GetEdgePosition().x*SLENGTH+SLENGTH))
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH+SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x+=rest_speed;
					}
					
				}
				
			}
			else if (left_judge==2&&right_judge==1)
			{
				if (coordinate.x%SLENGTH<=SLENGTH/2)//往左、推
				{
					rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
					if (rest_speed>coordinate.x-GetEdgePosition().x*SLENGTH)
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x-=rest_speed;
					}

				}
				else if (coordinate.x%SLENGTH>SLENGTH/2)//往右、走
				{
					rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
					if (rest_speed>(-coordinate.x+GetEdgePosition().x*SLENGTH+SLENGTH))
					{
						coordinate.y=GetEdgePosition().y*SLENGTH-bsign*(rest_speed-(-coordinate.x+GetEdgePosition().x*SLENGTH+SLENGTH));
						coordinate.x=GetEdgePosition().x*SLENGTH+SLENGTH;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x+=rest_speed;
					}
			
				}	
			}
			else if (left_judge==0&&right_judge!=0)
			{
				if (coordinate.x%SLENGTH<=SLENGTH/2)
				{

						coordinate.y=GetEdgePosition().y*SLENGTH;
						return ;
				}
				rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
				if (rest_speed>(-coordinate.x+GetEdgePosition().x*SLENGTH+SLENGTH))
				{
					if (right_judge==1)
					{
						coordinate.y=GetEdgePosition().y*SLENGTH-bsign*(rest_speed-(-coordinate.x+GetEdgePosition().x*SLENGTH+SLENGTH));
						coordinate.x=GetEdgePosition().x*SLENGTH+SLENGTH;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH+SLENGTH;
						m_pushing++;return;
					}
				} 
				else
				{
					coordinate.y=GetEdgePosition().y*SLENGTH;
					coordinate.x+=rest_speed;
				}
			}
			else											//左边可以走或推，右边不行
			{
				if (coordinate.x%SLENGTH>=SLENGTH/2)
				{
					coordinate.y=GetEdgePosition().y*SLENGTH;
					return ;
				}
				rest_speed-=bsign*(-GetEdgePosition().y*SLENGTH+coordinate.y);//
				if (rest_speed>coordinate.x-GetEdgePosition().x*SLENGTH)
				{
					
					if (left_judge==1)
					{
						coordinate.y=GetEdgePosition().y*SLENGTH-bsign*(rest_speed-(coordinate.x-GetEdgePosition().x*SLENGTH));
						coordinate.x=GetEdgePosition().x*SLENGTH;
					} 
					else
					{
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH;
						m_pushing++;return;
					}
				} 
				else
				{
					coordinate.y=GetEdgePosition().y*SLENGTH;
					coordinate.x-=rest_speed;
				}
			}		
	}
		m_pushing=0;//m_pushing清零重新计数
}
void Character::Move_X(int bsign)
{	
	int rest_speed=m_speed;//走了几个1后还能走的数量，中间变量
	if ((coordinate.x-GetEdgePosition().x*SLENGTH)*bsign>=m_speed)  
	{
		coordinate.x-=m_speed*bsign;//
	}
	else
	{	
			short up_judge,down_judge;
			//计算up_judge,down_judge
			if (myMainSet->pBlock[GetEdgePosition().x-bsign][GetEdgePosition().y]->JudgeMove()!=2)//左边能不能走
				up_judge=myMainSet->pBlock[GetEdgePosition().x-bsign][GetEdgePosition().y]->JudgeMove();
			else if ((myMainSet->pBlock[GetEdgePosition().x-2*bsign][GetEdgePosition().y]->JudgeMove()==1)&&
					(!myMainSet->Player1->InBlock(GetEdgePosition().x-2*bsign,GetEdgePosition().y))&&
					(!myMainSet->Player2->InBlock(GetEdgePosition().x-2*bsign,GetEdgePosition().y)))
			{
				up_judge=2;
			}
			else up_judge=0;
			if (myMainSet->pBlock[GetEdgePosition().x-bsign][GetEdgePosition().y+1]->JudgeMove()!=2)//右边能不能走
				down_judge=myMainSet->pBlock[GetEdgePosition().x-bsign][GetEdgePosition().y+1]->JudgeMove();
			else if ((myMainSet->pBlock[GetEdgePosition().x-2*bsign][GetEdgePosition().y+1]->JudgeMove()==1)&&
				(!myMainSet->Player1->InBlock(GetEdgePosition().x-2*bsign,GetEdgePosition().y+1))&&
				(!myMainSet->Player2->InBlock(GetEdgePosition().x-2*bsign,GetEdgePosition().y+1)))
			{
				down_judge=2;
			}
			else down_judge=0;

			if (up_judge==1&&down_judge==1)			//都能走
			{
				coordinate.x-=bsign*m_speed;//
			}
			else if (up_judge==0&&down_judge==0)		//都不能走
			{
				coordinate.x=GetEdgePosition().x*SLENGTH;
			}
			else if (up_judge==2&&down_judge==2)		//都能推
			{
				if (coordinate.y%SLENGTH<=SLENGTH/2)	//往上移推箱子
				{
					rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
					if (rest_speed>coordinate.y-GetEdgePosition().y*SLENGTH)
					{	
						coordinate.y=GetEdgePosition().y*SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y-=rest_speed;
					}
				}
				else if (coordinate.y%SLENGTH>SLENGTH/2)		//往下移推箱子
				{
					rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
					if (rest_speed>(-coordinate.y+GetEdgePosition().y*SLENGTH+SLENGTH))
					{
						coordinate.y=GetEdgePosition().y*SLENGTH+SLENGTH;
						coordinate.x=GetEdgePosition().x*SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y+=rest_speed;
					}
				}
				else
				{
					coordinate.x=GetEdgePosition().x*SLENGTH;
				}
			}
			else if (up_judge==1&&down_judge==2)
			{
				if (coordinate.y%SLENGTH<=SLENGTH/2)//往左、走
				{
					rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
					if (rest_speed>coordinate.y-GetEdgePosition().y*SLENGTH)
					{
						coordinate.x=GetEdgePosition().x*SLENGTH-bsign*(rest_speed-(coordinate.y-GetEdgePosition().y*SLENGTH));
						coordinate.y=GetEdgePosition().y*SLENGTH;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y-=rest_speed;
					}
				}
				else if (coordinate.y%SLENGTH>SLENGTH/2)//往右、推
				{
					rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
					if (rest_speed>(-coordinate.y+GetEdgePosition().y*SLENGTH+SLENGTH))
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y=GetEdgePosition().y*SLENGTH+SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y+=rest_speed;
					}
					
				}
				
			}
			else if (up_judge==2&&down_judge==1)
			{
				if (coordinate.y%SLENGTH<=SLENGTH/2)//往左、推
				{
					rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
					if (rest_speed>coordinate.y-GetEdgePosition().y*SLENGTH)
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y=GetEdgePosition().y*SLENGTH;
						m_pushing++;return;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y-=rest_speed;
					}

				}
				else if (coordinate.y%SLENGTH>SLENGTH/2)//往右、走
				{
					rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
					if (rest_speed>(-coordinate.y+GetEdgePosition().y*SLENGTH+SLENGTH))
					{
						coordinate.x=GetEdgePosition().x*SLENGTH-bsign*(rest_speed-(-coordinate.y+GetEdgePosition().y*SLENGTH+SLENGTH));
						coordinate.y=GetEdgePosition().y*SLENGTH+SLENGTH;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y+=rest_speed;
					}
			
				}	
			}
			else if (up_judge==0&&down_judge!=0)
			{
				if (coordinate.y%SLENGTH<=SLENGTH/2)
				{

						coordinate.x=GetEdgePosition().x*SLENGTH;
						return ;
				}
				rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
				if (rest_speed>(-coordinate.y+GetEdgePosition().y*SLENGTH+SLENGTH))
				{
					if (down_judge==1)
					{
						coordinate.x=GetEdgePosition().x*SLENGTH-bsign*(rest_speed-(-coordinate.y+GetEdgePosition().y*SLENGTH+SLENGTH));
						coordinate.y=GetEdgePosition().y*SLENGTH+SLENGTH;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y=GetEdgePosition().y*SLENGTH+SLENGTH;
						m_pushing++;return;
					}
				} 
				else
				{
					coordinate.x=GetEdgePosition().x*SLENGTH;
					coordinate.y+=rest_speed;
				}
			}
			else											//左边可以走或推，右边不行
			{
				if (coordinate.y%SLENGTH>=SLENGTH/2)
				{
					coordinate.x=GetEdgePosition().x*SLENGTH;
					return ;
				}
				rest_speed-=bsign*(-GetEdgePosition().x*SLENGTH+coordinate.x);//
				if (rest_speed>coordinate.y-GetEdgePosition().y*SLENGTH)
				{
					
					if (up_judge==1)
					{
						coordinate.x=GetEdgePosition().x*SLENGTH-bsign*(rest_speed-(coordinate.y-GetEdgePosition().y*SLENGTH));
						coordinate.y=GetEdgePosition().y*SLENGTH;
					} 
					else
					{
						coordinate.x=GetEdgePosition().x*SLENGTH;
						coordinate.y=GetEdgePosition().y*SLENGTH;
						m_pushing++;return;
					}
				} 
				else
				{
					coordinate.x=GetEdgePosition().x*SLENGTH;
					coordinate.y-=rest_speed;
				}
			}		
	}
		m_pushing=0;//m_pushing清零重新计数
}
//////////////////////////////////////////////////////////////////////////
//推箱子
void Character::PushMove()
{
	BlockType bt;bt.style=0;bt.attribute=1;
	static Box *tempblock;
	switch (m_picturestate/6)//移动
	{
	case MyDrctn_UP:
		if (m_pushing==31)
		{
			tempblock=new Box(*(Box *)myMainSet->pBlock[GetPosition().x][GetPosition().y-1]);
			myMainSet->pBlock[GetPosition().x][GetPosition().y-1]->SetLife(0);
			delete myMainSet->pBlock[GetPosition().x][GetPosition().y-2];
			myMainSet->pBlock[GetPosition().x][GetPosition().y-2]=new Rock(bt,myMainSet);
			myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x,GetPosition().y-1));
			coordinate.y-=m_speed;
			m_pushing=32;
		}
		else
		{
			if (coordinate.y-m_speed>=coordinate.y/SLENGTH*SLENGTH)
			{
				coordinate.y-=m_speed;	
			} 
			else
			{
				coordinate.y=coordinate.y/SLENGTH*SLENGTH;	
				movelist.clear();
				movelist.push_back(MyDrctn_STOP);
				m_pushing=0;
				delete myMainSet->pBlock[GetPosition().x][GetPosition().y-1];
	     		myMainSet->pBlock[GetPosition().x][GetPosition().y-1]=new Box(*tempblock);
				myMainSet->pBlock[GetPosition().x][GetPosition().y-1]->setlocation(GetPosition().x,GetPosition().y-1);
				myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x,GetPosition().y-1));
				delete tempblock;
			}
		}
		break;
	case MyDrctn_DOWN:
		if (m_pushing==31)
		{
			tempblock=new Box(*(Box *)myMainSet->pBlock[GetPosition().x][GetPosition().y+1]);
            myMainSet->pBlock[GetPosition().x][GetPosition().y+1]->SetLife(0);
			myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x,GetPosition().y+1));
			delete myMainSet->pBlock[GetPosition().x][GetPosition().y+2];
			myMainSet->pBlock[GetPosition().x][GetPosition().y+2]=new Rock(bt,myMainSet);
			coordinate.y+=m_speed;
			m_pushing=32;
		}
		else
		{
			if (coordinate.y+m_speed<=coordinate.y/SLENGTH*SLENGTH+SLENGTH)
			{
				coordinate.y+=m_speed;			
			} 
			else
			{
				coordinate.y=coordinate.y/SLENGTH*SLENGTH+SLENGTH;	
				movelist.clear();
				movelist.push_back(MyDrctn_STOP);
				m_pushing=0;
				delete myMainSet->pBlock[GetPosition().x][GetPosition().y+1];
				myMainSet->pBlock[GetPosition().x][GetPosition().y+1]=new Box(*tempblock);
				myMainSet->pBlock[GetPosition().x][GetPosition().y+1]->setlocation(GetPosition().x,GetPosition().y+1);
				myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x,GetPosition().y+1));
				delete tempblock;
			}
		}

		break;
	case MyDrctn_LEFT:
		if (m_pushing==31)
		{
			tempblock=new Box(*(Box *)myMainSet->pBlock[GetPosition().x-1][GetPosition().y]);
            myMainSet->pBlock[GetPosition().x-1][GetPosition().y]->SetLife(0);
			myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x-1,GetPosition().y));
			delete myMainSet->pBlock[GetPosition().x-2][GetPosition().y];
			myMainSet->pBlock[GetPosition().x-2][GetPosition().y]=new Rock(bt,myMainSet);
			coordinate.x-=m_speed;
			m_pushing=32;
		}
		else
		{
			if (coordinate.x-m_speed>=coordinate.x/SLENGTH*SLENGTH)
			{
				coordinate.x-=m_speed;			
			} 
			else
			{
				coordinate.x=coordinate.x/SLENGTH*SLENGTH;	
				movelist.clear();
				movelist.push_back(MyDrctn_STOP);
				m_pushing=0;
				delete myMainSet->pBlock[GetPosition().x-1][GetPosition().y];
				myMainSet->pBlock[GetPosition().x-1][GetPosition().y]=new Box(*tempblock);
				myMainSet->pBlock[GetPosition().x-1][GetPosition().y]->setlocation(GetPosition().x-1,GetPosition().y);
				myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x-1,GetPosition().y));
				myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x,GetPosition().y));
				delete tempblock;
			}
		}
		break;
	case MyDrctn_RIGHT:
		if (m_pushing==31)
		{
			tempblock=new Box(*(Box *)myMainSet->pBlock[GetPosition().x+1][GetPosition().y]);
			myMainSet->pBlock[GetPosition().x+1][GetPosition().y]->SetLife(0);
			myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x+1,GetPosition().y));
			delete myMainSet->pBlock[GetPosition().x+2][GetPosition().y];
			myMainSet->pBlock[GetPosition().x+2][GetPosition().y]=new Rock(bt,myMainSet);
			coordinate.x+=m_speed;
			m_pushing=32;
		}
		else
		{
			if (coordinate.x+m_speed<=coordinate.x/SLENGTH*SLENGTH+SLENGTH)
			{
				coordinate.x+=m_speed;			
			} 
			else
			{
				coordinate.x=coordinate.x/SLENGTH*SLENGTH+SLENGTH;
				movelist.clear();
				movelist.push_back(MyDrctn_STOP);
				m_pushing=0;
				delete myMainSet->pBlock[GetPosition().x+1][GetPosition().y];
				myMainSet->pBlock[GetPosition().x+1][GetPosition().y]=new Box(*tempblock);
				myMainSet->pBlock[GetPosition().x+1][GetPosition().y]->setlocation(GetPosition().x+1,GetPosition().y);
				myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x+1,GetPosition().y));
				myMainSet->m_RedrawDeque.push_back(CPoint(GetPosition().x,GetPosition().y));
				delete tempblock;
			}
		}
		break;
	}
}
bool Character::IsPushing()
{
	if (m_pushing>30)
	{
		return 1;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//Command
void Character::OnKeyDown(MyDirection direction)
{

	if (*(--movelist.end())!=direction)
	{
		if (m_pushing<=30)
		{
			movelist.push_back(direction);
			m_picturestate=direction*6;
		}
	}
}

void Character::OnKeyUp(MyDirection direction)
{
	movelist.remove(direction);
	if (MyDrctn_STOP!=*(--movelist.end()))
	{
		m_picturestate=*(--movelist.end())*6;//仍移动
	}
	else
	{
		m_picturestate=m_picturestate/6*6;//停下
	}
}


void Character::Bombed()
{
	MessageBox(NULL,"","",MB_OK);
}



void Character::OnTime()
{

}
