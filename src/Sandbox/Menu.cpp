#include "Menu.h"
#include "Player.h"

void Menu::OnInit()
{
	maxTime = 30;
	currentTime = maxTime;
	barBackground = GetCore()->GetResources()->Load<Texture>("Textures/UI/slider_background.png");
	bar = GetCore()->GetResources()->Load<Texture>("Textures/UI/slider_filler.png");

	scoreBar = GetCore()->GetResources()->Load<Texture>("Textures/UI/slider_filler_vert.png");
	scoreBarBackground = GetCore()->GetResources()->Load<Texture>("Textures/UI/slider_vert.png");

	frame = GetCore()->GetResources()->Load<Texture>("Textures/UI/Frame.png");

	title = GetCore()->GetResources()->Load<Texture>("Textures/UI/Title.png");
	endTitle = GetCore()->GetResources()->Load<Texture>("Textures/UI/End Title.png");

	startButton = GetObject()->AddComponent<Button>(GetCore()->GetResources()->Load<Texture>("Textures/UI/transparent.png"));
	startButton->SetSize(glm::vec2(210, 110));

	float xpos = (GetCore()->GetScreen()->GetSize().x / 2) - 105;
	float ypos = (GetCore()->GetScreen()->GetSize().y) - 200;
	startButton->SetPosition(glm::vec2(xpos, ypos));

	startButton->RegisterCallback([this] 
	{ 
		player->started = true;
		player->source->Play();
		player->ResetPos();
		startButton->SetIsActive(false);
	});
}

void Menu::OnUpdate()
{
	if (player->started && !player->finished)
	{
		currentTime -= GetWorld()->GetDeltaTime();
		if (currentTime <= 0)
		{
			player->finished = true;
		}
	}
}

void Menu::OnGUI()
{
	if (!player->started && !player->finished)
	{
		GetGUI()->DrawGUI(title);
	}
	else if (player->started && !player->finished)
	{
		float scoreLeft = (float)player->score / (float)player->maxScore;
		float barHieght = (GetScreen()->GetSize().y / 2 - 25) * scoreLeft;
		GetGUI()->DrawGUI(glm::vec4(40, (GetScreen()->GetSize().y / 2), 20, (GetScreen()->GetSize().y / 2 - 30)), scoreBarBackground);
		GetGUI()->DrawGUI(glm::vec4(40, (GetScreen()->GetSize().y - 34), 20, -barHieght), scoreBar);

		if (currentTime > 0)
		{
			float timeleft = currentTime / maxTime;
			float barLength = (GetScreen()->GetSize().x / 4 * 2) * timeleft;
			GetGUI()->DrawGUI(glm::vec4((GetScreen()->GetSize().x / 4), 30, (GetScreen()->GetSize().x / 4 * 2), 40), barBackground);
			GetGUI()->DrawGUI(glm::vec4((GetScreen()->GetSize().x / 4), 30, barLength, 40), bar);
		}

		GetGUI()->DrawGUI(frame);
	}
	else
	{
		GetGUI()->DrawGUI(endTitle);
	}
}
