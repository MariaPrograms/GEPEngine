#include <GL/glew.h>
#include <memory>

#include "Components.h"

class VBO;
class VAO;
class Shader;
class Mesh;
class Material;

class MeshRenderer : public Component
{
public:
	MeshRenderer();
	~MeshRenderer();

	void OnInit();
	void SetMesh(std::weak_ptr<Mesh> _mesh);

	std::shared_ptr<Mesh> GetMesh();
	std::shared_ptr<Material> GetMaterial();

private:
	void OnDisplay();

	std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;

	std::shared_ptr<VBO> vertexPos;
	std::shared_ptr<VBO> vertexCol;
	std::shared_ptr <VAO> buffer;
	std::shared_ptr <Shader> shader;
};

