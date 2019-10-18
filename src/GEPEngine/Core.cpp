#include "Core.h"
#include "Object.h"
#include "Keyboard.h"
#include "World.h"
#include <iostream>

Core::Core()
{

}

Core::~Core()
{

}

std::shared_ptr<Core> Core::Initialize()
{
	std::shared_ptr<Core> rtn(new Core());
	return rtn;
}

std::shared_ptr<Object> Core::AddObject()
{
	std::shared_ptr<Object> obj = std::make_shared<Object>();
	objects.push_front(obj);
	return obj;
}

void Core::Start()
{
	playing = true;
	for (int i = 0; i < 10; i++)
	{
		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			(*it)->Update();
		}
		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			(*it)->Desplay();
		}
	}

}

void Core::Pause()
{

}

void Core::Finish()
{
	playing = false;
}

std::shared_ptr<Keyboard> Core::GetKeyboard()
{
	return keyboard.lock();
}

std::shared_ptr<World> Core::GetWorld()
{
	return world.lock();
}