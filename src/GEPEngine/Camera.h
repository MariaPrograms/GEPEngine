#include <glm/glm.hpp>
#include <memory>
#include "Components.h"

class Camera : public Component, public std::enable_shared_from_this<Camera>
{
public:
	Camera();
	~Camera();
	void SetCameraFront(glm::vec3 _newFront) { cameraFront = _newFront; };
	void SetCameraOffset(glm::vec3 _value) { offset = _value; }
	glm::vec3 GetCameraFront() { return cameraFront; }
	glm::vec3 GetCameraUp() { return cameraUp; }
	glm::mat4 GetView();
	glm::mat4 GetProjection() { return perspectiveMatrix; }
	void OnInit();

private:
	glm::mat4 perspectiveMatrix;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 offset;
};

