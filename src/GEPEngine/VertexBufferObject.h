#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <vector>

class VBO
{
public:

	VBO();
	~VBO();
	void Add(glm::vec2 value);
	void Add(glm::vec3 value);
	void Add(glm::vec4 value);
	int GetComponents();
	int getDataSize();
	GLuint getVBO();

private:
	GLuint id;
	std::vector<GLfloat> data;
	int components;
	bool dirty;

};