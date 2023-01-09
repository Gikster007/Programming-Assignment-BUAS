#pragma once

#include "game.h"

using Tmpl8::Sprite;

class Spikes
{
public:
	// Constructors
	Spikes();
	Spikes(Sprite* sprite, int x, int y);
	// Method Headers
	void Draw(Tmpl8::Surface* screen) const;
	void CollisionCheck(int ballX, int ballY, int ballW, int ballH);
	static bool HasLost();
private:
	// Declaration of Attributes
	Sprite* sprite = nullptr;
	int x, y;
	bool isHit = false;
	static int spikesHit;
};