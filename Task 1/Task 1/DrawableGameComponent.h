#pragma once
#include "GameComponent.h"

class DrawableGameComponent : public GameComponent
{

public:
	enum Direction {Left, Right, Up, Down};
	Direction direction;
	DrawableGameComponent(int x, int y);
	const int SCREEN_HEIGHT;
	const int SCREEN_WIDTH;
	void Update(const tm* eventTime);

private:
	void ChangeDirection();
	void Draw();
	int x;
	int y;

};

