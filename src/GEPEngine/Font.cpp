#include "Font.h"
#include "Texture.h"
#include "Exception.h"
#include "Core.h"

void Font::Load(std::string _path)
{
	//renderFont = core->GetContext()->createFont();
	//long size;
	//std::vector<unsigned char> fontBuffer;

	//FILE* fontFile = fopen(_path.c_str(), "rb");
	//fseek(fontFile, 0, SEEK_END);
	//size = ftell(fontFile); /* how long is the file ? */
	//fseek(fontFile, 0, SEEK_SET); /* reset */

	//fontBuffer.resize(size);


	//fread(&fontBuffer.at(0), size, 1, fontFile);

	//renderFont->initFont(fontBuffer);

	//fclose(fontFile);
}

void Font::DrawFont(std::string _text, glm::vec2 position)
{

}

