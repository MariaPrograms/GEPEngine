#include "MeshRenderer.h"
#include "Materials.h"
#include "Shader.h"
#include "Mesh.h"
#include "Object.h"

MeshRenderer::MeshRenderer()
{
	
}

void MeshRenderer::OnInit()
{

}

void MeshRenderer::SetMaterial(std::shared_ptr<Material> _material)
{
	material = _material;
}

void MeshRenderer::SetMesh(std::shared_ptr<Mesh> _mesh)
{
	mesh = _mesh;
}

std::shared_ptr<Mesh> MeshRenderer::GetMesh()
{
	return mesh;
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
	material->GetShader()->setUniform("u_Model", object.lock()->GetModel());
	material->GetShader()->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
	material->GetShader()->setMesh(mesh->GetRender());
	material->GetShader()->render();
}
