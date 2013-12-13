// AI.h: interface for the AI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AI_H__8CC8D506_120E_4340_8E02_18871E97002A__INCLUDED_)
#define AFX_AI_H__8CC8D506_120E_4340_8E02_18871E97002A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <list>
#include "Character.h"

struct SpotInfo
{
	MyDirection lastdrctn;
	int judgemove;
	bool done;
	int myx,myy;
};

struct Command
{
	CPoint destination;
	bool dropbomb;
};


class AI : public Character  
{
public:
	AI(CPoint& point,MainSet* mainset,int type,CString name);
	std::list<MyDirection> ToDoList;
	virtual ~AI();
	void ToDoHandler(MyDirection drctn);
    void StopMoving();
	void OnTime();
    bool Commander();
	bool Analyser(Command cmd);
	void RemadeSpotInfo();
private:
	SpotInfo **spot;
    CPoint currentposition;
	bool busy;
	MyDirection movingdrctn;
	bool commandfinish;
};

#endif // !defined(AFX_AI_H__8CC8D506_120E_4340_8E02_18871E97002A__INCLUDED_)
