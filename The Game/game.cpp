#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <corecrt_math.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>

#include "coin.h"
#include "ball.h"
#include "spikes.h"

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

#define BALLWIDTH 60
#define BALLHEIGHT 60

#define TILEWIDTH 256
#define TILEHEIGHT 256

#define SPIKESWIDTH 128
#define SPIKESHEIGHT 32

namespace Tmpl8
{
	// Creating the Sprites that will be used throughout the program
	static Sprite ball(new Surface("assets/ball2.png"), 1);

	static Sprite leftSideWall(new Surface("assets/ground0.png"), 1);
	static Sprite rightSideWall(new Surface("assets/ground0.png"), 1);

	static Sprite floor(new Surface("assets/ground1.png"), 1);
	static Sprite roof(new Surface("assets/ground0.png"), 1);

	static Sprite coin(new Surface("assets/coin.png"), 1);

	static Sprite spikes(new Surface("assets/spikes.png"), 1);


	Ball myBall;
	Coin coins[7]{};
	Spikes mySpikes[2]{};


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

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		// Initializing the Ball Object
		myBall = Ball(&ball, 1000, 300);

		// Initializing an array of Coin Objects
		coins[0] = Coin(&coin, 300, 500);
		coins[1] = Coin(&coin, 1000, 700);
		coins[2] = Coin(&coin, 1250, 870);
		coins[3] = Coin(&coin, 300, 880);
		coins[4] = Coin(&coin, 550, 820);
		coins[5] = Coin(&coin, 1400, 160);
		coins[6] = Coin(&coin, 1600, 600);

		// Initializing an array of Spikes Objects
		mySpikes[0] = Spikes(&spikes, 500, SCREENHEIGHT - 190);
		mySpikes[1] = Spikes(&spikes, 1300, SCREENHEIGHT - 190);
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
		// Clearing the screen and setting the background colour to gray
		screen->Clear(0x222222);

		// Drawing the coins on the Screen
		for (int i = 0; i < 7; i++)
		{
			coins[i].Draw(screen);
		}

		// Drawing the ball on the Screen

		myBall.Draw(screen);

		// Drawing the Spikes on the Screen
		for (int i = 0; i < 2; i++)
		{
			mySpikes[i].Draw(screen);
		}

		// Drawing the following sprites: Floor, Roof, Right-Side Wall, Left-Side Wall
		DrawFloor(screen, floor);
		DrawRoof(screen, roof);
		DrawRightSideWall(screen, rightSideWall);
		DrawLeftSideWall(screen, leftSideWall);

		//myBall.DrawLine(screen, mouseX, mouseY);

			// Drawing a line from the center of the Ball to the location of the Cursor on the screen
			//screen->Line(myBall.GetBallX() + (BALLWIDTH / 2), myBall.GetBallY() + (BALLHEIGHT / 2), mouseX, mouseY, 0xff0000);

		

		// Moving the Ball

		myBall.MoveUpdate(click, release, mouseX, mouseY);


		// Collision Checking
		
		myBall.CollisionCheck(screen); // Checking if the Ball collides with the Roof, Floor, Right-Side Wall or Left-Side Wall

		for (int i = 0; i < 2; i++)  // Checking if the Ball collides with the Spikes
		{
			mySpikes[i].CollisionCheck(myBall.GetBallX(), myBall.GetBallY(), BALLWIDTH, BALLHEIGHT);
		}

		if (Spikes::HasLost()) // If the Ball has collided with the Spikes, then the Game is Lost and Text is printed to the Screen
		{
			myBall.SetXVel(0); // Ball is stopped
			myBall.SetYVel(0); // Ball is stopped
			screen->Print("YOU DIED!", 950, 540, 0xffffff);
		}

		for (int i = 0; i < 7; i++) // Checking if the Ball has collided with the Coins, if yes, the Coins will disappear from the Screen and the amount of Collected Coins is incremented
		{
			coins[i].CollisionCheck(myBall.GetBallX(), myBall.GetBallY(), BALLWIDTH, BALLHEIGHT);
		}

		if (Coin::HasWon()) // If the user collects a total amount of 5 Coins, the Game is Won and Text is printed on the Screen
		{
			myBall.SetXVel(0); // Ball is stopped
			myBall.SetYVel(0); // Ball is stopped
			screen->Print("YOU WIN!", 950, 540, 0xffffff);
		}
		
	}
};