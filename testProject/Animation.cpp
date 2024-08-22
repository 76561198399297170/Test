#include "Tool.h"

#include "Animation.h"

//构造初始化默认空动画
Animation::Animation()
{
	this->m_idx = 0;
	this->m_inertval_ms = new vector<int>(1, 0);
	this->m_timer = 0;
	return;
}

//有参初始化为传入的固定参数加载信息
Animation::Animation(string path, vector<int>* inertval_ms, int frame_num, double multiple)
{
	IMAGE* img;
	string newpath;

	this->m_idx = 0;
	this->m_timer = 0;

	this->m_inertval_ms = inertval_ms;

	for (int i = 0; i < frame_num; i++)
	{
		newpath = path;

		int idx = path.find("%d");
		newpath.replace(newpath.begin() + idx, newpath.begin() + idx + 2, to_string(i));
		cout << newpath << "\n";


		wstring wpath(newpath.begin(), newpath.end());
		LPCTSTR lp = wpath.c_str();

		img = new IMAGE();
		loadimage(img, lp);
		loadimage(img, lp, img->getwidth() * multiple, img->getheight() * multiple, true);

		this->m_img_list.push_back(img);
	}

	return;
}

//有参初始化为传入动画默认从0开始播放
Animation::Animation(const Animation* animation, bool idxStart0)
{
	this->m_idx = (idxStart0 ? 0 : getRandom() % animation->m_img_list.size());
	this->m_timer = 0;
	this->m_inertval_ms = animation->m_inertval_ms;

	for (int i = 0; i < animation->m_img_list.size(); i++)
	{
		this->m_img_list.push_back(animation->m_img_list[i]);
	}
	return;
}

//更新经过delta毫秒后在x, y坐标渲染当前帧动画
void Animation::playAnimation(int y, int x, int delta)
{
	this->m_timer += delta;
	if (this->m_timer >= (*this->m_inertval_ms)[this->m_idx])
	{
		this->m_timer = 0;

		this->m_idx++;
	}
	this->m_idx = this->m_idx % this->m_img_list.size();

	putImage(y, x, this->m_img_list[this->m_idx]);
	return;
}