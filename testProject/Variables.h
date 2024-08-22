#pragma once

#include <vector>

using namespace std;

//��ͼ��С
extern int MAP_SIZE_Y;
extern int MAP_SIZE_X;

//�ƶ��ٶ�
extern double SPEED;

//���ֱ仯ϵ��
extern double vc;

//���ű���
extern double vx;
extern double vy;

//��С��С
extern const double minvx;
extern const double minvy;

//���Ŵ�
extern const double maxvx;
extern const double maxvy;

//��Ļ��С
extern int WINDOWS_WIDTH;
extern int WINDOWS_HEIGHT;

//��Ⱦ�������
extern const int SCREEN_BLOCK_X;
extern const int SCREEN_BLOCK_Y;

//����λ��
extern double CENTRE_X;
extern double CENTRE_Y;

//�Ŵ���
extern double BLOCK_MULTIPLE;//BLOCK_MULTIPLE * BLOCK_SIZE  *  BLOCK_MULTIPLE * BLOCK_SIZE

//ͼƬ�ߴ�(��ƽ��()
extern int BLOCK_SIZE;

//ˢ����
extern double FPS;

class Block;

//�ؿ��б�
extern vector<Block*> block_list;