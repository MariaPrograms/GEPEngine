#include "Sound.h"
#include "stb_vorbis.h"

#include <vector>

struct ALSound
{
	ALSound()
	{
		alGenBuffers(1, &bufferId);
	}

	~ALSound()
	{
		alDeleteBuffers(1, &bufferId);
	}

	void Load(std::string _path)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_path.c_str(), &channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::exception();
		}

		// Record the sample rate required by OpenAL
		freq = sampleRate;

		// Record the format required by OpenAL
		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}
		else
		{
			format = AL_FORMAT_STEREO16;

			// Force format to be mono (Useful for positional audio)
			// format = AL_FORMAT_MONO16;
			// freq *= 2;
		}

		// Allocate enough space based on short (two chars) multipled by the number of
		// channels and length of clip
		bufferData.resize(sizeof(*output) * channels * samples);
		memcpy(&bufferData.at(0), output, bufferData.size());

		// Clean up the read data
		free(output);

		alBufferData(bufferId, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);
	}
	
	ALuint GetId()
	{
		return bufferId;
	}

private:
	ALuint bufferId = 0;
	ALenum format = 0;
	ALsizei freq = 0;
	std::vector<char> bufferData;

};

void Sound::Load(std::string _path)
{
	sound = std::make_shared<ALSound>();
	sound->Load(_path);
}

ALuint Sound::GetSoundID()
{
	return sound->GetId();
}