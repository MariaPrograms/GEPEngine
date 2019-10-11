#include <GEPengine/GEPengine.h>
#include <iostream>

#include "TestScene.h"

#define shared std::shared_ptr
#define weak std::weak_ptr

void main ()
{
	shared<Core> core = Core::Initialize();
	
	shared<Object> entity = core->AddObject();

	shared<TestScene> testScreen = entity->AddComponent<TestScene>();
	core->Start();
	return;
}