#include "Camera.h"
#include "Object.h"
#include "Core.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	
}



Camera::~Camera()
{

}

void Camera::OnInit()
{
	perspectiveMatrix = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	object.lock()->GetCore()->SetMainCamera(shared_from_this());
}


glm::mat4 Camera::GetView()
{
	return glm::inverse(GetObject()->GetModel());
}