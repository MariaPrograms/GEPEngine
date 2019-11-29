#include "Components.h"
#include <glm/glm.hpp>
#include <memory>

class Material;

class Light : public Component, public std::enable_shared_from_this<Light>
{
public:
	void SetLights(std::shared_ptr<Material> _shader);
	void OnInit(glm::vec3 _color);

private:
	glm::vec3 color;
};
