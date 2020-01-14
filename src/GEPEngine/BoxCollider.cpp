#include "BoxCollider.h"
#include "StaticModelCollider.h"
#include "Core.h"
#include "Object.h"
#include "Mesh.h"
#include "MeshRenderer.h"

#include <vector>
#include <glm/gtx/string_cast.hpp>

void BoxCollider::OnInit()
{
	std::sr1::shared_ptr<Mesh> model = GetObject()->GetComponent<MeshRenderer>()->GetMesh();
	size = model->GetExtent().max - model->GetExtent().min;
	lastPosition = GetObject()->GetPoition();
}

void BoxCollider::SetOffset(const glm::vec3& _offset)
{
	offset = _offset;
}

void BoxCollider::SetSize(const glm::vec3& _size)
{
	size = _size;
}

void BoxCollider::RegisterTriggerCallback(const std::function<void()>& _callback)
{
	triggerCallbacks.push_back(_callback);
}

void BoxCollider::RegisterCollisionCallback(const std::function<void()>& _callback)
{
	collisionCallbacks.push_back(_callback);
}

void BoxCollider::OnUpdate()
{
	CollideStaticMesh();
	CollideBox();
}

void BoxCollider::CollideBox()
{
	std::vector<std::shared_ptr<Object>> bces;

	GetCore()->GetEntities<BoxCollider>(bces);
	glm::vec3 np = object.lock()->GetPoition() + offset;

	for (std::vector<std::shared_ptr<Object>>::iterator it = bces.begin(); it != bces.end(); it++)
	{
		if (*it == GetObject())
		{
			continue;
		}

		std::shared_ptr<BoxCollider> bc = (*it)->GetComponent<BoxCollider>();

		if (bc->IsColliding(np, size))
		{
			if (trigger)
			{
				for (const auto &cb : triggerCallbacks)
				{
					cb();
				}
			}

			for (const auto &cb : collisionCallbacks)
			{
				cb();
			}

			glm::vec3 sp = bc->GetCollisionResponse(np, size);
			np = sp;
			np = np - offset;
			object.lock()->SetPoition(np);
			lastPosition = np;
		}

		
	}
}

void BoxCollider::CollideStaticMesh()
{
	std::vector<std::shared_ptr<Object>> smces;

	GetCore()->GetEntities<StaticModelCollider>(smces);

	glm::vec3 np = GetObject()->GetPoition() + offset;

	for (std::vector<std::shared_ptr<Object>>::iterator it = smces.begin(); it != smces.end(); it++)
	{
		std::shared_ptr<StaticModelCollider> smc = (*it)->GetComponent<StaticModelCollider>();

		if (smc->CheckForCollision(np, size))
		{
			if (trigger)
			{
				for (const auto &cb : triggerCallbacks)
				{
					cb();
				}
			}
			for (const auto &cb : collisionCallbacks)
			{
				cb();
			}

			bool solved = false;
			glm::vec3 sp = smc->GetCollisionResponse(np, size, solved);

			if (solved)
			{
				np = sp;
			}
			else
			{
				np = lastPosition + offset;
			}

			np = np - offset;
			object.lock()->SetPoition(np);
			lastPosition = np;
		}
	}
}

bool BoxCollider::IsColliding(glm::vec3 position, glm::vec3 size)
{
	glm::vec3 a = object.lock()->GetPoition() + offset;
	glm::vec3& as = this->size;
	glm::vec3& b = position;
	glm::vec3& bs = size;

	if (a.x > b.x) // a right of b
	{
		if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.x - bs.x > a.x + as.x)
		{
			return false;
		}
	}

	if (a.z > b.z) // a front of b
	{
		if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.z - bs.z > a.z + as.z)
		{
			return false;
		}
	}

	if (a.y > b.y) // a above b
	{
		if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.y - bs.y > a.y + as.y)
		{
			return false;
		}
	}

	return true;
}

glm::vec3 BoxCollider::GetCollisionResponse(glm::vec3 position, glm::vec3 size)
{
	float amount = 0.05f;
	float step = 0.05f;

	if (trigger)
	{
		for (const auto &cb : triggerCallbacks)
		{
			cb();
		}
	}

	for (const auto &cb : collisionCallbacks)
	{
		cb();
	}

	while (true)
	{
		if (!IsColliding(position, size)) break;
		position.x += amount;
		if (!IsColliding(position, size)) break;
		position.x -= amount;
		position.x -= amount;
		if (!IsColliding(position, size)) break;
		position.x += amount;
		position.z += amount;
		if (!IsColliding(position, size)) break;
		position.z -= amount;
		position.z -= amount;
		if (!IsColliding(position, size)) break;
		position.z += amount;
		position.y += amount;
		if (!IsColliding(position, size)) break;
		position.y -= amount;
		position.y -= amount;
		if (!IsColliding(position, size)) break;
		position.y += amount;
		amount += step;
	}

	return position;
}

