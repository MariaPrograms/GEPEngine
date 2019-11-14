#include <memory>
#include <vector>

class Shader;
class MaterialAttribute;
class Texture;

class Material
{
public:
	Material();
	~Material();

	void SetShader(std::weak_ptr<Shader> _shader);
	std::shared_ptr<Shader> GetShader();

	void SetValue(std::string _name, std::weak_ptr<Texture> _value);
	void SetValue(std::string _name, float _value);

private:
	std::weak_ptr<Shader> shader;
	std::vector<std::shared_ptr<MaterialAttribute>> attributes;
};

