#include "Object.h"
#include "Components.h"
#include "Core.h"
#include "Exception.h"
#include <iostream>

Object::Object()
{
}

Object::~Object()
{
}

void Object::Update()
{
	
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		try
		{
			(*it)->OnUpdate();
		}
		catch (Exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			//(*it)->Kill(); // Eject component
			//this?kill(); // Perhaps eject the entire object
		}
		
	}
}

void Object::Desplay()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		try
		{
			(*it)->OnDisplay();
		}
		catch (Exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			//(*it)->Kill(); // Eject component
			//this?kill(); // Perhaps eject the entire object
		}
	}
}

std::shared_ptr<Core> Object::GetCore()
{
	return core.lock();
}

void Object::SetPoition(glm::vec3 _change)
{
	position = _change;

}
void Object::SetRotation(glm::vec3 _change)
{
	rotation = _change;
}

void Object::SetScale(glm::vec3 _change)
{
	scale = _change;
}