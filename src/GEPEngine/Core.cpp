#include "Core.h"
#include "Keyboard.h"
#include "World.h"
#include "Object.h"
#include "Screen.h"
#include "Resources.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <AL/al.h>
#include <AL/alc.h>


struct AudioCore
{
	AudioCore()
	{
		device = alcOpenDevice(NULL); // Open up the OpenAL device

		if (device == NULL)
		{
			throw std::exception();
		}

		context = alcCreateContext(device, NULL); // Create audio context

		if (context == NULL)
		{
			alcCloseDevice(device);
			throw std::exception();
		}

		// Set as current context
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::exception();
		}
	}

	~AudioCore()
	{
		alcMakeContextCurrent(NULL);
		alcDestroyContext(context);
		alcCloseDevice(device);
	}

private:
	ALCdevice* device;
	ALCcontext* context;
};

Core::Core()
{
	screen = std::make_shared<Screen>(glm::vec2(800, 600));
	context = rend::Context::initialize();
	resources = std::make_shared<Resources>();
	audioCore = std::make_shared<AudioCore>();
	keyboard = std::make_shared<Keyboard>();
}

Core::~Core()
{
}

std::shared_ptr<Core> Core::Initialize()
{
	std::shared_ptr<Core> rtn(new Core());
	rtn->self = rtn;
	rtn->resources->SetCore(rtn);
	return rtn;
}

std::shared_ptr<Object> Core::AddObject()
{
	std::shared_ptr<Object> obj = std::make_shared<Object>();
	obj->SetSelf(obj);
	obj->SetCore(self);
	objects.push_front(obj);
	return obj;
}

void Core::Start()
{
	playing = true;

	for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		(*it)->Start();
	}

	while (playing)
	{
		screen->Clear();

		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				playing = false;
			}
		}
	
		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			(*it)->Update();
		}
		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			(*it)->Desplay();
		}

		screen->Display();
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

std::shared_ptr<Screen> Core::GetScreen()
{
	return screen;
}

std::shared_ptr<Resources> Core::GetResources()
{
	return resources;
}

std::shared_ptr<rend::Context> Core::GetContext()
{
	return context;
}

std::shared_ptr<Camera> Core::GetCamera()
{
	return mainCamera.lock();
}

std::shared_ptr<Light> Core::GetLights()
{
	return *lights.begin();
}
