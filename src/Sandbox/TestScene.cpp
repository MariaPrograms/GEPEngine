#include "TestScene.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>


TestScene::TestScene()
{
	yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	pitch = 0.0f;
}

TestScene::~TestScene()
{


}


void TestScene::OnInit()
{
	mousePos = GetInput()->MousePosition();
	lastPos = mousePos;
	cam = GetObject()->GetComponent<Camera>();
	cameraSpeed = 2;

	GetObject()->SetRotation(glm::vec3(0, 180, 0));
}

void TestScene::OnUpdate()
{
	glm::vec3 pos;

	if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_D))
	{
		pos = object.lock()->GetPoition() + glm::normalize(glm::cross(cam->GetCameraFront(), cam->GetCameraUp())) * cameraSpeed * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_A))
	{
		pos = object.lock()->GetPoition() - glm::normalize(glm::cross(cam->GetCameraFront(), cam->GetCameraUp())) * cameraSpeed * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_S))
	{
		pos.x = object.lock()->GetPoition().x - cameraSpeed * cam->GetCameraFront().x * GetWorld()->GetDeltaTime();
		pos.z = object.lock()->GetPoition().z - cameraSpeed * cam->GetCameraFront().z * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_W))
	{
		pos.x = object.lock()->GetPoition().x + cameraSpeed * cam->GetCameraFront().x * GetWorld()->GetDeltaTime();
		pos.z = object.lock()->GetPoition().z + cameraSpeed * cam->GetCameraFront().z * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}

	float xoffset = mousePos.x - lastPos.x;
	float yoffset = lastPos.y - mousePos.y; // reversed since y-coordinates go from bottom to top
	lastPos = mousePos;

	float sensitivity = 0.1f; // change this value to your liking
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cam->SetCameraFront(glm::normalize(direction));
	mousePos = GetInput()->MousePosition();

	if (GetInput()->RightMouseDown())
	{
		yaw = -90.0f;
		GetInput()->ResetMousePosition();
		lastPos = GetInput()->MousePosition();
	}
}

void TestScene::OnGUI()
{
	/*float x = GetCore()->GetScreen()->GetSize().x / 4;
	float y = GetCore()->GetScreen()->GetSize().y / 4;
	GetCore()->GetGUI()->DrawGUI(glm::vec4(x * 3, y * 3, 100, 150), test);*/
}
