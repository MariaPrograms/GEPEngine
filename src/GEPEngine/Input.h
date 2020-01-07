#include <vector>
#include <string> 

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Core;

class Input
{
public:
	Input(std::shared_ptr<Core> core);
	~Input();
	
	bool IsKeyDown(int _keyCode);
	bool IsKeyUp(int _keyCode);
	glm::vec2 MousePosition();
	void ResetMousePosition();
	bool LeftMouseDown();
	bool RightMouseDown();

private:
	const Uint8 *keyState;
	std::shared_ptr<Core> core;
};

