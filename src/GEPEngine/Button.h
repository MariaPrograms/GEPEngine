#include "Components.h"

#include <list>
#include <functional>
#include <glm/glm.hpp>

class Texture;

class Button : public Component
{
public:
	void RegisterCallback(const std::function<void()> &_callback);
	 void OnClick();

	void OnInit(std::shared_ptr<Texture> image);
	void SetImage(std::shared_ptr<Texture> image);
	void SetSize(glm::vec2 _size);

private:
	void OnUpdate();
	void OnGUI();
	std::shared_ptr<Texture> image;
	glm::vec2 size;
	std::list<std::function<void()>> callbacks;
};