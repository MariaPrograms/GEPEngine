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
	void SetMesh(std::weak_ptr<rend::Mesh> _mesh);
	void SetMaterial(std::shared_ptr<Material> _material);

	std::shared_ptr<rend::Mesh> GetMesh();
	std::shared_ptr<Material> GetMaterial();

private:
	void OnDisplay();
	std::weak_ptr<rend::Mesh> mesh;
	std::shared_ptr<Material> material;
};

