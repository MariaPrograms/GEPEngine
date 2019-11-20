#include "Resource.h"
#include "rend/rend.h"

class Shader : public Resource
{
public:
	~Shader();
	friend class Resources;
	std::shared_ptr<rend::Shader> GetRender() { return rendShader; }

private:
	void Load(std::string _path);
	std::shared_ptr<Shader> self;
	std::shared_ptr<rend::Shader> rendShader;
};

