#include "Resource.h"
#include <rend/rend.h>

class Texture;

class Mesh : public Resource
{
public:
	friend class Resources;
	void MakeMesh();
	std::shared_ptr<rend::Mesh> GetRender() { return rendMesh; }
	std::vector<rend::CollitionFace> &GetFaces() { return rendMesh->getTriangles(); }
	rend::Extent &GetExtent() { return rendMesh->getExtent(); }

private:
	void Load(std::string _path);
	std::shared_ptr<Mesh> self;
	std::shared_ptr<rend::Mesh> rendMesh;
};
