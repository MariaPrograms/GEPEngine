#include <list>
#include <memory>

class Component;

class Object
{
public:
	Object();
	~Object();

	template<typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> comp = std::make_shared<T>;
		components.push_back(comp);
		return comp;
	}
	//std::shared_ptr<class T> GetComponent();

private:
	std::list<std::shared_ptr<Component>> components;
	void Update();
	void Desplay();
};



