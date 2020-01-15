#include "StaticModelCollider.h"
#include "MeshRenderer.h"
#include "Object.h"
#include "Mesh.h"


#include <cmath>

int triBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3]);

bool ColliderColumn::IsColliding(glm::vec3 _position, glm::vec3 _size)
{
	for (std::vector<rend::CollitionFace>::iterator i = faces.begin(); i != faces.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->pa.x;
		f[0][1] = i->pa.y;
		f[0][2] = i->pa.z;
		f[1][0] = i->pb.x;
		f[1][1] = i->pb.y;
		f[1][2] = i->pb.z;
		f[2][0] = i->pc.x;
		f[2][1] = i->pc.y;
		f[2][2] = i->pc.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;

		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			return true;
		}
	}

	return false;
}

void ColliderColumn::GetColliding(glm::vec3 _position, glm::vec3 _size, std::vector<rend::CollitionFace>& _collisions)
{
	for (std::vector<rend::CollitionFace>::iterator i = faces.begin(); i != faces.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->pa.x;
		f[0][1] = i->pa.y;
		f[0][2] = i->pa.z;
		f[1][0] = i->pb.x;
		f[1][1] = i->pb.y;
		f[1][2] = i->pb.z;
		f[2][0] = i->pc.x;
		f[2][1] = i->pc.y;
		f[2][2] = i->pc.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;
		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			_collisions.push_back(*i);
		}
	}
}

void StaticModelCollider::OnInit()
{
	resolution = 5;
	tryStep = 0.01f;
	maxStep = 1.0f;
	tryInc = 0.01f;
	maxInc = 0.5f;

	std::sr1::shared_ptr<Mesh> model = GetObject()->GetComponent<MeshRenderer>()->GetMesh();
	extentMin = model->GetExtent().min;
	extentMax = model->GetExtent().max;

	// Create collision columns
	glm::vec3 size = (extentMax - extentMin);
	glm::vec3 colSize = size / resolution;
	colSize.y = size.y;

	for (size_t y = 0; y < resolution; y++)
	{
		glm::vec3 pos = extentMin + colSize / 2.0f;
		pos.z += (float)y * colSize.z;

		for (size_t x = 0; x < resolution; x++)
		{
			std::sr1::shared_ptr<ColliderColumn> cc = std::sr1::make_shared<ColliderColumn>();
			cc->size = colSize;

			// Overlap columns for sub column collision
			//cc->size.x += 1.0f;
			//cc->size.z += 1.0f;
			// Conflicts with x / y index generation when matching column to collide with.
			// Done when adding face instead.

			cc->position = pos;
			columns.push_back(cc);
			pos.x += colSize.x;
		}
	}

	for (size_t f = 0; f < model->GetFaces().size(); f++)
	{
		rend::CollitionFace face = model->GetFaces().at(f);
		AddFace(face);
	}
}

void StaticModelCollider::RegisterTriggerCallback(const std::function<void()>& _callback)
{
	triggerCallbacks.push_back(_callback);
}

void StaticModelCollider::RegisterCollisionCallback(const std::function<void()>& _callback)
{
	collisionCallbacks.push_back(_callback);
}

bool StaticModelCollider::IsColliding(rend::CollitionFace& _face, glm::vec3 _position, glm::vec3 _size)
{
	float f[3][3] = { 0 };
	f[0][0] = _face.pa.x;
	f[0][1] = _face.pa.y;
	f[0][2] = _face.pa.z;
	f[1][0] = _face.pb.x;
	f[1][1] = _face.pb.y;
	f[1][2] = _face.pb.z;
	f[2][0] = _face.pc.x;
	f[2][1] = _face.pc.y;
	f[2][2] = _face.pc.z;

	float bc[3] = { 0 };
	bc[0] = _position.x;
	bc[1] = _position.y;
	bc[2] = _position.z;
	float bhs[3] = { 0 };
	bhs[0] = _size.x / 2.0f;
	bhs[1] = _size.y / 2.0f;
	bhs[2] = _size.z / 2.0f;

	if (triBoxOverlap(bc, bhs, f))
	{
		return true;
	}

	return false;
}

bool StaticModelCollider::IsColliding(glm::vec3 _position, glm::vec3 _size)
{
	for (std::vector<rend::CollitionFace>::iterator i = collisions.begin(); i != collisions.end(); i++)
	{
		float f[3][3] = { 0 };
		f[0][0] = i->pa.x;
		f[0][1] = i->pa.y;
		f[0][2] = i->pa.z;
		f[1][0] = i->pb.x;
		f[1][1] = i->pb.y;
		f[1][2] = i->pb.z;
		f[2][0] = i->pc.x;
		f[2][1] = i->pc.y;
		f[2][2] = i->pc.z;

		float bc[3] = { 0 };
		bc[0] = _position.x;
		bc[1] = _position.y;
		bc[2] = _position.z;
		float bhs[3] = { 0 };
		bhs[0] = _size.x / 2.0f;
		bhs[1] = _size.y / 2.0f;
		bhs[2] = _size.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			return true;
		}
	}

	return false;
}

