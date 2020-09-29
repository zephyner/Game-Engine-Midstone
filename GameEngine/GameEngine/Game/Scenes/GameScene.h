#ifndef GAMESCENE_H

#include "../../Engine/Core/CoreEngine.h"
#include <glm/gtx/string_cast.hpp>

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime_);
	virtual void Render();
private: 

};
#endif //!GAMESCENE_H
