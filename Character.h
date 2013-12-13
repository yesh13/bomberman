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
	void Run();        //ÿ��timing���˱����ã��ж�box��judgemove����Ӧ���ƶ�
	void Bombed();//��ըʱ����
	//command
	void OnKeyDown(MyDirection direction);
	void OnKeyUp(MyDirection direction);
    virtual void OnTime();
	CPoint GetCoordinate();//������ھ�ȷλ��
	CPoint GetPosition();//�������Block����
	bool InBlock(long i,long j);//�Ƿ���block[i][j]�н���
	bool IsPushing();//0�� 1��
	int m_picturestate;
	int CharacterType;
	CString m_Name;
	int presentbomb;

protected:
	CPoint coordinate;
	std::list<MyDirection> movelist;//�˶�״̬

	int m_speed;//�ƶ��ٶ�
	int m_bombnumber;//ը������
	int m_range;//����
	int m_max_speed;
	int m_max_bombnumber;
	int m_max_range;

	int m_pushing;//�Ƿ��������� 0��30׼���ƣ�31��һ���ƣ�32������

	MainSet* myMainSet;//����������ָ��

	CPoint GetEdgePosition();//������ڱ�Եλ�ã�Move_X,Y�ĸ�������,�ж��ܷ��ж�
	void Move_X(int sign);//�����ƶ���Run���� left:1,right:-1
	void Move_Y(int sign);//�����ƶ���Run���� up:1,down:-1
	void PushMove();//m_pushing>30ʱ�����ӣ���Run����
	void Pick();//ʰ��item
	void ChangePicture();
};

#endif // !defined(AFX_CHARACTER_H__3668F686_591E_4FC0_9BAA_6B6E67CA3E7D__INCLUDED_)
