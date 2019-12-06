#include <list>
#include <memory>
#include <rend/rend.h>
#include <vector>

#include "NonCopyable.h"

class Object;
class World;
class Keyboard;
class Screen;
class Resources;
class Context;
class Camera;
class Light;

struct AudioCore;

class Core : private NonCopyable
{
public:
	~Core();
	static std::shared_ptr<Core> Initialize();

	std::shared_ptr<Object> AddObject();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<World> GetWorld();
	std::shared_ptr<Screen> GetScreen();
	std::shared_ptr<Resources> GetResources();
	std::shared_ptr<Camera> GetCamera();
	std::shared_ptr<rend::Context> GetContext();
	std::shared_ptr<Light> GetLights();

	template<typename T>
	std::shared_ptr<T> GetEntities(std::vector<std::shared_ptr<Object>>& _list)
	{
		for (std::list<std::shared_ptr<Object>>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			bool found;
			(*it)->CheckForComponent<T>(found);

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
	std::shared_ptr<Keyboard> keyboard;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<rend::Context> context;
	std::weak_ptr<Camera> mainCamera;
	std::list<std::shared_ptr<Object>> objects;
	std::list<std::shared_ptr<Light>> lights;

	bool playing;
};
