#include "MeshRenderer.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

MeshRenderer::MeshRenderer()
{
	
}

void MeshRenderer::OnInit()
{
	vertexPos = std::make_shared<VBO>();
	vertexPos->Add(glm::vec3(0.0f, 0.5f, 0.0f));
	vertexPos->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
	vertexPos->Add(glm::vec3(0.5f, -0.5f, 0.0f));

	vertexCol = std::make_shared<VBO>();
	vertexCol->Add(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	vertexCol->Add(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	vertexCol->Add(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

	buffer = std::make_shared<VAO>();
	buffer->SetBuffer("in_Position", vertexPos);
	buffer->SetBuffer("in_Color", vertexCol);

	//Shader 
	shader = std::make_shared<Shader>("../Shaders/simple");
}

void MeshRenderer::SetMesh(std::weak_ptr<Mesh> _mesh)
{
	mesh = _mesh;
}

std::shared_ptr<Mesh> MeshRenderer::GetMesh()
{
	return mesh.lock();
}

std::shared_ptr<Material> MeshRenderer::GetMaterial()
{
	return material;
}


MeshRenderer::~MeshRenderer()
{
}



void MeshRenderer::OnDisplay()
{
	shader->SetUniform("in_Model", glm::mat4(1.0f));
	shader->SetUniform("in_Projection", glm::mat4(1.0f));
	shader->Draw(buffer);
}
