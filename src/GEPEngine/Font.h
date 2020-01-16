#include "Resource.h"

#include <rend/rend.h>
#include <vector>
#include <glm/glm.hpp>

//!  The Font class. The class is still in development.
/*!
please do not use this class as it is still in development and will
not work.
*/
class Font : public Resource
{
public:
	void Load(std::string _path);
	std::shared_ptr<Font> self;

	void DrawFont(std::string _text, glm::vec2 position);

private:
	std::shared_ptr<rend::Font> renderFont;
	
};

