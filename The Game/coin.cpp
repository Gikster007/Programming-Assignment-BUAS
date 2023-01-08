#include "coin.h"

#define COINWIDTH 40
#define COINHEIGHT 40

#define BALLWIDTH 60
#define BALLHEIGHT 60

int Coin::collectedCoins = 0;

bool AABB(int x1, int x2, int y1, int y2, int w1, int w2, int h1, int h2) 
{
	return x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2;
}

Coin::Coin()
{
	x = 0;
	y = 0;
}

Coin::Coin(Sprite* sprite, int x, int y)
{
	this->sprite = sprite;
	this->x = x;
	this->y = y;
}

void Coin::Draw(Tmpl8::Surface* screen) const
{
	if(active)
	{
		sprite->DrawScaled(x, y, COINWIDTH, COINHEIGHT, screen);
	}	
}

void Coin::CollisionCheck(int ballX, int ballY, int ballW, int ballH)
{
	if (active && AABB(x, ballX, y, ballY, COINWIDTH, BALLWIDTH, COINHEIGHT, BALLHEIGHT))
	{
		active = false;
		collectedCoins++;
	}
}

bool Coin::HasWon()
{
	return collectedCoins >= 5;
}

