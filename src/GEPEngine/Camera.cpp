#include "Camera.h"
#include "Object.h"
#include "Core.h"

#include <glm/gtc/matrix_transform.hpp>

void Camera::OnInit()
{
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	perspectiveMatrix = glm::perspective(glm::radians(45.0f), 1.0f, 1.0f, 100.0f);
	object.lock()->GetCore()->SetMainCamera(shared_from_this());
}


glm::mat4 Camera::GetView()
{
	glm::vec3 pos = GetObject()->GetPoition() + offset;
	return glm::lookAt(pos, pos + cameraFront, cameraUp);
}