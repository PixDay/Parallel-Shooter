#include "parallel-shooter.h"


static void playButtonComportment(GameObject *self)
{

}

static void creditsButtonComportment(GameObject *self)
{

}

static void exitButtonComportment(GameObject *self)
{

}

void InitMenu(App &app)
{
    DisplayableObject *playButton = new DisplayableObject("img/playButton.png", &playButtonComportment);
    DisplayableObject *creditsButton = new DisplayableObject("img/creditsButton.png", &creditsButtonComportment);
    DisplayableObject *exitButton = new DisplayableObject("img/exitButton.png", &exitButtonComportment);

    sf::Vector2f playButtonPosition = {100.0f, 100.0f};
    sf::Vector2f creditsButtonPosition = {500.0f, 500.0f};
    sf::Vector2f exitButtonPosition= {600.0f, 600.0f};

    playButton->setPosition(playButtonPosition);
    creditsButton->setPosition(creditsButtonPosition);
    exitButton->setPosition(exitButtonPosition);
}