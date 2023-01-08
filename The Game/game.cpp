#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <corecrt_math.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include "coin.h"

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
	static Sprite ball(new Surface("assets/ball2.png"), 1);

	static Sprite leftSideWall(new Surface("assets/ground0.png"), 1);
	static Sprite rightSideWall(new Surface("assets/ground0.png"), 1);

	static Sprite floor(new Surface("assets/ground1.png"), 1);
	static Sprite roof(new Surface("assets/ground0.png"), 1);

	static Sprite coin(new Surface("assets/coin.png"), 1);

	static Sprite spikes(new Surface("assets/spikes.png"), 1);

	Coin coins[7]{};

	int ballX = 1000;
	int ballY = 300;
	
	// Draws the ball on the screen
	void Game::DrawBall(Surface* screen, Sprite& ball)
	{
		ball.DrawScaled(ballX, ballY, BALLWIDTH, BALLHEIGHT, screen);
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

	void Game::DrawSpikes(Surface* screen, Sprite& spikes, int x)
	{
		spikes.DrawScaled(x, SCREENHEIGHT - 190, SPIKESWIDTH, SPIKESHEIGHT, screen);
	}


	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		// Initializing an array of coins
		coins[0] = Coin(&coin, 300, 500);
		coins[1] = Coin(&coin, 1000, 700);
		coins[2] = Coin(&coin, 1250, 870);
		coins[3] = Coin(&coin, 300, 880);
		coins[4] = Coin(&coin, 550, 820);
		coins[5] = Coin(&coin, 1400, 160);
		coins[6] = Coin(&coin, 1600, 600);
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

		// Drawing the coins
		for (int i = 0; i < 7; i++)
		{
			coins[i].Draw(screen);
		}

		// Drawing the ball
		DrawBall(screen, ball);

		// Drawing the spikes
		DrawSpikes(screen, spikes, 500);
		DrawSpikes(screen, spikes, 1300);

		// Drawing the following sprites: Floor, Roof, Right-Side Wall, Left-Side Wall
		DrawFloor(screen, floor);
		DrawRoof(screen, roof);
		DrawRightSideWall(screen, rightSideWall);
		DrawLeftSideWall(screen, leftSideWall);

		// Drawing a line from the center of the Ball to the location of the Cursor on the screen
		screen->Line(ballX + (BALLWIDTH / 2), ballY + (BALLHEIGHT / 2), mouseX, mouseY, 0xff0000);

		// Moving the Ball
		if (click && !release)
		{
			//screen->Print("Mouse", 10, 10, 0xffffff);
			dx = (mouseX - ballX); // Calculates the difference between x's
			dy = (mouseY - ballY); // Calculates the difference between y's
			angle = atan2(dy, dx); // Calculates the angle

			// Calculates the velocity 
			xv = cos(angle) * 10;
			yv = sin(angle) * 10;
		}
		if (release) // On release
		{
			click = 0; // Reset the click variable
			release = 0; // Reset the release variable
		}

		if (click == 0) // During release
		{
			ballX += xv; // Moves the ball in the new direction on X axis
			ballY += yv; // Moves the ball in the new direction on Y axis
		}

		// Collision Checking

		if (ballX < 129 || ballX > SCREENWIDTH - 185) // Checking for collision with the Left Side Wall and Right Side Wall
		{
			xv = -xv;
			ballX += xv;
		}
		else if (ballY > SCREENHEIGHT - 215 || ballY < 128) // Checking for collision with the Floor and Roof
		{
			yv = -yv;
			ballY += yv;
		}
		else if ((ballX >= 460 && ballX <= 613) && (ballY >= 840 && ballY <= 890)) // Checking for collision with the Spikes on theleft
		{
			xv = 0;
			yv = 0;
			screen->Print("YOU DIED!", 960, 540, 0xffffff);
		}
		else if ((ballX >= 1255 && ballX <= 1408) && (ballY >= 840 && ballY <= 890)) // Checking for collision with the Spikes onthe right
		{
			xv = 0;
			yv = 0;
			screen->Print("YOU DIED!", 940, 540, 0xffffff);
		}
		

		for (int i = 0; i < 7; i++)
		{
			coins[i].CollisionCheck(ballX, ballY, BALLWIDTH, BALLHEIGHT);
		}
		
		if (Coin::HasWon())
		{
			xv = 0;
			yv = 0;
			screen->Print("YOU WIN!", 950, 540, 0xffffff);
		}
		
	}
};