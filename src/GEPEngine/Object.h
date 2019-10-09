#include <list>
#include <memory>
#include "Components.h" 

class Object
{
public:
	Object();
	~Object();
	std::shared_ptr<class T> AddComponent();
	std::shared_ptr<class T> GetComponent();

private:
	std::list<std::shared_ptr<Component>> components;
	void Update();
	void Desplay();
};



