#include <list>
#include <memory>
#include <glm/glm.hpp>

class Component;
class Core;

class Object
{
public:
	Object();
	~Object();

	template<typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		components.push_back(comp);
		return comp;
	}

	template<typename T, typename A>
	std::shared_ptr<T> AddComponent(A _a)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a);
		components.push_back(comp);
		return comp;
	}
	
	template<typename T, typename A, typename B>
	std::shared_ptr<T> AddComponent(A _a, B _b)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b);
		components.push_back(comp);
		return comp;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> AddComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b, _c);
		components.push_back(comp);
		return comp;
	}
	void SetPoition(glm::vec3 _change);
	void SetRotation(glm::vec3 _change);
	void SetScale(glm::vec3 _change);
	void Update();
	void Desplay();
	std::shared_ptr<Core> GetCore();

private:
	std::weak_ptr<Core> core;
	std::list<std::shared_ptr<Component>> components;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};



