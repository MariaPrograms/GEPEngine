#include <GEPEngine/GEPengine.h>

class TriangleRenderer : public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	void OnDisplay();
	void Initialize();

private:
	GLuint programId;
	GLuint vaoId;

};

