#include <vector>
#include <string> 

#include <SDL2/SDL.h>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	bool IsKeyDown(int _keyCode);
	bool IsKeyUp(int _keyCode);

private:
	const Uint8 *keyState;
};

