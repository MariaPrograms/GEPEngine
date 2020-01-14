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
		printf("HIT");
	}
};

void main ()
{
	shared<Core> core = Core::Initialize();

	shared<Object> entity = core->AddObject();
	

	entity->AddComponent<Light>(glm::vec3(1.0f));
	
	shared<MeshRenderer> rend = entity->AddComponent<MeshRenderer>();
	shared<Mesh> shape = core->GetResources()->Load<Mesh>("Objects/maze.obj");
	shared<Shader> shader = core->GetResources()->Load<Shader>("Shaders/Light.txt");
	shared<Texture> texture = core->GetResources()->Load<Texture>("Textures/MazeTexture.png");
	shared<Material> mat = std::make_shared<Material>();

	mat->SetShader(shader);
	mat->SetTexture(texture);
	entity->SetPoition(glm::vec3(0, 0, 0));
	rend->SetMesh(shape);
	rend->SetMaterial(mat);
	
	shared<StaticModelCollider> box = entity->AddComponent<StaticModelCollider>();

	///////Second OBJ
	shared<Object> entity2 = core->AddObject();

	shared<Camera> cam = entity2->AddComponent<Camera>();
	cam->SetCameraOffset(glm::vec3(0, 4, 10));
	shared<TestScene> thing = entity2->AddComponent<TestScene>();


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
	//entity2->AddComponent<Movement>();


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