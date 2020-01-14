#include "Texture.h"
#include "Core.h"
#include "Exception.h"

#include "stb_image.h"

void Texture::Load(std::string _path)
{
	rendText = core->GetContext()->createTexture();

	int w = 0;
	int h = 0;
	int bpp = 0;

	unsigned char *data = stbi_load(_path.c_str(),&w, &h, &bpp, 4);

	if (!data)
	{
		throw Exception("Failed to open image");
	}

	rendText->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 4 + x * 4;

			rendText->setPixel(x, y, glm::vec4(data[r] / 255.0f, data[r + 1] / 255.0f, data[r + 2] / 255.0f, data[r + 3] / 255.0f));
		}
	}

	stbi_image_free(data);
}

void Texture::MakeTexture(unsigned char* _data, int _w, int _h)
{
	rendText = core->GetContext()->createTexture();

	rendText->setSize(_w, _h);

	for (int y = 0; y < _h; y++)
	{
		for (int x = 0; x < _w; x++)
		{
			int r = y * _w * 3 + x * 3;

			rendText->setPixel(x, y, glm::vec3(_data[r] / 255.0f, _data[r + 1] / 255.0f, _data[r + 2] / 255.0f));
		}
	}
}



Texture::~Texture()
{
	rendText->~Texture();
}