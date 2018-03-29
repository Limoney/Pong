#ifndef  H_PADDLE
#define H_PADDLE
#include <iostream>
#include <Windows.h>
#include <conio.h>




class Paddle
{
public:
	Paddle(int x, int y);
	void setKeyBinds(char UP, char DOWN);
	~Paddle();

	void Update(char **m);

	int x;
	int y;
	char UP;
	char DOWN;
};
#endif // ! H_PADDLE
