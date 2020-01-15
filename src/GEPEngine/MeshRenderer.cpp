#include "Core.h"
#include "Object.h"
#include "Camera.h"
#include "Light.h"
#include "Materials.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
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

void MeshRenderer::OnStart()
{
	if (material->GetTexture())
	{
		mesh->GetRender()->setTexture("u_Texture", material->GetTexture()->GetRender());
	}
}

void MeshRenderer::OnDisplay()
{
	material->setUniform("u_Model", object.lock()->GetModel());
	material->setUniform("u_Projection", object.lock()->GetCore()->GetCamera()->GetProjection());
	material->setUniform("u_View", object.lock()->GetCore()->GetCamera()->GetView());

	if (material->UsesLights())
	{
		GetObject()->GetCore()->GetLights()->SetLights(material);
	}

	material->GetShader()->setMesh(mesh->GetRender());
	material->GetShader()->setCullFaces(true);
	material->GetShader()->setDepthTesting(true);
	material->GetShader()->render();
}
