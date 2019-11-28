
#include "Materials.h"
#include "Shader.h"
#include "Mesh.h"
#include "Core.h"
#include "Object.h"
#include "Camera.h"
#include "MeshRenderer.h"

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
	material->GetShader()->setUniform("u_Projection", object.lock()->GetCore()->GetCamera()->GetProjection());
	material->GetShader()->setUniform("u_View", object.lock()->GetCore()->GetCamera()->GetView());
	material->GetShader()->setMesh(mesh->GetRender());
	material->GetShader()->render();
}
