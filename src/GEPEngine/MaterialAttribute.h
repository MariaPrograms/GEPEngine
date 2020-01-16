#include <string>

class Texture;

//!  The MaterialAttribute class. The class is still in development.
/*!
please do not use this class as it is still in development and is 
not in use.
*/
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