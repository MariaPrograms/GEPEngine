#pragma once
#ifndef Component_H
#define Component_H

#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <exception>

class Object;
class Input;
class World;
class Core;
class Screen;
class GUI;

//! The Component class to add features to an Object
/*!
Components are to add a feature or components to Objects.
To make your own Component to add to an Object please make your class and then
make it a child of Component.

Example 
#Include <GEPEngine/GEPEngine.h>

Class Exapmle : Public Component
{

}
*/
class Component
{
public:
	//! Use as a shortcut to access the Input
	/*!
	Use this function to access the Input class and it's functions
	*/
	std::shared_ptr<Input>  GetInput();

	//! Use as a shortcut to access the GUI
	/*!
	Use this function to access the GUI class and it's functions
	*/
	std::shared_ptr<GUI>  GetGUI();

	//! Use as a shortcut to access the Object
	/*!
	Use this function to access the Object that holds the componenet
	*/
	std::shared_ptr<Object>  GetObject();

	//! Use as a shortcut to access the World
	/*!
	Use this function to access the World class and it's functions
	*/
	std::shared_ptr<World>  GetWorld();

	//! Use as a shortcut to access the Screen
	/*!
	Use this function to access the Screen class and it's functions
	*/
	std::shared_ptr<Screen>  GetScreen();

	//! Use as a shortcut to access Core
	/*!
	Use this function to access the Core class and it's functions
	*/
	std::shared_ptr<Core>  GetCore();

	void SetIsActive(bool _value) { isActive = _value; }

protected:
	friend class Object;

	//! This is a vertual function to Initalise the component
	/*!
	Use this function to run any lines of code once when the compenent is created and added to the Object. 
	*/
	virtual void OnInit() {};

	//! This is a vertual function to Initalise the component
	/*!
	Use this function to run any lines of code once at the very start of the project.
	*/
	virtual void OnStart() {};

	//! This is a vertual function to Initalise the component
	/*!
	Use this function to run any lines of code every frame of the game.
	*/
	virtual void OnUpdate() {};

	//! This is a vertual function to Initalise the component
	/*!
	Use this function to run lines of code every frame after the update is called.
	This is use for rendering 3D models and meshes.
	*/
	virtual void OnDisplay() {};

	//! This is a vertual function to Initalise the component
	/*!
	Use this function to run lines of code at the end of the every Frame.
	Use this for rendering your UI, like buttons and Images.
	*/
	virtual void OnGUI() {};

	
	std::weak_ptr<Object> object;//! This is referience to the Object that holds this Component

	bool isActive = true;//! This is for the comenent to run in that frame
};

#endif // Component_H
