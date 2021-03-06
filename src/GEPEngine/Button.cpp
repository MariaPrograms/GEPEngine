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
	normalImage = _image;
	currentImage = normalImage;
	size = glm::vec2(0.f);
	position = glm::vec2(0.f);
}

void Button::SetImage(std::shared_ptr<Texture> _image)
{
	normalImage = _image;
}

void Button::SetSize(glm::vec2 _size)
{
	size = _size;
}

void Button::SetPosition(glm::vec2 _position)
{
	position = _position;
}

void Button::SetClickedImage(std::shared_ptr<Texture> _image)
{
	clickedImage = _image;
}

void Button::OnUpdate()
{
	currentImage = normalImage;

	if (GetInput()->MousePosition().x >= position.x && GetInput()->MousePosition().x <= position.x + size.x &&
		GetInput()->MousePosition().y >= position.y && GetInput()->MousePosition().y <= position.y + size.y)
	{
		if (GetInput()->LeftMouseDown())
		{
			if (clickedImage != NULL)
			{
				currentImage = clickedImage;
			}
			OnClick();
		}
	}
}

void Button::OnGUI()
{
	if (size.x <= 0 && size.y <= 0)
	{
		size = glm::vec2(normalImage->GetRender()->getWidth(), normalImage->GetRender()->getHeight());
	}

	GetGUI()->DrawGUI(glm::vec4(position.x, position.y, size.x, size.y), currentImage);
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