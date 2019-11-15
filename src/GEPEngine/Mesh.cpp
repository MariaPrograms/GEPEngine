#include "Mesh.h"///////////
#include "Exception.h"
#include "Core.h"


void Mesh::Load(std::string _path)
{
	std::shared_ptr<rend::Mesh> rendMesh = core->GetContext()->createMesh();
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