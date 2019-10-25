#include <GEPEngine/GEPengine.h>

class VBO
{
public:
	VBO();
	~VBO();
	void CreatePositionVBO(GLfloat _information[], int _vertex);

private:
	GLuint id;


};

VBO::VBO()
{
}

VBO::~VBO()
{
}

void VBO::CreatePositionVBO(GLfloat _information[], int _vertex)
{
	GLuint positionsVboId = 0;

	glGenBuffers(1, &positionsVboId); // Create a new VBO on the GPU and bind it

	if (!positionsVboId)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_information), _information, GL_STATIC_DRAW);  //Upload a copy of the data from memory into the new VBO
	glVertexAttribPointer(0, _vertex, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}