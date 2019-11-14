#include "Mesh.h"
#include "Exception.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

#include <fstream>
#include <iostream>
#include <sstream>

void Mesh::AddFace(Face _face)
{

}


std::shared_ptr<Mesh> Mesh::Create()
{
	std::shared_ptr<Mesh> rtn = std::make_shared<Mesh>();
	return rtn;
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
}

void Mesh::Parse(const std::string& data, std::string& currentLine)
{
	std::vector<std::string> lines;
	splitStringLineEnding(data, lines);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> tcs;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> lmcs;
	std::vector<Face> faces;

	for (std::vector<std::string>::iterator lit = lines.begin(); lit != lines.end(); lit++)
	{
		currentLine = *lit;
		if (lit->length() < 1) continue;

		std::vector<std::string> tokens;
		splitStringWhitespace(*lit, tokens);
		if (tokens.size() < 1) continue;

		if (tokens.at(0) == "v")
		{
			glm::vec3 p(
				atof(tokens.at(1).c_str()),
				atof(tokens.at(2).c_str()),
				atof(tokens.at(3).c_str()));

			positions.push_back(p);
		}
		else if (tokens.at(0) == "vt")
		{
			glm::vec2 tc(atof(tokens.at(1).c_str()), atof(tokens.at(2).c_str()));

			tcs.push_back(tc);
		}
		else if (tokens.at(0) == "vn")
		{
			glm::vec3 n(
				atof(tokens.at(1).c_str()),
				atof(tokens.at(2).c_str()),
				atof(tokens.at(3).c_str()));

			normals.push_back(n);
		}
		else if (tokens.at(0) == "f")
		{
			if (tokens.size() < 4) continue;

			Face f;
			std::vector<std::string> sub;
			splitString(tokens.at(1), '/', sub);
			if (sub.size() >= 1) f.pa = positions.at(atoi(sub.at(0).c_str()) - 1);
			if (sub.size() >= 2) f.tca = tcs.at(atoi(sub.at(1).c_str()) - 1);
			if (sub.size() >= 3) f.na = normals.at(atoi(sub.at(2).c_str()) - 1);
			if (sub.size() >= 4) f.lmca = lmcs.at(atoi(sub.at(3).c_str()) - 1);

			splitString(tokens.at(2), '/', sub);
			if (sub.size() >= 1) f.pb = positions.at(atoi(sub.at(0).c_str()) - 1);
			if (sub.size() >= 2) f.tcb = tcs.at(atoi(sub.at(1).c_str()) - 1);
			if (sub.size() >= 3) f.nb = normals.at(atoi(sub.at(2).c_str()) - 1);
			if (sub.size() >= 4) f.lmcb = lmcs.at(atoi(sub.at(3).c_str()) - 1);

			splitString(tokens.at(3), '/', sub);
			if (sub.size() >= 1) f.pc = positions.at(atoi(sub.at(0).c_str()) - 1);
			if (sub.size() >= 2) f.tcc = tcs.at(atoi(sub.at(1).c_str()) - 1);
			if (sub.size() >= 3) f.nc = normals.at(atoi(sub.at(2).c_str()) - 1);
			if (sub.size() >= 4) f.lmcc = lmcs.at(atoi(sub.at(3).c_str()) - 1);

			faces.push_back(f);
			if (tokens.size() < 5) continue;

			Face fq;
			fq.pa = f.pc;
			fq.tca = f.tcc;
			fq.na = f.nc;
			fq.lmca = f.lmcc;

			splitString(tokens.at(4), '/', sub);
			if (sub.size() >= 1) fq.pb = positions.at(atoi(sub.at(0).c_str()) - 1);
			if (sub.size() >= 2) fq.tcb = tcs.at(atoi(sub.at(1).c_str()) - 1);
			if (sub.size() >= 3) fq.nb = normals.at(atoi(sub.at(2).c_str()) - 1);
			if (sub.size() >= 4) fq.lmcb = lmcs.at(atoi(sub.at(3).c_str()) - 1);

			fq.pc = f.pa;
			fq.tcc = f.tca;
			fq.nc = f.na;
			fq.lmcc = f.lmca;

			faces.push_back(fq);
		}
	}

	if (positions.size() > 0)
	{
		std::shared_ptr<VBO> b = std::make_shared<VBO>();

		for (std::vector<Face>::iterator fit = faces.begin();
			fit != faces.end(); fit++)
		{
			b->Add(fit->pa);
			b->Add(fit->pb);
			b->Add(fit->pc);
		}

		buffer->SetBuffer("a_Position", b);
	}

	if (tcs.size() > 0)
	{
		std::shared_ptr<VBO> b = std::make_shared<VBO>();

		for (std::vector<Face>::iterator fit = faces.begin();
			fit != faces.end(); fit++)
		{
			b->Add(fit->tca);
			b->Add(fit->tcb);
			b->Add(fit->tcc);
		}

	
		buffer->SetBuffer("a_TexCoord", b);
	}

	if (normals.size() > 0)
	{
		std::shared_ptr<VBO> b = std::make_shared<VBO>();

		for (std::vector<Face>::iterator fit = faces.begin();
			fit != faces.end(); fit++)
		{
			b->Add(fit->na);
			b->Add(fit->nb);
			b->Add(fit->nc);
		}

		buffer->SetBuffer("a_Normal", b);
	}

	if (lmcs.size() > 0)
	{
		std::shared_ptr<VBO> b = std::make_shared<VBO>();

		for (std::vector<Face>::iterator fit = faces.begin();
			fit != faces.end(); fit++)
		{
			b->Add(fit->lmca);
			b->Add(fit->lmcb);
			b->Add(fit->lmcc);
		}

		buffer->SetBuffer("a_LightMapCoord", b);
	}
}

void Mesh::splitStringLineEnding(const std::string& input, std::vector<std::string>& output)
{
	std::string curr;

	output.clear();

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input.at(i) == '\n')
		{
			output.push_back(curr);
			curr = "";
		}
		else if (input.at(i) == '\r')
		{
			// Ignore
		}
		else
		{
			curr += input.at(i);
		}
	}

	if (curr.length() > 0)
	{
		output.push_back(curr);
	}
}


void Mesh::splitStringWhitespace(const std::string& input, std::vector<std::string>& output)
{
	std::string curr;

	output.clear();

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input.at(i) == ' ' ||
			input.at(i) == '\r' ||
			input.at(i) == '\n' ||
			input.at(i) == '\t')
		{
			if (curr.length() > 0)
			{
				output.push_back(curr);
				curr = "";
			}
		}
		else
		{
			curr += input.at(i);
		}
	}

	if (curr.length() > 0)
	{
		output.push_back(curr);
	}
}

void Mesh::splitString(const std::string& input, char splitter, std::vector<std::string>& output)
{
	std::string curr;

	output.clear();

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input.at(i) == splitter)
		{
			output.push_back(curr);
			curr = "";
		}
		else
		{
			curr += input.at(i);
		}
	}

	if (curr.length() > 0)
	{
		output.push_back(curr);
	}
}

