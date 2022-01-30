#include "parallel-shooter.h"
#include <iostream>
#include <cmath>

void InitGame(App &app)
{
    DisplayableObject *blackPlayer = new DisplayableObject("img/blackPlayer.png", &blackPlayerUpdate);
    DisplayableObject *whitePlayer = new DisplayableObject("img/whitePlayer.png", &whitePlayerUpdate);
    DisplayableObject *blackBackground = new DisplayableObject("img/blackBackground.png");
    DisplayableObject *whiteBackground = new DisplayableObject("img/whiteBackground.png");

    DisplayableObject *blackBullet = new DisplayableObject("img/blackBullet.png", &blackBulletUpdate);
    DisplayableObject *whiteBullet = new DisplayableObject("img/whiteBullet.png", &whiteBulletUpdate);

    TextObject* blackPlayerScore = new TextObject("0");
    TextObject* whitePlayerScore = new TextObject("0");

    blackBullet->addObject(blackPlayerScore);
    whiteBullet->addObject(whitePlayerScore);

    initBlackPlayer(blackPlayer, blackBullet);
    initWhitePlayer(whitePlayer, whiteBullet);
    initBlackBackground(blackBackground);
    initWhiteBackground(whiteBackground);
    initEnnemies(app, blackPlayer, whitePlayer);
    

    blackBackground->setLayout(1);
    whiteBackground->setLayout(1);
    whitePlayer->setLayout(2);
    blackPlayer->setLayout(2);
    blackPlayerScore->setLayout(5);
    whitePlayerScore->setLayout(5);

    blackPlayerScore->setPosition({970.f, 10.f});
    whitePlayerScore->setPosition({10.f, 10.f});

    blackPlayerScore->setColor(0x000000);

    app.addObjectTo(blackBackground, GAME_SCENE);
    app.addObjectTo(whiteBackground, GAME_SCENE);

    app.addObjectTo(blackPlayer, GAME_SCENE);
    app.addObjectTo(whitePlayer, GAME_SCENE);  

    app.addObjectTo(blackBullet, GAME_SCENE);  
    app.addObjectTo(whiteBullet, GAME_SCENE);

    app.addObjectTo(blackPlayerScore, GAME_SCENE);
    app.addObjectTo(whitePlayerScore, GAME_SCENE);
}

void initBlackPlayer(DisplayableObject *blackPlayer, DisplayableObject * blackBullet)
{
    sf::Vector2f position = {1390.0f, 490.0f};
    sf::Vector2f origin = {50.0f, 50.0f};
    sf::Vector2f scale = {0.3f, 0.3f};

    blackPlayer->setPosition(position);
    blackPlayer->setOrigin(origin);
    blackPlayer->setScale(scale);
    blackPlayer->setAngle(0.0f);
    
    blackPlayer->addObject(blackBullet);
    blackPlayer->setTag("blackPlayer");

    blackBullet->setLayout(3);
    blackBullet->setTag("blackbullet");
}

void initWhitePlayer(DisplayableObject *whitePlayer, DisplayableObject * whiteBullet)
{
    sf::Vector2f position = {430.0f, 490.0f};
    sf::Vector2f origin = {50.0f, 50.0f};
    sf::Vector2f scale = {0.3f, 0.3f};

    whitePlayer->setPosition(position);
    whitePlayer->setOrigin(origin);
    whitePlayer->setScale(scale);
    whitePlayer->setAngle(0.0f);

    whitePlayer->addObject(whiteBullet);
    whitePlayer->setTag("whitePlayer");

    whiteBullet->setLayout(3);
    whiteBullet->setTag("whitebullet");
}

void initBlackBackground(DisplayableObject *blackBackground)
{
    sf::Vector2f position = {0.0f, 0.0f};

    blackBackground->setPosition(position);
}

void initWhiteBackground(DisplayableObject *whiteBackground)
{
    sf::Vector2f position = {960.0f, 0.0f};

    whiteBackground->setPosition(position);
}

void whitePlayerUpdate(GameObject *self)
{
    whitePlayerMovement(self);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        whitePlayerAttack(self);
    }
}

void blackPlayerUpdate(GameObject *self)
{
    blackPlayerMovement(self);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
       blackPlayerAttack(self);
    }
}

