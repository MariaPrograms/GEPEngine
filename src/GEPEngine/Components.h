#include <memory>

class Component
{
public:
	Component();
	~Component();

private:
	//std::weak_ptr<Object> object;
	void OnInit();
	void OnStart();
	void Update();
	void OnDisplay();
};

