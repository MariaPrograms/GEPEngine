#include "TriangleRenderer.h"

TriangleRenderer::TriangleRenderer()
{
	vertexPos = std::make_shared<VBO>();
	vertexPos->Add(glm::vec3(0.0f, 0.5f, 0.0f));
	vertexPos->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
	vertexPos->Add(glm::vec3 (0.5f, -0.5f, 0.0f));

	vertexCol = std::make_shared<VBO>();
	vertexCol->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	vertexCol->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	vertexCol->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

	buffer = std::make_shared<VAO>();
	buffer->setBuffer("in_Position", vertexPos);
	buffer->setBuffer("in_Color", vertexCol);

	//Shader 
	shader = std::make_shared<Shader>("C:\\Users\\s4915051\\GEPEngine\\src\\GEPEngine\\Shader");

}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::OnDisplay()
{
	shader->draw(buffer);
}