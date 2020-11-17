#ifndef PARTICAL_H
#define PARTICAL_H

//include similar to mesh class
#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Camera/Camera.h"
#include "../Graphics/TextureHandler.h"
#include <glm/gtc/matrix_transform.hpp>
#include "../Graphics/ShaderHandler.h"
#include <iostream>
#include "../Math/Randomizer.h"

class Particle
{
public:
	glm::vec3 Position;
	glm::vec3 Velocity;
	glm::vec3 Colour;
	float Size;
	float Lifetime;

	Particle(GLuint shaderProgram_);
	~Particle();

	void Render(Camera* camera_);
	void OnDestroy();

private:
	void GenerateBuffers();

	GLuint VAO, VBO;
	GLuint shaderProgram;
	GLuint textureID;
	GLuint projLoc, tintColour, viewLoc, PosLoc;
	GLuint camPosLoc;

};
#endif

