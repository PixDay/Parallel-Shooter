#include "dodger.h"
#include <iostream>

#define ENEMIES 70

void ennemyMovement(GameObject *self)
{
    sf::Vector2f direction = self->getDirection();
    sf::Vector2f position = self->getPosition();
    float elaspedTime = static_cast<DisplayableObject *>(self)->getTime();

    if (position.x > 1870.0f) {
        direction.x = -(self->getDirection().x);
        self->setSpeed(self->getSpeed() + 0.5f);
    }
    if (position.x < 0.0f) {
        direction.x = -(self->getDirection().x);
        self->setSpeed(self->getSpeed() + 0.5f);
    }
    if (position.y > 1030.0f) {
        direction.y = -(self->getDirection().y);
        self->setSpeed(self->getSpeed() + 0.5f);
    }
    if (position.y < 0.0f) {
        direction.y = -(self->getDirection().y);
        self->setSpeed(self->getSpeed() + 0.5f);
    }
    position.x = position.x + (direction.x * self->getSpeed()) * elaspedTime;
    position.y = position.y + (direction.y * self->getSpeed()) * elaspedTime;
    self->setDirection(direction);
    static_cast<DisplayableObject *>(self)->setPosition(position);
    static_cast<DisplayableObject *>(self)->resetTimer();
}

void createEnnemies(App &app)
{
    sf::Vector2f direction;
    sf::Vector2f positions[4] = {
        {80.0f, 80.0f},
        {80.0f, 1000.0f},
        {1840.0f, 80.0f},
        {1840.0f, 1000.0f},
    };

    for(size_t i = 0; i < ENEMIES; i++) {
        DisplayableObject *ennemy = new DisplayableObject("img/ennemy.png", &ennemyMovement);
        direction.x = ((float)(rand() % 100 + 1) / 100.0f);
        direction.y = ((float)(rand() % 100 + 1) / 100.0f);
        ennemy->setPosition(positions[rand() % 4]);
        ennemy->setDirection(direction);
        ennemy->setTag("Ennemy");
        ennemy->setSpeed((float)(rand() % 100) / 120.0f + 80.5f);
        app.addObject(ennemy);
    }
}