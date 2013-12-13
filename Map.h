// Map.h: interface for the Map class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP_H__BD77A6A7_032C_420A_86F9_E34303076C43__INCLUDED_)
#define AFX_MAP_H__BD77A6A7_032C_420A_86F9_E34303076C43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct BlockType
{
	BYTE blank;
	BYTE type;
	BYTE attribute;
	BYTE style;
};

class Map  
{
public:
	Map();
	~Map();
	bool LoadMap(LPCTSTR lpszFileName);
	bool StoreMap();
	void DrawGround();
	int GetPicture(long i,long j,bool t=0);//t判断读取地面还是砖块
	//存于文件中
	char m_Name[20];
	int m_GameMode;
	int m_Rank;
	CPoint m_P1Position,m_P2Position;
	BlockType blocktype[225];	//15x15
	//临时构建
	CBitmap *m_pGroundBMP;
};

#endif // !defined(AFX_MAP_H__BD77A6A7_032C_420A_86F9_E34303076C43__INCLUDED_)

//////////////////////////////////////////////////////////////////////////
/*
Mark:
	The new file format .bhmp is used to store Map data;
	follows:
		
		GameMode(4 bytes)
		RankOfMap(4 bytes) 
		Player1Position(8 bytes ) 
		Player1Position(8 bytes ) 
		NameSize(4 bytes)
		MapName(20 bytes) 
		BlockType(RankOfMap*RankOfMap*4 bytes)
	
	Use LoadMap and StoreMap to read from and write to the Hard Disk!	
*/
