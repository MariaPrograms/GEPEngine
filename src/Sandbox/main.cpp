#include <GEPengine/GEPengine.h>
#include <iostream>

#include "TriangleRenderer.h"

#define shared std::shared_ptr
#define weak std::weak_ptr

void main ()
{
	shared<Core> core = Core::Initialize();
	
	shared<Object> entity = core->AddObject();

	shared<TriangleRenderer> testScreen = entity->AddComponent<TriangleRenderer>();
	core->Start();
	return;
}