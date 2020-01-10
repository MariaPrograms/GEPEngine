#include "Font.h"

#define STB_TRUETYPE_IMPLEMENTATION  // force following include to generate implementation
#include "stb_truetype.h"

namespace rend
{
	void Font::initFont(std::vector<unsigned char> buffer)
	{
		stbtt_BakeFontBitmap(&buffer.at(0), 0, 32.0, temp_bitmap, 512, 512, 32, 96, cdata); // no guarantee this fits!
		
		// can free ttf_buffer at this point
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 512, 512, 0, GL_RED, GL_UNSIGNED_BYTE, temp_bitmap);
		
		// can free temp_bitmap at this point
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}

	void Font::printFont(float x, float y, char *text)
	{
		// assume orthographic projection with units = screen pixels, origin at top left
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, id);
		glBegin(GL_QUADS);

		while (*text) 
		{
			if (*text >= 32 && *text < 128) 
			{
				stbtt_aligned_quad q;
				stbtt_GetBakedQuad(cdata, 512, 512, *text - 32, &x, &y, &q, 1);//1=opengl & d3d10+,0=d3d9
				glTexCoord2f(q.s0, q.t1); glVertex2f(q.x0, q.y0);
				glTexCoord2f(q.s1, q.t1); glVertex2f(q.x1, q.y0);
				glTexCoord2f(q.s1, q.t0); glVertex2f(q.x1, q.y1);
				glTexCoord2f(q.s0, q.t0); glVertex2f(q.x0, q.y1);
			}
			++text;
		}
	}

	Font::~Font()
	{

	}

}

