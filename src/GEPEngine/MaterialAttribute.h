#include <string>

class Texture;

class MaterialAttribute
{
public:
	std::string name;
	int type;
	float floatValue;
	std::weak_ptr<Texture> textureValue;

	MaterialAttribute();
	~MaterialAttribute();
private:

};