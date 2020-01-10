#include <glm/glm.hpp>
#include <memory>
#include <string>

class Core;
class Mesh;
class Shader;
class Texture;
class Font;

class GUI
{
public:
	GUI(std::shared_ptr<Core> core);
	~GUI();

	void DrawGUI(glm::vec2 _pos, std::shared_ptr<Texture> _image);
	void DrawGUI(glm::vec4 _posNSize, std::shared_ptr<Texture> _image);
	void DrawGUI(std::shared_ptr<Texture> _image);
	
	void DrawText(std::string _text, glm::vec2 _pos, std::shared_ptr<Font> _font, float _scale = 1);

private:
	glm::mat4 projection;
	glm::ivec2 screenSize;
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Core> core;

};

