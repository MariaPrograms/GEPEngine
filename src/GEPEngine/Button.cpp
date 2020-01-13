#include "Button.h"
#include "Object.h"
#include "Core.h"
#include "Input.h"
#include "GUI.h"
#include "Texture.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>

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

void Button::SetPosition(glm::vec2 _position)
{
	position = _position;
}

void Button::OnUpdate()
{
	if (GetInput()->MousePosition().x >= position.x && GetInput()->MousePosition().x <= position.x + size.x &&
		GetInput()->MousePosition().y >= position.y && GetInput()->MousePosition().y <= position.y + size.y)
	{
		if (GetInput()->LeftMouseDown())
		{
			OnClick();
		}
	}
}

void Button::OnGUI()
{
	GetGUI()->DrawGUI(glm::vec4(position.x, position.y, size.x, size.y), image);
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