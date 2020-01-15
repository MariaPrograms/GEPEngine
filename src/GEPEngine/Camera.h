#include <glm/glm.hpp>
#include <memory>
#include "Components.h"

//!  The Camera class. this is for the veiw port of the game.
/*!
Here is where you will have controll over the camera component. 
You need a camera in your scene to render anything. 
*/
class Camera : public Component, public std::enable_shared_from_this<Camera>
{
public:
	//!  The OnInit function inherited from Component.
	/*!
	This is mainly called by the Object call when it's created so you don't need to.
	*/
	void OnInit();

	//!This is to set the front of the camera
	/*!
	This function takes in a vec3,_newFront, that update that camera front variable.
	*/
	void SetCameraFront(glm::vec3 _newFront) { cameraFront = _newFront; };

	//!This is to ofset the camera.
	/*!
	This function takes in a vec3, _value, that will offset the camera from the center of your object.
	*/
	void SetCameraOffset(glm::vec3 _value) { offset = _value; }

	//!This is to get the Front of the camera 
	/*!
	This function returns the vector the represents the front of the camera.
	*/
	glm::vec3 GetCameraFront() { return cameraFront; }

	//!This is to get the Front of the camera 
	/*!
	This function returns a vec3 that represents the direction going up from the front of the camera.
	*/
	glm::vec3 GetCameraUp() { return cameraUp; }

	//!This is to get the View Matrix of the camera 
	/*!
	This function returns a 4x4 matrix that represents the View Matrix of the camera.
	*/
	glm::mat4 GetView();

	//!This is to get the Projection Matrix of the camera 
	/*!
	This function returns a 4x4 matrix that represents the Projection Matrix of the camera.
	*/
	glm::mat4 GetProjection() { return perspectiveMatrix; }

private:
	glm::mat4 perspectiveMatrix;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 offset;
};

