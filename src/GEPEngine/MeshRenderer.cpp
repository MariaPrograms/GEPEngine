#include "MeshRenderer.h"
#include "Materials.h"
#include "Shader.h"
#include "Mesh.h"

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
	//material->GetShader()->setUniform("in_Model", glm::mat4(1.0f));
	material->GetShader()->GetRender()->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
	material->GetShader()->GetRender()->setMesh(mesh.lock()->GetRender());
	material->GetShader()->GetRender()->render();
}
