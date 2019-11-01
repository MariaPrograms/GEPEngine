#include <GEPEngine/GEPengine.h>

class TriangleRenderer : public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	void OnDisplay();

private:
	std::shared_ptr<VBO> vertexPos;
	std::shared_ptr<VBO> vertexCol;
	VAO buffer;
	std::shared_ptr <Shader> shader;
};

