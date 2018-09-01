#include "stdafx.h"
#include "DrawableGameComponent.h"

DrawableGameComponent::DrawableGameComponent(int x, int y) : SCREEN_HEIGHT(20), SCREEN_WIDTH(80)
{
	this->x = 0;
	this->y = 0;
	this->direction = Right;
}

void DrawableGameComponent::Update(const tm * eventTime)
{
	struct tm uTime = *eventTime;
	cout << "ID: " << id << " Updated @ " << uTime.tm_hour << ":" << uTime.tm_min << ":" << uTime.tm_sec << endl;

	switch (direction) 
	{
		case Left:
			if (x > -1 && x < SCREEN_WIDTH) 
			{
				x -= 1;
			}
	break;
		case Right:
			if (x > -1 && x < SCREEN_WIDTH) 
			{
				x += 1;
			}
	break;
		case Up:
			if (y > -1 && y < SCREEN_HEIGHT) 
			{
				y += 1;
			}
	break;
		case Down:
			if (y > -1 && y < SCREEN_HEIGHT) 
			{
				y -= 1;
			}
	break;
	}

	if (x < 0)
	{
		x = 0;
	}

	if (y < 0)
	{
		y = 0;
	}

	Draw();
	ChangeDirection();

}

void DrawableGameComponent::ChangeDirection()
{
	Direction previousDirection = direction;

	do
	{
		direction = static_cast<Direction>(rand() % 4);
	} while (previousDirection == direction);

}

void DrawableGameComponent::Draw()
{

	switch (direction) 
	{
	case Left:cout << "Left";
		break;
	case Right:cout << "Right";
		break;
	case Up:cout << "Up";
		break;
	case Down:cout << "Down";
		break;
	default: break;
	}

	cout << " X: " << x << " Y: " << y << endl << endl;

}