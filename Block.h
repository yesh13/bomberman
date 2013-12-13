// Block.h: interface for the Block class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Block_H__797FF0B5_28DE_4FE0_B7CB_9CDBCEA17A77__INCLUDED_)
#define AFX_Block_H__797FF0B5_28DE_4FE0_B7CB_9CDBCEA17A77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bomb.h"
#include "Map.h"
class MainSet;
/////////////基类
class Block
{
public:
	Block(MainSet* mains);
    virtual int JudgeMove()=0;  //询问某格子能不能走，0不能1表示能走，2表示可以推
	void CreateBomb(int range,Character *player);
	virtual Item CreateItem(); 
    void SetLife(int i);
    virtual void Bombed();
	void setlocation(int x,int y);
	CPoint getlocation();
	Item PickItem();
	void EraseItem();
	virtual int PictureParameter()=0;
	int BombPicture();
	void SetBombingDrctn(int i);
	virtual ~Block();
	bool OccupybyBomb;
	Bomb bomb;
protected:
	MainSet* mainset;
	CPoint location;
    int m_life;
	Item m_item;
	int m_initlife;
	BYTE m_style;
	int bombingdirection;
};

//////////////////派生类
class Stone:public Block        //bombed函数用基类的
{
public:
	Stone(BlockType mytype,MainSet* mains);
	int JudgeMove();
	Item CreateItem();
	void EraseItem();
	int PictureParameter();
	virtual ~Stone();
};

class Box:public Block          //bombed函数用基类的
{
public:
	Box(BlockType mytype,MainSet* mains);
	int JudgeMove();
	Item CreateItem();
	void EraseItem();
	int PictureParameter();
	virtual ~Box();
};

class Rock:public Block        //bombed函数用自己的，内容为不掉血。
{
public:
	Rock(BlockType mytype,MainSet* mains);
	int JudgeMove();
	void Bombed();
	Item CreateItem();
	void EraseItem();
	virtual ~Rock();
	int PictureParameter();
};

#endif // !defined(AFX_Block_H__797FF0B5_28DE_4FE0_B7CB_9CDBCEA17A77__INCLUDED_)
