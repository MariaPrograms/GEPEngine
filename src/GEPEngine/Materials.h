#include <memory>
#include <vector>
#include <rend/rend.h>
#include <string>

class Shader;
class MaterialAttribute;
class Texture;

class Material
{
public:
	Material();
	~Material();

	void SetShader(std::shared_ptr<Shader> _shader);
	void SetTexture(std::shared_ptr<Texture>);

	std::shared_ptr<rend::Shader> GetShader();
	std::shared_ptr<Texture> GetTexture();

	void setUniform(const std::string& variable, float value);
	void setUniform(const std::string& variable, glm::mat4 value);
	void setUniform(const std::string& variable, glm::vec2 value);
	void setUniform(const std::string& variable, glm::vec3 value);
	void setUniform(const std::string& variable, glm::vec4 value);

	bool UsesLights();

private:
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture> texture;
	std::vector<std::shared_ptr<MaterialAttribute>> attributes;
};

