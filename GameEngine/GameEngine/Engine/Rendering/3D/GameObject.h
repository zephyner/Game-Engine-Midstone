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
	
	void SetPosition(glm::vec3 Position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);
	void OnDestroy();

	//component add it here
	template <class T>
	void AddComponent() 
	{ 
		T* temp = new T(); 
		
		if (dynamic_cast<Component*>(temp) == nullptr)
		{
			Debug::Error("Object is not child of component: " + filePath_, "GameObject.h", __LINE__);
			delete temp;
			temp = nullptr;
			return;
		}

		if (GetComponent<T>() != nullptr)
		{
			Debug::Error("Object is not child of component: " + filePath_, "GameObject.h", __LINE__);
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
		T* = component;
		int numComponents = 10;
		for (int component{0}; component < numComponents; component++ )
		{
			if (component <= 1)
			{
				Component* c = dynamic_cast<Component*>(c);
				Component* b = dynamic_cast<Component*>(b);
				Component* a = dynamic_cast<Component*>(a);
				return;
			}
			return 0;
		}
	}
	template <class T>
	void RemoveComponent() 
	{
		T* = component;
		for (Component* c; Component* b; Component* a; : component)
		{
			delete c;
			c = nullptr;

			delete b;
			b = nullptr;

			delete a;
			a = nullptr;
		}
		component.clear();
	}

private:

	std::vector<Component*> component;

	Model* model;
	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;
	int modelInstance;

	BoundingBox box;

	std::string tag;
	bool hit;
};

#endif // !GAMEOBJECT_H
