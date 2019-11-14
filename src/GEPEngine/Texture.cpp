#include "Texture.h"
#include "Exception.h"
#include "stb_image.h"

std::shared_ptr<Texture> Texture::Create(glm::uvec2 _size)
{
	GLuint id = 0;
	glGenTextures(1, &id);

	std::shared_ptr<Texture> rtn = std::make_shared<Texture>();
	rtn->id = id;
	rtn->SetSize(_size);

	return rtn;
}

void Texture::Load(std::string _path)
{
	int w = 0;
	int h = 0;
	int bpp = 0;

	const char* path = _path.c_str();
	unsigned char *data = stbi_load(path ,&w, &h, &bpp, 3);

	if (!data)
	{
		throw Exception("Failed to open image");
	}

	SetSize(glm::vec2(w, h));

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			SetPixel(glm::vec2(x, y), glm::vec3(data[r] / 255.0f, data[r + 1] / 255.0f, data[r + 2] / 255.0f));
		}
	}

	stbi_image_free(data);
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


GLuint Texture::GetTexture()
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