#include "Movement.h"

Movement::Movement()
{
}

Movement::~Movement()
{


}

void Movement::OnUpdate()
{
	glm::vec3 pos;

	if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_D))
	{
		pos = object.lock()->GetPoition() - glm::vec3(1, 0, 0) * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_A))
	{
		pos = object.lock()->GetPoition() + glm::vec3(1, 0, 0)  * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_S))
	{
		pos = object.lock()->GetPoition() - glm::vec3(0, 0, 1) * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
	else if (object.lock()->GetCore()->GetInput()->IsKeyDown(SDL_SCANCODE_W))
	{
		pos = object.lock()->GetPoition() + glm::vec3(0, 0, 1) * GetWorld()->GetDeltaTime();
		object.lock()->SetPoition(pos);
	}
}
