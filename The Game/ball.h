#pragma once
#include "game.h"

using Tmpl8::Sprite;

class Ball
{
public:
	// Constructors
	Ball();
	Ball(Sprite* ball, int x, int y);
	// Method Headers
	void Draw(Tmpl8::Surface* screen) const;
	void DrawLine(Tmpl8::Surface* screen, int mouseX, int mouseY);
	void MoveUpdate(int click, int release, int mouseX, int mouseY);
	void CollisionCheck(Tmpl8::Surface* screen);
	int GetBallX();
	int GetBallY();
	void SetXVel(int xv);
	void SetYVel(int yv);
private:
	// Declaration of Attributes
	Sprite* sprite = nullptr;
	int ballX;
	int ballY;
	double dx, dy, angle, xv, yv;
};