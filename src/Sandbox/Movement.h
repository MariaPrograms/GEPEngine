#include <GEPEngine/GEPengine.h>
#include <iostream>

class Movement : public Component
{
public:
	void OnInit();
	std::shared_ptr<Texture> bar;
	std::shared_ptr<Texture> barBackground;

private:
	void OnUpdate();
	void OnGUI();
	float maxTime;
	float currentTime;
};

