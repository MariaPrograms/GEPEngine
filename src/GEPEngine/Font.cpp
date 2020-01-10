#include "Font.h"
#include "Exception.h"

void Font::Load(std::string _path)
{
	long size;
	unsigned char* fontBuffer;

	FILE* fontFile = fopen(_path.c_str, "rb");
	fseek(fontFile, 0, SEEK_END);

	size = ftell(fontFile); /* how long is the file ? */
	fseek(fontFile, 0, SEEK_SET); /* reset */

	fontBuffer = (unsigned char*) malloc(size);

	fread(fontBuffer, size, 1, fontFile);
	fclose(fontFile);

	if (!stbtt_InitFont(&fontInfo, fontBuffer, 0))
	{
		Exception("Font Unable to Load");
	}
}

stbtt_fontinfo Font::GetFontInfo()
{
	return fontInfo;
}
