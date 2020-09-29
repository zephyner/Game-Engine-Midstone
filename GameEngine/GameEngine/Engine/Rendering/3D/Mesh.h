#ifndef MESH_H
#define MESH_H 

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "../../Graphics/MaterialHandler.h"

//struct is public by default
struct Vertex 
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 colour;
};
struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<int> meshIndices;
	Material material;
 };
//class is private by dafult
class Mesh
{
public :
	Mesh(SubMesh subMesh_, GLuint shaderProgram_);
   ~Mesh();

   void Render(Camera* camera_, std::vector<glm::mat4> instances_);
   void OnDestroy();

private:
	void GenerateBuffers();

	SubMesh subMesh;

	GLuint VAO, VBO;
	GLuint shaderProgram;
	GLuint modelLoc, viewLoc, projLoc;
	GLuint diffuseMapLoc, shininessLoc, transparencyLoc, ambientLoc, diffuseLoc, specLoc;
	GLuint camPosLoc;

	GLuint lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightColorLoc;
	
};
#endif // !MESH_H 