#include "Resource.h"


class Texture : public Resource
{
public:
	~Texture();

	void SetSize(glm::uvec2 _size);
	void SetPixel(glm::uvec2 _position, glm::vec3 _colorRGB);
	void SetPixel(glm::uvec2 _position, glm::vec4 _colorRGBA);

	const glm::vec4 GetPixel(glm::uvec2 _position);
	const glm::ivec2 GetSize();
	const int GetWidth();
	const int GetHeight();

	GLuint GetTexture();

private:
	std::shared_ptr<Texture> Create(glm::uvec2 _size);
	void Load(std::string _path);

	GLuint id;
	std::shared_ptr<Texture> self;
	std::vector<glm::vec4> pixelData;
	glm::vec2 textureSize;
	bool dirty;
};

