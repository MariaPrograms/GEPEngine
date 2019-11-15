#include "Resource.h"

class Shader : public Resource
{
public:
	~Shader();
	friend class Resources;
	std::shared_ptr<rend::Shader> GetRender() { return rendShader; }

private:
	std::shared_ptr<Shader> Load(std::string _path);
	std::shared_ptr<Shader> self;
	std::shared_ptr<rend::Shader> rendShader;
};