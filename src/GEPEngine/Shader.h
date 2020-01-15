#include "Resource.h"
#include "rend/rend.h"

//!  The Mesh class. The class where data from the obj files for meshes are stored
/*!
This class is for 3D objects you want to render in your scene.
Mesh is a child of Resource so please use the Resources class to load one in.
*/
class Shader : public Resource
{
public:
	~Shader();

	//!  This is to get the some functions and information for rendering.
	/*!
	This function is only used for rendering puropuses.
	It allows you too add information to the shader that you've loaded in.
	*/
	std::shared_ptr<rend::Shader> GetRender() { return rendShader; }

private:
	friend class Resources;
	void Load(std::string _path);
	std::shared_ptr<Shader> self;
	std::shared_ptr<rend::Shader> rendShader;
};

