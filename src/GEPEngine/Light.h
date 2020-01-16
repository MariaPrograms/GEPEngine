#include "Components.h"
#include <glm/glm.hpp>
#include <memory>

class Material;

//!  The Light class. The class lights are created
/*!
This class is used to add lights to your scene.
Light is a child of Component so please use the Object class to add one
to an Object.

Example..

shared<Light> example = exampleObject->AddComponent<Light>();
*/
class Light : public Component, public std::enable_shared_from_this<Light>
{
public:
	//!This passes information on about the light into a shader
	/*!
	This function takes in Material  that it will then get it's shader and populate the specific 
	uniforms with the correct information.
	*/
	void SetLights(std::shared_ptr<Material> _shader);

	//!The OnInit function inherited from Component.
	/*!
	This is mainly called by the Object call when it's created so you don't need to
	use this function.
	*/
	void OnInit(glm::vec3 _color);

private:
	glm::vec3 color;
};
