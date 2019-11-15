#include <list>
#include <memory>
#include <vector>
#include <rend/rend.h>

class Resource;
class Core;


class Resources
{
public:
	template<typename T>
	std::shared_ptr<T> Load(std::string _path)
	{
		std::shared_ptr<T> resorce = std::make_shared<T>();
		resorce->core = core;
		resorce->self = resorce;
		
		resorce->Load("D:\\Programming Projects\\GEPEngine\\Resources\\" + _path);

		resources.push_back(resorce);
		return resorce;
	}

	Resources();
	void SetCore(std::shared_ptr<Core> _core) { core = _core; }

private:
	std::vector<std::shared_ptr<Resource>> resources;
	std::shared_ptr<Core> core;
};