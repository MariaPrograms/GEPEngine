#include <list>
#include <memory>
#include <glm/glm.hpp>

#include "Exception.h"

class Component;
class Core;

//! The Object class that holds components.
/*!
Here is the class that holds components 
*/
class Object 
{
public:
	Object();
	~Object();

	//! Use this function to add components to an Object
	/*!
	Here is where you add a Component with no paramaeters to the Object.
	*/
	template<typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		comp->object = self;
		comp->OnInit();
		components.push_back(comp);
		return comp;
	}

	//! Use this function to add components to an Object
	/*!
	Here is where you add a Component with one peramator to the Object.
	*/
	template<typename T, typename A>
	std::shared_ptr<T> AddComponent(A _a)
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		comp->object = self;
		comp->OnInit(_a);
		components.push_back(comp);
		return comp;
	}
	
	//! Use this function to add components to an Object
	/*!
	Here is where you add a Component with two peramator to the Object.
	*/
	template<typename T, typename A, typename B>
	std::shared_ptr<T> AddComponent(A _a, B _b)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b);
		comp->object = self;
		comp->OnInit(_a, _b);
		components.push_back(comp);
		return comp;
	}

	//! Use this function to add components to an Object
	/*!
	Here is where you add a Component with three peramator to the Object.
	*/
	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> AddComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b, _c);
		comp->object = self;
		comp->OnInit(_a, _b, _c);
		components.push_back(comp);
		return comp;
	}

	//! Use this function to get a Component from the Object
	/*!
	Here is where you can return specific Component from the Object.
	*/
	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);

			if (rtn)
			{
				return rtn;
			}
		}

		throw Exception("Comonent not found");
	}

	//! Use this function to check if an Object has a Component
	/*!
	This function returns a bool if the Object has the specific Component.
	*/
	template<typename T>
	bool CheckForComponent()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);

			if (rtn)
			{
				return true;
			}
		}

		return false;
	}


	//Transform
	//! This function is to set the Objects position
	/*!
	Use this to set the Object's current position.
	*/
	void SetPoition(glm::vec3 _pos);

	//! This function is to set the Objects rotation
	/*!
	Use this to set the Objects current rotation.
	*/
	void SetRotation(glm::vec3 _rot);

	//! This function is to set the Objects scale
	/*!
	Use this to set the Objects current scale.
	*/
	void SetScale(glm::vec3 _scale);

	//! This function is to get the Objects position
	/*!
	Use this to get the Objects current position.
	*/
	glm::vec3 GetPoition() { return position; }

	//! This function is to get the Objects rotation
	/*!
	Use this to get the Objects current rotation.
	*/
	glm::vec3 GetRotate() { return rotation; }

	//! This function is to get the Objects scale
	/*!
	Use this to get the Objects current scale.
	*/
	glm::vec3 GetScale() { return scale; }

	//! This function is to get the Objects model matrix
	/*!
	Use this to get the Objects models matrix for rendering the mesh.
	*/
	glm::mat4 GetModel();

	//! This function is to move the object by a certain amount
	/*!
	Use this to move the Objects in a certain direction for an amount.
	*/
	void Move(glm::vec3 _direction);
	
	//! This function is to get access to Core 
	/*!
	Use this in Components to get access to the Core and it's functions
	*/
	std::shared_ptr<Core> GetCore();

private:
	friend class Core;
	void Start();
	void Update();
	void Display();
	void GUI();
	void SetSelf(std::shared_ptr<Object> _self) { self = _self; }
	void SetCore(std::shared_ptr<Core> _core) { core = _core; }

	std::weak_ptr<Core> core;
	std::weak_ptr<Object> self;
	std::list<std::shared_ptr<Component>> components;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};



