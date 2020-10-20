#ifndef SPRITESURFACE_H
#define SPRITESURFACE_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "Model.h"

struct Vertex
{
	glm::vec2 position;
	glm::vec2 texCoords;
};

class SpriteSurface
{
public:
	SpriteSurface();
	~SpriteSurface();

	void Render();
	void Draw();
	void OnDestroy();

	float GetWidth();
	float GetHeight();

	void SetWidth(float width_);
	void SetHeight(float height_);

private:
	void GenerateBuffers();
	

	glm::vec2 scale;
	float angle, width, height;
	std::string imagename;
	GLuint VAO, VBO;
};


#endif // !SPRITESURFACE_H
