#pragma once

#include <easyx.h>

using namespace std;

class Block;
class Position;

class GameMap
{
public:
	//无参初始化地图为NULL空
	GameMap();

	//有参初始化地图大小为x, y格
	GameMap(int size_y, int size_x);

	//打印pos坐标为中心的地图，时间经过delta毫秒
	void printMap(Position* pos, int delta);

	//析构释放内存
	~GameMap();

public:
	int m_y;//地图大小y
	int m_x;//地图大小x
	Block*** m_map;//游戏地图

};

class Player
{
public:
	//构造初始化位置为方块大小中间
	Player();
	
	//构造初始化位置为x, y
	Player(int pos_y, int pos_x);

	//更新移动位置
	void move();

	//处理按键消息与移动消息
	void processEvnt(const ExMessage& msg);

public:
	bool m_is_move_up = false;//是否向上移动
	bool m_is_move_down = false;//是否向下移动
	bool m_is_move_left = false;//是否向左移动
	bool m_is_move_right = false;//是否向右移动

	Position* m_pos;//玩家坐标位置

};