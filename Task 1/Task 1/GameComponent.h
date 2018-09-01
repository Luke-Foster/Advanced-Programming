#pragma once
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
#include <windows.h>

using namespace std;

class GameComponent
{

public:
	GameComponent();
	virtual void Update(const tm*);
	friend class DrawableGameComponent;

private:
	int id = 0;
	static int instances;

};

