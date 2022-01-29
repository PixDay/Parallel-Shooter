#include "parallel-shooter.h"

void player(GameObject *self)
{
    sf::Vector2f position = self->getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        position.y -= self->getSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        position.y += self->getSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        position.x -= self->getSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position.x += self->getSpeed();
    static_cast<DisplayableObject *>(self)->setPosition(position);
}

void player1Init(DisplayableObject *player1)
{
    sf::Vector2f position = {300.0f, 300.0f};
    sf::Vector2f scale = {1.5f, 1.5f};
    sf::Vector2f origin = {0.0f, 0.0f};
    sf::Vector2f direction = {0.0f, 0.0f};
    sf::Vector2f hitbox = {0.0f, 0.0f};

    player1->setPosition(position);
    player1->setScale(scale);
    player1->setOrigin(origin);
    player1->setDirection(direction);
    player1->setHitbox(hitbox);
}

int main()
{
    App app = App();
    DisplayableObject *player1 = new DisplayableObject("img/player.png", &player);
    player1->setSpeed(5.0f);
    player1->setTag("Player");

    player1Init(player1);
    app.addScene("Game");
    app.setCurrentScene("Game");    

    app.addObject(player1);
    app.run();
    return 0;
}

//cmake --build . -j8