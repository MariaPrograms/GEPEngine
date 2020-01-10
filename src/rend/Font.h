#include "mathutil.h"

#include <GL/glew.h>
#include <sr1/vector>
#include <sr1/memory>
#include <sr1/noncopyable>
#include <sr1/zero_initialized>

#include "stb_truetype.h"

//Maria's Work
namespace rend
{
	struct Context;

	struct Font : public std::sr1::noncopyable
	{
		~Font();
		void initFont(std::vector<unsigned char> buffer);
		void printFont(float x, float y, char *text);

	private:
		friend struct Context;
		std::sr1::shared_ptr<Context> context;
		std::sr1::zero_initialized<GLuint> id;

		//std::vector<unsigned char> ttf_buffer;
		unsigned char temp_bitmap[512 * 512];
		stbtt_bakedchar cdata[96]; // ASCII 32..126 is 95 glyphs
		//GLuint getId();

	};

}
