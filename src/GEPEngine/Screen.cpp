#include "Screen.h"
#include "Exception.h"

Screen::Screen(glm::vec2 _size)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	size = _size;
	window = SDL_CreateWindow("GEP Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		size.x, size.y, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw Exception("Failed to Create Window");
	}

	if (glewInit() != GLEW_OK)
	{
		throw Exception("Failed to Init Glew");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	if (!glContext)
	{
		throw Exception("Failed to create OpenGL context");
	}
}

Screen::~Screen()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Screen::Clear()
{
	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::Display()
{
	SDL_GL_SwapWindow(window);
}
