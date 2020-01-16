#include "SoundSource.h"
#include "Sound.h"

#include <AL/al.h>
#include <AL/alc.h>

//!The ALSource class. This controlls the API for playing and loading sounds
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

	//!This function plays the sound
	void Play()
	{
		alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sourceId, AL_BUFFER, soundBufferId);
		alSourcePlay(sourceId);
	}

	//!This function updates the sound
	void OnUpdate()
	{
		ALint state = 0;
		alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			//Do thing here
		}
	}

	//!This sets the sound ID
	void SetID(ALuint _soundBufferId)
	{
		soundBufferId = _soundBufferId;
	}

private:
	ALuint sourceId = 0;
	ALuint soundBufferId = 0;
};

void SoundSource::OnInit()
{
	source = std::make_shared<ALSource>();
}

void SoundSource::OnInit(std::shared_ptr<Sound> _sound)
{
	source = std::make_shared<ALSource>();
	source->SetID(_sound->GetSoundID());
}

SoundSource::~SoundSource()
{
	source->~ALSource();
}


void SoundSource::SetSound(std::shared_ptr<Sound> _sound)
{
	source->SetID(_sound->GetSoundID());
}

void SoundSource::Play()
{
	source->Play();
}

void SoundSource::OnUpdate()
{
	source->OnUpdate();
}