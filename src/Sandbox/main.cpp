#include <GEPengine/GEPengine.h>
#include <iostream>

#define shared std::shared_ptr
#define weak std::weak_ptr

void main ()
{
	shared<Core> core = Core::Initialize();
	
	shared<Object> entity = core->AddObject();

	shared<MeshRenderer> testScreen = entity->AddComponent<MeshRenderer>();
	core->Start();
	return;
}