#include <glm/glm.hpp>
#include <memory>
#include <string>

class Core;
class Mesh;
class Shader;
class Texture;
class Font;

//!The GUI class. This class controlls all the GUI on screen.
/*!
Here is where all the GUI for the screen is rendered.
*/
class GUI
{
public:
	//!The constructor class
	/*!
	You do not need to use this as Core creates a refrence to this class for you to use;
	*/
	GUI(std::shared_ptr<Core> core);

	//!The destructor class
	/*!
	You do not need to use this.
	*/
	~GUI();

	//!This function is used to draw 2D images to your screen
	/*!
	This function takes two parametors a vec2 that is the position and a Texture
	that is the image that will be rendered
	the vec2 is used to position the images reletive to the top left corner of the screen.
	and the Texture is what will be draw to the screen.
	The size of the image will be the size of the texture you pass in.
	*/
	void DrawGUI(glm::vec2 _pos, std::shared_ptr<Texture> _image);

	//!This function is used to draw 2D images to your screen
	/*!
	This function takes two parametors a vec4 that is the position and size and a Texture 
	that is the image that will be rendered
	the first two values of the vec 4 is used to position the image reletive to the top left corner of the screen.
	The last two values of the vec 4 is used for the size of the image on the screen.
	and the Texture is what will be draw to the screen.
	*/
	void DrawGUI(glm::vec4 _posNSize, std::shared_ptr<Texture> _image);

	//!This function is used to draw 2D images to your screen
	/*!
	This function takes one parametor that is a Texture that is the image that will be rendered
	the image be rendered in the centre of the screen  and take up the whole screen.
	*/
	void DrawGUI(std::shared_ptr<Texture> _image);
	
	//void DrawText(std::string _text, glm::vec2 _pos, std::shared_ptr<Font> _font, float _scale = 1);

private:
	glm::mat4 projection;
	glm::vec2 screenSize;
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Core> core;

};

