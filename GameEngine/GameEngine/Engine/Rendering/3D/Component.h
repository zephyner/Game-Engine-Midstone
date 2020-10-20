#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <iostream>

//forward declaration
class GameObject;

class Component
{
public:

	Component(); //{ gameObject = nullptr; }
	virtual ~Component(); //{ gameObject = nullptr; }
	virtual bool OnCreate(GameObject* gameObject_);
	virtual void Update(const float deltaTime_);

protected:
	GameObject* gameObject;

};
#endif // !COMPONENT_H