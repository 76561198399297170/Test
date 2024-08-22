#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <easyx.h>

using namespace std;

class Animation;

class Block
{
public:
	//构造初始化编号-1动画为NULL空
	Block();

	//构造初始化为传入的固定参数加载信息
	Block(int id, string path, vector<int>* inertval_ms, int frame_num, double block_multiple = 4);

	//构造初始化为传入方块
	Block(const Block& block);

	//绘制当前方块位置为x, y
	void drawBlock(int y, int x, int delta);

	//获取当前方块渲染的图片
	IMAGE* getPictrue();

	//析构释放内存
	~Block();

public:
	Animation* m_animation;//当前地块动画

	int m_id;//当前地块编号

};

//初始化加载地块
void initBolck();