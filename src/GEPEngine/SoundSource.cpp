#include "SoundSource.h"
#include "Sound.h"

#include <AL/al.h>
#include <AL/alc.h>

struct ALSource
{
	ALSource()
	{
		alGenSources(1, &sourceId);
	}

	~ALSource()
	{
		alDeleteSources(1, &sourceId);
	}

	void Play()
	{
		alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sourceId, AL_BUFFER, soundBufferId);
		alSourcePlay(sourceId);
	}

	void OnUpdate()
	{
		ALint state = 0;
		alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			//Do thing here
		}
	}

	void SetID(ALuint _soundBufferId)
	{
		soundBufferId = _soundBufferId;
	}

private:
	ALuint sourceId = 0;
	ALuint soundBufferId = 0;
};

SoundSource::SoundSource()
{
	source = std::make_shared<ALSource>();
}

SoundSource::~SoundSource()
{
	source->~ALSource();
}


void SoundSource::SetSound(std::shared_ptr<Sound> _sound)
{
	source->SetID(_sound->GetSoundID());
}

void SoundSource::OnInit()
{
	source->Play();
}

void SoundSource::OnUpdate()
{
	source->OnUpdate();
}