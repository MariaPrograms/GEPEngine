#include <GEPengine/GEPengine.h>
#include <iostream>

#include "TestScene.h"

#define shared std::shared_ptr
#define weak std::weak_ptr

void main ()
{
	shared<Core> core = Core::Initialize();
	
	shared<Object> CamObj = core->AddObject();
	shared<Camera> cam = CamObj->AddComponent<Camera>();

	shared<Object> LightObj = core->AddObject();
	shared<Light> light = LightObj->AddComponent<Light>(glm::vec3(1.0f));
	

	//shared<Object> entity = core->AddObject();
	//shared<MeshRenderer> rend = entity->AddComponent<MeshRenderer>();
	//shared<Mesh> shape = core->GetResources()->Load<Mesh>("curuthers/curuthers.obj");
	//shared<Shader> shader = core->GetResources()->Load<Shader>("Shaders/Light.txt");
	//shared<Texture> texture = core->GetResources()->Load<Texture>("curuthers/Whiskers_diffuse.png");
	//shared<Material> mat = std::make_shared<Material>();
	//mat->SetShader(shader);
	//mat->SetTexture(texture);
	//entity->SetPoition(glm::vec3(0, 0, -10));
	//rend->SetMesh(shape);
	//rend->SetMaterial(mat);

	//shared<BoxCollider> coll = entity->AddComponent<BoxCollider>();

	shared<Object> entity2 = core->AddObject();
	shared<MeshRenderer> rend2 = entity2->AddComponent<MeshRenderer>();
	shared<Mesh> shape2 = core->GetResources()->Load<Mesh>("aca.obj");
	shared<Shader> shader2 = core->GetResources()->Load<Shader>("Shaders/Light.txt");
	shared<Texture> texture2 = core->GetResources()->Load<Texture>("DefaultTexture.png");
	shared<Material> mat2 = std::make_shared<Material>();
	
	mat2->SetShader(shader2);
	mat2->SetTexture(texture2);
	entity2->SetPoition(glm::vec3(0, 0, -40));
	entity2->SetScale(glm::vec3(.5, .5, .5));
	rend2->SetMesh(shape2);
	rend2->SetMaterial(mat2);

	shared<TestScene> test = entity2->AddComponent<TestScene>();
	shared<BoxCollider> coll2 = entity2->AddComponent<BoxCollider>();

	/*shared<SoundSource> source = entity->AddComponent<SoundSource>();
	shared<Sound> sound = core->GetResources()->Load<Sound>("dixie_horn.ogg");
	source->SetSound(sound);*/
	
	 
	core->Start();
	return;
}