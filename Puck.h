#ifndef H_PUCK
#define H_PUCK
#include <time.h>
#include "Paddle.h"


class Puck
{
public:
	Puck();
	~Puck();
	void Update(char **m, Paddle p1, Paddle p2);
	bool checkCollision(Paddle p);
	void setRandomVelocity();

	int x;
	int y;
	int velX;
	int velY;
};
#endif // !H_PUCK
