#include "Components.h"

#include <list>
#include <glm/glm.hpp>
#include <functional>

//!  The BoxCollider class. This is used to check for collitions.
/*!
By adding this Component to your object they will then check for collitions with any
other objects that have either a BoxCollider or a StaticMeshCollider.
BoxCollider is a child of Component so please use the Object class to add one
to an Object.

Example..

shared<BoxCollider> example = exampleObject->AddComponent<BoxCollider>();
*/
class BoxCollider : public Component
{
public:
	//!This function initalises the collider
	/*!
	This function is called automaticly when the BoxCollider is created so you 
	don't need to call it yourself.
	*/
	void OnInit();

	//!This function sets the offset
	/*!
	If you wish for the BoxCollider to not be in the centre of the object
	please set this to how much you wish to move the collider.
	*/
	void SetOffset(const glm::vec3& _offset);

	//!This function sets the size of the collider
	/*!
	If you wish for the BoxCollider to be a different size to what is automatically generated 
	then please set this to how big you wish for the collider to be.
	*/
	void SetSize(const glm::vec3& _size);

	//!This function sets if the object with the collider will move.
	/*!
	If you wish for the object with BoxCollider to not move when hit then set the parametier to true
	otherwise it will automatially be set to false.
	*/
	void SetStatic(bool _value);

	//!This function sets if collider will call any Trigger callbacks when it collides with another object
	/*!
	If you wish for the object with BoxCollider to call 
	any trigger callbacks you have then set the parameter to true
	otherwise it will automatially be set to false.
	*/
	void IsTrigger(bool _value) { trigger = _value; };

	//!This function will add a callback for when the BoxCollider is triggered
	/*!
	this function takes a function as a parameter that will be added to a list of callbacks
	that will be called when the BoxCollider is triggered.
	*/
	void RegisterTriggerCallback(const std::function<void()> &_callback);

	//!This function will add a callback for when the BoxCollider is collided with
	/*!
	this function takes a function as a parameter that will be added to a list of callbacks
	that will be called when the BoxCollider is collided with.
	*/
	void RegisterCollisionCallback(const std::function<void()> &_callback);
	bool isColliding;

private:
	void OnUpdate();
	void CollideStaticMesh();
	void CollideBox();
	bool IsColliding(glm::vec3 position, glm::vec3 size);
	glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size);
	
	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 lastPosition;

	bool isStatic;
	bool trigger;
	
	std::list<std::function<void()>> collisionCallbacks;
	std::list<std::function<void()>> triggerCallbacks;
};
