#include <GEPEngine/GEPengine.h>
#include <iostream>

class Player : public Component
{
public:
	std::shared_ptr<Texture> test;

	void OnInit();

private:
	void OnUpdate();

	glm::vec2 mousePos;
	glm::vec2 lastPos;

	glm::vec3 front;
	glm::vec3 up;

	float cameraSpeed;
	float yaw;
	float pitch;
};

