// Character.h: interface for the Character class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARACTER_H__3668F686_591E_4FC0_9BAA_6B6E67CA3E7D__INCLUDED_)
#define AFX_CHARACTER_H__3668F686_591E_4FC0_9BAA_6B6E67CA3E7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>

class MainSet;

class Character
{
public:
	Character(CPoint& point,MainSet* mainset,int type,CString name);
	virtual ~Character();
	void Dropbomb();
	void Run();        //每次timing到了被调用，判断box的judgemove，相应的移动
	void Bombed();//被炸时调用
	//command
	void OnKeyDown(MyDirection direction);
	void OnKeyUp(MyDirection direction);
    virtual void OnTime();
	CPoint GetCoordinate();//获得所在精确位置
	CPoint GetPosition();//获得所在Block坐标
	bool InBlock(long i,long j);//是否与block[i][j]有交集
	bool IsPushing();//0不 1是
	int m_picturestate;
	int CharacterType;
	CString m_Name;
	int presentbomb;

protected:
	CPoint coordinate;
	std::list<MyDirection> movelist;//运动状态

	int m_speed;//移动速度
	int m_bombnumber;//炸弹数量
	int m_range;//威力
	int m_max_speed;
	int m_max_bombnumber;
	int m_max_range;

	int m_pushing;//是否在推箱子 0到30准备推，31第一次推，32正在推

	MainSet* myMainSet;//所属背景的指针

	CPoint GetEdgePosition();//获得所在边缘位置，Move_X,Y的辅助函数,判断能否行动
	void Move_X(int sign);//产生移动被Run调用 left:1,right:-1
	void Move_Y(int sign);//产生移动被Run调用 up:1,down:-1
	void PushMove();//m_pushing>30时推箱子，被Run调用
	void Pick();//拾起item
	void ChangePicture();
};

#endif // !defined(AFX_CHARACTER_H__3668F686_591E_4FC0_9BAA_6B6E67CA3E7D__INCLUDED_)
