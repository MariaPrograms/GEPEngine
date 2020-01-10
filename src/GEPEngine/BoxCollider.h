#include "Components.h"
#include "glm/glm.hpp"

class BoxCollider : public Component
{
public:
	void OnInit();
	void SetOffset(const glm::vec3& offset);
	void SetSize(const glm::vec3& size);
	void IsStationary(bool _value) { stationary = _value; };

private:
	void OnUpdate();
	void CollideStaticMesh();
	void CollideBox();
	bool IsColliding(glm::vec3 position, glm::vec3 size);
	glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size);

	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 lastPosition;
	bool stationary;
};
