#include "Resource.h"

class Texture : public Resource
{
	
public:
	friend class Resources;
	~Texture();

private:
	void Load(std::string _path);
	std::shared_ptr<Texture> self;
};

