#include "Resource.h"
#include <rend/rend.h>

class Texture;

class Mesh : public Resource
{
public:
	friend class Resources;
	//void AddFace(Face _face);
	std::shared_ptr<rend::Mesh> GetRender() { return rendMesh; }

private:
	void Load(std::string _path);
	std::shared_ptr<Mesh> self;
	std::shared_ptr<rend::Mesh> rendMesh;
};
