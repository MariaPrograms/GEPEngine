#include <glm/glm.hpp>

#include "Components.h"

class Camera : public Component
{
public:
	Camera();
	~Camera();
	glm::mat4 GetView();
	glm::mat4 GetProjection();

private:
	glm::mat4 perspectiveMatrix;

};

