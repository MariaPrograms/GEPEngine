#include "Resource.h"

#include <rend/rend.h>
#include <vector>
#include <glm/glm.hpp>


class Font : public Resource
{
public:
	void Load(std::string _path);
	std::shared_ptr<Font> self;

	void DrawFont(std::string _text, glm::vec2 position);

private:
	std::shared_ptr<rend::Font> renderFont;
	
};

