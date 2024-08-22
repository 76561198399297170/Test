#include "Variables.h"

//地图大小
int MAP_SIZE_Y = 10;
int MAP_SIZE_X = 10;

//移动速度
double SPEED = 2;

//滚轮变化系数
double vc = 0.2;

//缩放倍数
double vx = 2;
double vy = 2;

//最小缩小
const double minvx = 1.2;
const double minvy = 1.2;

//最大放大
const double maxvx = 4;
const double maxvy = 4;

//屏幕大小
int WINDOWS_WIDTH = 960;
int WINDOWS_HEIGHT = 540;

//渲染方块个数
const int SCREEN_BLOCK_X = /*>=960/16=60*/120;
const int SCREEN_BLOCK_Y = /*540/16~=34*/50;

//中心位置
double CENTRE_X = WINDOWS_WIDTH / 2;
double CENTRE_Y = WINDOWS_HEIGHT / 2;

//放大倍数
double BLOCK_MULTIPLE = 1;//BLOCK_MULTIPLE * BLOCK_SIZE  *  BLOCK_MULTIPLE * BLOCK_SIZE

//图片尺寸(乘平方()
int BLOCK_SIZE = 16;

//刷新率
double FPS = 1000 / 144;

class Block;

//地块列表
vector<Block*> block_list;