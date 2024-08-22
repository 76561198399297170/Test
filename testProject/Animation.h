#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <easyx.h>

using namespace std;

void putImage(int y, int x, IMAGE* img);

class Animation
{
public:
	//�����ʼ��Ĭ�Ͽն���
	Animation();

	//�вγ�ʼ��Ϊ����Ĺ̶�����������Ϣ
	Animation(string path, vector<int>* inertval_ms, int frame_num, double multiple);

	//�вγ�ʼ��Ϊ���붯��Ĭ�ϴ�0��ʼ����
	Animation(const Animation* animation, bool idxStart0 = false);
	
	//���¾���delta�������x, y������Ⱦ��ǰ֡����
	void playAnimation(int y, int x, int delta);

public:
	vector<IMAGE*> m_img_list;//�����б�
	vector<int>* m_inertval_ms;//֡����ʱ����

	int m_timer;//������ʱ��
	int m_idx;//֡�±�����

};