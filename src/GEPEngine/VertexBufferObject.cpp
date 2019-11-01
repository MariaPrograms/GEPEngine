#include "VertexBufferObject.h"
#include "Exception.h"

VBO::VBO()
{
	dirty = false;
	components = 0;

	glGenBuffers(1, &id); // Create VBO on the GPU and bind it
	if (!id)
	{
		throw std::exception();
	}
}

VBO::~VBO()
{
}

void VBO::Add(glm::vec2 value)
{
	if (!components)
	{
		components = 2;
	}

	if (components != 2)
	{
		throw std::exception();
	}

	data.push_back(value.x);
	data.push_back(value.y);
	dirty = true;
}

void VBO::Add(glm::vec3 value)
{
	if (!components)
	{
		components = 3;
	}

	if (components != 3)
	{
		throw std::exception();
	}

	data.push_back(value.x);
	data.push_back(value.y);
	data.push_back(value.z);
	dirty = true;
}

void VBO::Add(glm::vec4 value)
{
	if (!components)
	{
		components = 4;
	}

	if (components != 4)
	{
		throw std::exception();
	}

	data.push_back(value.x);
	data.push_back(value.y);
	data.push_back(value.z);
	data.push_back(value.w);
	dirty = true;
}

int VBO::GetComponents()
{
	if (!components)
	{
		throw Exception("No Components");
	}

	return components;
}

int VBO::getDataSize()
{
	if (dirty)
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		dirty = false;
	}

	return id;
}

GLuint VBO::getVBO()
{ 
	if (dirty)
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		dirty = false;
	}

	return id;
}