#include <GEPEngine/GEPengine.h>
#include <iostream>

class Movement : public Component
{
public:
	Movement();
	~Movement();

private:
	void OnUpdate();
};

