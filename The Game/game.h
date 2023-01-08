#pragma once
#include <iostream>
#include "surface.h"

#define BALLWIDTH 60
#define BALLHEIGHT 60

namespace Tmpl8 {

class Surface;
class Sprite;
class Game
{
public:
	void DrawBall(Surface* screen, Sprite& ball);
	void DrawLeftSideWall(Surface* screen, Sprite& leftWall);
	void DrawRightSideWall(Surface* screen, Sprite& rightWall);
	void DrawFloor(Surface* screen, Sprite& floor);
	void DrawRoof(Surface* screen, Sprite& roof);
	void DrawRampTR(Surface* screen, Sprite& rampTR);
	void DrawRampTL(Surface* screen, Sprite& rampTL);
	void DrawRampBR(Surface* screen, Sprite& rampBR);
	void DrawRampBL(Surface* screen, Sprite& rampBL);
public:
	void SetTarget( Surface* surface ){ screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) 
	{  
		
	}
	void MouseDown(int button) 
	{
		dx = mouseX - ballX;
		dy = mouseY - ballY;

		ballX += dx - (BALLWIDTH / 2);
		ballY += dy - (BALLHEIGHT / 2);

	}
	void MouseMove(int x, int y) { mouseX = x, mouseY = y; }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
private:
	Surface* screen;
	int mouseX, mouseY, initialMouseX, initialMouseY, newMouseX, newMouseY;
	int ballX = 200;
	int ballY = 300;
	int speedY = 50;
	int speedX = 50;
	int dx;
	int dy;
};

}; // namespace Tmpl8