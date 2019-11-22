#include "Resource.h"
#include <string>
#include <AL/al.h>
#include <AL/alc.h>

struct ALSound;

class Sound : public Resource
{
public:
	Sound();
	~Sound();
	friend class SoundSource;
	friend class Resources;

private:
	void Load(std::string _path);
	std::shared_ptr<Sound> self;
	std::shared_ptr<ALSound> sound;
	ALuint GetSoundID();
};

