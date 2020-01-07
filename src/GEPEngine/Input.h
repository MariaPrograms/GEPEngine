#include <vector>
#include <string> 

#include <SDL2/SDL.h>

class Input
{
public:
	Input();
	~Input();
	bool IsKeyDown(int _keyCode);
	bool IsKeyUp(int _keyCode);
	void MousePosition(int* x, int* y);
	bool LeftMouseDown();
	bool RightMouseDown();

private:
	const Uint8 *keyState;
};

