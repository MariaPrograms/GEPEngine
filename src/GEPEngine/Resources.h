#include <list>
#include <memory>

class Resource;

class Resources
{
public:
	template<typename T>
	std::shared_ptr<T> Create()
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		resources.push_back(comp);
		return comp;
	}

	template<typename T>
	std::shared_ptr<T> Load(std::string _path)
	{
		for (std::list<std::shared_ptr<Resource>>::iterator it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>();

			if (rtn)
			{
				rtn->Load(_path);
			}
		}

		throw Exception("Comonent not found");
	}


private:
	std::list<std::shared_ptr<Resource>> resources;

};