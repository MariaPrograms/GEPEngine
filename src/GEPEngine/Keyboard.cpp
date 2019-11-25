#include "Keyboard.h"
#include <iostream>

Keyboard::Keyboard()
{
	keyState = SDL_GetKeyboardState(NULL);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::IsKeyDown(int _keyCode)
{
	if (keyState[_keyCode]) 
	{
		printf("Boo");
		return true;
	}
	return false;
}

bool Keyboard::IsKeyUp(int _keyCode)
{
	if (!keyState[_keyCode])
	{
		printf("Boo");
		return true;
	}
	return false;
}