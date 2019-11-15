#include "MeshRenderer.h"
#include "Materials.h"

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

void MeshRenderer::SetMesh(std::weak_ptr<rend::Mesh> _mesh)
{
	mesh = _mesh;
}

std::shared_ptr<rend::Mesh> MeshRenderer::GetMesh()
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
	material->GetShader()->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));

	material->GetShader()->setMesh(mesh.lock());
	material->GetShader()->render();
}
