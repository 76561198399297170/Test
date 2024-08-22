#include "Animation.h"
#include "Variables.h"

#include "Block.h"

//�����ʼ�����-1����ΪNULL��
Block::Block()
{
	this->m_id = -1;
	this->m_animation = NULL;
	return;
}

//�����ʼ��Ϊ����Ĺ̶�����������Ϣ
Block::Block(int id, string path, vector<int>* inertval_ms, int frame_num, double block_multiple)
{
	this->m_id = id;
	this->m_animation = new Animation(path, inertval_ms, frame_num, block_multiple);
	return;
}

//�����ʼ��Ϊ���뷽��
Block::Block(const Block& block)
{
	this->m_id = block.m_id;
	this->m_animation = new Animation(block.m_animation);
	return;
}

//���Ƶ�ǰ����λ��Ϊx, y
void Block::drawBlock(int y, int x, int delta)
{
	this->m_animation->playAnimation(y, x, delta);
	return;
}

//��ȡ��ǰ������Ⱦ��ͼƬ
IMAGE* Block::getPictrue()
{
	return this->m_animation == NULL ? NULL : this->m_animation->m_img_list[this->m_animation->m_idx];
}

//�����ͷ��ڴ�
Block::~Block()
{
	if (this->m_animation != NULL)
	{
		delete this->m_animation;
		this->m_animation = NULL;
	}
	return;
}

//��ʼ�����صؿ�
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