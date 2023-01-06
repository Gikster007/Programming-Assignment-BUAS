#include "game.h"
#include "surface.h"
#include <cstdio> //printf

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

#define BALLWIDTH 50
#define BALLHEIGHT 50

#define TILEWIDTH 256
#define TILEHEIGHT 256


namespace Tmpl8
{
	// Draws the ball on the screen
	void Game::DrawBall(Surface* screen, Sprite& ball)
	{
		ball.Draw(screen, 200, 300);
	}

	// Draws the left-side wall
	void Game::DrawLeftSideWall(Surface* screen, Sprite& leftWall)
	{
		for (int i = -50; i <= SCREENHEIGHT; i += TILEHEIGHT)
		{
			leftWall.Draw(screen, -(TILEWIDTH / 2), i);
		}
	}

	// Draws the right-side wall
	void Game::DrawRightSideWall(Surface* screen, Sprite& rightWall)
	{
		for (int i = -50; i <= SCREENHEIGHT; i += TILEHEIGHT)
		{
			rightWall.Draw(screen, SCREENWIDTH - (TILEWIDTH / 2), i);
		}
	}

	// Draws the floor
	void Game::DrawFloor(Surface* screen, Sprite& floor)
	{
		for (int i = (TILEWIDTH / 2); i <= SCREENWIDTH - TILEWIDTH; i += TILEWIDTH)
		{
			floor.Draw(screen, i, SCREENHEIGHT - 160);
		}
	}

	// Draws the roof
	void Game::DrawRoof(Surface* screen, Sprite& roof)
	{
		for (int i = (TILEWIDTH / 2); i <= SCREENWIDTH; i += TILEWIDTH)
		{
			roof.Draw(screen, i, -(TILEHEIGHT / 2));
		}
	}

	// Draws the Top-Right Ramp
	void Game::DrawRampTR(Surface* screen, Sprite& rampTR)
	{
		rampTR.DrawScaled(SCREENWIDTH - TILEWIDTH, TILEHEIGHT / 2, 128, 128, screen);
	}

	// Draws the Top-Left Ramp
	void Game::DrawRampTL(Surface* screen, Sprite& rampTL)
	{
		rampTL.DrawScaled(TILEWIDTH / 2, TILEHEIGHT / 2, 128, 128, screen);
	}

	// Draws the Bottom-Right Ramp
	void Game::DrawRampBR(Surface* screen, Sprite& rampBR)
	{
		rampBR.DrawScaled(SCREENWIDTH - TILEWIDTH, SCREENHEIGHT - ((TILEHEIGHT / 2) + 160), 128, 128, screen);
	}

	// Draws the Bottom-Left Ramp
	void Game::DrawRampBL(Surface* screen, Sprite& rampBL)
	{
		rampBL.DrawScaled(TILEWIDTH / 2, SCREENHEIGHT - ((TILEHEIGHT / 2) + 160), 128, 128, screen);
	}

	static Sprite ball(new Surface("assets/ball.png"), 1);

	static Sprite leftSideWall(new Surface("assets/ground0.png"), 1);
	static Sprite rightSideWall(new Surface("assets/ground0.png"), 1);

	static Sprite floor(new Surface("assets/ground1.png"), 1);
	static Sprite roof(new Surface("assets/ground0.png"), 1);

	static Sprite rampTR(new Surface("assets/rampTR.png"), 1);
	static Sprite rampTL(new Surface("assets/rampTL.png"), 1);

	static Sprite rampBR(new Surface("assets/rampBR.png"), 1);
	static Sprite rampBL(new Surface("assets/rampBL.png"), 1);

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		// Clearing the screen and setting the background colour to gray
		screen->Clear(0x222222);

		// Drawing the ball
		DrawBall(screen, ball);

		// Drawing the following sprites: Floor, Roof, Right-Side Wall, Left-Side Wall
		DrawFloor(screen, floor);
		DrawRoof(screen, roof);
		DrawRightSideWall(screen, rightSideWall);
		DrawLeftSideWall(screen, leftSideWall);

		// Drawing the following sprites: Top-Right Ramp, Top-Left Ramp, Bottom-Right Ramp, Bottom-Left Ramp
		DrawRampTR(screen, rampTR);
		DrawRampTL(screen, rampTL);
		DrawRampBR(screen, rampBR);
		DrawRampBL(screen, rampBL);
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		
		

		//screen->Print("Game Initialised", 2, 2, 0xffffff);
		

		//printf("The height of the ball: %i \n", ball.GetHeight());
		//printf("The width of the ball: %i \n", ball.GetWidth());


		//printf("The height of tile1: %i \n", leftSideWall.GetHeight()); --  256 X 256
		//printf("The width of tile1: %i \n", leftSideWall.GetWidth());
	}
};