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
	core->SetMainCamera(cam);


	shared<Object> entity = core->AddObject();
	shared<MeshRenderer> rend = entity->AddComponent<MeshRenderer>();
	shared<TestScene> test = entity->AddComponent<TestScene>();

	shared<Mesh> shape = core->GetResources()->Load<Mesh>("curuthers/curuthers.obj");
	shared<Shader> shader = core->GetResources()->Load<Shader>("Shaders/Texture.txt");
	shared<Texture> texture = core->GetResources()->Load<Texture>("curuthers/Whiskers_diffuse.png");
	shared<Material> mat = std::make_shared<Material>();
	
	mat->SetShader(shader);
	shape->SetTexture(texture);


	shared<SoundSource> source = entity->AddComponent<SoundSource>();
	shared<Sound> sound = core->GetResources()->Load<Sound>("dixie_horn.ogg");
	source->SetSound(sound);

	rend->SetMesh(shape);
	rend->SetMaterial(mat);
	 
	core->Start();
	return;
}