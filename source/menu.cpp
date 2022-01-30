#include "parallel-shooter.h"

// X = 220, Y = 120

static void playButtonComportment(GameObject *self)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    if (mousePosition.x >= 820 && mousePosition.x <= 1040 && mousePosition.y >= 350 && mousePosition.y <= 470) {
        static_cast<DisplayableObject *>(self)->setTexture("img/playButtonHover.png");
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            static_cast<App *>(myApp())->setCurrentScene(GAME_SCENE);
    }
    else        
        static_cast<DisplayableObject *>(self)->setTexture("img/playButton.png");
}

static void creditsButtonComportment(GameObject *self)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    if (mousePosition.x >= 820 && mousePosition.x <= 1040 && mousePosition.y >= 475 && mousePosition.y <= 595)
    {
        static_cast<DisplayableObject *>(self)->setTexture("img/creditsButtonHover.png");
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            static_cast<App *>(myApp())->setCurrentScene(CREDITS_SCENE);
    }
    else
        static_cast<DisplayableObject *>(self)->setTexture("img/creditsButton.png");
}

static void exitButtonComportment(GameObject *self)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    if (mousePosition.x >= 820 && mousePosition.x <= 1040 && mousePosition.y >= 600 && mousePosition.y <= 720)
    {
        static_cast<DisplayableObject *>(self)->setTexture("img/exitButtonHover.png");
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            self->setTag(STOP_RUN);
    }
    else
        static_cast<DisplayableObject *>(self)->setTexture("img/exitButton.png");

}

void leaveCredits(GameObject *self)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        static_cast<App *>(myApp())->setCurrentScene(MENU_SCENE);
}

void InitMenu(App &app)
{
    DisplayableObject *playButton = new DisplayableObject("img/playButton.png", &playButtonComportment);
    DisplayableObject *creditsButton = new DisplayableObject("img/creditsButton.png", &creditsButtonComportment);
    DisplayableObject *exitButton = new DisplayableObject("img/exitButton.png", &exitButtonComportment);

    TextObject *dev = new TextObject("Developpeurs :");
    TextObject *mihailo = new TextObject("Mihailo Pavlovic");
    TextObject *yoan = new TextObject("Yoan Rock");
    TextObject *adrien = new TextObject("Adrien Colombier");

    sf::Vector2f playButtonPosition = {820.0f, 350.0f};
    sf::Vector2f creditsButtonPosition = {820.0f, 475.0f};
    sf::Vector2f exitButtonPosition= {820.0f, 600.0f};

    playButton->setPosition(playButtonPosition);
    creditsButton->setPosition(creditsButtonPosition);
    exitButton->setPosition(exitButtonPosition);

    dev->setPosition({800.0f, 200.0f});
    mihailo->setPosition({800.0f, 300.0f});
    yoan->setPosition({800.0f, 400.0f});
    adrien->setPosition({800.0f, 500.0f});

    dev->setSize(50);
    mihailo->setSize(50);
    yoan->setSize(50);
    adrien->setSize(50);
    adrien->setFunction(&leaveCredits);

    app.addObject(playButton);
    app.addObject(creditsButton);
    app.addObject(exitButton);

    app.addObjectTo(dev, CREDITS_SCENE);
    app.addObjectTo(mihailo, CREDITS_SCENE);
    app.addObjectTo(yoan, CREDITS_SCENE);
    app.addObjectTo(adrien, CREDITS_SCENE);
}