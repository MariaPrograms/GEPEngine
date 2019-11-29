#include <glm/glm.hpp>
#include <memory>
#include "Components.h"

class Camera : public Component, public std::enable_shared_from_this<Camera>
{
public:
	Camera();
	~Camera();
	glm::mat4 GetView();
	glm::mat4 GetProjection() { return perspectiveMatrix; }
	void OnInit();

private:
	glm::mat4 perspectiveMatrix;

};

