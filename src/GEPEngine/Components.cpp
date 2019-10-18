#include "Components.h"
#include "Object.h"

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

std::shared_ptr<KeyBoard> Component::GetKeyboard()
{
	std::shared_ptr<KeyBoard> board;
	return board;

}