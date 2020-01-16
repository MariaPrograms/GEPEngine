#include <memory>
#include <vector>
#include <rend/rend.h>
#include <string>

class Shader;
class MaterialAttribute;
class Texture;

//!  The Material class. The class that controlls what your Mesh looks like.
/*!
This class is used to set the look of your 3D objects.
This class uses a Shader and a Texture to calculate what your 
pbject will look like. 

Depending on the shader you choose to use you may not need a texture, but a shader will always be 
required.


Example..

shared<Material> material = std::make_shared<Material>();

*/
class Material
{
public:
	//!This sets the Shader for the Material.
	/*!
	This function is used to set the Shader your Material.
	The shader you use will change the way your object is shadeded and other features.
	Please make sure that a Shader is set before you call Core->Start();
	*/
	void SetShader(std::shared_ptr<Shader> _shader);

	//!This sets the Textue for the Renderer.
	/*!
	This function is used to set the Texture for the object.
	Pass the chosen Texture as a shared pointer into the function.
	You can change the Texture at any time in code, but make sure that a Texture is set
	before you call Core->Start();.

	Not all shaders requires a Texture so please make sure you are using the correct shader 
	as you may get an error if you try and pass a Texture in a Shader that does not use one.
	Same vise versa.
	*/
	void SetTexture(std::shared_ptr<Texture>);

	//!This gets the Shader the Material is using.
	/*!
	This function is used to get the Shader the Material is using.
	This is mainly used for rendering purposes. 
	*/
	std::shared_ptr<rend::Shader> GetShader();

	//!This gets the Texture the Material is using.
	/*!
	This function is used to get the Texture the Material is using.
	This is mainly used for rendering purposes.
	*/
	std::shared_ptr<Texture> GetTexture();

	//!This sets a Uniform with a float value.
	/*!
	This function is used to set a Uniform in the shader, 
	The string paramater, _variable, is the Name of the Uniform, and 
	the float paramater, _value, is the value you wish to set it to.
	This is mainly used for rendering purposes.
	*/
	void setUniform(const std::string& _variable, float _value);

	//!This sets a Uniform with a mat4 value.
	/*!
	This function is used to set a Uniform in the shader,
	The string paramater, _variable, is the Name of the Uniform, and
	the float paramater, _value, is the value you wish to set it to.
	This is mainly used for rendering purposes.
	*/
	void setUniform(const std::string& _variable, glm::mat4 _value);

	//!This sets a Uniform with a vec2 value.
	/*!
	This function is used to set a Uniform in the shader,
	The string paramater, _variable, is the Name of the Uniform, and
	the float paramater, _value, is the value you wish to set it to.
	This is mainly used for rendering purposes.
	*/
	void setUniform(const std::string& _variable, glm::vec2 _value);

	//!This sets a Uniform with a vec3 value.
	/*!
	This function is used to set a Uniform in the shader,
	The string paramater, _variable, is the Name of the Uniform, and
	the float paramater, _value, is the value you wish to set it to.
	This is mainly used for rendering purposes.
	*/
	void setUniform(const std::string& _variable, glm::vec3 _value);

	//!This sets a Uniform with a vec4 value.
	/*!
	This function is used to set a Uniform in the shader,
	The string paramater, _variable, is the Name of the Uniform, and
	the float paramater, _value, is the value you wish to set it to.
	This is mainly used for rendering purposes.
	*/
	void setUniform(const std::string& _variable, glm::vec4 _value);

	//!This checks if the Shader requries Lights
	/*!
	This function returns a bool to check if the Shader 
	needs any information about any Lights in the scene.
	This is mainly used for rendering purposes.
	*/
	bool UsesLights();

private:
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture> texture;
	std::vector<std::shared_ptr<MaterialAttribute>> attributes;
};

