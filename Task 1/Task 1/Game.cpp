#include "stdafx.h"
#include "Game.h"

void Game::Add(GameComponent* component)
{
	components[componentCount] = component;
	componentCount++;
}

Game::Game(int maxComponents) : TICKS_1000MS(1000)
{
	components = new GameComponent*[maxComponents];
}

void Game::Run()
{
	initialise();
	
	__time32_t rawTime;
	struct tm time;

	for (int a = 0; a < 5; a++)
	{
		for (int i = 0; i < componentCount; i++)
		{
			_time32(&rawTime);
			_localtime32_s(&time, &rawTime);
			components[i]->Update(&time);
		}
		Sleep(TICKS_1000MS);
	}
	terminate();
}

void Game::SetInitialise(FP init)
{
	initialise = init;
}

void Game::SetTerminate(FP term)
{
	terminate = term;
}