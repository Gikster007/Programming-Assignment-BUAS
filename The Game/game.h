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
	// Function Headers for the Drawing of Sprites
	void static DrawLeftSideWall(Surface* screen, Sprite& leftWall);
	void static DrawRightSideWall(Surface* screen, Sprite& rightWall);
	void static DrawFloor(Surface* screen, Sprite& floor);
	void static DrawRoof(Surface* screen, Sprite& roof);
public:
	void SetTarget( Surface* surface ){ screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp(int button) { release = button; }
	void MouseDown(int button) { click = button; }
	void MouseMove(int x, int y) { mouseX = x, mouseY = y; }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
private:
	// Declaration of Attributes
	Surface* screen;
	int click, release;
	int mouseX, mouseY;
	
	
};

}; // namespace Tmpl8