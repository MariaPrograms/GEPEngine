#ifndef Component_H
#define Component_H

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

#endif // Component_H
