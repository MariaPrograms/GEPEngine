#include <list>
#include <memory>
#include <glm/glm.hpp>

#include "Exception.h"

class Component;
class Core;

class Object //: std::enable_shared_from_this<Object>
{
public:
	Object();
	~Object();

	template<typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		comp->object = self;
		components.push_back(comp);
		return comp;
	}

	template<typename T, typename A>
	std::shared_ptr<T> AddComponent(A _a)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a);
		comp->object = self;
		components.push_back(comp);
		return comp;
	}
	
	template<typename T, typename A, typename B>
	std::shared_ptr<T> AddComponent(A _a, B _b)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b);
		comp->object = self;
		components.push_back(comp);
		return comp;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> AddComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b, _c);
		comp->object = self;
		components.push_back(comp);
		return comp;
	}

	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>();

			if (rtn)
			{
				return rtn;
			}
		}

		throw Exception("Comonent not found");
	}

	//Transform
	void SetPoition(glm::vec3 _pos);
	void SetRotation(glm::vec3 _rot);
	void SetScale(glm::vec3 _scale);
	glm::vec3 GetPoition() { return position; }
	glm::vec3 GetRotate() { return rotation; }
	glm::vec3 GetScale() { return scale; }
	glm::mat4 GetModel() { return myMatrix; }

	void Init();
	void Update();
	void Desplay();
	std::shared_ptr<Core> GetCore();
	void SetSelf(std::shared_ptr<Object> _self) { self = _self; }
	void SetCore(std::shared_ptr<Core> _core) { core = _core; }


private:
	std::weak_ptr<Core> core;
	std::weak_ptr<Object> self;
	std::list<std::shared_ptr<Component>> components;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::mat4 myMatrix;
};



