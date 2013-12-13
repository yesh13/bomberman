// Block.cpp: implementation of the Block class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test1.h"
#include "Block.h"
#include "MainSet.h"
#include <ctime>
#include <cstdlib>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


//////setlocation////////////////////////////////////////////////////////////////////
void Block::setlocation(int x,int y)
{
	location.x=x;
	location.y=y;
	bomb.setlocation(x,y);
}
/////getlocation/////////////////////////////////////////////////////////////////////
CPoint Block::getlocation()
{
	return location;
}
//////构造函数///////////////////////////////////////////////////////////////////
Block::Block(MainSet* mains):bomb(mains)
{
    OccupybyBomb=false;
	bombingdirection=-1;
}
//////析构函数////////////////////////////////////////////////////////////////////
Block::~Block()
{
	
}
///////////SetBombingDrctn(int i);///////////////////////////////////////////////////////////////
void Block::SetBombingDrctn(int i)
{
	bombingdirection=i;
}
//////AddLife();////////////////////////////////////////////////////////////////////
void Block::SetLife(int i)
{
	m_life=i;
}

//////////////////////////////////////////////////////////////////////////
//CreateItem

Item Block::CreateItem()
{

	int r=rand()%100;
    switch(m_initlife)
	{
	case 1: if (r<15) return Item_RANGE;
		else if (r<30) return Item_SPEED;
		else if (r<45) return Item_BOMB;
		else return Item_NONE;
	case 2: if (r<15) return Item_RANGE;
		else if (r<30) return Item_SPEED;
		else if (r<45) return Item_BOMB;
		else if (r<60) return Item_ULTRANGE;
		else if (r<75) return Item_ULTSPEED;
		else return Item_NONE;
	case 3: if (r<5) return Item_RANGE;
		else if (r<10) return Item_SPEED;
		else if (r<15) return Item_BOMB;
		else if (r<55) return Item_ULTRANGE;
		else if (r<95) return Item_ULTSPEED;
		else return Item_NONE;
	default:return Item_NONE;
	}
} 



void Block::Bombed()
{
	if((m_life==0)&&(m_item!=Item_NONE)) EraseItem();
	else
	{
    	m_life--;
    	if (m_life==0) 
		{
			m_item=CreateItem();
			mainset->m_RedrawDeque.push_back(getlocation());
		}
    	if (location==mainset->Player1->GetPosition())
		{
    		mainset->Player1->Bombed();
		}
    	if (location==mainset->Player2->GetPosition())
		{
			mainset->Player2->Bombed();
		}
	}
}




Item Block::PickItem()
{
	if (m_item!=Item_NONE)
	{
		EraseItem();
	}
	return m_item;
}




void Block::EraseItem()
{
    m_item=Item_NONE;
	mainset->m_RedrawDeque.push_back(getlocation());
}

void Block::CreateBomb(int range,Character* player)
{
	OccupybyBomb=TRUE;
	bomb.StartBombing(range,player);
}
int Block::BombPicture()
{
	const int count=4;
	return bomb.m_phase%(4*count)/count;
}

///////下面是Stone///////////////////////////////////////////////////////////////////

Stone::Stone(BlockType mytype,MainSet* mains):Block(mains)
{
	mainset=mains;
	m_life=mytype.attribute;
	m_initlife=mytype.attribute;
	m_style=mytype.style;
	m_item=Item_NONE;
}

/////////PictureParameter();/////////////////////////////////////////////////////////////////
int Stone::PictureParameter()
{
	static int phase=0;
	if (m_life>0) return 0x00010100+m_style;
	if (bombingdirection!=-1) return 0x00010600+bombingdirection;
	return 0x00010400+m_item;
}

int Stone::JudgeMove()
{
	
	if(m_life>0||OccupybyBomb) return 0;
	return 1;
}



