#include "GUI.h"
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Core.h"
#include "Resources.h"
#include "Screen.h"
#include "Camera.h"
#

++++nt.h"
+
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <rend/rend.h>


GUI::GUI(std::shared_ptr<Core> _core)
{
	core = _core;
	screenSize = core->GetScreen()->GetSize();
	mesh = core->GetResources()->Load<Mesh>("Objects/Texture.obj");
	shader = core->GetResources()->Load<Shader>("Shaders/GUI.txt");
	projection = glm::ortho(0.0f, (float)screenSize.x, 0.0f, (float)screenSize.y);
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


	shader->GetRender()->setUniform("u_Projection", projection);
	shader->GetRender()->setUniform("u_Model", model);
	

	shader->GetRender()->setMesh(mesh->GetRender());
	shader->GetRender()->setDepthTesting(false);
	shader->GetRender()->render();
}

void GUI::DrawGUI(glm::vec4 _posNSize, std::shared_ptr<Texture> _image)
{
	rend::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(_posNSize.x, _posNSize.y, 0));
	model = glm::scale(model, glm::vec3(_posNSize.z, _posNSize.w, 1.0f));

	mesh->GetRender()->setTexture("u_Texture", _image->GetRender());
	shader->GetRender()->setUniform("u_Projection", projection);
	shader->GetRender()->setUniform("u_Model", model);

	shader->GetRender()->setMesh(mesh->GetRender());
	shader->GetRender()->setDepthTesting(false);
	shader->GetRender()->render();
}

void GUI::DrawGUI(std::shared_ptr<Texture> _image)
{
	
	rend::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0, 0, 0));
	model = glm::scale(model, glm::vec3(screenSize.x, screenSize.y, 1.0f));

	shader->GetRender()->setUniform("u_Model", model);
	shader->GetRender()->setUniform("u_Projection", projection);
	mesh->GetRender()->setTexture("u_Texture", _image->GetRender());

	shader->GetRender()->setMesh(mesh->GetRender());
	shader->GetRender()->setDepthTesting(false);
	shader->GetRender()->render();
}

void GUI::DrawText(std::string _text, glm::vec2 _pos, Font _font, float _scale)
{


}
