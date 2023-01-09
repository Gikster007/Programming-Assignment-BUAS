#include "ball.h"

#define BALLWIDTH 60
#define BALLHEIGHT 60

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

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

void Ball::Draw(Tmpl8::Surface* screen) const
{
	sprite->DrawScaled(ballX, ballY, BALLWIDTH, BALLHEIGHT, screen);
}

void Ball::DrawLine(Tmpl8::Surface* screen, int mouseX, int mouseY)
{
	screen->Line(ballX + (BALLWIDTH / 2), ballY + (BALLHEIGHT / 2), mouseX, mouseY, 0xff0000);
}

void Ball::MoveUpdate(int click, int release, int mouseX, int mouseY)
{
	if (click && !release)
	{
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
}

void Ball::CheckCollision(Tmpl8::Surface* screen)
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
}

int Ball::GetBallX()
{
	return ballX;
}

int Ball::GetBallY()
{
	return ballY;
}

void Ball::SetXVel(int xv)
{
	this->xv = xv;
}

void Ball::SetYVel(int yv)
{
	this->yv = yv;
}

