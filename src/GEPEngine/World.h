#include <SDL2/SDL.h>

class World
{
public:
	World();
	~World();
	float GetDeltaTime();
	void SetTime();

private:
	float currentTime;
	float oldTime;
	float deltaTime;
};

