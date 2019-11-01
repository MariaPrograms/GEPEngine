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

const GLchar *vertexShaderSrc =
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = vec4(in_Position, 1.0);" \
"  ex_Color = in_Color;" \
"}" \
"";

const GLchar *fragmentShaderSrc =
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"";


TriangleRenderer::TriangleRenderer()
{
	vertexPos = std::make_shared<VBO>();
	vertexPos->Add(glm::vec3(0.0f, 0.5f, 0.0f));
	vertexPos->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
	vertexPos->Add(glm::vec3 (0.5f, -0.5f, 0.0f));

	vertexCol = std::make_shared<VBO>();
	vertexCol->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	vertexCol->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	vertexCol->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	buffer.setBuffer("in_Position", vertexPos);
	buffer.setBuffer("in_Color", vertexCol);

	//Shader 
	shader = std::make_shared<Shader>("C:\\Users\\s4915051\\GEPEngine\\src\\GEPEngine\\VertexShader.txt", "C:\\Users\\s4915051\\GEPEngine\\src\\GEPEngine\\FragmentShader.txt");

}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::OnDisplay()
{
	shader->draw(&buffer);
}