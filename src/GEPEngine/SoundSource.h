#include "Components.h"


class Sound;
struct ALSource;

class SoundSource : public Component
{
public:
	SoundSource();
	~SoundSource();
	void SetSound(std::shared_ptr<Sound> _sound);
	
private:
	void OnInit();
	void OnUpdate();
	std::shared_ptr<ALSource> source;
};

