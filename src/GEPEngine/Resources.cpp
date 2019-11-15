#include "Resources.h"
#include "Exception.h"

#include <fstream>
#include <iostream>
#include <stb_image.h>

std::string Resources::LoadFile(std::string _path)
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

void Resources::LoadTexture(std::string _path, rend::Texture& _text)
{
	int w = 0;
	int h = 0;
	int bpp = 0;

	const char* path = _path.c_str();
	unsigned char *data = stbi_load(path, &w, &h, &bpp, 3);

	if (!data)
	{
		throw Exception("Failed to open image");
	}
	
	_text.setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			_text.setPixel(x, y, glm::vec3(data[r] / 255.0f, data[r + 1] / 255.0f, data[r + 2] / 255.0f));
		}
	}

	stbi_image_free(data);
}