void StaticModelCollider::GetColliding(glm::vec3 _position, glm::vec3 _size)
{
	glm::vec3 pos = _position - extentMin;
	size_t x = (size_t)(pos.x / columns.at(0)->size.x);
	size_t y = (size_t)(pos.z / columns.at(0)->size.z);
	size_t idx = y * resolution + x;

	if (idx >= columns.size()) return;

	columns.at(idx)->GetColliding(_position, _size, collisions);
}

glm::vec3 StaticModelCollider::FaceNormal(rend::CollitionFace& face)
{
	glm::vec3 N = glm::cross
	(
		glm::vec3(face.pb) - glm::vec3(face.pc), 
		glm::vec3(face.pa) - glm::vec3(face.pc)
	);

	return glm::normalize(N);
}



bool StaticModelCollider::CheckForCollision(glm::vec3 _position, glm::vec3 _size)
{
	glm::vec3 solve = _position;
	collisions.clear();
	GetColliding(solve, _size);

	return IsColliding(solve, _size);
}

glm::vec3 StaticModelCollider::GetCollisionResponse(glm::vec3 _position, glm::vec3 _size, bool& _solved)
{
	glm::vec3 solve = _position;
	_solved = false;

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


	// Favour Y faces first.
	for (std::vector<rend::CollitionFace>::iterator it = collisions.begin(); it != collisions.end(); it++)
	{
		if (!IsColliding(*it, solve, _size))
		{
			continue;
		}

		glm::vec3 n = FaceNormal(*it);
		//std::cout << n.x << " " << n.y << " " << n.z << std::endl;
		if (n.y < fabs(n.x) + fabs(n.z)) continue;

		float amount = tryStep;

		while (true)
		{
			solve = solve + n * amount;

			if (!IsColliding(*it, solve, _size))
			{
				break;
			}

			solve = solve - n * amount;
			amount += tryStep;

			if (amount > maxStep)
			{
				break;
			}
		}
	}

	if (!IsColliding(solve, _size))
	{
		_solved = true;
		return solve;
	}

	float amount = tryInc;

	while (true)
	{
		glm::vec3 total;

		// Try to uncollide using face normals
		for (std::vector<rend::CollitionFace>::iterator it = collisions.begin(); it != collisions.end(); it++)
		{
			glm::vec3 n = FaceNormal(*it);
			total = total + n;
			solve = solve + n * amount;

			if (!IsColliding(solve, _size))
			{
				_solved = true;
				return solve;
			}

			solve = solve - n * amount;
		}

		// Try to uncollide using averaged face normals
		total = glm::normalize(total);
		solve = solve + total * amount;

		if (!IsColliding(solve, _size))
		{
			_solved = true;
			return solve;
		}

		solve = solve - total * amount;
		amount += tryInc;

		if (amount > maxInc)
		{
			break;
		}
	}

	_solved = false;
	return _position;
}

void StaticModelCollider::AddFace(rend::CollitionFace _face)
{
	float f[3][3] = { 0 };
	f[0][0] = _face.pa.x;
	f[0][1] = _face.pa.y;
	f[0][2] = _face.pa.z;
	f[1][0] = _face.pb.x;
	f[1][1] = _face.pb.y;
	f[1][2] = _face.pb.z;
	f[2][0] = _face.pc.x;
	f[2][1] = _face.pc.y;
	f[2][2] = _face.pc.z;

	bool found = false;

	for (size_t i = 0; i < columns.size(); i++)
	{
		float bc[3] = { 0 };
		bc[0] = columns.at(i)->position.x;
		bc[1] = columns.at(i)->position.y;
		bc[2] = columns.at(i)->position.z;

		// Overlap columns for sub column collision
		glm::vec3 s = columns.at(i)->size;
		s.x += 1;
		s.z += 1;

		float bhs[3] = { 0 };
		bhs[0] = s.x / 2.0f;
		bhs[1] = s.y / 2.0f;
		bhs[2] = s.z / 2.0f;

		if (triBoxOverlap(bc, bhs, f))
		{
			columns.at(i)->faces.push_back(_face);
			//std::cout << "Pushing face into " << i << std::endl;
			found = true;
		}
	}

	if (!found)
	{
		/*std::cout << "Assertion failed: Face not in spacial partition" << std::endl;
		std::cout << f[0][0] << ", " << f[0][1] << ", " << f[0][2] << std::endl;
		std::cout << f[1][0] << ", " << f[1][1] << ", " << f[1][2] << std::endl;
		std::cout << f[2][0] << ", " << f[2][1] << ", " << f[2][2] << std::endl;
		std::cout << "Expect collision errors" << std::endl;*/
		//throw Exception("Face not assigned spatial partition");
	}

	
}
