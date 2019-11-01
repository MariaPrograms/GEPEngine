#include "Shader.h"
#include "VertexArrayObject.h"
#include "Exception.h"

Shader::Shader(std::string path)
{
	id = glCreateProgram();

	GLuint vertexShaderId = CreateShader(LoadShader(path + "Vertex.txt"), GL_VERTEX_SHADER);
	GLuint fragmentShaderId = CreateShader(LoadShader(path + "Fragment.txt"), GL_FRAGMENT_SHADER);
	
	glAttachShader(id, vertexShaderId);
	glAttachShader(id, fragmentShaderId);
	glBindAttribLocation(id, 0, "in_Position");
	glBindAttribLocation(id, 1, "in_Color");
	glBindAttribLocation(id, 2, "in_TexCoord");

	if (glGetError() != GL_NO_ERROR)
	{
		throw Exception("Error");
	}

	glLinkProgram(id);
	GLint success = 0;
	glGetProgramiv(id, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw Exception("Error");
	}

	glDetachShader(id, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(id, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}

Shader::~Shader()
{
	glDeleteProgram(id);
}

GLuint Shader::CreateShader(std::string _shaderCode, GLenum _type)
{
	const GLchar *s = _shaderCode.c_str();
	GLuint shaderId = glCreateShader(_type);
	glShaderSource(shaderId, 1, &s, NULL);
	glCompileShader(shaderId);
	GLint success = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shaderId, maxLength, &maxLength, &errorLog[0]);

		std::cout << &errorLog.at(0) << std::endl;
		throw Exception("");
	}

	return shaderId;
}

std::string Shader::LoadShader(std::string _path)
{
	std::ifstream file(_path.c_str());
	std::string shaderSrc;

	if (!file.is_open())
	{
		throw Exception("Cannot Open File");
	}
	else
	{
		std::cout << "Opened shader file at " << _path << std::endl;
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		shaderSrc += line + "\n";
	}

	file.close();
	std::cout << shaderSrc << std::endl;
	return shaderSrc;
}

void Shader::draw(std::shared_ptr<VAO> vertexArray)
{
	glUseProgram(id);
	glBindVertexArray(vertexArray->GetVAO());

	glDrawArrays(GL_TRIANGLES, 0, vertexArray->GetVertexCount());

	glBindVertexArray(0);
	glUseProgram(0);
}

void Shader::setUniform(std::string uniform, glm::mat4 value)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(value));
	glUseProgram(0);
}

void Shader::setUniform(std::string uniform, glm::vec4 value)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform4f(uniformId, value.x, value.y, value.z, value.w);
	glUseProgram(0);
}

void Shader::setUniform(std::string uniform, int value)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform1i(uniformId, value);
	glUseProgram(0);
}

void Shader::setUniform(std::string uniform, float value)
{
	GLint uniformId = glGetUniformLocation(id, uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform1f(uniformId, value);
	glUseProgram(0);
}