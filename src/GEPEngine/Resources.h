#include <list>
#include <memory>
#include <vector>
#include <rend/rend.h>

class Resource;
class Core;
class Mesh;

class Resources
{
public:
	Resources(std::shared_ptr<Core> _core);

	template<typename T>
	std::shared_ptr<T> Load(std::string _path)
	{
		std::string resourcePath = "/Resources/" + _path;
		std::shared_ptr<T> resorce = std::make_shared<T>();
		resorce->core = core;
		resorce->self = resorce;
		resorce->path = _path;
		resorce->Load(basePath + resourcePath);
		resources.push_back(resorce);
		return resorce;
	}

	std::shared_ptr<Mesh> MakeMesh();

	//void GetResource(std::string _path)
	//{
	//	for (std::vector<std::shared_ptr<Resource>>::iterator it = resources.begin(); it != resources.end(); it++)
	//	{
	//		if (true)
	//		{

	//		}
	//			*it->OnStart();
	//		
	//	}
	//}

private:
	std::vector<std::shared_ptr<Resource>> resources;
	std::shared_ptr<Core> core;
	std::string basePath;
};