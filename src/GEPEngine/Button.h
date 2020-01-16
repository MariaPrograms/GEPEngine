#include "Components.h"

#include <list>
#include <functional>
#include <glm/glm.hpp>

class Texture;

//!  The Button class.
/*!
By adding this Button to your object you can then add callbacks to it to 
run when the button is clicked.
Button is a child of Component so please use the Object class to add one
to an Object.

Example..

shared<Button> example = exampleObject->AddComponent<Button>();
*/
class Button : public Component
{
public:
	//!This function will add a callback for when the button is click
	/*!
	this function takes a function as a parameter that will be added to a list of callbacks
	that will be called when the button is clicked with the Mouse.
	*/
	void RegisterCallback(const std::function<void()> &_callback);

	//!This function will run all the callbacks you have set
	/*!
	this runs all the functions you have set on this Button
	This is run automataclly on the OnUpdate, but you can call it yourself
	*/
	void OnClick();

	//!The OnInit function inherited from Component.
	/*!
	This is mainly called by the Object call when it's created so you don't need to
	use this function.
	*/
	void OnInit(std::shared_ptr<Texture> image);

	//!This sets the Image of the button
	/*!
	This sets the image of the button,
	Though you set this in when creating the button you can change it durring the game 
	*/
	void SetImage(std::shared_ptr<Texture> image);

	//!This sets the size of the button
	/*!
	This sets the size of the button, if no size is set then the size will be 
	that of the image you've passed in.
	*/
	void SetSize(glm::vec2 _size);

	//!This sets the position of the button
	/*!
	This sets the position of the button, if no position is set then the button will apear 
	in the top left corner of the screen.
	*/
	void SetPosition(glm::vec2 _position);

	void SetClickedImage(std::shared_ptr<Texture> _image);

private:
	void OnUpdate();
	void OnGUI();
	std::shared_ptr<Texture> normalImage;
	std::shared_ptr<Texture> clickedImage;
	std::shared_ptr<Texture> currentImage;
	glm::vec2 size;
	glm::vec2 position;
	std::list<std::function<void()>> callbacks;
};