void whitePlayerMovement(GameObject *self)
{
    sf::Vector2f position = self->getPosition();
    sf::Vector2f vector = {0.0f, 0.0f};

    vector.x = - sin(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);
    vector.y = cos(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        position.y -= self->getSpeed() * vector.y;
        position.x -= self->getSpeed() * vector.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.y += self->getSpeed() * vector.y;
        position.x += self->getSpeed() * vector.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        static_cast<DisplayableObject *>(self)->setAngle(static_cast<DisplayableObject *>(self)->getAngle() + ROTATE_SPEED);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        static_cast<DisplayableObject *>(self)->setAngle(static_cast<DisplayableObject *>(self)->getAngle() - ROTATE_SPEED);

    const float minX = 0.0f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxX = 960.f - PLAYER_SIZE_PIXEL / 4.f;
    const float minY = 0.0f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxY = 1080.0f - PLAYER_SIZE_PIXEL / 4.f;

    position.x = (position.x < minX) ? minX : (position.x > maxX) ? maxX : position.x;
    position.y = (position.y < minY) ? minY : (position.y > maxY) ? maxY : position.y;
    static_cast<DisplayableObject *>(self)->setPosition(position);
}

void blackPlayerMovement(GameObject *self)
{
    sf::Vector2f position = self->getPosition();
    sf::Vector2f vector = {0.0f, 0.0f};

    // Calculate the vector based on angle of black player
    vector.x = - sin(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);
    vector.y = cos(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position.y -= self->getSpeed() * vector.y;
        position.x -= self->getSpeed() * vector.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        position.y += self->getSpeed() * vector.y;
        position.x += self->getSpeed() * vector.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        static_cast<DisplayableObject *>(self)->setAngle(static_cast<DisplayableObject *>(self)->getAngle() + ROTATE_SPEED);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        static_cast<DisplayableObject *>(self)->setAngle(static_cast<DisplayableObject *>(self)->getAngle() - ROTATE_SPEED);

    const float minX = 960.f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxX = 1920.f - PLAYER_SIZE_PIXEL / 4.f;
    const float minY = 0.0f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxY = 1080.0f - PLAYER_SIZE_PIXEL / 4.f;

    position.x = (position.x < minX) ? minX : (position.x > maxX) ? maxX : position.x;
    position.y = (position.y < minY) ? minY : (position.y > maxY) ? maxY : position.y;

    static_cast<DisplayableObject *>(self)->setPosition(position);
}

void whitePlayerAttack(GameObject *self)
{
    DisplayableObject * bullet = static_cast<DisplayableObject *>(self)->getObjects()[0];
    bullet->setActive(true);
    sf::Vector2f position = {self->getPosition().x, self->getPosition().y};
    sf::Vector2f origin = {3.0f, 8.0f};

    bullet->setPosition(position);
    bullet->setOrigin(origin);
    bullet->setAngle(static_cast<DisplayableObject *>(self)->getAngle());
    bullet->setSpeed(10.f);
}

void blackPlayerAttack(GameObject *self)
{
    DisplayableObject * bullet = static_cast<DisplayableObject *>(self)->getObjects()[0];
    bullet->setActive(true);
    sf::Vector2f position = {self->getPosition().x, self->getPosition().y};
    sf::Vector2f origin = {3.0f, 8.0f};

    bullet->setPosition(position);
    bullet->setOrigin(origin);
    bullet->setAngle(static_cast<DisplayableObject *>(self)->getAngle());
    bullet->setSpeed(10.f);
}

void blackBulletUpdate(GameObject *self)
{
    sf::Vector2f position = self->getPosition();
    sf::Vector2f vector = {0.0f, 0.0f};

    // Calculate the vector based on angle of black player
    vector.x = - sin(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);
    vector.y = cos(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);

    position.y -= self->getSpeed() * vector.y;
    position.x -= self->getSpeed() * vector.x;

    static_cast<DisplayableObject *>(self)->setPosition(position);

    const float minX = 0.f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxX = 1920.f - PLAYER_SIZE_PIXEL / 4.f;
    const float minY = 0.0f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxY = 1080.0f - PLAYER_SIZE_PIXEL / 4.f;

    if(position.x > minX && position.x < maxX && position.y > minY && position.y < maxY)
    {
      self->setActive(true); 
    }else{
        self->setActive(false);
    }
}

void whiteBulletUpdate(GameObject *self)
{
    sf::Vector2f position = self->getPosition();
    sf::Vector2f vector = {0.0f, 0.0f};

    // Calculate the vector based on angle of black player
    vector.x = - sin(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);
    vector.y = cos(static_cast<DisplayableObject *>(self)->getAngle() * 3.1415 / 180.0f);

    position.y -= self->getSpeed() * vector.y;
    position.x -= self->getSpeed() * vector.x;

    static_cast<DisplayableObject *>(self)->setPosition(position);

    const float minX = 0.f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxX = 1920.f - PLAYER_SIZE_PIXEL / 4.f;
    const float minY = 0.0f + PLAYER_SIZE_PIXEL / 4.f;
    const float maxY = 1080.0f - PLAYER_SIZE_PIXEL / 4.f;

    if(position.x > minX && position.x < maxX && position.y > minY && position.y < maxY)
    {
        self->setActive(true); 
    }
    else
    {
        self->setActive(false);
    }
}

void initEnnemies(App &app, DisplayableObject *blackPlayer, DisplayableObject *whitePlayer)
{
    float randX = 0.0f;
    float randY = 0.0f;

    // 10 levels of ennemies 10 + the level per level
    // Generate white ennemies (left of the screen)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 + i; j++)
        {
            randX = rand() % 960 - 960;
            randY = (randX < 0.0f) ? rand() % 50 - 75 : rand() % 50 + 1125.0f;
            DisplayableObject *ennemy = new DisplayableObject("img/whiteEnnemy.png");
            sf::Vector2f position = {randX, randY};
            sf::Vector2f origin = {50.0f, 50.0f};
            sf::Vector2f scale = {0.3f, 0.3f};

            ennemy->setPosition(position);
            ennemy->setOrigin(origin);
            ennemy->setScale(scale);
            ennemy->setAngle(0.0f);
            ennemy->addObject(whitePlayer);
            ennemy->setSpeed(0.11f);
            ennemy->setLayout(2);
            ennemy->setOnCollide(&ennemyCollide);
            ennemy->setTag("ew" + std::to_string(i + 1) + std::to_string(j));
            app.addCollisionPair("ew" + std::to_string(i + 1) + std::to_string(j), "whitePlayer");
            app.addCollisionPair("ew" + std::to_string(i + 1) + std::to_string(j), "blackbullet");
             app.addCollisionPair("ew" + std::to_string(i + 1) + std::to_string(j), "whitebullet");
            if (i > 0)
                ennemy->setActive(false);
            ennemy->setFunction(&ennemyMovement);
            app.addObjectTo(ennemy, GAME_SCENE);
        }
    }
    
    // Generate black ennemies (right of the screen)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 + i; j++)
        {
            randX = rand() % 960 + 960;
            randY = (randX > 1920.0f) ? rand() % 50 - 75 : rand() % 50 + 1125.0f;
            DisplayableObject *ennemy = new DisplayableObject("img/blackEnnemy.png");
            sf::Vector2f position = {randX, randY};
            sf::Vector2f origin = {50.0f, 50.0f};
            sf::Vector2f scale = {0.3f, 0.3f};

            ennemy->setPosition(position);
            ennemy->setOrigin(origin);
            ennemy->setScale(scale);
            ennemy->setAngle(0.0f);
            ennemy->addObject(blackPlayer);
            ennemy->setSpeed(0.11f);
            ennemy->setLayout(2);
            ennemy->setOnCollide(&ennemyCollide);
            ennemy->setTag("eb" + std::to_string(i + 1) + std::to_string(j));
            app.addCollisionPair("eb" + std::to_string(i + 1) + std::to_string(j), "blackPlayer");
            app.addCollisionPair("eb" + std::to_string(i + 1) + std::to_string(j), "blackbullet");
            app.addCollisionPair("eb" + std::to_string(i + 1) + std::to_string(j), "whitebullet");
            if (i > 0)
                ennemy->setActive(false);
            ennemy->setFunction(&ennemyMovement);
            app.addObjectTo(ennemy, GAME_SCENE);
        }
    }
}

