#include "Texture.h"
#include "Exception.h"
#include "stb_image.h"

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
}

GLuint Texture::GetTexture()
{
		
}	