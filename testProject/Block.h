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
	//�����ʼ�����-1����ΪNULL��
	Block();

	//�����ʼ��Ϊ����Ĺ̶�����������Ϣ
	Block(int id, string path, vector<int>* inertval_ms, int frame_num, double block_multiple = 4);

	//�����ʼ��Ϊ���뷽��
	Block(const Block& block);

	//���Ƶ�ǰ����λ��Ϊx, y
	void drawBlock(int y, int x, int delta);

	//��ȡ��ǰ������Ⱦ��ͼƬ
	IMAGE* getPictrue();

	//�����ͷ��ڴ�
	~Block();

public:
	Animation* m_animation;//��ǰ�ؿ鶯��

	int m_id;//��ǰ�ؿ���

};

//��ʼ�����صؿ�
void initBolck();