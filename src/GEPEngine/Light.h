#include "Components.h"
#include <glm/glm.hpp>

class Light : public Component
{
public:
	Light();
	~Light();

private:
	glm::vec3 color;
};
