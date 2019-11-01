#include <GEPEngine/GEPengine.h>

class TriangleRenderer : public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	void OnDisplay();

private:
	GLuint programId;
	std::shared_ptr<VBO> vertexPos;
	std::shared_ptr<VBO> vertexCol;
	std::shared_ptr <VAO> buffer;
	std::shared_ptr <Shader> shader;
};

