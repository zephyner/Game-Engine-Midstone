#include "Component.h"

Component::Component()
{
	gameObject = nullptr;
}

Component::~Component()
{
	gameObject = nullptr;
}

bool Component::OnCreate(GameObject* gameObject_)
{
	gameObject = gameObject_;
}

void Component::Update(const float deltaTime_)
{

}
