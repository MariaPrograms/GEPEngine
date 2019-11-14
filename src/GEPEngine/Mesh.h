#include "Resource.h"

#include <memory>

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
	//GLuint GetMesh();
	~Mesh();

private:
	std::shared_ptr<Mesh> Create();
	std::shared_ptr<Mesh> Load(std::string _path);
	void Parse(const std::string& data, std::string& currentLine);

	std::shared_ptr<VAO> buffer;

	void splitStringWhitespace(const std::string& input, std::vector<std::string>& output);
	void splitStringLineEnding(const std::string& input, std::vector<std::string>& output);
	void splitString(const std::string& input, char splitter, std::vector<std::string>& output);
};
