#include "dodger.h"
#include <string>

void updateTimer(GameObject *self)
{
    std::string time(std::to_string((static_cast<DisplayableObject *>(self)->getTime())));

    static_cast<TextObject *>(self)->setText(time);
}

void gameTimer(App &app)
{
    TextObject *timer = new TextObject("0.0");
    sf::Vector2f position = {940.0f, 20.0f};

    static_cast<GameObject *>(timer)->setFunction(&updateTimer);
    timer->setPosition(position);
    timer->setSize(50);
    app.addObject(timer);
}