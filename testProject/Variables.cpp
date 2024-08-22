#include "Variables.h"

//��ͼ��С
int MAP_SIZE_Y = 10;
int MAP_SIZE_X = 10;

//�ƶ��ٶ�
double SPEED = 2;

//���ֱ仯ϵ��
double vc = 0.2;

//���ű���
double vx = 2;
double vy = 2;

//��С��С
const double minvx = 1.2;
const double minvy = 1.2;

//���Ŵ�
const double maxvx = 4;
const double maxvy = 4;

//��Ļ��С
int WINDOWS_WIDTH = 960;
int WINDOWS_HEIGHT = 540;

//��Ⱦ�������
const int SCREEN_BLOCK_X = /*>=960/16=60*/120;
const int SCREEN_BLOCK_Y = /*540/16~=34*/50;

//����λ��
double CENTRE_X = WINDOWS_WIDTH / 2;
double CENTRE_Y = WINDOWS_HEIGHT / 2;

//�Ŵ���
double BLOCK_MULTIPLE = 1;//BLOCK_MULTIPLE * BLOCK_SIZE  *  BLOCK_MULTIPLE * BLOCK_SIZE

//ͼƬ�ߴ�(��ƽ��()
int BLOCK_SIZE = 16;

//ˢ����
double FPS = 1000 / 144;

class Block;

//�ؿ��б�
vector<Block*> block_list;