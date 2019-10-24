#include <list>
#include <memory>
#include "NonCopyable.h"

class Object;
class World;
class Keyboard;

class Core : private NonCopyable
{
public:
	~Core();
	static std::shared_ptr<Core> Initialize();
	std::shared_ptr<Object> AddObject();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<World> GetWorld();
	void Start();
	void Pause();
	void Finish();

private:
	std::weak_ptr<World> world;
	std::weak_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Object>> objects;
	bool playing;
	Core();

};
