#include "Components.h"

#include <list>
#include <glm/glm.hpp>
#include <functional>

class BoxCollider : public Component
{
public:
	void OnInit();
	void SetOffset(const glm::vec3& offset);
	void SetSize(const glm::vec3& size);
	void IsTrigger(bool _value) { trigger = _value; };
	void RegisterTriggerCallback(const std::function<void()> &_callback);
	void RegisterCollisionCallback(const std::function<void()> &_callback);
	
private:
	void OnUpdate();
	void CollideStaticMesh();
	void CollideBox();
	bool IsColliding(glm::vec3 position, glm::vec3 size);
	glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size);
	
	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 lastPosition;

	bool trigger;
	std::list<std::function<void()>> collisionCallbacks;
	std::list<std::function<void()>> triggerCallbacks;
};
