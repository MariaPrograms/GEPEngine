#include <glm/glm.hpp>
#include <memory>

class Screen
{
public:
	Screen();
	~Screen();
	glm::uvec2 GetSize() { return size; }

private:
	glm::uvec2 size;
};

