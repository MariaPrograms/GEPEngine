#include "TriangleRenderer.h"

const GLfloat positions[] = 
{
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
};

const GLfloat colors[] = 
{
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f
};


TriangleRenderer::TriangleRenderer()
{
}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::OnDisplay()
{

}