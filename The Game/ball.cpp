#include "ball.h"

#define BALLWIDTH 60
#define BALLHEIGHT 60

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

// Default Constructor Method
Ball::Ball()
{
	ballX = 0;
	ballY = 0;
	angle = 0;
	dx = 0;
	dy = 0;
	xv = 0;
	yv = 0;
}

// Constructor Method
Ball::Ball(Sprite* ball, int x, int y)
{
	this->sprite = ball;
	this->ballX = x;
	this->ballY = y;
	angle = 0;
	dx = 0;
	dy = 0;
	xv = 0;
	yv = 0;
}

// Method that will Draw the Sprite on Screen
void Ball::Draw(Tmpl8::Surface* screen) const
{
	sprite->DrawScaled(ballX, ballY, BALLWIDTH, BALLHEIGHT, screen);
}

// Method that will draw a Line starting from the center of the Ball until the coords of the Mouse Cursor
void Ball::DrawLine(Tmpl8::Surface* screen, int mouseX, int mouseY)
{
	screen->Line(ballX + (BALLWIDTH / 2), ballY + (BALLHEIGHT / 2), mouseX, mouseY, 0xff0000);
}

// Method that will make the Ball move in the direction of the Mouse Cursor once a Button is Clicked on the Mouse
void Ball::MoveUpdate(int click, int release, int mouseX, int mouseY)
{
	if (click && !release)
	{
		dx = (mouseX - ballX); // Calculates the difference between x's
		dy = (mouseY - ballY); // Calculates the difference between y's
		angle = atan2(dy, dx); // Calculates the angle

		// Calculates the velocity 
		xv = cos(angle) * 15;
		yv = sin(angle) * 15;
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
}

// Method that checks for collision with the Walls, Floor and Roof and makes the Ball bounce accordingly
void Ball::CollisionCheck(Tmpl8::Surface* screen)
{
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
}

// Method that returns the X-coordinate of the Ball
int Ball::GetBallX()
{
	return ballX;
}

// Method that returns the Y-coordinate of the Ball
int Ball::GetBallY()
{
	return ballY;
}

// Method that sets the Velocity on the X-coordinate
void Ball::SetXVel(int xv)
{
	this->xv = xv;
}

// Method that sets the Velocity on the Y-coordinate
void Ball::SetYVel(int yv)
{
	this->yv = yv;
}

