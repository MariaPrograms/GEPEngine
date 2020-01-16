#include "GEPEngine/GEPengine.h"

#include <string>
#include <vector>
#include <memory>

#define shared std::shared_ptr

class PlanetController : public Component
{
public:
	void OnInit();
	void MinePlanet();
	void ButtonFunction();

	shared<Object> player;

private:
	void OnUpdate();
	void Reset();

	glm::vec3 rotation;
	float speed;
	bool mined;
	shared<Button> mineButton;
};



class Planets
{
public:
	Planets(shared<Core> _core, int _amountOfPlanets, shared<Object> _player);
	~Planets();
	void ListOfPlanets();
	int howManyPlanets;

private:
	std::vector<shared<Object>> planets;
	std::vector<std::string> planerObjects;
	shared<Core> core;
};

