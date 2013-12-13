#include "StdAfx.h"
#include "ResourceMap.h"
#include "resource.h"
long GetResID(long Type)
{
	int t1,t2,t3,t4;
	t1=Type>>24;
	t2=(Type<<8)>>24;
	t3=Type<<16>>24;
	t4=Type<<24>>24;
	switch(t1)
	{
	case 0:
		switch(t2)
		{
		case 0:
			switch(t3)
			{
			case 0:
				switch(t4)
				{
				case 6:	return IDB_ChRed06;
				case 7:	return IDB_ChRed07;
				case 8:	return IDB_ChRed08;
				case 9:	return IDB_ChRed06;
				case 10:return IDB_ChRed10;
				case 11:return IDB_ChRed11;
				case 12:return IDB_ChRed12;
				case 13:return IDB_ChRed13;
				case 14:return IDB_ChRed14;
				case 15:return IDB_ChRed12;
				case 16:return IDB_ChRed16;
				case 17:return IDB_ChRed17;
				case 18:return IDB_ChRed18;
				case 19:return IDB_ChRed19;
				case 20:return IDB_ChRed20;
				case 21:return IDB_ChRed18;
				case 22:return IDB_ChRed22;
				case 23:return IDB_ChRed23;
				case 24:return IDB_ChRed24;
				case 25:return IDB_ChRed25;
				case 26:return IDB_ChRed26;
				case 27:return IDB_ChRed24;
				case 28:return IDB_ChRed28;
				case 29:return IDB_ChRed29;
				}
			case 1:
				switch(t4)
				{
				case 6:	return IDB_ChBlue06;
				case 7:	return IDB_ChBlue07;
				case 8:	return IDB_ChBlue08;
				case 9:	return IDB_ChBlue06;
				case 10:return IDB_ChBlue10;
				case 11:return IDB_ChBlue11;
				case 12:return IDB_ChBlue12;
				case 13:return IDB_ChBlue13;
				case 14:return IDB_ChBlue14;
				case 15:return IDB_ChBlue12;
				case 16:return IDB_ChBlue16;
				case 17:return IDB_ChBlue17;
				case 18:return IDB_ChBlue18;
				case 19:return IDB_ChBlue19;
				case 20:return IDB_ChBlue20;
				case 21:return IDB_ChBlue18;
				case 22:return IDB_ChBlue22;
				case 23:return IDB_ChBlue23;
				case 24:return IDB_ChBlue24;
				case 25:return IDB_ChBlue25;
				case 26:return IDB_ChBlue26;
				case 27:return IDB_ChBlue24;
				case 28:return IDB_ChBlue28;
				case 29:return IDB_ChBlue29;
				}
			}
		break;
		case 1:
			switch(t3)
			{
			case 0://¿ÕµØ
				switch(t4)
				{
				case 0:return IDB_SBL_BLANK0;
				case 1:return IDB_SBL_BLANK1;
				case 2:return IDB_SBL_BLANK2;
				}
				break;
			case 1://stone
				switch(t4)
				{
				case 0:return IDB_SBL_BLANK0;
				case 1:return IDB_SBL_STONE1;
				case 2:return IDB_SBL_STONE2;
				}
				break;
			case 2://Box
				if(t4)return IDB_SBL_BOX;
				else return IDB_SBL_BLANK0;
			case 3://ROCK
				switch(t4)
				{
				case 0:return IDB_SBL_BLANK0;
				case 1:return IDB_SBL_ROCK1;
				//case 2:return IDB_SBL_ROCK2;
				}
				break;
			case 4://ITEM
				switch(t4)
				{
				case 0:return IDB_SBL_BLANK0;
				case 1:return IDB_ITEM1;
				case 2:return IDB_ITEM2;
				case 3:return IDB_ITEM3;
				}
			case 5://BOMB
				switch(t4)
				{
				case 0:return IDB_BOMB1;
				case 1:return IDB_BOMB2;
				case 2:return IDB_BOMB1;
				case 3:return IDB_BOMB3;
				}
			case 6:
				switch(t4)
				{
				case 0:return IDB_WatVolMid;
				case 1:return IDB_WatVolUp;
				case 2:return IDB_WatVolDown;
				case 3:return IDB_WatVolLeft;
				case 4:return IDB_WatVolRight;
				case 5:return IDB_WatUpEnd;
				case 6:return IDB_WatDnEnd;
				case 7:return IDB_WatLtEnd;
				case 8:return IDB_WatRtEnd;
				}
			}
		}
	}
}