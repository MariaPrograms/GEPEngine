#include <GEPEngine/GEPengine.h>
#include <iostream>

class TestScene : public Component
{
public:
	TestScene();
	~TestScene();
	std::shared_ptr<Texture> test;

	void OnInit();

private:
	
	void OnUpdate();
	void OnGUI();

	std::shared_ptr<Camera> cam;
	glm::vec2 mousePos;
	glm::vec2 lastPos;
	float cameraSpeed;
	float yaw;
	float pitch;
};

