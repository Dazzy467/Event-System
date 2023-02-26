#include <iostream>
#include "event.h"

void MouseClickHandler(const mouseEvent& e)
{
    std::cout << "Event id: " << e.getId() << std::endl;
    std::cout << "Left-click di coordinat " << e.getX() << ", " << e.getY() << std::endl;
}

int ye(const int& i)
{
    return i;
}

template<typename T>
void tes(const std::function<int(const T&)>& h)
{
    auto lambda = [h](const int& i)
    {
        std::cout << h(i) << std::endl;
    };

    //this just CALLS and doesn't do anything, don't think too much about it
    lambda(0);
}

int main()
{
    eventSystem Events;
    mouseEvent mevent(2,80,40);
    mouseEventListener listenMouse(Events);


    bool isClick = true;
    
    Events.Bind<mouseEvent>(EventType::EVENT_MOUSE_LCLICK,MouseClickHandler);
    Events.Publish(EventType::EVENT_MOUSE_ANY,mevent);
    if (isClick)
        Events.Publish(EventType::EVENT_MOUSE_LCLICK,mevent);

    int a = 5;
    tes<int>(std::bind(ye,a));
}