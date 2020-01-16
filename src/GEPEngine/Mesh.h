#include "Resource.h"

#include <rend/rend.h>

class Texture;

//!  The Mesh class. The class where data from the obj files for meshes are stored
/*!
This class is for 3D objects you want to render in your scene. 
Mesh is a child of Resource so please use the Resources class to load one in.
*/
class Mesh : public Resource
{
public:
	//!  This is to get information of all the faces of a mesh.
	/*!
	This function is mainly used in collistion. 
	It returns information an each face/trigangle of the mesh you've loaded in. 
	*/
	std::vector<rend::CollitionFace> &GetFaces() { return rendMesh->getTriangles(); }

	//!  This is to get information of the bounds of the mesh
	/*!
	This function is also used maily in collistion.
	It returns a struct that holds to vec3s that 
	store the minimum and maximum points of the Mesh
	*/
	rend::Extent &GetExtent() { return rendMesh->getExtent(); }

	//!  This is to get the some functions and information to render the Mesh.
	/*!
	This function is only used for rendering puropuses.
	and allows you too see some information about the mesh you've loaded in.
	*/
	std::shared_ptr<rend::Mesh> GetRender() { return rendMesh; }

private:
	friend class Resources;

	void Load(std::string _path);

	std::shared_ptr<Mesh> self;
	std::shared_ptr<rend::Mesh> rendMesh;
};
