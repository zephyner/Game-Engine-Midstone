#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;


CoreEngine::CoreEngine()  
{
    window = nullptr;
    isRunning = false;
    fps = 120.0f;
    gameInterFace = nullptr;
    currentSceneNum = 0;
    camera = nullptr;
}
CoreEngine::~CoreEngine()
{
    //OnDestroy(); 
    //stops the error from popping up since being destroyed twice. here then when isrunning is false.
}

CoreEngine* CoreEngine::GetInstance() 
{
    if (engineInstance.get() == nullptr)
    {
        engineInstance.reset(new CoreEngine);
    }
    return engineInstance.get();
}

bool CoreEngine::OnCreate(std::string name_, int width_, int height_)
{
    Debug::DebugInit();
    Debug::SetSeverity(MessageType::TYPE_INFO);

    window = new Window();
    if (!window->OnCreate(name_, width_, height_))
    {
        Debug::FatalError("Window Failed to initialize", "CoreEngine.cpp", __LINE__);
        return isRunning = false;
    }

    SDL_WarpMouseInWindow(window->GetWindow(), window->GetWidth() / 2, window->GetHeight() / 2); //put mouse in center of screen on creation.

    MouseEventListener::RegisterEngineObject(this); //register the core engine because its the engine we can use this.
    ShaderHandler::GetInstance()->CreateProgram("ColourShader", "Engine/Shaders/ColourVertexShader.glsl", "Engine/Shaders/ColourFragmentShader.glsl");
    ShaderHandler::GetInstance()->CreateProgram("basicShader", "Engine/Shaders/VertexShader.glsl", "Engine/Shaders/FragmentShader.glsl");

    if (gameInterFace) // gameInterface != nullptr;
    {
        if (!gameInterFace->OnCreate())
        {
            //Debug
            Debug::Error("Game Failed to Create", "CoreEngine.cpp", __LINE__);
            return isRunning = false;
        }
    }

    timer.Start();

    Debug::Info("Everything Worked!", "CoreEngine.cpp", __LINE__);

    return isRunning = true;
}
void CoreEngine::Run()
{
    while (isRunning)
    {
        timer.UpdateFrameTicks();
        EventListener::Update();
        Update(timer.GetDeltaTime());
        Render();
        SDL_Delay(timer.GetSleepTime(fps));
       
    }
    if (!isRunning)
    {
        OnDestroy();
    }
}


bool CoreEngine::GetIsRunning() const
{
    return isRunning;
}


void CoreEngine:: Update(const float deltaTime_)
{
    if (gameInterFace)
    {
        gameInterFace->Update(deltaTime_);
    }
}
void CoreEngine::Render()
{
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (gameInterFace)
    {
        gameInterFace->Render();
        gameInterFace->Draw();
    }
    
    //RENDER GAME 
    SDL_GL_SwapWindow(window->GetWindow());

}
   
void CoreEngine::OnDestroy()
{
    TextureHandler::GetInstance()->OnDestroy();
    ShaderHandler::GetInstance()->OnDestroy();
    SceneGraph::GetInstance()->OnDestroy();
    CollisionHandler::GetInstance()->OnDestroy();
    delete camera;
    camera = nullptr;

    delete gameInterFace;
    gameInterFace = nullptr;

    delete window;
    window = nullptr;

    SDL_Quit();
    exit(0);
}
   
void CoreEngine::SetGameInterFace(GameInterFace* gameInterface_)
{
    gameInterFace = gameInterface_;
}

int CoreEngine::GetCurrentScene()
{
    return currentSceneNum;
}

void CoreEngine::SetCurrentScene(int sceneNum_)
{
    currentSceneNum = sceneNum_;
}

void CoreEngine::Exit()
{
    isRunning = false;
}

glm::vec2 CoreEngine::GetWindowsize() const
{
    return glm::vec2(window->GetWidth(), window->GetHeight());
}

Camera* CoreEngine::GetCamera() const
{
    return camera;

}

void CoreEngine::SetCamera(Camera* camera_)
{
    camera = camera_;
}

void CoreEngine::NotifyOfMousePressed(glm::vec2 mouse_)
{

}
void CoreEngine::NotifyOfMouseReleased(glm::vec2 mouse_, int buttonType_)
{
    CollisionHandler::GetInstance()->Update(mouse_, buttonType_);
}
void CoreEngine::NotifyOfMouseMoved(glm::vec2 mouse_)
{
    if (camera) {
        camera->ProcessMouseMovement(MouseEventListener::GetMouseOffset());
    }
}
void CoreEngine::NotifyOfMouseScroll(int y_)
{
    if (camera) {
        camera->ProcessMouseZoom(y_);
    }
}