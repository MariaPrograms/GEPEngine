#include "TestScene.h"
#include <SDL2/SDL.h>

TestScene::TestScene()
{
	std::cout << "Made" << std::endl;

}

TestScene::~TestScene()
{


}

void TestScene::OnDisplay()
{
}

void TestScene::OnUpdate()
{
	glm::vec3 pos;

	if (object.lock()->GetCore()->GetKeyboard()->IsKeyDown(SDL_SCANCODE_RIGHT))
	{
		pos = object.lock()->GetPoition() + glm::vec3(1, 0, 0);
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetKeyboard()->IsKeyDown(SDL_SCANCODE_LEFT))
	{
		pos = object.lock()->GetPoition() + glm::vec3(-1, 0, 0);
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetKeyboard()->IsKeyDown(SDL_SCANCODE_UP))
	{
		pos = object.lock()->GetPoition() + glm::vec3(0, 0, 1);
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetKeyboard()->IsKeyDown(SDL_SCANCODE_DOWN))
	{
		pos = object.lock()->GetPoition() + glm::vec3(0, 0, -1);
		object.lock()->SetPoition(pos);
	}

}