Item Stone::CreateItem()
{
	int r=rand()%100;
    switch(m_initlife)
	{
	case 1: if (r<20) return Item_RANGE;
		else if (r<40) return Item_SPEED;
		else if (r<60) return Item_BOMB;
		else return Item_NONE;
	case 2: if (r<15) return Item_RANGE;
		else if (r<30) return Item_SPEED;
		else if (r<45) return Item_BOMB;
		else if (r<60) return Item_ULTRANGE;
		else if (r<75) return Item_ULTSPEED;
	    else return Item_NONE;
	case 3: if (r<5) return Item_RANGE;
	    else if (r<10) return Item_SPEED;
        else if (r<15) return Item_BOMB;
	    else if (r<55) return Item_ULTRANGE;
	    else if (r<95) return Item_ULTSPEED;
		else return Item_NONE;
	default:return Item_NONE;
	}
};




Stone::~Stone()
{}


/////下面是Box///////////////////



Box::Box(BlockType mytype,MainSet* mains):Block(mains)
{
	mainset=mains;
	m_life=mytype.attribute;
	m_initlife=mytype.attribute;
	m_style=mytype.style;
	m_item=Item_NONE;
}

/////////PictureParameter();/////////////////////////////////////////////////////////////////
int Box::PictureParameter()
{
	static int phase=0;
	if (m_life>0) return 0x00010200+m_style;
	if (bombingdirection!=-1) return 0x00010600+bombingdirection;
	return 0x00010400+m_item;
}

int Box::JudgeMove()
{
	
	if(m_life>0) return 2;
	if(OccupybyBomb) return 0;
	return 1;
}



Item Box::CreateItem()
{
	int r=rand()%100;
    switch(m_initlife)
	{
    case 1: if (r<20) return Item_RANGE;
	       	else if (r<40) return Item_SPEED;
	     	else if (r<60) return Item_BOMB;
			else return Item_NONE;
	case 2: if (r<15) return Item_RANGE;
		    else if (r<30) return Item_SPEED;
		    else if (r<45) return Item_BOMB;
			else if (r<60) return Item_ULTRANGE;
			else if (r<75) return Item_ULTSPEED;
			else return Item_NONE;
	case 3: if (r<5) return Item_RANGE;
		    else if (r<10) return Item_SPEED;
		    else if (r<15) return Item_BOMB;
	     	else if (r<55) return Item_ULTRANGE;
		    else if (r<95) return Item_ULTSPEED;
			else return Item_NONE;
	default:return Item_NONE;
	}
}



Box::~Box(){};


///////下面是Rock,函数内容全部照抄，不过bombed重载为不掉血，所以其他内容如果不出错的话用不到///////
Rock::Rock(BlockType mytype,MainSet* mains):Block(mains)
{
	mainset=mains;
	m_life=mytype.attribute;
	m_initlife=mytype.attribute;
	m_style=mytype.style;
	m_item=Item_NONE;
}
/////////PictureParameter();/////////////////////////////////////////////////////////////////
int Rock::PictureParameter()
{
	static int phase=0;
	if (m_life>0) return 0x00010300+m_style;
	if (bombingdirection!=-1) return 0x00010600+bombingdirection;
	return 0x00010400+m_item;
}


int Rock::JudgeMove()
{
	if(m_life>0) return 0;
	return 1;
}



Item Rock::CreateItem()
{
	int r=rand()%100;
    switch(m_initlife)
	{
    case 1: if (r<20) return Item_RANGE;
		else if (r<40) return Item_SPEED;
		else if (r<60) return Item_BOMB;
		else return Item_NONE;
	case 2: if (r<15) return Item_RANGE;
		else if (r<30) return Item_SPEED;
		else if (r<45) return Item_BOMB;
		else if (r<60) return Item_ULTRANGE;
		else if (r<75) return Item_ULTSPEED;
		else return Item_NONE;
	case 3: if (r<5) return Item_RANGE;
		else if (r<10) return Item_SPEED;
        else if (r<15) return Item_BOMB;
		else if (r<55) return Item_ULTRANGE;
		else if (r<95) return Item_ULTSPEED;
		else return Item_NONE;
	default:return Item_NONE;
	}
};


void Rock::Bombed()
{}


Rock::~Rock(){}
