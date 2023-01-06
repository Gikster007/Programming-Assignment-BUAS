#pragma once

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
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
private:
	Surface* screen;
};

}; // namespace Tmpl8