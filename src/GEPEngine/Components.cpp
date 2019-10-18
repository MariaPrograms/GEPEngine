#include "Components.h"
#include "Object.h"
#include "Core.h"

Component::Component()
{
	

}

Component::~Component()
{
}

/*
void Component::OnInit()
{

}

void Component::OnStart()
{

}

void Component::OnUpdate()
{

}

void Component::OnDisplay()
{

}*/

std::shared_ptr<Keyboard> Component::GetKeyboard()
{
	return object.lock()->GetCore()->GetKeyboard();
}

std::shared_ptr<Object> Component::GetObject()
{
	return object.lock();
}

std::shared_ptr<World> Component::GetWorld()
{
	return object.lock()->GetCore()->GetWorld();
}
