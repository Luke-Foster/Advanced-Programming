#pragma once
#include "GameComponent.h"

typedef void (*FP)();

class Game
{
public:
	void Add(GameComponent*);
	Game(int maxComponents);
	void Run();
	void SetInitialise(FP init);
	void SetTerminate(FP term);
private:
	int componentCount;
	GameComponent** components;
	FP initialise;
	FP terminate;
	const int TICKS_1000MS;
};

