#include "Resource.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class VAO;

class Shader : public Resource
{
public:
	~Shader();
	void Draw(std::shared_ptr<VAO> _vertexArray);
	void SetUniform(std::string _uniform, glm::vec4 _value);
	void SetUniform(std::string _uniform, float _value);
	void SetUniform(std::string _uniform, int _value);
	void SetUniform(std::string _uniform, glm::mat4 _value);
	GLuint getId() { return id; }


private:
	std::shared_ptr<Shader> Create();
	std::shared_ptr<Shader> Load(std::string _path);

	std::string LoadShaderFile(std::string _path);
	GLuint CompileShaderFile(std::string _shaderCode, GLenum _type);

	std::vector<GLuint> shaders;
	GLuint id;
};