#include "Variables.h"

#include "Tool.h"

//��ʼ��������Ϸ����Ʒ
void initGame()
{
	initBolck();

	return;
}

//������(x, y)��ӦͼƬ���ϽǴ�ӡͼƬ
void putImage(int y, int x, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 225, AC_SRC_ALPHA });

	return;
}

//��ȡ�����
int getRandom()
{
	random_device rd;
	default_random_engine re(rd());

	uniform_int_distribution<> dist(0, 9999);

	return dist(re) * dist(re);
}

//�����ʼ��Ϊ0, 0λ��
Position::Position()
{
	this->m_x = 0;
	this->m_y = 0;

	return;
}

//�вγ�ʼ��Ϊx, yλ��
Position::Position(int y, int x)
{
	this->m_x = x;
	this->m_y = y;

	return;
}

//�вγ�ʼ��Ϊp.x, p.yλ��
Position::Position(Position* p)
{
	this->m_x = p->m_x;
	this->m_y = p->m_y;

	return;
}

//������x, y�ƶ�����
void Position::movePos(int y, int x)
{
	this->m_x += x;
	this->m_y += y;

	return;
}

//��������Ϊx, y
void Position::setPos(int y, int x)
{
	this->m_x = x;
	this->m_y = y;

	return;
}

//��ȡx����
int Position::getPosX()
{
	return this->m_x * BLOCK_MULTIPLE;
}

//��ȡy����
int Position::getPosY()
{
	return this->m_y * BLOCK_MULTIPLE;
}

//�����ͷ��ڴ�
Position::~Position()
{
	return;
}


//�вγ�ʼ��
Button::Button(LPCTSTR path_up, LPCTSTR path_down, int y, int x)
{
	this->m_pos.setPos(y, x);

	this->m_button_up = new IMAGE();
	this->m_button_down = new IMAGE();

	loadimage(this->m_button_down, path_down);
	loadimage(this->m_button_up, path_up);

	return;
}

//�Ƿ��ڵ�ǰ��ť��
bool Button::isOnButton(int y, int x)
{
	if (y > this->m_pos.m_y && y < this->m_pos.m_y + this->m_button_up->getheight())
	{
		return true;
	}
	if (x > this->m_pos.m_x && x < this->m_pos.m_x + this->m_button_up->getwidth())
	{
		return true;
	}

	return false;
}

//�����ͷ��ڴ�
Button::~Button()
{
	return;
}