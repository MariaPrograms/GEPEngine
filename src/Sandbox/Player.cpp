#include "Player.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>


void Player::OnInit()
{
	yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	pitch = 0.0f;
	mousePos = GetInput()->MousePosition();
	lastPos = mousePos;
	cameraSpeed = 10;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
}

void Player::OnUpdate()
{
	glm::vec3 pos;

	if (GetInput()->IsKeyDown(SDL_SCANCODE_S))
	{
		pos = object.lock()->GetPoition() - cameraSpeed * front * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (GetInput()->IsKeyDown(SDL_SCANCODE_W))
	{
		pos = object.lock()->GetPoition() + cameraSpeed * front * GetWorld()->GetDeltaTime();
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
	if (pitch > 100.0f)
		pitch = 100.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(direction);

	mousePos = GetInput()->MousePosition();
	GetObject()->SetRotation(glm::vec3(pitch, -yaw - 90, 0));


	if (GetInput()->IsKeyDown(SDL_SCANCODE_Q))
	{
		yaw = -90.0f;
		pitch = 0.0f;
		GetInput()->ResetMousePosition();
		lastPos = GetInput()->MousePosition();
	}
}
