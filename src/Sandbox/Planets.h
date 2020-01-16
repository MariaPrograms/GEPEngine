#include "GEPEngine/GEPengine.h"

#include <string>
#include <vector>
#include <memory>

#define shared std::shared_ptr
#define weak std::weak_ptr

class PlanetController : public Component
{
public:
	void OnInit();
	void MinePlanet();

private:
	void OnUpdate();
	
	shared<Object> player;
	glm::vec3 rotation;
	float speed;
	bool mined;
	shared<Button> mineButton;
};



class Planets
{
public:
	Planets(shared<Core> _core, int _amountOfPlanets);
	~Planets();
	void ListOfPlanets();
	int howManyPlanets;

private:
	std::vector<shared<Object>> planets;
	std::vector<std::string> planerObjects;
	shared<Core> core;

	

};

