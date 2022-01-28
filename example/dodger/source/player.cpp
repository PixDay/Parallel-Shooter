#include "dodger.h"

void playerSetting(App &app, DisplayableObject *player)
{
    sf::Vector2f position = {935.0f, 515.0f};
    sf::Vector2f scale = {0.5f, 0.5f};

    player->setTag("Player");
    player->setSpeed(550.0f);
    player->setScale(scale);
    player->setPosition(position);
    player->setFunction(&playerController);
    player->setOnCollide(&playerCollision);
    app.addObject(player);
}

void playerController(GameObject *self)
{
    sf::Vector2f position = self->getPosition();
    float elaspedTime = static_cast<DisplayableObject *>(self)->getTime();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        position.y -= (self->getSpeed() * elaspedTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        position.y += (self->getSpeed() * elaspedTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position.x += (self->getSpeed() * elaspedTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        position.x -= (self->getSpeed() * elaspedTime);
    position.x = (position.x < 0.0f) ? 0.0f : (position.x > 1870.0f) ? 1870.0f : position.x;
    position.y = (position.y < 0.0f) ? 0.0f : (position.y > 1030.0f) ? 1030.0f : position.y;
    static_cast<DisplayableObject *>(self)->setPosition(position);
    static_cast<DisplayableObject *>(self)->resetTimer();
}

void playerCollision(GameObject *self, GameObject *collided)
{
    self->setTag(STOP_RUN);
}