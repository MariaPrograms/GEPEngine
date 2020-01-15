#include <SDL2/SDL.h>

//!  The World class. 
/*!
This class gives you information about the current hardware environment.
*/
class World
{
public:
	//!  The constructor class
	/*!
	You do not need to use this as Core creates a refrence to this class for you to use;
	*/
	World();
	~World();

	//!This function is for getting the Delta Time
	/*!
	This returns the a float that is the time between frames.
	*/
	float GetDeltaTime();

	//!This function is updating the delta time
	/*!
	This functions is called in the update loop so please don't use it.
	*/
	void SetTime();

private:
	float currentTime;
	float oldTime;
	float deltaTime;
};

