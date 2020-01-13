#include "World.h"

float World::GetDeltaTime()
{
	return deltaTime;
}

void World::SetTime()
{
	currentTime = SDL_GetTicks();

	deltaTime = (double)(currentTime - oldTime) / 1000;

	oldTime = currentTime;	
}

World::World()
{
	currentTime = SDL_GetTicks();
	oldTime = 0;
	deltaTime = 0;
}

World::~World()
{

}