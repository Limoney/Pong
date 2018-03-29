#include "Puck.h"

int height = 20, width = 50;

Puck::Puck()
{
	x = width/2;
	y = height/2;
	velX = 0;
	velY = 0;
}


Puck::~Puck()
{

}

void Puck::Update(char **m, Paddle p1, Paddle p2)
{
	if (y >= height -2||y<=1)
	{
		velY *= -1;
	}
	if(checkCollision(p1)) velX *= -1;
	else if (checkCollision(p2)) velX *= -1;
	
	x += velX;
	y += velY;
	if (x<=0||x>= width -1)
	{
		//std::cout << "punkty kiedys" << std::endl;
		
		m[x-velX][y-velY] = ' ';
		x = width /2;
		y = height/2;
		velX *= -1;
		system("pause");
	}
	m[x][y] = 'o';
	m[x-velX][y-velY] = ' ';
}

bool Puck::checkCollision(Paddle p)
{
	if (y>=p.y-1&&y<=p.y+1)
	{
		if (abs(x-p.x)==1) return true;
		else return false;
	}
	else return false;
	
}

void Puck::setRandomVelocity()
{
	if (rand() % 4 >= 2) velX = -1;
	else velX = 1;
	if (rand() % 4 >= 2) velY = -1;
	else velY = 1;
}
