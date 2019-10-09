#include "World.h"
#include "Keyboard.h"
#include "Object.h"

#include <list>
#include <memory>

class Core
{
public:
	Core();
	~Core();
	std::shared_ptr<Core> Initalise();
	std::shared_ptr<Object> addObject();
	void Start();
	void Pause();
	void End();

private:
	std::shared_ptr<World> world;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Object>> objects;
	bool playing;

};
