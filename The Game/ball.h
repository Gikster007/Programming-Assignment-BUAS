#pragma once
#include "game.h"

using Tmpl8::Sprite;

class Ball
{
public:
	Ball();
	Ball(Sprite* ball, int x, int y);
	void Draw(Tmpl8::Surface* screen) const;
	void DrawLine(Tmpl8::Surface* screen, int mouseX, int mouseY);
	void MoveUpdate(int click, int release, int mouseX, int mouseY);
	void CheckCollision(Tmpl8::Surface* screen);
	int GetBallX();
	int GetBallY();
	void SetXVel(int xv);
	void SetYVel(int yv);
private:
	Sprite* sprite = nullptr;
	int ballX;
	int ballY;
	double dx, dy, angle, xv, yv;
};