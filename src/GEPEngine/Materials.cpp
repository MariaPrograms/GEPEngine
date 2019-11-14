#include "Materials.h"

Material::Material()
{
}

Material::~Material()
{
}

void Material::SetShader(std::weak_ptr<Shader> _shader)
{

}

std::shared_ptr<Shader> Material::GetShader()
{
	return shader.lock();
}

void Material::SetValue(std::string _name, std::weak_ptr<Texture> _value)
{

}

void Material::SetValue(std::string _name, float _value)
{

}