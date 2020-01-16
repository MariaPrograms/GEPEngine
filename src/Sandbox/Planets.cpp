#include "Planets.h"
#include "Player.h"

#include <glm/gtx/string_cast.hpp>
#include <time.h>

void PlanetController::OnInit()
{
	//Rotation
	rotation = glm::vec3((rand() % 50), (rand() % 50), 0);
	GetObject()->SetRotation(rotation);
	speed = rand() % 20 + 3;

	//Button
	shared<Texture> buttonImage = GetCore()->GetResources()->Load<Texture>("Textures/UI/MineButton.png");
	mineButton = GetObject()->AddComponent<Button>(buttonImage);

	float xpos = (GetCore()->GetScreen()->GetSize().x / 2) - buttonImage->GetRender()->getWidth() / 2;
	float ypos = (GetCore()->GetScreen()->GetSize().y) - buttonImage->GetRender()->getWidth();
	mineButton->SetPosition(glm::vec2(xpos, ypos));

	mineButton->SetIsActive(false);
	mineButton->RegisterCallback([this] { ButtonFunction(); });
}

void PlanetController::MinePlanet()
{
	if (player->GetComponent<BoxCollider>()->isColliding && !mined)
	{
		mineButton->SetIsActive(true);
	}
}

void PlanetController::ButtonFunction()
{
	if (!mined)
	{
		player->GetComponent<Player>()->score += 10;
		mined = true;
	}
}

void PlanetController::OnUpdate()
{
	if (GetObject()->GetPoition().z > player->GetPoition().z )
	{
		Reset();
	}

	if (!player->GetComponent<BoxCollider>()->isColliding)
	{
		mineButton->SetIsActive(false);
	}

	rotation.x += speed * GetWorld()->GetDeltaTime();
	rotation.y += speed * GetWorld()->GetDeltaTime();
	GetObject()->SetRotation(rotation);
}

void PlanetController::Reset()
{
	float x = (rand() % 6) * 10;
	float y = (rand() % 6) * 10;
	float z = (rand() % 20 + 5) * -10;
	glm::vec3 newPos(x, y, (player->GetPoition().z + z));
	GetObject()->SetPoition(newPos);
	mined = false;
}


Planets::Planets(shared<Core> _core, int _amountOfPlanets, shared<Object> _player)
{
	ListOfPlanets();
	core = _core;
	srand(time(NULL));

	for (int i = 0; i < _amountOfPlanets; i++)
	{
		shared<Object> tempObj = core->AddObject();

		float x = (rand() % 6) * 10;
		float y = (rand() % 6) * 10;
		float z = (rand() % 20 + 2) * -10;
		tempObj->SetPoition(glm::vec3(x, y, z));

		shared<PlanetController> controller = tempObj->AddComponent<PlanetController>();

		shared<MeshRenderer> rend = tempObj->AddComponent<MeshRenderer>();
		shared<Material> mat = std::make_shared<Material>();

		mat->SetShader(core->GetResources()->Load<Shader>("Shaders/Light.txt"));
		mat->SetTexture(core->GetResources()->Load<Texture>("Textures/color_webgl.png"));

		int planetObj = rand() % planerObjects.size();
		rend->SetMesh(core->GetResources()->Load<Mesh>("Objects" + planerObjects.at(planetObj)));
		rend->SetMaterial(mat);

		controller->player = _player;

		shared<BoxCollider> box = tempObj->AddComponent<BoxCollider>();
		box->SetStatic(true);
		box->SetSize(glm::vec3(10));
		box->RegisterCollisionCallback([controller]
		{
			controller->MinePlanet();
		});

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
