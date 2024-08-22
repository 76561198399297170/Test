#include <easyx.h>

#include "Variables.h"
#include "Game.h"
#include "Tool.h"

using namespace std;

//EX_SHOWCONSOLE 1 // EX_DBLCLKS 8

//内容开始位置
int start()
{
	//初始化窗口
	initgraph(WINDOWS_WIDTH, WINDOWS_HEIGHT, EX_SHOWCONSOLE);
	initGame();
	setbkcolor(RGB(120, 200, 130));

	//创建信息类
	ExMessage msg();

	//====================//
	//测试创建默认地图并提示成功创建
	GameMap gm(MAP_SIZE_Y, MAP_SIZE_X);
	Player player(MAP_SIZE_Y * BLOCK_MULTIPLE * BLOCK_SIZE / 2, MAP_SIZE_X * BLOCK_MULTIPLE * BLOCK_SIZE / 2);

	//====================//

	//程序准备运行
	bool running = true;

	//开始渲染
	BeginBatchDraw();
	//开始循环
	while (running)
	{
		//开始计时
		DWORD start_time = GetTickCount();

		ExMessage msg;
		while (peekmessage(&msg))
		{
			player.processEvnt(msg);
		}
		player.move();

		//====================//
		//测试打印地图
		gm.printMap(player.m_pos, (int)FPS);
		circle(CENTRE_X, CENTRE_Y, 2);


		//====================//
		FlushBatchDraw();

		//结束计时
		DWORD end_time = GetTickCount();
		//计算用时
		DWORD delta_time = end_time - start_time;
		//动态延时
		if (delta_time < FPS)
		{
			Sleep(FPS - delta_time);
		}
		//清除屏幕
		cleardevice();
	}

	EndBatchDraw();
	return 0;
}

//主程序开始位置
int main()
{
	start();

	return 0;
}