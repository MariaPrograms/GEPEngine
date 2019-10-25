#include <list>
#include <memory>
#include "NonCopyable.h"

class Object;
class World;
class Keyboard;
class Screen;

class Core : private NonCopyable
{
public:
	~Core();
	static std::shared_ptr<Core> Initialize();
	std::shared_ptr<Object> AddObject();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<World> GetWorld();
	std::shared_ptr<Screen> GetScreen();
	void Start();
	void Pause();
	void Finish();

private:
	std::shared_ptr<World> world;
	std::shared_ptr<Keyboard> keyboard;
	std::shared_ptr<Screen> screen;
	std::list<std::shared_ptr<Object>> objects;
	bool playing;
	Core();

};
