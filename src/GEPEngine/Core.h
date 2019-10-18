#include <list>
#include <memory>

class Object;
class World;
class Keyboard;

class Core
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
	std::shared_ptr<World> world;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Object>> objects;
	bool playing;
	Core();

};
