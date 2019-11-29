#include "World.h"
#include <SDL2/SDL.h>

float World::GetDeltaTime()
{
	float time = SDL_GetTicks();
	float diff = time - lastTime;
	deltaTime = diff / 1000.0f;
	lastTime = time;
	return deltaTime;
}

World::World()
{
	float lastTime = SDL_GetTicks();
}

World::~World()
{

}