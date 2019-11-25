#include "Camera.h"
#include "Object.h";

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	perspectiveMatrix = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetView()
{
	return glm::inverse(GetObject()->GetModel());
}