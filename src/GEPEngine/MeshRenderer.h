#include <GL/glew.h>
#include <memory>
#include <rend/rend.h>

#include "Components.h"

class Mesh;
class Material;

class MeshRenderer : public Component
{
public:
	MeshRenderer();
	~MeshRenderer();

	void OnInit();
	void SetMesh(std::shared_ptr<Mesh> _mesh);
	void SetMaterial(std::shared_ptr<Material> _material);

	std::shared_ptr<Mesh> GetMesh();
	std::shared_ptr<Material> GetMaterial();

private:
	void OnDisplay();
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
};

