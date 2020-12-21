#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H 

#include "Model.h"
#include "Component.h"

class GameObject
{
public:

	GameObject(Model* model_, glm::vec3 position_ = glm::vec3());
	~GameObject();

	void Render(Camera* camera_);
	void Update(const float deltaTime_);

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;
	BoundingBox GetBoundingBox();
	std::string GetTag() const;
	bool GetHit() const;
	glm::vec3 GetVelocity() const;
	float GetMass() const;
	glm::vec3 GetAcceleration() const;

	void SetPosition(glm::vec3 Position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);
	void SetVelocity(glm::vec3 velocity_);
	void SetMass(float mass_);
	void SetAcceleration(glm::vec3 acceleration_);
	void ApplyForce(glm::vec3 force);
	void OnDestroy();

	template <class T>
	void AddComponent()
	{
		T* temp = new T();

		if (dynamic_cast<Component*>(temp) == nullptr)
		{
			Debug::Error("Object is not child of component: ", "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		if (GetComponent<T>() != nullptr)
		{
			Debug::Error("Object could not be gotten: ", "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		temp->OnCreate(this);
		component.push_back(temp);
	}

	template <class T>
	T* GetComponent()
	{
		for (Component* comp : component)
			if (dynamic_cast<T>(*comp))
				return (T*)comp;
		return nullptr;
	}

	template <class T>
	void RemoveComponent()
	{
		for (int i = 0; i < component.size(); i++)
		{
			if (dynamic_cast<T*>(component[i]))
			{
				delete component[i];
				component[i] = nullptr;

				component.erase(component.begin() + i);

				break;
			}
		}
	}

private:

	std::vector<Component*> component;

	Model* model;
	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;
	int modelInstance;
	glm::vec3 velocity;
	float mass;
	glm::vec3 acceleration;

	BoundingBox box;

	std::string tag;
	bool hit;
};

#endif // !GAMEOBJECT_H


