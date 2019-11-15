#include "Shader.h"
#include "Exception.h"
#include "Core.h"

std::shared_ptr<Shader> Shader::Load(std::string _path)
{
	rendShader = core->GetContext()->createShader();

	std::ifstream file(_path.c_str());
	std::string shaderSrc;

	if (!file.is_open())
	{
		throw Exception("Cannot Open File");
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		shaderSrc += line + "\n";
	}

	file.close();

	rendShader->parse(shaderSrc);
}

Shader::~Shader()
{
	rendShader->~Shader();
}