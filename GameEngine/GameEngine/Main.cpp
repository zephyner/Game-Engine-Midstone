#include "Engine/Core/CoreEngine.h"
#include "Game/Game1.h"
#include "Engine/Rendering/3D/Container.h"


int main(int argc, char* argv[])
{
	CoreEngine::GetInstance()->SetGameInterFace(new Game1);
	
	//checking window is running good;
	if (!CoreEngine::GetInstance()->OnCreate("GAME ENGINE", 1280, 720))
	{
		std::cout << "Engine failed to be created " << std::endl;
		return 0;
	}


	
	CoreEngine::GetInstance()->Run();

	Container<int>* intContainer = new Container<int>();

	intContainer->AddElement(1);
	intContainer->AddElement(2);
	intContainer->AddElement(3);
	
	Container<std::string>stringContainer;
	
	stringContainer.AddElement("a");
	stringContainer.AddElement("b");
	stringContainer.AddElement("c");
	
	intContainer->PrintElements();
	std::cout << "--------------" << std::endl;
	stringContainer.PrintElements();
	delete intContainer;
	intContainer = nullptr;
	getchar();

	return 0;
}
