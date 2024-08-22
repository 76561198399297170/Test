#include "Tool.h"
#include "Block.h"
#include "Variables.h"

#include "Game.h"

//无参初始化地图为NULL空
GameMap::GameMap()
{
	this->m_x = 0;
	this->m_y = 0;
	this->m_map = NULL;

	return;
}

//有参初始化地图大小为x, y格
GameMap::GameMap(int size_y, int size_x)
{
	this->m_x = size_x;
	this->m_y = size_y;

	this->m_map = new Block * *[size_y];
	for (int i = 0; i < size_y; i++)
	{
		this->m_map[i] = new Block * [size_x];
	}
	//====================//
	//测试地图生成
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (getRandom() % 10 >= 9)
			{
				this->m_map[i][j] = new Block(*block_list[2]);
			}
			else
			{
				this->m_map[i][j] = new Block(*block_list[1]);
			}
		}
	}


	//====================//

	return;
}

//打印pos坐标为中心的地图，时间经过delta毫秒
void GameMap::printMap(Position* pos, int delta)
{
	int blocksize = BLOCK_SIZE * BLOCK_MULTIPLE;
	for (double i = -SCREEN_BLOCK_Y * blocksize - pos->getPosY() % blocksize; i < CENTRE_Y + SCREEN_BLOCK_Y * blocksize; i += blocksize)
	{
		for (double j = -SCREEN_BLOCK_X * blocksize - pos->getPosX() % blocksize; j < CENTRE_X + SCREEN_BLOCK_X * blocksize; j += blocksize)
		{
			if (pos->getPosY() + i < 0 || (pos->getPosY() + i) / blocksize >= MAP_SIZE_Y || pos->getPosX() + j < 0 || (pos->getPosX() + j) / blocksize >= MAP_SIZE_X)
			{
				continue;
			}
			this->m_map[(int)((pos->getPosY() + i) / blocksize)][(int)((pos->getPosX() + j) / blocksize)]->drawBlock(CENTRE_Y + i, CENTRE_X + j, delta);
		}
	}

	return;
}

//析构释放内存
GameMap::~GameMap()
{
	for (int i = 0; i < this->m_y; i++)
	{
		for (int j = 0; j < this->m_x; j++)
		{
			delete this->m_map[i][j];
		}
		delete[] this->m_map[i];
	}

	return;
}


//构造初始化位置为方块大小中间
Player::Player()
{
	this->m_pos = new Position(BLOCK_SIZE / 2, BLOCK_SIZE / 2);

	return;
}

//构造初始化位置为x, y
Player::Player(int pos_y, int pos_x)
{
	this->m_pos = new Position(pos_y, pos_x);

	return;
}

//更新移动位置
void Player::move()
{
	int dir_x = this->m_is_move_right - this->m_is_move_left;
	int dir_y = this->m_is_move_down - this->m_is_move_up;
	double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);

	if (len_dir != 0)
	{
		double normalized_x = dir_x / len_dir;
		double normalized_y = dir_y / len_dir;
		this->m_pos->movePos((int)(SPEED * normalized_y), (int)(SPEED * normalized_x));
	}

	if (this->m_pos->getPosX() < 0)
	{
		this->m_pos->setPos(this->m_pos->getPosY(), 0);
	}
	else if (this->m_pos->getPosX() > MAP_SIZE_X * BLOCK_MULTIPLE * BLOCK_SIZE)
	{
		this->m_pos->setPos(this->m_pos->getPosY(), MAP_SIZE_X * BLOCK_MULTIPLE * BLOCK_SIZE);
	}

	if (this->m_pos->getPosY() < 0)
	{
		this->m_pos->setPos(0, this->m_pos->getPosX());
	}
	else if (this->m_pos->getPosY() > MAP_SIZE_Y * BLOCK_MULTIPLE * BLOCK_SIZE)
	{
		this->m_pos->setPos(MAP_SIZE_Y * BLOCK_MULTIPLE * BLOCK_SIZE, this->m_pos->getPosX());
	}

	return;
}

//处理按键消息与移动消息
void Player::processEvnt(const ExMessage& msg)
{
	char ch = ' ';

	switch (msg.message)
	{
	case WM_KEYDOWN:
	{
		switch (msg.vkcode)
		{
		case VK_UP:
		case 0x57:
			this->m_is_move_up = true;
			break;
		case VK_DOWN:
		case 0x53:
			this->m_is_move_down = true;
			break;
		case VK_LEFT:
		case 0x41:
			this->m_is_move_left = true;
			break;
		case VK_RIGHT:
		case 0x44:
			this->m_is_move_right = true;
			break;
		default:
			break;
		}
	}
	break;
	case WM_KEYUP:
	{
		switch (msg.vkcode)
		{
		case VK_UP:
		case 0x57:
			this->m_is_move_up = false;
			break;
		case VK_DOWN:
		case 0x53:
			this->m_is_move_down = false;
			break;
		case VK_LEFT:
		case 0x41:
			this->m_is_move_left = false;
			break;
		case VK_RIGHT:
		case 0x44:
			this->m_is_move_right = false;
			break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}

	if (msg.ctrl == 1)
	{
		switch (msg.wheel)
		{
		case 120:
		{
			if (vx < maxvx && vy < maxvy)
			{
				vx += vc;
				vy += vc;
			}
		}
		break;
		case -120:
		{
			if (vx > minvx && vy > minvy)
			{
				vx -= vc;
				vy -= vc;
			}
		}
		break;
		default:
			break;
		}

		CENTRE_X = (double)WINDOWS_WIDTH / 2 / vx;
		CENTRE_Y = (double)WINDOWS_HEIGHT / 2 / vy;

		setaspectratio(vx, vy);
	}

	return;
}