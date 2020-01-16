#include "Planets.h"

void PlanetController::OnInit()
{
	rotation = glm::vec3((rand() % 50), (rand() % 50), 0);
	GetObject()->SetRotation(rotation);
	speed = rand() % 20 + 3;
}

void PlanetController::OnUpdate()
{
	rotation.x += speed * GetWorld()->GetDeltaTime();
	rotation.y += speed * GetWorld()->GetDeltaTime();
	GetObject()->SetRotation(rotation);
}


Planets::Planets(shared<Core> _core, int _amountOfPlanets)
{
	ListOfPlanets();
	core = _core;

	//mineButtonObject = core->AddObject();
	//mineButton = mineButtonObject->AddComponent<Button>(core->GetResources()->Load<Texture>("Textures/UI/MineButton.png"));
	//mineButton->SetPosition(glm::vec2(core->GetScreen()->GetSize().x / 2, 0));

	for (int i = 0; i < _amountOfPlanets; i++)
	{
		shared<Object> tempObj = core->AddObject();
		tempObj->SetPoition(glm::vec3((rand() % 200), (rand() % 100), (rand() % 150 - 200)));

		shared<MeshRenderer> rend = tempObj->AddComponent<MeshRenderer>();
		shared<Material> mat = std::make_shared<Material>();

		mat->SetShader(core->GetResources()->Load<Shader>("Shaders/Light.txt"));
		mat->SetTexture(core->GetResources()->Load<Texture>("Textures/color_webgl.png"));

		int planetObj = rand() % planerObjects.size();
		rend->SetMesh(core->GetResources()->Load<Mesh>("Objects" + planerObjects.at(planetObj)));
		rend->SetMaterial(mat);

		tempObj->AddComponent<PlanetController>();
		shared<BoxCollider> box = tempObj->AddComponent<BoxCollider>();
		box->SetStatic(true);
		box->SetSize(glm::vec3(10));

		planets.push_back(tempObj);
	}
}

Planets::~Planets()
{

}

void Planets::ListOfPlanets()
{
	planerObjects.push_back("/Planet Forest.obj");
	planerObjects.push_back("/Planet Grey Ice.obj");
	planerObjects.push_back("/Planet Ice.obj");
	planerObjects.push_back("/Planet Island.obj");
	planerObjects.push_back("/Planet Orange.obj");
	planerObjects.push_back("/Planet Pine.obj");
	planerObjects.push_back("/Planet Pyramid.obj");
}
