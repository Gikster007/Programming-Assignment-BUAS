#pragma once
#include "game.h"

using Tmpl8::Sprite;

class Coin 
{
public:
	// Constructors
	Coin();
	Coin(Sprite* sprite, int x, int y);
	// Method Headers
	void Draw(Tmpl8::Surface* screen) const;
	void CollisionCheck(int ballX, int ballY, int ballW, int ballH);
	static bool HasWon();
private:
	// Declaration of Attributes
	Sprite* sprite = nullptr;
	int x, y;
	bool active = true;
	static int collectedCoins;
};