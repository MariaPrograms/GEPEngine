#include <GEPengine/GEPengine.h>
#include <iostream>

#include "Player.h"
#include "Movement.h"
#include "Planets.h"

#define shared std::shared_ptr
#define weak std::weak_ptr

void main ()
{
	shared<Core> core = Core::Initialize();

	shared<Object> entity = core->AddObject();

	shared<Planets> planetController = std::make_shared<Planets>(core, 10);

	///////Second OBJ
	shared<Object> entity2 = core->AddObject();
	entity2->SetPoition(glm::vec3(100, 50, 0));

	shared<Camera> cam = entity2->AddComponent<Camera>();
	cam->SetCameraOffset(glm::vec3(0, 0, 4));

	shared<MeshRenderer> rend2 = entity2->AddComponent<MeshRenderer>();
	shared<Mesh> shape2 = core->GetResources()->Load<Mesh>("Objects/Player Ship.obj");
	shared<Shader> shader2 = core->GetResources()->Load<Shader>("Shaders/Light.txt");
	shared<Texture> texture2 = core->GetResources()->Load<Texture>("Textures/Space Ship Textures/RedSkin.png");
	shared<Material> mat2 = std::make_shared<Material>();
	
	mat2->SetShader(shader2);
	mat2->SetTexture(texture2);
	
	rend2->SetMesh(shape2);
	rend2->SetMaterial(mat2);

	shared<BoxCollider> box2 = entity2->AddComponent<BoxCollider>();
	//box2->RegisterCollisionCallback([] {std::cout << "Hit" << std::endl; });
	//entity2->AddComponent<Movement>();

	shared<Player> thing = entity2->AddComponent<Player>();

	//Light
	shared<Light> light = entity2->AddComponent<Light>(glm::vec3(1.f));
	light->SetOffset(glm::vec3(0, 0, -4));

	shared<SoundSource> source = entity->AddComponent<SoundSource>();
	shared<Sound> sound = core->GetResources()->Load<Sound>("Sounds/dixie_horn.ogg");
	source->SetSound(sound);
	
	source->Play();

	core->Start();
	return;
}