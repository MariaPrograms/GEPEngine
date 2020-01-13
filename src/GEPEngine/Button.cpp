#include "Button.h"
#include "Object.h"
#include "Core.h"
#include "Input.h"
#include "GUI.h"
#include "Texture.h"

#include <iostream>


void Button::OnInit(std::shared_ptr<Texture> _image)
{
	image = _image;
}

void Button::SetImage(std::shared_ptr<Texture> _image)
{
	image = _image;
}

void Button::SetSize(glm::vec2 _size)
{
	size = _size;
}

void Button::OnUpdate()
{
	glm::vec3 position = GetObject()->GetPoition();
	if (GetInput()->MousePosition().y >= position.y)
	{
		// && GetInput()->MousePosition().y >= position.y + size.y
		//GetInput()->MousePosition().x >= position.x && GetInput()->MousePosition().x <= position.x + size.x &&
		std::cout << "In Y" << std::endl;
		if (GetInput()->LeftMouseDown())
		{
			std::cout << "Click" << std::endl;
		}
	}
}

void Button::OnGUI()
{
	GetGUI()->DrawGUI(glm::vec4(GetObject()->GetPoition().x, GetObject()->GetPoition().y,  size), image);
}

void Button::RegisterCallback(const std::function<void()> &_callback)
{
	callbacks.push_back(_callback);
}

 void Button::OnClick()
{
	for (const auto &cb : callbacks)
	{
		cb();
	}
}