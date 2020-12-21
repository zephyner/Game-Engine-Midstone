#include "Engine/Core/CoreEngine.h"
#include "Game/Game1.h"

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

	getchar();

	return 0;
}
