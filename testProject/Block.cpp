#include "Animation.h"
#include "Variables.h"

#include "Block.h"

//构造初始化编号-1动画为NULL空
Block::Block()
{
	this->m_id = -1;
	this->m_animation = NULL;
	return;
}

//构造初始化为传入的固定参数加载信息
Block::Block(int id, string path, vector<int>* inertval_ms, int frame_num, double block_multiple)
{
	this->m_id = id;
	this->m_animation = new Animation(path, inertval_ms, frame_num, block_multiple);
	return;
}

//构造初始化为传入方块
Block::Block(const Block& block)
{
	this->m_id = block.m_id;
	this->m_animation = new Animation(block.m_animation);
	return;
}

//绘制当前方块位置为x, y
void Block::drawBlock(int y, int x, int delta)
{
	this->m_animation->playAnimation(y, x, delta);
	return;
}

//获取当前方块渲染的图片
IMAGE* Block::getPictrue()
{
	return this->m_animation == NULL ? NULL : this->m_animation->m_img_list[this->m_animation->m_idx];
}

//析构释放内存
Block::~Block()
{
	if (this->m_animation != NULL)
	{
		delete this->m_animation;
		this->m_animation = NULL;
	}
	return;
}

//初始化加载地块
void initBolck()
{
	int nm = 0;
	char ch = ' ';

	vector<int>* ms;
	ifstream ifs;

	ifs.open("./txtmsg/block_msg.txt");

	Block nullbk;
	int block_num = 0;

	string tmp;
	getline(ifs, tmp);

	block_num = atoi(tmp.c_str());

	for (int idx = 0; idx < block_num; idx++)
	{
		getline(ifs, tmp);
		ms = new vector<int>();

		getline(ifs, tmp);
		int id = atoi(tmp.c_str());

		getline(ifs, tmp);
		int num = atoi(tmp.c_str());

		getline(ifs, tmp);
		string path = tmp;

		for (int i = 0; i < num; i++)
		{
			ifs >> nm;
			ms->push_back(nm);
		}
		getline(ifs, tmp);
		block_list.push_back(new Block(id, path, ms, num, BLOCK_MULTIPLE));
	}

	return;
}