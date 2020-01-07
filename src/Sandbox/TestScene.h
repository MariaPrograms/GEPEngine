#include <GEPEngine/GEPengine.h>
#include <iostream>

class TestScene : public Component
{
public:
	TestScene();
	~TestScene();
	std::shared_ptr<Texture> bun;

private:
	void OnDisplay();
	void OnUpdate();
	void OnGUI();
	
};

