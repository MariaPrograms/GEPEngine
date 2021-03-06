#include "Exception.h"

#include <GL/glew.h>
#include <iostream>


Exception::Exception(const std::string& _message)
{
	message = _message;
}

Exception::~Exception() throw() 
{
}

void Exception::CheckForError()
{
	GLenum err = glGetError();

	if (err == GL_NO_ERROR)
	{
		return;
	}

	throw Exception("OpenGL emitted an error");
}

const char* Exception::What() const throw()
{
	return message.c_str();
}
