#include "Variables.h"

#include "Tool.h"

//初始化加载游戏内物品
void initGame()
{
	initBolck();

	return;
}

//在坐标(x, y)对应图片左上角打印图片
void putImage(int y, int x, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 225, AC_SRC_ALPHA });

	return;
}

//获取随机数
int getRandom()
{
	random_device rd;
	default_random_engine re(rd());

	uniform_int_distribution<> dist(0, 9999);

	return dist(re) * dist(re);
}

//构造初始化为0, 0位置
Position::Position()
{
	this->m_x = 0;
	this->m_y = 0;

	return;
}

//有参初始化为x, y位置
Position::Position(int y, int x)
{
	this->m_x = x;
	this->m_y = y;

	return;
}

//有参初始化为p.x, p.y位置
Position::Position(Position* p)
{
	this->m_x = p->m_x;
	this->m_y = p->m_y;

	return;
}

//坐标向x, y移动距离
void Position::movePos(int y, int x)
{
	this->m_x += x;
	this->m_y += y;

	return;
}

//设置坐标为x, y
void Position::setPos(int y, int x)
{
	this->m_x = x;
	this->m_y = y;

	return;
}

//获取x坐标
int Position::getPosX()
{
	return this->m_x * BLOCK_MULTIPLE;
}

//获取y坐标
int Position::getPosY()
{
	return this->m_y * BLOCK_MULTIPLE;
}

//析构释放内存
Position::~Position()
{
	return;
}


//有参初始化
Button::Button(LPCTSTR path_up, LPCTSTR path_down, int y, int x)
{
	this->m_pos.setPos(y, x);

	this->m_button_up = new IMAGE();
	this->m_button_down = new IMAGE();

	loadimage(this->m_button_down, path_down);
	loadimage(this->m_button_up, path_up);

	return;
}

//是否在当前按钮上
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

//析构释放内存
Button::~Button()
{
	return;
}