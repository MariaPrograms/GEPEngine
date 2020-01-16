#include <GEPEngine/GEPengine.h>
#include <iostream>

class Player : public Component
{
public:
	void OnInit();
	void ResetPos();

	std::shared_ptr<SoundSource> source;

	int score;
	int maxScore;
	bool started;
	bool finished;
	
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

