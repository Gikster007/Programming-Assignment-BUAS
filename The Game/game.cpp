#include "game.h"
#include "surface.h"
#include <cstdio> //printf

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

namespace Tmpl8
{
	// Drawing the ball on the screen
	void Game::DrawBall(Surface* screen, Sprite ball)
	{
		ball.Draw(screen, 200, 100);
	}

	// Drawing the left-side wall
	void Game::DrawLeftSideWall(Surface* screen, Sprite leftWall)
	{
		for (int i = -50; i <= SCREENHEIGHT; i += 128)
		{
			leftWall.Draw(screen, -64, i);
		}
	}

	// Drawing the right-side wall
	void Game::DrawRightSideWall(Surface* screen, Sprite rightWall)
	{
		for (int i = -50; i <= SCREENHEIGHT; i += 128)
		{
			rightWall.Draw(screen, 1920 - 64, i);
		}
	}

	// Drawing the floor
	void Game::DrawFloor(Surface* screen, Sprite floor)
	{
		for (int i = 64; i <= SCREENWIDTH; i += 128)
		{
			floor.Draw(screen, i, 1080 - 50);
		}
	}

	// Drawing the roof
	void Game::DrawRoof(Surface* screen, Sprite roof)
	{
		for (int i = 64; i <= SCREENWIDTH; i += 128)
		{
			roof.Draw(screen, i, -50);
		}
	}

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	static Sprite ball(new Surface("assets/ball.png"), 1);

	static Sprite leftSideWall(new Surface("assets/ground2.png"), 1);
	static Sprite rightSideWall(new Surface("assets/ground2.png"), 1);

	static Sprite floor(new Surface("assets/ground5.png"), 1);
	static Sprite roof(new Surface("assets/ground5.png"), 1);

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// Clearing the screen
		screen->Clear(0x222222);

		//screen->Print("Game Initialised", 2, 2, 0xffffff);
		
		/*ball.Draw(screen, 200, 100);

		for (int i = -50; i <= SCREENHEIGHT; i += 128)
		{
			leftSideWall.Draw(screen, -64, i);
		}

		for (int i = -50; i <= SCREENHEIGHT; i += 128)
		{
			rightSideWall.Draw(screen, 1920 - 64, i);
		}

		for (int i = 64; i <= SCREENWIDTH; i += 128)
		{
			floor.Draw(screen, i, 1080 - 50);
		}

		for (int i = 64; i <= SCREENWIDTH; i += 128)
		{
			roof.Draw(screen, i, -50);
		}*/





		
		DrawBall(screen, ball);
		DrawLeftSideWall(screen, leftSideWall);
		DrawRightSideWall(screen, rightSideWall);
		DrawFloor(screen, floor);
		DrawRoof(screen, roof);




		//printf("The height of the ball: %i \n", ball.GetHeight());
		//printf("The width of the ball: %i \n", ball.GetWidth());


		//printf("The height of tile1: %i \n", tile1.GetHeight());
		//printf("The width of tile1: %i \n", tile1.GetWidth());
	}
};