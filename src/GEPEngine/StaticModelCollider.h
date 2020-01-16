#include "Components.h"
#include "glm/glm.hpp"

#include <rend/rend.h>
#include <vector>
#include <functional>
#include <list>

struct Triangle;


//!The ColliderColumn struct is used in StaticModelCollider to have colloums for efficency 
/*!
This struct is for StaticModelCollider to help with 
effiency and not check for collitions that are far from the mesh
*/
struct ColliderColumn
{
	glm::vec3 position;//!the position of the column
	glm::vec3 size;//!the size of the column
	std::vector<rend::CollitionFace> faces;//!the faces of the meshes in the column

	//!This function is to check for collitions in the position in the column
	bool IsColliding(glm::vec3 _position, glm::vec3 _size);

	//!Returns the faces that are colliding in the column
	void GetColliding(glm::vec3 _position, glm::vec3 _size, std::vector<rend::CollitionFace>& _collisions);
};

//!The StaticModelCollider class. This is used to check for collitions on static Objects.
/*!
This class is for Objects that don't move, are static, and are a bit to complex for a BoxCollider.
This will check if any other Objects with BoxColliders have collided with it.
StaticModelCollider is a child of Component so please use the Object class to add one
to an Object.

Example..

shared<StaticModelCollider> example = exampleObject->AddComponent<StaticModelCollider>();
*/
class StaticModelCollider : public Component
{
public:
	//!This function initalises the collider
	/*!
	This function is called automaticly when the StaticModelCollider is created so you
	don't need to call it yourself.
	*/
	void OnInit();

	//!This function checks for collitions
	/*!
	This function checks if an Object with a BoxCollider is 
	colliding with any of the Mesh
	*/
	bool CheckForCollision(glm::vec3 position, glm::vec3 size);

	//!This function gets the response for collision
	/*!
	This function returns the position for the Object colliding with it
	and run any callbacks you have set.
	*/
	glm::vec3 GetCollisionResponse(glm::vec3 position, glm::vec3 size, bool& solved);
	
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

private:
	std::vector<std::shared_ptr<ColliderColumn>> columns;
	glm::vec3 extentMin;
	glm::vec3 extentMax;
	float resolution;
	float tryStep;
	float maxStep;
	float tryInc;
	float maxInc;
	std::vector<rend::CollitionFace> collisions;
	std::vector<rend::CollitionFace> all;

	bool trigger;
	std::list<std::function<void()>> collisionCallbacks;
	std::list<std::function<void()>> triggerCallbacks;

	bool IsColliding(rend::CollitionFace& face, glm::vec3 position, glm::vec3 size);
	bool IsColliding(glm::vec3 position, glm::vec3 size);
	void GetColliding(glm::vec3 position, glm::vec3 size);

	void AddFace(rend::CollitionFace face);
	glm::vec3 FaceNormal(rend::CollitionFace& face);
};