#include <easyx.h>

#include "Variables.h"
#include "Game.h"
#include "Tool.h"

using namespace std;

//EX_SHOWCONSOLE 1 // EX_DBLCLKS 8

//���ݿ�ʼλ��
int start()
{
	//��ʼ������
	initgraph(WINDOWS_WIDTH, WINDOWS_HEIGHT, EX_SHOWCONSOLE);
	initGame();
	setbkcolor(RGB(120, 200, 130));

	//������Ϣ��
	ExMessage msg();

	//====================//
	//���Դ���Ĭ�ϵ�ͼ����ʾ�ɹ�����
	GameMap gm(MAP_SIZE_Y, MAP_SIZE_X);
	Player player(MAP_SIZE_Y * BLOCK_MULTIPLE * BLOCK_SIZE / 2, MAP_SIZE_X * BLOCK_MULTIPLE * BLOCK_SIZE / 2);

	//====================//

	//����׼������
	bool running = true;

	//��ʼ��Ⱦ
	BeginBatchDraw();
	//��ʼѭ��
	while (running)
	{
		//��ʼ��ʱ
		DWORD start_time = GetTickCount();

		ExMessage msg;
		while (peekmessage(&msg))
		{
			player.processEvnt(msg);
		}
		player.move();

		//====================//
		//���Դ�ӡ��ͼ
		gm.printMap(player.m_pos, (int)FPS);
		circle(CENTRE_X, CENTRE_Y, 2);


		//====================//
		FlushBatchDraw();

		//������ʱ
		DWORD end_time = GetTickCount();
		//������ʱ
		DWORD delta_time = end_time - start_time;
		//��̬��ʱ
		if (delta_time < FPS)
		{
			Sleep(FPS - delta_time);
		}
		//�����Ļ
		cleardevice();
	}

	EndBatchDraw();
	return 0;
}

//������ʼλ��
int main()
{
	start();

	return 0;
}