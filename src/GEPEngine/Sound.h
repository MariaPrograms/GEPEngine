#include "Resource.h"

#include <string>
#include <AL/al.h>
#include <AL/alc.h>

struct ALSound;

//!  The Sound class. The class where data from the ogg files for sounds are stored
/*!
This class is for sounds for your game.
Sound is a child of Resource so please use the Load functioon from the Resources class to load it in.
*/
class Sound : public Resource
{
public:
	bool looping;//!This is for music that you wish loop. Set to true for it to play continuously. 

private:
	friend class SoundSource;
	friend class Resources;
	void Load(std::string _path);
	std::shared_ptr<Sound> self;
	std::shared_ptr<ALSound> sound;
	ALuint GetSoundID();
};

