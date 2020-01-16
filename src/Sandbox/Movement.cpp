#include "Movement.h"

void Movement::OnInit()
{
	maxTime = 10;
	currentTime = maxTime;
}

void Movement::OnUpdate()
{
	currentTime -= GetWorld()->GetDeltaTime();
}

void Movement::OnGUI()
{
	float timeleft = currentTime / maxTime;
	float barLength = (GetScreen()->GetSize().x / 4 * 3) * timeleft;
	GetGUI()->DrawGUI(glm::vec4((GetScreen()->GetSize().x / 4), 55, (GetScreen()->GetSize().x / 4 * 3), 10), bar);
	GetGUI()->DrawGUI(glm::vec4(barLength, 55, (GetScreen()->GetSize().x / 4 * 3), 10), bar);
}
