#include <list>
#include <memory>
#include <rend/rend.h>
#include <vector>

#include "NonCopyable.h"

class Object;
class World;
class Input;
class Screen;
class Resources;
class Context;
class Camera;
class Light;
class GUI;

struct AudioCore;

//!  The Core class. The main controller of the engine.
/*!
  Here is where you will have controll over different aspects of the enginethat are not Componenets. 
  Here you can create Objects, access the GUI, audio, world systems ect... 
*/

class Core : private NonCopyable
{
public:
	~Core();

	//! The Core constructor.
	/*!  
		Use this at the start of your code to initalise Core and be able to use it. 
		It returns a smart pointer for you to store and use.
	*/
	static std::shared_ptr<Core> Initialize(); 

	//! The function for creating an Object.
	/*!
		This function is to create Objects. 
	*/
	std::shared_ptr<Object> AddObject();

	//! The function for getting the Input class
	/*!
		Use this function to access the Input class and it's functions 
	*/
	std::shared_ptr<Input> GetInput();

	//! The function for getting the World class
	/*!
		Use this function to access the World class and it's functions
	*/
	std::shared_ptr<World> GetWorld();

	//! The function for getting the Screen class
	/*!
		Use this function to access the Screen class and it's functions
	*/
	std::shared_ptr<Screen> GetScreen();

	//! The function for getting the Resources class
	/*!
		Use this function to access the Resources class and it's functions
	*/
	std::shared_ptr<Resources> GetResources();

	//! The function for getting the main Camera in the scene
	/*!
		Use this function to access the current main camera in the scene 
	*/
	std::shared_ptr<Camera> GetCamera();
	std::shared_ptr<rend::Context> GetContext();
	std::shared_ptr<Light> GetLights();
	std::shared_ptr<GUI> GetGUI();

	template<typename T>
	void GetEntities(std::vector<std::shared_ptr<Object>>& _list)
	{
		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			bool found = (*it)->CheckForComponent<T>();

			if (found)
			{
				_list.push_back((*it));
			}
		}
	}

	void AddLight(std::shared_ptr<Light> _light) { lights.push_back(_light); }
	void SetMainCamera(std::weak_ptr<Camera> _cam) { mainCamera = _cam; }

	void Start(); 
	void Pause();
	void Finish();

private:
	Core();

	std::shared_ptr<AudioCore> audioCore;
	std::shared_ptr<Core> self;
	std::shared_ptr<World> world;
	std::shared_ptr<Input> input;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<rend::Context> context;
	std::shared_ptr<GUI> gui;
	std::weak_ptr<Camera> mainCamera;
	std::list<std::shared_ptr<Object>> objects;
	std::list<std::shared_ptr<Light>> lights;

	bool playing;
};
