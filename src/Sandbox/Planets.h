#include "GEPEngine/GEPengine.h"

#include <string>
#include <vector>
#include <memory>

#define shared std::shared_ptr
#define weak std::weak_ptr

class PlanetMovement : public Component
{
public:
	void OnInit();

private:
	void OnUpdate();
	glm::vec3 rotation;
	float speed;
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

	shared<Object> mineButtonObject;
	shared<Button> mineButton;

};

