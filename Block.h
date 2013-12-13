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
/////////////����
class Block
{
public:
	Block(MainSet* mains);
    virtual int JudgeMove()=0;  //ѯ��ĳ�����ܲ����ߣ�0����1��ʾ���ߣ�2��ʾ������
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

//////////////////������
class Stone:public Block        //bombed�����û����
{
public:
	Stone(BlockType mytype,MainSet* mains);
	int JudgeMove();
	Item CreateItem();
	void EraseItem();
	int PictureParameter();
	virtual ~Stone();
};

class Box:public Block          //bombed�����û����
{
public:
	Box(BlockType mytype,MainSet* mains);
	int JudgeMove();
	Item CreateItem();
	void EraseItem();
	int PictureParameter();
	virtual ~Box();
};

class Rock:public Block        //bombed�������Լ��ģ�����Ϊ����Ѫ��
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
