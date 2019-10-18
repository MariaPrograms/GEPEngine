#ifndef Component_H
#define Component_H

#include <memory>

class Object;
class Keyboard;

class Component
{
public:
	Component();
	~Component();
	friend class Object;
	std::shared_ptr<Keyboard>  GetKeyboard();

protected:
	virtual void OnInit() {};
	virtual void OnStart() {};
	virtual void OnUpdate() {};
	virtual void OnDisplay() {};

private:
	std::weak_ptr<Object> object;

};

#endif // Component_H
