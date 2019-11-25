#include <iostream>

#include "Object.h"
#include "Components.h"
#include "Core.h"
#include "Exception.h"

Object::Object()
{
	position = glm::vec3(0, 0, -10);
	myMatrix = glm::translate(glm::mat4(1.0f), position);
}

Object::~Object()
{

}

void Object::Init()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		try
		{
			(*it)->OnInit();
		}
		catch (Exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			//(*it)->Kill(); // Eject component
			//this?kill(); // Perhaps eject the entire object
		}

	}
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

void Object::SetPoition(glm::vec3 _pos)
{
	position = _pos;
	myMatrix = glm::translate(glm::mat4(1.0f), position);

}
void Object::SetRotation(glm::vec3 _rot)
{
	rotation = _rot;
	myMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), rotation);
}

void Object::SetScale(glm::vec3 _scale)
{
	scale = _scale;
	myMatrix = glm::scale(glm::mat4(1.0f), scale);
}