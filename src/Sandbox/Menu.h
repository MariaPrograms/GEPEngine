#include <GEPEngine/GEPengine.h>
#include <vector>

class Player;

class Menu : public Component
{
public:
	void OnInit();
	std::shared_ptr<Texture> bar;
	std::shared_ptr<Texture> barBackground;

	std::shared_ptr<Texture> scoreBar;
	std::shared_ptr<Texture> scoreBarBackground;

	std::shared_ptr<Texture> frame;
	std::shared_ptr<Player> player;
	
	std::shared_ptr<Texture> title;
	std::shared_ptr<Texture> endTitle;

	std::shared_ptr<Button> startButton;
private:
	void OnUpdate();
	void OnGUI();
	float maxTime;
	float currentTime;
	
};
