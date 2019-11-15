#include <list>
#include <memory>
#include <vector>
#include <rend/rend.h>

class Resource;
#include "Core.h"


class Resources
{
public:
	template<typename T>
	std::shared_ptr<T> Load(std::string _path)
	{
		std::shared_ptr<T> resorce = std::make_shared<T>();
		resorce->core = core;
		resorce->Load(_path);
		resorce->self = self;

		resources.push_back(resorce);
		return resources;
	}

	std::string LoadFile(std::string _path);
	void LoadTexture(std::string _path, rend::Texture& _text);


private:
	std::vector<std::shared_ptr<Resource>> resources;
	std::shared_ptr<Core> core;
};