void ennemyMovement(GameObject *self)
{
    sf::Vector2f targetPosition = static_cast<DisplayableObject *>(self)->getObjects()[0]->getPosition();
    sf::Vector2f position = self->getPosition();

    if (position.x > targetPosition.x)
        position.x -= self->getSpeed();
    else
        position.x += self->getSpeed();
    if (position.y > targetPosition.y)
        position.y -= self->getSpeed();
    else
        position.y += self->getSpeed();
    static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ennemyCollide(GameObject *self, GameObject *collided)
{
    self->setActive(false);
    collided->setActive(false);

    if(collided->getTag() == "whitePlayer")
    {
        // TODO : Lose life
    }
    else if(collided->getTag() == "blackPlayer")
    {
        // TODO : Lose life
    }
    else if(collided->getTag() == "whitebullet")
    {
        //TextObject * blackPlayerScore = static_cast<TextObject *>(collided)->getObjects()[0];
       // blackPlayerScore->setText(std::to_string(std::stoi(blackPlayerScore->getText()) + 1));
    }
    else if(collided->getTag() == "blackbullet")
    {
       // TextObject * whitePlayerScore = static_cast<TextObject *>(collided)->getObjects()[0];
       // whitePlayerScore->setText(std::to_string(std::stoi(whitePlayerScore->getText()) + 1));
    }
}