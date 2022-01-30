#include "parallel-shooter.h"
#include <unistd.h>

// X = 220, Y = 120

static void playButtonComportment(GameObject *self)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    if (mousePosition.x >= 820 && mousePosition.x <= 1040)
        if (mousePosition.y >= 350 && mousePosition.y <= 470)
            static_cast<DisplayableObject *>(self)->setTexture("img/playButtonHover.png");
    else        
        static_cast<DisplayableObject *>(self)->setTexture("img/playButton.png");
}

static void creditsButtonComportment(GameObject *self)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    if (mousePosition.x >= 820 && mousePosition.x <= 1040)
        if (mousePosition.y >= 475 && mousePosition.y <= 595)
            static_cast<DisplayableObject *>(self)->setTexture("img/creditsButtonHover.png");
    else
        static_cast<DisplayableObject *>(self)->setTexture("img/creditsButton.png");
}

static void exitButtonComportment(GameObject *self)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    if (mousePosition.x >= 820 && mousePosition.x <= 1040)
        if (mousePosition.y >= 600 && mousePosition.y <= 720)
            static_cast<DisplayableObject *>(self)->setTexture("img/exitButtonHover.png");
    else
        static_cast<DisplayableObject *>(self)->setTexture("img/exitButton.png");

}

void InitMenu(App &app)
{
    DisplayableObject *playButton = new DisplayableObject("img/playButton.png", &playButtonComportment);
    DisplayableObject *creditsButton = new DisplayableObject("img/creditsButton.png", &creditsButtonComportment);
    DisplayableObject *exitButton = new DisplayableObject("img/exitButton.png", &exitButtonComportment);

    sf::Vector2f playButtonPosition = {820.0f, 350.0f};
    sf::Vector2f creditsButtonPosition = {820.0f, 475.0f};
    sf::Vector2f exitButtonPosition= {820.0f, 600.0f};

    playButton->setPosition(playButtonPosition);
    creditsButton->setPosition(creditsButtonPosition);
    exitButton->setPosition(exitButtonPosition);

    app.addObject(playButton);
    app.addObject(creditsButton);
    app.addObject(exitButton);
}