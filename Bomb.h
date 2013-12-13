// Bomb.h: interface for the Bomb class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMB_H__BC1DB7CF_B82B_4FF5_B5F4_6C95B5D1CBBC__INCLUDED_)
#define AFX_BOMB_H__BC1DB7CF_B82B_4FF5_B5F4_6C95B5D1CBBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class MainSet;
class Character;
class Bomb  
{
public:
	Bomb(MainSet* mains);
	virtual ~Bomb();
	void setlocation(int x,int y);
	void StartBombing(int range,Character* player);
	void SetTimesCount(int time);
	void Setbombingcount(int time);
	void OnTime();
	int m_phase;
protected:
	bool OnBombing;
	MainSet *myMainSet;
	int timescount;
	virtual void Exploding();
	int mighty;
	CPoint bomblocation;
	Character *origplayer;
	int bombingcount;
};

#endif // !defined(AFX_BOMB_H__BC1DB7CF_B82B_4FF5_B5F4_6C95B5D1CBBC__INCLUDED_)
