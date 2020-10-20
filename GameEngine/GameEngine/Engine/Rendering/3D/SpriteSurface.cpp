#include "SpriteSurface.h"


SpriteSurface::SpriteSurface() : VAO(0), VBO(0)
{
	angle = 0.0f;
	scale = glm::vec2(1.0f);
	GenerateBuffers();
}

SpriteSurface::~SpriteSurface()
{
	OnDestroy();
}

void SpriteSurface::Render()
{

}

void SpriteSurface::Draw()
{

}

void SpriteSurface::OnDestroy()
{

}

float SpriteSurface::GetWidth()
{
	return 0.0f;
}

float SpriteSurface::GetHeight()
{
	return 0.0f;
}

void SpriteSurface::SetWidth(float width_)
{
}

void SpriteSurface::SetHeight(float height_)
{
}

void SpriteSurface::GenerateBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	

	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//TEX COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));
}