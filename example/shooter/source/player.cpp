#include "shooter.h"

void initPlayer(App &app, GameObject *camera)
{
    sf::Vector2f position = {1920.0f / 2.0f, 1080.0f / 2.0f};
    sf::Vector2f scale = {0.20f, 0.20f};

    DisplayableObject *player = new DisplayableObject("img/player.png");
    DisplayableObject *ennemy1 = new DisplayableObject("img/ennemy.png");
    DisplayableObject *ennemy2 = new DisplayableObject("img/ennemy.png");

    player->setTag("Player");
    player->setPosition(position);
    player->setSpeed(450.0f);
    player->setScale(scale);
    player->setFunction(&playerController);
    static_cast<Camera *>(camera)->setObjectToFollow(player);
    camera->setFunction(&cameraController);
    app.addObject(player);
    app.addObject(camera);
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
    static_cast<DisplayableObject *>(self)->setPosition(position);
    static_cast<DisplayableObject *>(self)->resetTimer();
}

void cameraController(GameObject *self)
{
    sf::Vector2f toFollowPosition = static_cast<Camera *>(self)->getToFollow()->getPosition();
    sf::Vector2f currentPosition = static_cast<Camera *>(self)->getPosition();
    
    toFollowPosition.x = (toFollowPosition.x - currentPosition.x) / 15.0f;
    toFollowPosition.y = (toFollowPosition.y - currentPosition.y) / 15.0f;
    static_cast<Camera *>(self)->move(toFollowPosition);
}