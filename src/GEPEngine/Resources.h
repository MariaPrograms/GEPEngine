#include <list>
#include <memory>
#include <vector>
#include <rend/rend.h>

class Resource;
class Core;
class Mesh;

//!  The Resources class. This class is used for loading for a Resource
/*!
Use this class to load in a Resource. A Resource is anything loaded from a file like 
Shaders, Textures and Meshes to use in other classes.
*/
class Resources
{
public:
	//!  The Constuctor. 
	/*!
	This is the constructor you do not need to use this as the Core automatically has a refrence to it
	for you to use.
	*/
	Resources(std::shared_ptr<Core> _core);

	//!  The Load Function to load in a Resource. 
	/*!
	Use this function to load in a Resource from a file.
	The parameter _path need be the path to the resource from the Resources folder.
	It will then return a pointer to the newly created Resource.

	Example...

	shared<Texture> example = core->GetResources()->Load<Texture>("Textures/UI/MineButton.png");
	*/
	template<typename T>
	std::shared_ptr<T> Load(std::string _path)
	{
		int position;
		if (CheckResource(_path, position))
		{
			return std::dynamic_pointer_cast<T>(resources.at(position));
		}

		std::string resourcePath = "/Resources/" + _path;
		std::shared_ptr<T> resorce = std::make_shared<T>();
		resorce->core = core;
		resorce->self = resorce;
		resorce->path = _path;
		resorce->Load(basePath + resourcePath);
		resources.push_back(resorce);
		return resorce;
	}

private:
	bool CheckResource(std::string _path, int& _position);

	std::vector<std::shared_ptr<Resource>> resources;
	std::shared_ptr<Core> core;
	std::string basePath;
};