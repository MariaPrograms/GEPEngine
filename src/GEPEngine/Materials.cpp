#include "Materials.h"
#include "Shader.h"
#include "Texture.h"

Material::Material()
{

}

Material::~Material()
{

}

void Material::SetShader(std::shared_ptr<Shader> _shader)
{
	shader = _shader;
}

std::shared_ptr<Shader> Material::GetShader()
{
	return shader;
}

void Material::SetValue(std::string _name, std::weak_ptr<Texture> _value)
{

}

void Material::SetValue(std::string _name, float _value)
{

}