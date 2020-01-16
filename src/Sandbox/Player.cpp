#include "Player.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>

void Player::OnInit()
{
	//Movement
	yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	pitch = 0.0f;
	mousePos = GetInput()->MousePosition();
	lastPos = mousePos;
	cameraSpeed = 10;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	
	score = 0;
	maxScore = 50;

	started = false;
	finished = false;

	//Camera
	std::shared_ptr<Camera> cam = GetObject()->AddComponent<Camera>();
	cam->SetCameraOffset(glm::vec3(0, 0, 4));

	//Rendering
	std::shared_ptr<MeshRenderer> rend2 = GetObject()->AddComponent<MeshRenderer>();
	std::shared_ptr<Material> mat2 = std::make_shared<Material>();

	mat2->SetShader(GetCore()->GetResources()->Load<Shader>("Shaders/Light.txt"));
	mat2->SetTexture(GetCore()->GetResources()->Load<Texture>("Textures/Space Ship Textures/RedSkin.png"));

	rend2->SetMesh(GetCore()->GetResources()->Load<Mesh>("Objects/Player Ship.obj"));
	rend2->SetMaterial(mat2);

	//Box Collider
	std::shared_ptr<BoxCollider> box = GetObject()->AddComponent<BoxCollider>();

	//Light
	std::shared_ptr<Light> light = GetObject()->AddComponent<Light>(glm::vec3(1.f));
	light->SetOffset(glm::vec3(0, 0, -4));

	//Sound
	source = GetObject()->AddComponent<SoundSource>();
	source->SetSound(GetCore()->GetResources()->Load<Sound>("Sounds/Background.ogg"));
	source->SetLooping(true);
}

void Player::ResetPos()
{
	yaw = -90.0f;
	pitch = 0.0f;
	GetInput()->ResetMousePosition();
	lastPos = GetInput()->MousePosition();
}

void Player::OnUpdate()
{
	if (GetInput()->IsKeyDown(SDL_SCANCODE_ESCAPE))
	{
		GetCore()->Finish();
	}

	if (started && !finished)
	{
		//Position Movement
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

		float sensitivity = .1f; // change this value to your liking
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
			ResetPos();
		}
		
		if (score >= maxScore)
		{
			finished = true;
		}
	}
}
