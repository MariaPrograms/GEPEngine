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

std::shared_ptr<rend::Shader> Material::GetShader()
{
	return shader->GetRender();
}

void Material::SetTexture(std::shared_ptr<Texture> _texture)
{
	texture = _texture;
}

std::shared_ptr<Texture> Material::GetTexture()
{
	return texture;
}

void Material::setUniform(const std::string& _variable, float _value)
{
	shader->GetRender()->setUniform(_variable, _value);
}

void Material::setUniform(const std::string& _variable, glm::mat4 _value)
{
	shader->GetRender()->setUniform(_variable, _value);
}

void Material::setUniform(const std::string& _variable, glm::vec2 _value)
{
	shader->GetRender()->setUniform(_variable, _value);
}

void Material::setUniform(const std::string& _variable, glm::vec3 _value)
{
	shader->GetRender()->setUniform(_variable, _value);
}

void Material::setUniform(const std::string& _variable, glm::vec4 _value)
{
	shader->GetRender()->setUniform(_variable, _value);
}

bool Material::UsesLights()
{
	int check = shader->path.find("Light");
	return check > 0;
}
