#include <memory>
#include <vector>
#include <rend/rend.h>

class Shader;
class MaterialAttribute;
class Texture;

class Material
{
public:
	Material();
	~Material();

	void SetShader(std::shared_ptr<rend::Shader> _shader);
	std::shared_ptr<rend::Shader> GetShader();

	void SetValue(std::string _name, std::weak_ptr<Texture> _value);
	void SetValue(std::string _name, float _value);

private:
	std::shared_ptr<rend::Shader> shader;
	std::vector<std::shared_ptr<MaterialAttribute>> attributes;
};

