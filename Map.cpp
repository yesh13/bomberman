// Map.cpp: implementation of the Map class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "Map.h"
#include <fstream>
#include "test1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Map::Map()
{

}

Map::~Map()
{

}
//////////////////////////////////////////////////////////////////////////
//LoadMap
bool Map::LoadMap(LPCTSTR lpszFileName)
{
	using namespace std;
	ifstream file;
	file.open(lpszFileName,ios_base::binary);
	if (!file)
	{
		return 1;
	}

	file.read((char *)&m_Rank,4);
	file.read((char *)&m_GameMode,4);
	file.read((char *)&m_P1Position,8);
	file.read((char *)&m_P2Position,8);

	for(int i=0;i<20;i++) m_Name[i]=0;
	file.read(this->m_Name,20);

	file.read((char *)this->blocktype,m_Rank*m_Rank*4);

	file.close();	
	return 0;
}
//////////////////////////////////////////////////////////////////////////
//StoreMap
bool Map::StoreMap()
{
	using namespace std;	
	char lpszFileName[30];
	for(int i=0;i<20;i++) lpszFileName[i]=0;
	strcat(lpszFileName,"Maps\\");
	strcat(lpszFileName,m_Name);
	strcat(lpszFileName,".bhm");

	ofstream file;
	file.open(lpszFileName,ios_base::binary);
	
	file.write((char *)&m_Rank,4);
	file.write((char *)&m_GameMode,4);
	file.write((char *)&m_P1Position,8);
	file.write((char *)&m_P2Position,8);
	
	file.write(this->m_Name,20);
	
	file.write((char *)this->blocktype,m_Rank*m_Rank*4);
	
	file.close();	
	return 0;

}
//////////////////////////////////////////////////////////////////////////
//获取该地点地图资源号
int Map::GetPicture(long i,long j,bool t)
{
	if (i==0||j==0||i==m_Rank+1||j==m_Rank+1)
	{
		if(t)
		{
			return BMP_BLANK;
		}
		return BMP_EDGE;
	}
	else
	{
		if(t)
		{
			return BMP_BLANK|blocktype[(j-1)*m_Rank+i-1].blank;
		}
		if (blocktype[(j-1)*m_Rank+i-1].attribute==0)
		{
			return BMP_BLANK;
		}
		else
		return BMP_BLOCK|(blocktype[(j-1)*m_Rank+i-1].type<<8)|blocktype[(j-1)*m_Rank+i-1].style;
	}
	
}
//////////////////////////////////////////////////////////////////////////
//DrawGround
void Map::DrawGround()
{
/*
		CDC dc;
		CDC ScreenDC=GetDC(NULL);
		dc.CreateCompatibleDC(&ScreenDC);
		m_pGroundBMP = new CBitmap;
		m_pGroundBMP->CreateCompatibleBitmap(&ScreenDC);
		CDC tempDC;
		CBitmap tempBMP;
		tempDC.CreateCompatibleDC(&ScreenDC);
		
		
		
		dc.DeleteDC();
		ScreenDC.DeleteDC()*/
	
}