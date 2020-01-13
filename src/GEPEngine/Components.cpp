#include "Components.h"
#include "Object.h"
#include "Core.h"
#include "Screen.h"
#include "GUI.h"

Component::Component()
{
	

}

Component::~Component()
{
}

std::shared_ptr<Object> Component::GetObject()
{
	return object.lock();
}

std::shared_ptr<Core> Component::GetCore()
{
	return object.lock()->GetCore();
}

std::shared_ptr<Input> Component::GetInput()
{
	return object.lock()->GetCore()->GetInput();
}

std::shared_ptr<GUI> Component::GetGUI()
{
	return object.lock()->GetCore()->GetGUI();
}


std::shared_ptr<Screen> Component::GetScreen()
{
	return object.lock()->GetCore()->GetScreen();
}

std::shared_ptr<World> Component::GetWorld()
{
	return object.lock()->GetCore()->GetWorld();
}
