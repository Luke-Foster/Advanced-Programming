#include "stdafx.h"
#include "GameComponent.h"

int GameComponent::instances = 0;

GameComponent::GameComponent()
{
	instances++;
	id = instances;
}

void GameComponent::Update(const tm* eventTime)
{
	struct tm uTime = *eventTime; 
	cout << "ID: " << id << " Updated @ " << uTime.tm_hour << ":" << uTime.tm_min << ":" << uTime.tm_sec << endl;
}