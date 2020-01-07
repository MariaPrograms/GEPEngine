#include "Input.h"
#include "Core.h"
#include "Screen.h"

#include <iostream>

Input::Input(std::shared_ptr<Core> _core)
{
	keyState = SDL_GetKeyboardState(NULL);
	core = _core;
}

Input::~Input()
{
}

bool Input::IsKeyDown(int _keyCode)
{
	return keyState[_keyCode];
}

bool Input::IsKeyUp(int _keyCode)
{
	if (!keyState[_keyCode])
	{
		return true;
	}
	return false;
}

glm::vec2 Input::MousePosition()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return glm::vec2(x, y);
}

void Input::ResetMousePosition()
{
	SDL_WarpMouseInWindow(core->GetScreen()->GetWindow(), core->GetScreen()->GetSize().x/2, core->GetScreen()->GetSize().y / 2);
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