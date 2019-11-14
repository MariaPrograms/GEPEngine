#include "Shader.h"
#include "VertexArrayObject.h"
#include "Exception.h"


std::shared_ptr<Shader> Shader::Create()
{
	GLuint id = 0;
	id = glCreateProgram();

	if (id == 0)
	{
		throw Exception("Failed to create shader program");
	}

	std::shared_ptr<Shader> rtn = std::make_shared<Shader>();
	rtn->id = id;

	return rtn;
}

std::shared_ptr<Shader> Shader::Load(std::string _path)
{
	GLuint vertexShaderId = CompileShaderFile(LoadShaderFile(_path + ".vert"), GL_VERTEX_SHADER);
	GLuint fragmentShaderId = CompileShaderFile(LoadShaderFile(_path + ".frag"), GL_FRAGMENT_SHADER);

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

GLuint Shader::CompileShaderFile(std::string _shaderCode, GLenum _type)
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

std::string Shader::LoadShaderFile(std::string _path)
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

void Shader::Draw(std::shared_ptr<VAO> _vertexArray)
{
	glUseProgram(id);
	glBindVertexArray(_vertexArray->GetVAO());

	glDrawArrays(GL_TRIANGLES, 0, _vertexArray->GetVertexCount());

	glBindVertexArray(0);
	glUseProgram(0);
}

void Shader::SetUniform(std::string _uniform, glm::mat4 _value)
{
	GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(_value));
	glUseProgram(0);
}

void Shader::SetUniform(std::string _uniform, glm::vec4 _value)
{
	GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform4f(uniformId, _value.x, _value.y, _value.z, _value.w);
	glUseProgram(0);
}

void Shader::SetUniform(std::string _uniform, int _value)
{
	GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform1i(uniformId, _value);
	glUseProgram(0);
}

void Shader::SetUniform(std::string _uniform, float _value)
{
	GLint uniformId = glGetUniformLocation(id, _uniform.c_str());

	if (uniformId == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform1f(uniformId, _value);
	glUseProgram(0);
}