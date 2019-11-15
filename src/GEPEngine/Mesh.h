#include "Resource.h"
#include <memory>
#include <glm/glm.hpp>
class VAO;

struct Face
{
	glm::vec3 pa;
	glm::vec3 pb;
	glm::vec3 pc;

	glm::vec2 tca;
	glm::vec2 tcb;
	glm::vec2 tcc;

	glm::vec3 na;
	glm::vec3 nb;
	glm::vec3 nc;

	glm::vec2 lmca;
	glm::vec2 lmcb;
	glm::vec2 lmcc;
};

class Mesh : public Resource
{
public:
	void AddFace(Face _face);
	~Mesh();

private:
	std::shared_ptr<Mesh> Load(std::string _path);
	std::shared_ptr<Mesh> self;
};
