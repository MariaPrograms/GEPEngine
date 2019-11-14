#include <GL/glew.h>
#include <glm/glm.hpp>

#include <list>
#include <string>
#include <memory>

class VBO;

class VAO
{
public:
	VAO();
	~VAO();
	void SetBuffer(std::string attribute, std::weak_ptr<VBO> buffer);
	int GetVertexCount();
	GLuint GetVAO();

private:
	GLuint id;
	bool dirty;
	std::list<std::shared_ptr<VBO>> buffers;
	

};

