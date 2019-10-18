#include "Core.h"
#include "Object.h"
#include "Keyboard.h"
#include "World.h"

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
	return obj;
}

void Core::Start()
{
	playing = true;
	for (size_t i = 0; i < 10; i++)
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
	return keyboard;
}

std::shared_ptr<World> Core::GetWorld()
{
	return world;
}