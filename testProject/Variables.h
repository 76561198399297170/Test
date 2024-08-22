#pragma once

#include <vector>

using namespace std;

//地图大小
extern int MAP_SIZE_Y;
extern int MAP_SIZE_X;

//移动速度
extern double SPEED;

//滚轮变化系数
extern double vc;

//缩放倍数
extern double vx;
extern double vy;

//最小缩小
extern const double minvx;
extern const double minvy;

//最大放大
extern const double maxvx;
extern const double maxvy;

//屏幕大小
extern int WINDOWS_WIDTH;
extern int WINDOWS_HEIGHT;

//渲染方块个数
extern const int SCREEN_BLOCK_X;
extern const int SCREEN_BLOCK_Y;

//中心位置
extern double CENTRE_X;
extern double CENTRE_Y;

//放大倍数
extern double BLOCK_MULTIPLE;//BLOCK_MULTIPLE * BLOCK_SIZE  *  BLOCK_MULTIPLE * BLOCK_SIZE

//图片尺寸(乘平方()
extern int BLOCK_SIZE;

//刷新率
extern double FPS;

class Block;

//地块列表
extern vector<Block*> block_list;