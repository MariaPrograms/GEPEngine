#include "Components.h"
#include "Object.h"
#include "Core.h"

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

std::shared_ptr<Keyboard> Component::GetKeyboard()
{
	return object.lock()->GetCore()->GetKeyboard();
}

std::shared_ptr<World> Component::GetWorld()
{
	return object.lock()->GetCore()->GetWorld();
}
