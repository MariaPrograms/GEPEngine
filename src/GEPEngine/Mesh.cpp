#include "Mesh.h"///////////
#include "Exception.h"

#include <fstream>
#include <iostream>
#include <sstream>

void Mesh::AddFace(Face _face)
{

}

std::shared_ptr<Mesh> Mesh::Load(std::string _path)
{
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

	
	std::string currentLine;

	try
	{
		Parse(obj, currentLine);
	}
	catch (std::exception& e)
	{
		throw Exception("Failed to parse model data [" + currentLine + "]");
	}

	return self;
}