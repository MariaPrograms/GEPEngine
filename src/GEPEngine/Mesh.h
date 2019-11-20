#include "Resource.h"
#include <rend/rend.h>

class Mesh : public Resource
{
public:
	//void AddFace(Face _face);
	friend class Resources;
	std::shared_ptr<rend::Mesh> GetRender() { return rendMesh; }

private:
	void Load(std::string _path);
	std::shared_ptr<Mesh> self;
	std::shared_ptr<rend::Mesh> rendMesh;
};
