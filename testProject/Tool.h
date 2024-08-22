#pragma once
#include <iostream>

#include <random>
#include <easyx.h>

using namespace std;

void initBolck();

//初始化加载游戏内物品
void initGame();

//在坐标(x, y)对应图片左上角打印图片
#pragma comment(lib, "Msimg32.lib")
void putImage(int y, int x, IMAGE* img);

//获取随机数
int getRandom();

class Position
{
public:
	//构造初始化为0, 0位置
	Position();

	//有参初始化为x, y位置
	Position(int y, int x);

	//有参初始化为p.x, p.y位置
	Position(Position* p);

	//坐标向x, y移动距离
	void movePos(int y, int x);

	//设置坐标为x, y
	void setPos(int y, int x);

	//获取x坐标
	int getPosX();

	//获取y坐标
	int getPosY();

	//析构释放内存
	~Position();

public:
	int m_x;//x坐标
	int m_y;//y坐标

};

class Button
{
public:
	//有参初始化
	Button(LPCTSTR path_up, LPCTSTR path_down, int y, int x);

	//是否在当前按钮上
	bool isOnButton(int y, int x);

	//析构释放内存
	~Button();

public:
	IMAGE* m_button_up;//按钮弹起图片
	IMAGE* m_button_down;//按钮按下图片
	Position m_pos;//按钮坐标位置

};