#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class VAO;
class Shader
{
public:
	Shader(std::string vert, std::string frag);
	~Shader();
	void draw(VAO *vertexArray);
	void setUniform(std::string uniform, glm::vec4 value);
	void setUniform(std::string uniform, float value);
	void setUniform(std::string uniform, int value);
	void setUniform(std::string uniform, glm::mat4 value);
	GLuint getId() { return id; }


private:
	GLuint id;
};