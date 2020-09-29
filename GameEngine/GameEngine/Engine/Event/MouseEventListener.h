#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include<SDL.h>
#include<glm/glm.hpp>

class CoreEngine;
class MouseEventListener
{
public:
    MouseEventListener(const MouseEventListener&) = delete;
    MouseEventListener(MouseEventListener&&) = delete;
    MouseEventListener& operator = (const MouseEventListener&) = delete;
    MouseEventListener& operator = (MouseEventListener&&) = delete;

    MouseEventListener() = delete;
    ~MouseEventListener();

    static void RegisterEngineObject(CoreEngine* engine_);
    static void Update(SDL_Event e_);

    static void NotifyOfMousePressed(int buttonType_);
    static void NotifyOfMouseReleased(int buttonType_);
    static void NotifyOfMouseMoved();
    static void NotifyOfMouseScroll(int y_);
    
    static glm::vec2 GetPreviousMousePosition();
    static glm::vec2 GetCurrentMousePosition();
    static glm::vec2 GetMouseOffset();
private:
    static CoreEngine* engineInstance;
    static glm::vec2 mouse;
    static glm::vec2 prevMouse;
    static bool firstUpdate;
    static void UpdateMousePosition();
};
#endif // !MOUSEEVENTLISTENER_H
