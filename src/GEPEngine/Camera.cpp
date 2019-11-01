#include "Camera.h"
#include "Object.h";

Camera::Camera()
{
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetView()
{
	return glm::inverse(GetObject()->GetModel());
}