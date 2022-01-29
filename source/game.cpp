#include "parallel-shooter.h"

void InitGame(App &app)
{
    DisplayableObject *blackPlayer = new DisplayableObject("img/black-player.png");
    DisplayableObject *whitePlayer = new DisplayableObject("img/white-player.png");
    DisplayableObject *blackBackground = new DisplayableObject("img/black-background.png");
    DisplayableObject *whiteBackground = new DisplayableObject("img/white-background.png");

    initBlackPLayer(blackPlayer);
    initWhitePlayer(whitePlayer);
    initBlackBackground(blackBackground);
    initWhiteBackground(whiteBackground);

    app.addObjectTo(blackPlayer, GAME_SCENE);
    app.addObjectTo(whitePlayer, GAME_SCENE);
    app.addObjectTo(blackBackground, GAME_SCENE);
    app.addObjectTo(whiteBackground, GAME_SCENE);
}

void initBlackPLayer(DisplayableObject *blackPlayer)
{
    sf::Vector2f position = {0.0f, 0.0f};

    blackPlayer->setPosition(position);
}

void initWhitePLayer(DisplayableObject *whitePlayer)
{
    sf::Vector2f position = {960.0f, 0.0f};

    whitePlayer->setPosition(position);
}

void initBlackBackground(DisplayableObject *blackBackground)
{
    sf::Vector2f position = {430.0f, 490.0f};
    sf::Vector2f origin = {50.0f, 50.0f};

    blackBackground->setPosition(position);
    blackBackground->setOrigin(origin);
}


void initWhiteBackground(DisplayableObject *whiteBackground)
{
    sf::Vector2f position = {860.0f, 490.0f};
    sf::Vector2f origin = {50.0f, 50.0f};

    whiteBackground->setPosition(position);
    whiteBackground->setOrigin(origin);
}
