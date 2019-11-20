#include "Shader.h"
#include "Exception.h"
#include "Core.h"

#include <fstream>
#include <iostream>
#include <sstream>

void Shader::Load(std::string _path)
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