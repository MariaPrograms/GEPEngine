#include <glm/glm.hpp>
#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

//!  The Screen class. This class controlls your screen.
/*!
Here is where you will have controll over your screen, like it's size and name. 
*/
class Screen
{
public:
	//!  The constructor class
	/*!
	You do not need to use this as Core creates a refrence to this class for you to use;
	*/
	Screen(glm::vec2 _size);

	//!  The destructor class
	~Screen();

	//!This function is for getting the Screen size
	/*!
	This returns the a vec2 that holds the width and height of the Window.	
	*/
	glm::uvec2 GetSize() { return size; }

	//!This function is to get a refrence to the Window renderer
	/*!
	This returns the a SDL_Window pointer thats is mainly for Core.
	*/
	SDL_Window* GetWindow() { return window; }
	
	//!This function set the window name
	/*!
	This sets the Window name. You pass in a string that will be the name.
	*/
	void ScreenName(std::string _name);

	//!This is called at the end of the Update loop.
	/*!
	This displays frame at the end of the loop with all the current information.
	*/
	void Display();

	//!This is called at the start of the Update loop.
	/*!
	This clears the frame at the start the loop so that the screen is clean to be drawn on. 
	*/
	void Clear();

private:
	glm::uvec2 size;
	SDL_Window* window;
};

