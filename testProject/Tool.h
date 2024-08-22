#pragma once
#include <iostream>

#include <random>
#include <easyx.h>

using namespace std;

void initBolck();

//��ʼ��������Ϸ����Ʒ
void initGame();

//������(x, y)��ӦͼƬ���ϽǴ�ӡͼƬ
#pragma comment(lib, "Msimg32.lib")
void putImage(int y, int x, IMAGE* img);

//��ȡ�����
int getRandom();

class Position
{
public:
	//�����ʼ��Ϊ0, 0λ��
	Position();

	//�вγ�ʼ��Ϊx, yλ��
	Position(int y, int x);

	//�вγ�ʼ��Ϊp.x, p.yλ��
	Position(Position* p);

	//������x, y�ƶ�����
	void movePos(int y, int x);

	//��������Ϊx, y
	void setPos(int y, int x);

	//��ȡx����
	int getPosX();

	//��ȡy����
	int getPosY();

	//�����ͷ��ڴ�
	~Position();

public:
	int m_x;//x����
	int m_y;//y����

};

class Button
{
public:
	//�вγ�ʼ��
	Button(LPCTSTR path_up, LPCTSTR path_down, int y, int x);

	//�Ƿ��ڵ�ǰ��ť��
	bool isOnButton(int y, int x);

	//�����ͷ��ڴ�
	~Button();

public:
	IMAGE* m_button_up;//��ť����ͼƬ
	IMAGE* m_button_down;//��ť����ͼƬ
	Position m_pos;//��ť����λ��

};