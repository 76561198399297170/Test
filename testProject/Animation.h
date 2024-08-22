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
	//构造初始化默认空动画
	Animation();

	//有参初始化为传入的固定参数加载信息
	Animation(string path, vector<int>* inertval_ms, int frame_num, double multiple);

	//有参初始化为传入动画默认从0开始播放
	Animation(const Animation* animation, bool idxStart0 = false);
	
	//更新经过delta毫秒后在x, y坐标渲染当前帧动画
	void playAnimation(int y, int x, int delta);

public:
	vector<IMAGE*> m_img_list;//动画列表
	vector<int>* m_inertval_ms;//帧毫秒时间间隔

	int m_timer;//动画计时器
	int m_idx;//帧下标索引

};