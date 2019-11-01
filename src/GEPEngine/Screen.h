#include <glm/glm.hpp>
#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Screen
{
public:
	Screen(glm::vec2 _size);
	~Screen();
	glm::uvec2 GetSize() { return size; }
	SDL_Window* GetWindow() { return window; }
	void Display();
	void Clear();

private:
	glm::uvec2 size;
	SDL_Window* window;
};

