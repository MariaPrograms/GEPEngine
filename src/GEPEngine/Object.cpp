#include "Object.h"
#include "Components.h"
#include "Core.h"

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
		(*it)->OnUpdate();
	}
}

void Object::Desplay()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->OnDisplay();
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