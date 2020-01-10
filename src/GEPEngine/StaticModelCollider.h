#include "Components.h"
#include "glm/glm.hpp"

#include <rend/rend.h>
#include <vector>

struct Triangle;

struct ColliderColumn
{
	glm::vec3 position;
	glm::vec3 size;
	std::vector<rend::CollitionFace> faces;

	bool IsColliding(glm::vec3 _position, glm::vec3 _size);

	void GetColliding(glm::vec3 _position, glm::vec3 _size, std::vector<rend::CollitionFace>& _collisions);
};

class StaticModelCollider : public Component
{
public:
	void OnInit();

	bool IsColliding(rend::CollitionFace& face, glm::vec3 position, glm::vec3 size);
	bool IsColliding(glm::vec3 position, glm::vec3 size);

	void GetColliding(glm::vec3 position, glm::vec3 size);

	glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size, bool& solved);

private:
	std::vector<std::shared_ptr<ColliderColumn>> columns;
	glm::vec3 extentMin;
	glm::vec3 extentMax;
	float resolution;
	float tryStep;
	float maxStep;
	float tryInc;
	float maxInc;
	std::vector<rend::CollitionFace> collisions;
	std::vector<rend::CollitionFace> all;

	void AddFace(rend::CollitionFace face);
	glm::vec3 FaceNormal(rend::CollitionFace& face);
};