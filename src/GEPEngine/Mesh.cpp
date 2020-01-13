#include "Mesh.h"///////////
#include "Exception.h"
#include "Core.h"
#include "Texture.h"

#include <fstream>
#include <iostream>
#include <sstream>

void Mesh::MakeMesh()
{
	rendMesh = core->GetContext()->createMesh();
	std::sr1::shared_ptr<rend::Buffer> buffer = core->GetContext()->createBuffer();
	buffer->add(glm::vec2(0, 0));
	buffer->add(glm::vec2(0, 1));
	buffer->add(glm::vec2(1, 1));

	buffer->add(glm::vec2(1, 1));
	buffer->add(glm::vec2(1, 0));
	buffer->add(glm::vec2(0, 0));
	rendMesh->setBuffer("a_Position", buffer);
}

void Mesh::Load(std::string _path)
{
	rendMesh = core->GetContext()->createMesh();
	std::ifstream f(_path.c_str());
	std::string obj;
	std::string line;

	if (!f.is_open())
	{
		throw Exception("Failed to open model");
	}

	while (!f.eof())
	{
		std::getline(f, line);
		obj += line + "\n";
	}

	rendMesh->parse(obj);

}