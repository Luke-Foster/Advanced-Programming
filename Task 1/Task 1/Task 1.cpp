// Task 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DrawableGameComponent.h"
#include "Game.h"
#include "GameComponent.h"

void Initialise()
{
	cout << "Initialising game" << endl;
}

void Terminate()
{
	cout << "Terminating game" << endl;
}

int main()
{
	Game *G = new Game(2);
	
	G->SetInitialise(*Initialise);
	G->SetTerminate(*Terminate);
	G->Add(new GameComponent);
	G->Add(new DrawableGameComponent(0, 0));
	G->Run();

	system("PAUSE");
    return 0;
}

