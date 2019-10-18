#include "Components.h"
#include "Object.h"
#include "Core.h"
#include "Keyboard.h"

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