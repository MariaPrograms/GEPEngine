#include <GEPEngine/GEPengine.h>
#include <iostream>

class TestScene : public Component
{
public:
	TestScene();
	~TestScene();

private:
	void OnDisplay();
	void OnUpdate();

};

