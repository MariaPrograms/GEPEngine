#include <vector>
#include <string> 

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Core;

//!  The Input class for any type of hardware inputs.
/*!
Here is where you can get information or controll different inputs from the 
the hardware like mouse to the keyboard.
*/
class Input
{
public:
	//!  The constructor class
	/*!
	You do not need to use this as Core creates a refrence to this class for you to use;
	*/
	Input(std::shared_ptr<Core> core);
	~Input();
	
	//! This function is for the keyboard 
	/*!
	This is to check if a key is has been pressed in that frame.
	*/
	bool IsKeyDown(int _keyCode);

	//! This function is also for the keyboard 
	/*!
	This is to check if a key is hasn't been pressed in that frame.
	*/
	bool IsKeyUp(int _keyCode);

	//! This function is for the Mouse position 
	/*!
	This is to see where the mouse is on the sceen from the top left corner.
	*/
	glm::vec2 MousePosition();

	//! This function is also for the Mouse position 
	/*!
	This is to for the mouse position onto the middle of the screen.
	*/
	void ResetMousePosition();

	//! This function is for the left mouse button
	/*!
	This is to check if the Left mouse button has been pressed.
	*/
	bool LeftMouseDown();

	//! This function is for the right mouse button
	/*!
	This is to check if the right mouse button has been pressed.
	*/
	bool RightMouseDown();

private:
	const Uint8 *keyState;
	std::shared_ptr<Core> core;
};

