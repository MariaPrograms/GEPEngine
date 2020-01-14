#include <GEPengine/GEPengine.h>
#include <iostream>

#include "TestScene.h"
#include "Movement.h"

#define shared std::shared_ptr
#define weak std::weak_ptr

class Client1 
{
public:
	static void func()
	{
		printf("BITCH");
	}
};

void main ()
{
	shared<Core> core = Core::Initialize();

	shared<Object> CamObj = core->AddObject();
	CamObj->AddComponent<Light>(glm::vec3(1.0f));
	CamObj->SetPoition(glm::vec3(0, 0, 30));
	CamObj->AddComponent<Camera>();
	shared<TestScene> thing = CamObj->AddComponent<TestScene>();
	shared<Texture> thingIm = core->GetResources()->Load<Texture>("Textures/Button.jpg");
	thing->test = thingIm;


	shared<Object> entity = core->AddObject();
	shared<MeshRenderer> rend = entity->AddComponent<MeshRenderer>();
	shared<Mesh> shape = core->GetResources()->Load<Mesh>("Objects/ChickenSmall.obj");
	shared<Shader> shader = core->GetResources()->Load<Shader>("Shaders/Light.txt");
	shared<Texture> texture = core->GetResources()->Load<Texture>("Textures/Whiskers_diffuse.png");
	shared<Material> mat = std::make_shared<Material>();

	mat->SetShader(shader);
	mat->SetTexture(texture);
	entity->SetPoition(glm::vec3(0, 0, 0));
	rend->SetMesh(shape);
	rend->SetMaterial(mat);
	
	shared<BoxCollider> box = entity->AddComponent<BoxCollider>();
	box->IsTrigger(true);
	box->RegisterTriggerCallback(Client1::func);

	///////Second OBJ
	shared<Object> entity2 = core->AddObject();
	shared<MeshRenderer> rend2 = entity2->AddComponent<MeshRenderer>();
	shared<Mesh> shape2 = core->GetResources()->Load<Mesh>("Objects/ChickenSmall.obj");
	shared<Shader> shader2 = core->GetResources()->Load<Shader>("Shaders/Light.txt");
	shared<Texture> texture2 = core->GetResources()->Load<Texture>("Textures/Chicken.png");
	shared<Material> mat2 = std::make_shared<Material>();
	
	mat2->SetShader(shader2);
	mat2->SetTexture(texture2);
	entity2->SetPoition(glm::vec3(5, 0, 0));
	entity2->SetScale(glm::vec3(.6));
	rend2->SetMesh(shape2);

	rend2->SetMaterial(mat2);

	shared<BoxCollider> box2 = entity2->AddComponent<BoxCollider>();
	box2->RegisterCollisionCallback([] {std::cout << "Hit" << std::endl; });
	entity2->AddComponent<Movement>();


	shared<Object> button = core->AddObject();
	shared<Texture> butIma = core->GetResources()->Load<Texture>("Textures/bunnyTest.png");
	shared<Button> but =  button->AddComponent<Button>(butIma);
	but->SetPosition(glm::vec2(10, 10));
	but->SetSize(glm::vec2(100, 100));

	
	/*shared<SoundSource> source = entity->AddComponent<SoundSource>();
	shared<Sound> sound = core->GetResources()->Load<Sound>("dixie_horn.ogg");
	source->SetSound(sound);*/
	 
	core->Start();
	return;
}