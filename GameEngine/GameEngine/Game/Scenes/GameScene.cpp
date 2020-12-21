#include "GameScene.h"
// this is like test scene
GameScene::GameScene() : Scene()
{
}
GameScene::~GameScene()
{
	SceneGraph::GetInstance()->OnDestroy();
}

bool GameScene::OnCreate()
{
	Debug::Info("Creating Game Scene", "GameScene.cpp", __LINE__);


	CoreEngine::GetInstance()->SetCamera(new Camera);
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CollisionHandler::GetInstance()->OnCreate();
	//Light Source
	CoreEngine::GetInstance()->GetCamera()->AddLightSources(new LightSource(glm::vec3(0.0f, 0.0f, 2.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	//dice model
	
	Model* model1 = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model1);

	//apple model
	Model* model2 = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model2);

	//add gameobject
	GameObject* dice = new GameObject(model1, glm::vec3(-2.0f, 0.5f, 0.0f));
	SceneGraph::GetInstance()->AddGameObject(dice, "dice");

	GameObject* dice2 = new GameObject(model2, glm::vec3(3.0f, -1.0f, 0.0f));
	SceneGraph::GetInstance()->AddGameObject(dice2, "dice2");

	SceneGraph::GetInstance()->GetGameObject("dice")->SetMass(1.0f);
	SceneGraph::GetInstance()->GetGameObject("dice")->ApplyForce(glm::vec3(0.05f, 0.02f, 0.0f));
	

	return true;
}
void GameScene::Update(const float deltaTime_)
{
	SceneGraph::GetInstance()->Update(deltaTime_);
	
	//SceneGraph::GetInstance()->GetGameObject("dice")->SetPosition(glm::vec3(0.05f, 0.02f, 0.0f));

}
void GameScene::Render()
{
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}

void GameScene::Draw()
{

}

