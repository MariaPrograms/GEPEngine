#include "Texture.h"
#include "Exception.h"

Texture::Texture()
{
	glGenTextures(1, &id);
	id = id;
	SetSize(glm::vec2(256, 256));
}

Texture::~Texture()
{
	GLuint delId = id;
	glDeleteTextures(1, &delId);
}

//Texture Sizing 
void Texture::SetSize(glm::uvec2 _size)
{
	dirty = true;
	textureSize = _size;
	pixelData.resize(_size.x * _size.y);
}

const glm::ivec2 Texture::GetSize()
{
	return textureSize;
}

const int Texture::GetWidth()
{
	return textureSize.x;
}

const int Texture::GetHeight()
{
	return textureSize.y;
}

//Pixel Changes
void Texture::SetPixel(glm::uvec2 _position, glm::vec3 _colorRGB)
{
	dirty = true;
	pixelData.at(_position.x * _position.y) = glm::vec4( _colorRGB, 1);
}

void Texture::SetPixel(glm::uvec2 _position, glm::vec4 _colorRGBA)
{
	dirty = true;
	pixelData.at(_position.x * _position.y) = _colorRGBA;
}

const glm::vec4 Texture::GetPixel(glm::uvec2 _position)
{
	return pixelData.at(_position.x * _position.y);
}


GLuint Texture::getId()
{
	if (dirty)
	{
		glBindTexture(GL_TEXTURE_2D, id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureSize.x, textureSize.y, 0, GL_RGBA, GL_FLOAT, &pixelData.at(0));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		dirty = false;
	}

	return id;
}