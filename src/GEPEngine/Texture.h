#include "Resource.h"

#include <rend/rend.h>

//!  The Texture class. The class where images for meshes and GUI are stored
/*!
This class is for any images helloooooooooo you need for texturing a Mesh or desplaying GUI.
Texture is a child of Resource so please use the Resources class to load one in.
*/

class Texture : public Resource
{
public:
	~Texture();
	//void MakeTexture(unsigned char*_data, int w = 0, int h = 0);#

	//!  This is to get the functions to the class the holds information to render the Texture.
	/*!
	This function is only used for rendering puropuses and is often passed into the Material class.
	This function allows you too see some information on the texture. 
	*/
	std::shared_ptr<rend::Texture> GetRender() { return rendText; }
	
private:
	
	friend class Resources;
	void Load(std::string _path);
	std::shared_ptr<Texture> self;
	std::shared_ptr<rend::Texture> rendText;
};

