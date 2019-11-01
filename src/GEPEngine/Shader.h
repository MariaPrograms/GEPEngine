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
	Shader(std::string _path);
	~Shader();
	void draw(std::shared_ptr<VAO> _vertexArray);
	void setUniform(std::string _uniform, glm::vec4 _value);
	void setUniform(std::string _uniform, float _value);
	void setUniform(std::string _uniform, int _value);
	void setUniform(std::string _uniform, glm::mat4 _value);
	GLuint getId() { return id; }


private:
	std::string LoadShader(std::string _path);
	GLuint CreateShader(std::string _shaderCode, GLenum _type);
	std::vector<GLuint> shaders;
	GLuint id;
};