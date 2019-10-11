#include <list>
#include <memory>

class Object;
class World;
class Keyboard;

class Core
{
public:
	static std::shared_ptr<Core> Initialize();
	~Core();
	std::shared_ptr<Object> AddObject();
	void Start();
	void Pause();
	void End();

private:
	std::shared_ptr<World> world;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Object>> objects;
	bool playing;
	Core();

};
