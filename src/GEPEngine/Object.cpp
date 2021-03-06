#include <iostream>

#include "Object.h"
#include "Components.h"
#include "Core.h"
#include "Exception.h"

Object::Object()
{
	position = glm::vec3(0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1);
	isActive = true;
}

void Object::Start()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		try
		{
			(*it)->OnStart();
		}
		catch (Exception& e)
		{
			std::cout << "Exception: " << e.What() << std::endl;
			//(*it)->Kill(); // Eject component
			//this?kill(); // Perhaps eject the entire object
		}

	}
}

void Object::Update()
{
	
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		if ((*it)->isActive)
		{
			try
			{
				(*it)->OnUpdate();
			}
			catch (Exception& e)
			{
				std::cout << "Exception: " << e.What() << std::endl;
				//(*it)->Kill(); // Eject component
				//this?kill(); // Perhaps eject the entire object
			}
		}
		
	}
}

void Object::Display()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		if ((*it)->isActive)
		{
			try
			{
				(*it)->OnDisplay();
			}
			catch (Exception& e)
			{
				std::cout << "Exception: " << e.What() << std::endl;
				//(*it)->Kill(); // Eject component
				//this?kill(); // Perhaps eject the entire object
			}
		}
	}
}

void Object::GUI()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		if ((*it)->isActive)
		{
			try
			{
				(*it)->OnGUI();
			}
			catch (Exception& e)
			{
				std::cout << "Exception: " << e.What() << std::endl;
				//(*it)->Kill(); // Eject component
				//this?kill(); // Perhaps eject the entire object
			}
		}
	}
}



std::shared_ptr<Core> Object::GetCore()
{
	return core.lock();
}

glm::mat4 Object::GetModel()
{ 
	glm::mat4 model(1.0f);
	model = glm::translate(model, position);

	model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));

	model = glm::scale(model, scale);
	return model;
}

void Object::SetPoition(glm::vec3 _pos)
{
	position = _pos;
}

void Object::SetScale(glm::vec3 _scale)
{
	scale = _scale;
}

void Object::Move(glm::vec3 _direction)
{
	glm::mat4 temp(1.0f);

	//Translate Based on Pos
	temp = glm::translate(temp, position);

	//Rotate based on Rot
	temp = glm::rotate(temp, glm::radians(rotation.y), glm::vec3(0, 1, 0));

	//tralate basied on direction
	temp = glm::translate(temp, _direction);
	
	position = temp * glm::vec4(0, 0, 0, 1);
}

void Object::SetRotation(glm::vec3 _rot)
{
	rotation = _rot;
}

