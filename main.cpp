#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Puck.h"
#include "Paddle.h"

void FillMap();
void DrawMap();
void setup();
void run();


int rows = 20, cols = 50;

char **map=new char*[cols];

Puck puck;

Paddle paddleL(1,10);
Paddle paddleR(cols-2, 10);


int main()
{
	
	setup();
	run();
	std::cout << "over";
	system("pause");
	return 0;
}

void FillMap()
{
	for (int j=0;j<rows;j++)
	{
		for (int i=0;i<cols;i++)
		{
			if (i==0||i==cols-1)
			{
				map[i][j] = '|';
			}
			if (i>0&&i<cols-1&&j==0&&j==rows-1)
			{
				map[i][j] = '-';
			}
			if (i>0&&i<cols-1&&j>0&&j<rows-1)
			{
				map[i][j] = ' ';
			}
		}
	}
}
void DrawMap()
{
	for (int j=0;j<rows;j++)
	{
		for (int i=0;i<cols;i++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}
void setup()
{
	srand(time(NULL));
	for (int i = 0; i<cols; i++)
	{
		map[i] = new char[rows];
	}
	FillMap();
	puck.setRandomVelocity();
	paddleL.setKeyBinds('W', 'S');
	paddleR.setKeyBinds('T', 'G');
}
void run()
{
	while (true)
	{
		puck.Update(map, paddleL, paddleR);
		paddleR.Update(map);
		paddleL.Update(map);

		DrawMap();
		Sleep(130);
		system("cls");
	}
}
