#include "Input.h"
#include <iostream>

Input::Input()
{
	keyState = SDL_GetKeyboardState(NULL);
}

Input::~Input()
{
}

bool Input::IsKeyDown(int _keyCode)
{
	if (keyState[_keyCode]) 
	{
		return true;
	}
	return false;
}

bool Input::IsKeyUp(int _keyCode)
{
	if (!keyState[_keyCode])
	{
		return true;
	}
	return false;
}

void Input::MousePosition(int* x, int* y)
{
	SDL_GetMouseState(x, y);
}

bool Input::LeftMouseDown()
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) 
	{
		return true;
	}

	return false;
}

bool Input::RightMouseDown()
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		return true;
	}

	return false;
}