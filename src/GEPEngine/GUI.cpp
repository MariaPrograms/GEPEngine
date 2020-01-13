#include "GUI.h"
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Core.h"
#include "Resources.h"
#include "Screen.h"
#include "Camera.h"
#include "Font.h"

#include <iostream>
#include <rend/rend.h>


GUI::GUI(std::shared_ptr<Core> _core)
{
	core = _core;
	screenSize = core->GetScreen()->GetSize();
	mesh = core->GetResources()->Load<Mesh>("Objects/GUI.obj");
	shader = core->GetResources()->Load<Shader>("Shaders/GUI.txt");
	projection = glm::ortho(0.f, (float)screenSize.x, (float)screenSize.y, 0.f);
}

GUI::~GUI()
{
}

void GUI::DrawGUI(glm::vec2 _pos, std::shared_ptr<Texture> _image)
{
	rend::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(_pos.x, _pos.y, 1));
	model = glm::scale(model, glm::vec3(_image->GetRender()->getHeight(), _image->GetRender()->getWidth(), 1.0f));

	mesh->GetRender()->setTexture("u_Texture", _image->GetRender());
	shader->GetRender()->setUniform("u_Projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));
	shader->GetRender()->setUniform("u_Model", model);
	shader->GetRender()->setMesh(mesh->GetRender());

	//shader->GetRender()->setDepthTesting(false);
	//shader->GetRender()->setCullFaces(false);

	shader->GetRender()->render();
}

void GUI::DrawGUI(glm::vec4 _posNSize, std::shared_ptr<Texture> _image)
{
	rend::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(_posNSize.x, _posNSize.y, 1.0f));
	model = glm::scale(model, glm::vec3(_posNSize.z, _posNSize.w, 1.0f));
	shader->GetRender()->setUniform("u_Model", model);

	mesh->GetRender()->setTexture("u_Texture", _image->GetRender());
	shader->GetRender()->setUniform("u_Projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));
	shader->GetRender()->setMesh(mesh->GetRender());

	shader->GetRender()->render();
}

void GUI::DrawGUI(std::shared_ptr<Texture> _image)
{
	rend::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0, 0, 0));
	model = glm::scale(model, glm::vec3(screenSize.x, screenSize.y, 1.0f));

	//shader->GetRender()->setUniform("u_Model", model);
	shader->GetRender()->setUniform("u_Projection", projection);
	mesh->GetRender()->setTexture("u_Texture", _image->GetRender());
	shader->GetRender()->setMesh(mesh->GetRender());

	shader->GetRender()->setCullFaces(false);
	shader->GetRender()->setDepthTesting(false);

	shader->GetRender()->render();
}

void GUI::DrawText(std::string _text, glm::vec2 _pos, std::shared_ptr<Font> _font, float _scale)
{
	/*rend::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0, 0, 0));
	model = glm::scale(model, glm::vec3(text->GetRender()->getWidth(), text->GetRender()->getHeight(), 1.0f));

	shader->GetRender()->setUniform("u_Model", model);
	shader->GetRender()->setUniform("u_Projection", projection);
	mesh->GetRender()->setTexture("u_Texture", text->GetRender());

	shader->GetRender()->setMesh(mesh->GetRender());
	shader->GetRender()->setDepthTesting(false);
	shader->GetRender()->render();*/
}
