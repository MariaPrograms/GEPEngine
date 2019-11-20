#include "Mesh.h"///////////
#include "Exception.h"
#include "Core.h"

#include <fstream>
#include <iostream>
#include <sstream>

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