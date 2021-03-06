#include "GameObject.h"



GameObject::GameObject(Model* model_, glm::vec3 position_) : model(nullptr)
{
	model = model_;
	position = position_;
	angle = 0.0f;
	rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	scale = glm::vec3(1.0f);
	tag = "";
	hit = false;
	if (model)
	{
		modelInstance = model->CreateInstace(position, angle, rotation, scale);
		box = model->GetBoundingBox();
		box.transform = model->GetTransform(modelInstance);
	}

}
GameObject::~GameObject()
{
	OnDestroy();
}
void GameObject::OnDestroy()
{
	model = nullptr;
	component.clear();
}

void GameObject::Render(Camera* camera_)
{
	if (model)
	{
		model->Render(camera_);
	}
}

void GameObject::Update(const float deltaTime_)
{
	SetAngle(angle + 0.005f);
	component;
	
	position += velocity * deltaTime_ + 0.5f * acceleration * deltaTime_ * deltaTime_;
	velocity += acceleration * deltaTime_;

	if (position.x >= 20)
	{
		position.x = 20;
	}
	else if (position.x <= -20)
	{
		position.x = -20;
	}

	if (position.y >= 10)
	{
		position.y = 10;
	}
	else if (position.y <= -10)
	{
		position.y = -10;
	}

	if (position.z >= 10)
	{
		position.z = 10;
	}
	else if (position.z <= -10)
	{
		position.z = -10;
	}
}

 glm::vec3 GameObject::GetPosition() const
{
	 return position;
}
float GameObject::GetAngle() const
{
	return angle;
}
glm::vec3 GameObject:: GetRotation() const
{
	return rotation;
}
glm::vec3 GameObject::GetScale() const
{
	return scale;
}

BoundingBox GameObject::GetBoundingBox()
{
	return box;
}

void GameObject::SetPosition(glm::vec3 Position_)
{
	position = Position_;
	
	

	

	if (model)
	{
		model->UpdateInstace(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetAngle(float angle_)
{
	angle = angle_;
	if (model)
	{
		model->UpdateInstace(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetRotation(glm::vec3 rotation_)
{
	rotation = rotation_;
	if (model)
	{
		model->UpdateInstace(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
	}

}
void GameObject::SetScale(glm::vec3 scale_)
{
	scale = scale_;
	if (model)
	{
		model->UpdateInstace(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
		box.minVert *= scale.x > 1.0f ? 1.0f : (scale.x / 2.0f);
		box.maxVert *= scale.x > 1.0f ? 1.0f : (scale.x / 2.0f);
	}
	
}

void GameObject::SetTag(std::string tag_)
{
	tag = tag_;
}

std::string GameObject::GetTag() const
{
	return tag;
}

bool GameObject::GetHit() const
{
	return hit;
}
void GameObject::SetHit(bool hit_, int buttonType_)
{
	hit = hit_;
	if (hit)
	{
		std::cout << "Hit: " << tag << std::endl;
	}

}

glm::vec3 GameObject::GetVelocity() const
{
	return velocity;
}
float GameObject::GetMass() const
{
	return mass;
}
glm::vec3 GameObject::GetAcceleration() const
{
	return acceleration;
}

void GameObject::SetVelocity(glm::vec3 velocity_)
{
	velocity = velocity_;
}
void GameObject::SetMass(float mass_)
{
	mass = mass_;
}
void GameObject::SetAcceleration(glm::vec3 acceleration_)
{
	acceleration = acceleration_;
}
void GameObject::ApplyForce(glm::vec3 force)
{
	acceleration = force / mass;
}

