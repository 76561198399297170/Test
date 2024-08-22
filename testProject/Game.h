#pragma once

#include <easyx.h>

using namespace std;

class Block;
class Position;

class GameMap
{
public:
	//�޲γ�ʼ����ͼΪNULL��
	GameMap();

	//�вγ�ʼ����ͼ��СΪx, y��
	GameMap(int size_y, int size_x);

	//��ӡpos����Ϊ���ĵĵ�ͼ��ʱ�侭��delta����
	void printMap(Position* pos, int delta);

	//�����ͷ��ڴ�
	~GameMap();

public:
	int m_y;//��ͼ��Сy
	int m_x;//��ͼ��Сx
	Block*** m_map;//��Ϸ��ͼ

};

class Player
{
public:
	//�����ʼ��λ��Ϊ�����С�м�
	Player();
	
	//�����ʼ��λ��Ϊx, y
	Player(int pos_y, int pos_x);

	//�����ƶ�λ��
	void move();

	//��������Ϣ���ƶ���Ϣ
	void processEvnt(const ExMessage& msg);

public:
	bool m_is_move_up = false;//�Ƿ������ƶ�
	bool m_is_move_down = false;//�Ƿ������ƶ�
	bool m_is_move_left = false;//�Ƿ������ƶ�
	bool m_is_move_right = false;//�Ƿ������ƶ�

	Position* m_pos;//�������λ��

};