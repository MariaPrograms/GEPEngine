#include "TriangleRenderer.h"

const GLfloat positions[] = 
{
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
};

const GLfloat colors[] = 
{
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f
};


TriangleRenderer::TriangleRenderer()
{
	/*if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}
	*/
}

TriangleRenderer::~TriangleRenderer()
{

}

void TriangleRenderer::OnDisplay()
{

}