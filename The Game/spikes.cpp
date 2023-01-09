#include "spikes.h"

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

#define SPIKESWIDTH 128
#define SPIKESHEIGHT 32

int Spikes::spikesHit = 0;

// Function that checks for Collision
bool spikesAABB(int x1, int x2, int y1, int y2, int w1, int w2, int h1, int h2)
{
	return x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2;
}

// Default Constructor Method
Spikes::Spikes()
{
	x = 0;
	y = 0;
}

// Constructor Method
Spikes::Spikes(Sprite* sprite, int x, int y)
{
	this->sprite = sprite;
	this->x = x;
	this->y = y;
}

// Method that will Draw the Sprite on Screen
void Spikes::Draw(Tmpl8::Surface* screen) const
{
	sprite->DrawScaled(x, SCREENHEIGHT - 190, SPIKESWIDTH, SPIKESHEIGHT, screen);
}

// Method that uses the AABB function in order to check for Collisions
void Spikes::CollisionCheck(int ballX, int ballY, int ballW, int ballH)
{
	if (!isHit && spikesAABB(x + 20, ballX, y, ballY, 90, BALLWIDTH, SPIKESHEIGHT, BALLHEIGHT))
	{
		isHit = true;
		spikesHit++;
	}
}

// Method that returns true or false, depending on the amount of Spikes hit by the Ball
bool Spikes::HasLost()
{
	return spikesHit >= 1;
}
