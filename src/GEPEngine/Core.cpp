#include "Core.h"
#include "Input.h"
#include "World.h"
#include "Object.h"
#include "Screen.h"
#include "Resources.h"
#include "Camera.h"
#include "GUI.h"
#include "Exception.h"
#include <glm/glm.hpp>
#include <AL/al.h>
#include <AL/alc.h>

//!  The AudioCore class. This initialises the audio software.
struct AudioCore
{
	AudioCore()
	{
		device = alcOpenDevice(NULL); // Open up the OpenAL device

		if (device == NULL)
		{
			throw Exception("unable to open device");
		}

		context = alcCreateContext(device, NULL); // Create audio context

		if (context == NULL)
		{
			alcCloseDevice(device);
			throw Exception("Unable to create context");
		}

		// Set as current context
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw Exception("Unable to make context current");
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

Core::Core(glm::vec2 _screenSize)
{
	screen = std::make_shared<Screen>(_screenSize);
	context = rend::Context::initialize();
	audioCore = std::make_shared<AudioCore>();
	world = std::make_shared<World>();
}

Core::~Core()
{
}

std::shared_ptr<Core> Core::Initialize(glm::vec2 _screenSize)
{
	std::shared_ptr<Core> rtn(new Core(_screenSize));
	rtn->self = rtn;
	rtn->input = std::make_shared<Input>(rtn);
	rtn->resources = std::make_shared<Resources>(rtn);
	rtn->gui = std::make_shared<GUI>(rtn);
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
		world->SetTime();
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
			if ((*it)->isActive)
			{
				(*it)->Update();
				(*it)->Display();
			}
		}

		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			if ((*it)->isActive)
			{
				(*it)->GUI();
			}
		}

		screen->Display();
	}
}

void Core::Finish()
{
	playing = false;
}

std::shared_ptr<Input> Core::GetInput()
{
	return input;
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

std::shared_ptr<GUI> Core::GetGUI()
{
	return gui;
}
