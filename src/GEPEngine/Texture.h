#include "Resource.h"
#include <rend/rend.h>

class Texture : public Resource
{
public:
	~Texture();
	friend class Resources;
	void MakeTexture(unsigned char*_data, int w = 0, int h = 0);
	std::shared_ptr<rend::Texture> GetRender() { return rendText; }
	
private:
	void Load(std::string _path);
	std::shared_ptr<Texture> self;
	std::shared_ptr<rend::Texture> rendText;
};

