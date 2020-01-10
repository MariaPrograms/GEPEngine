#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"
#include "Resource.h"

class Texture;

class Font : public Resource
{
public:
	void Load(std::string _path);
	stbtt_fontinfo GetFontInfo();

private:
	stbtt_fontinfo fontInfo;
	int i;
	int j;
	int ascent;
	int baseline;
	int ch = 0;
	float scale;
	float xpos = 2; 
};

