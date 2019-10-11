#include "Core.h"
#include "Object.h"

Core::Core()
{

}

Core::~Core()
{

}

std::shared_ptr<Core> Core::Initialize()
{
	std::shared_ptr<Core> rtn(new Core());
	return rtn;
}

std::shared_ptr<Object> Core::AddObject()
{
	std::shared_ptr<Object> obj = std::make_shared<Object>();
	return obj;
}

void Core::Start()
{

}

void Core::Pause()
{

}

void Core::End()
{

}