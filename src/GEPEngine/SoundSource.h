#include "Components.h"


class Sound;
struct ALSource;

//! The SoundSource class. This plays audio
/*!
Here is where you can play any audio you have loaded in.
SoundSource is a child of Component so please use the Object class to add one
to an Object.

Example..

shared<SoundSource> example = exampleObject->AddComponent<SoundSource>();
*/
class SoundSource : public Component
{
public:
	//!This function initalises the source
	/*!
	This function is called automaticly when the SoundSource is created so you
	don't need to call it yourself.
	*/
	void OnInit();

	//!This function initalises the source with a sound
	/*!
	With this function you can pass in a sound when you make it. Instead of later
	This function is called automaticly when the SoundSource is created so you
	don't need to call it yourself.
	*/
	void OnInit(std::shared_ptr<Sound> _sound);

	//!The desturctor function
	~SoundSource();

	//!This function sets the Sound of the Source
	/*!
	With this function you can pass in a sound for the audio source to play.
	*/
	void SetSound(std::shared_ptr<Sound> _sound);
	
	//!This function plays the current set Sound
	void Play();

	//!Pass into function a bool of true if you want your music to loop
	void SetLooping(bool _value);

private:
	void OnUpdate();
	std::shared_ptr<ALSource> source;
};

