#include <GEPEngine/GEPengine.h>

class TriangleRenderer : public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();

	void OnDisplay();

private:
	SDL_Window* window;
	GLuint programId;
	GLuint vaoId;

};

