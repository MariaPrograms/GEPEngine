#include <iostream>

#include "VertexArrayObject.h"
#include "Exception.h"
#include "VertexBufferObject.h"


VAO::VAO()
{
	dirty = false;
	glGenVertexArrays(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	buffers.resize(5);
}

VAO::~VAO()
{


}

void VAO::setBuffer(std::string attribute, std::weak_ptr<VBO> buffer)
{
	std::list<std::shared_ptr<VBO>>::iterator it = buffers.begin();

	if (attribute == "in_Position")
	{
		(*it) = buffer.lock();
	}
	else if (attribute == "in_Color")
	{
		it++;
		(*it) = buffer.lock();
	}
	else
	{
		throw std::exception();
	}

	dirty = true;
}

int VAO::GetVertexCount()
{
	std::list<std::shared_ptr<VBO>>::iterator it = buffers.begin();
	if (!(*it))
	{
		throw Exception("bufers info empty");
	}

	return (*it)->GetComponents() / (*it)->getDataSize();
}

GLuint VAO::GetVAO()
{
	if (dirty)
	{
		glBindVertexArray(id);
		int i = 0;
		for (std::list<std::shared_ptr<VBO>>::iterator it = buffers.begin(); it != buffers.end(); it++)
		{
			if ((*it))
			{
				glBindBuffer(GL_ARRAY_BUFFER, (*it)->getVBO());

				glVertexAttribPointer(i, (*it)->GetComponents(), GL_FLOAT, GL_FALSE,
					(*it)->GetComponents() * sizeof(GLfloat), (void *)0);

				glEnableVertexAttribArray(i);
			}
			else
			{
				glDisableVertexAttribArray(i);
			}
			i++;
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		dirty = false;
	}

	return id;
}