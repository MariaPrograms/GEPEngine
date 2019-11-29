#include "Light.h"
#include "Materials.h"
#include "Object.h"
#include "Core.h"

void Light::OnInit(glm::vec3 _color)
{
	color = _color;
	object.lock()->GetCore()->AddLight(shared_from_this());
}

void Light::SetLights(std::shared_ptr<Material> _material)
{
	_material->setUniform("u_LightPos", GetObject()->GetPoition());
	_material->setUniform("u_LightColor", color);
}