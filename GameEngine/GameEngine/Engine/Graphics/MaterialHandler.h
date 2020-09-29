#ifndef MATERIALHANDLER_H
#define MATERIALHANDLER_H

#include <glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>

struct Material
{
	inline Material() : diffuseMap(0), shiniess(0.0f), transparency(0.0f), ambient(glm::vec3(1.0f)) , diffuse(glm::vec3(1.0f)) , specular(glm::vec3(1.0f)) , name("")
	{

	}
	GLuint diffuseMap; //newmtl1

	float shiniess; //Ns
	float transparency; //d

	glm::vec3 ambient; //Ka
	glm::vec3 diffuse;	//Kd
	glm::vec3 specular;	//Ks
	std::string name;
};
class MaterialHandler
{
public:
	MaterialHandler(const MaterialHandler&) = delete;
	MaterialHandler(MaterialHandler&&) = delete;
	MaterialHandler& operator = (const MaterialHandler&) = delete;
	MaterialHandler& operator = (MaterialHandler&&) = delete;

	static MaterialHandler* GetInstance();
	void AddMaterial(Material mat_);
	const Material GetMaterial(const std::string& matName_);
	void OnDestroy();

	const Material GetMaterialeData(const std::string textureName_);
private:
	MaterialHandler();
	~MaterialHandler();

	static std::unique_ptr<MaterialHandler> MaterialInstance;
	friend std::default_delete<MaterialHandler>;
	static std::vector<Material> materials;
};
#endif
