#include "Paddle.h"

int h = 20, w = 50;

Paddle::Paddle(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Paddle::setKeyBinds(char UP, char DOWN)
{
	this->UP = UP;
	this->DOWN = DOWN;
}


Paddle::~Paddle()
{
}

void Paddle::Update(char ** m)
{
		if (GetAsyncKeyState(UP)&&y-1>1)
		{
			m[x][y - 2] = '|';
			m[x][y + 1] = ' ';
			y--;
		}
		else if (GetAsyncKeyState(DOWN)&&y+1<h-2)
		{
			m[x][y + 2] = '|';
			m[x][y - 1] = ' ';
			y++;
		}
		m[x][y-1]	= '|';
		m[x][y]		= '|';
		m[x][y+1]	= '|';
}
