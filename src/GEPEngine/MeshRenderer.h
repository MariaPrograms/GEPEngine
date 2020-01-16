#include <GL/glew.h>
#include <memory>
#include <rend/rend.h>

#include "Components.h"

class Mesh;
class Material;

//!  The MeshRenderer class. The class where meshes are drawn to the screen
/*!
This class is used to render 3D objects to your scene.
MeshRenderer is a child of Component so please use the Object class to add one
to an Object.

Example..

shared<MeshRenderer> example = exampleObject->AddComponent<MeshRenderer>();

*/

class MeshRenderer : public Component
{
public:
	//!This sets the Mesh that will render.
	/*!
	This function is used to set the mesh you wish to render for the object.
	Pass the chosen Mesh as a shared pointer into the paramater.
	You can change the mesh at any time in code, but make sure that a Mesh is set 
	before you call Core->Start();
	*/	
	void SetMesh(std::shared_ptr<Mesh> _mesh);

	//!This sets the Material that will render.
	/*!
	This function is used to set the Material for the Mesh, 
	by passing the chosen Material as a shared pointer into this function.
	You can change the Material for your Mesh at any time in code,
	but make sure that a Material is set before you call Core->Start();
	*/
	void SetMaterial(std::shared_ptr<Material> _material);

	//!This gets the current Mesh.
	/*!
	This function will return a shared_ptr of current the Mesh 
	that it is rendering.
	*/
	std::shared_ptr<Mesh> GetMesh();

	//!This gets the current Material.
	/*!
	This function will return a shared_ptr of current the Material
	that it is using.
	*/
	std::shared_ptr<Material> GetMaterial();
	
private:
	void OnStart();
	void OnDisplay();
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
};

