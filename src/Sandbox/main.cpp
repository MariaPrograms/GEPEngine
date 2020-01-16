#include <GEPengine/GEPengine.h>
#include <iostream>

#include "Player.h"
#include "Menu.h"
#include "Planets.h"

#define shared std::shared_ptr
#define weak std::weak_ptr

void main ()
{
	shared<Core> core = Core::Initialize(glm::vec2(800, 600));
	core->GetScreen()->SetScreenName("SPACE");

	///////player OBJ
	shared<Object> player = core->AddObject();
	player->SetPoition(glm::vec3(30, 30, 5));
	shared<Player> thing = player->AddComponent<Player>();

	shared<Object> menu = core->AddObject();
	shared<Menu> menuScript = menu->AddComponent<Menu>();
	menuScript->player = thing;


	shared<Planets> planetController = std::make_shared<Planets>(core, 10, player);
	core->Start();
	return;
}