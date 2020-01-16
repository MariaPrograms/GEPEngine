#include "Light.h"
#include "Materials.h"
#include "Object.h"
#include "Core.h"

void Light::OnInit(glm::vec3 _color)
{
	color = _color;
	object.lock()->GetCore()->AddLight(shared_from_this());
	offset = glm::vec3(0);
}

void Light::SetOffset(glm::vec3 _offset)
{
	offset = _offset;
}

void Light::SetLights(std::shared_ptr<Material> _material)
{
	_material->setUniform("u_LightPos", GetObject()->GetPoition() + offset);
	_material->setUniform("u_LightColor", color);
}