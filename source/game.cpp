#include "shooter.h"

void instantiateGame(App &app) {
    DisplayableObject *background       = new DisplayableObject("img/gameBackground.png");
    DisplayableObject *bottomDecoration = new DisplayableObject("img/bottomDecoration.png");
    DisplayableObject *QSpell           = new DisplayableObject("img/QSpell.png", QSpellFunction);
    DisplayableObject *WSpell           = new DisplayableObject("img/WSpell.png", WSpellFunction);
    DisplayableObject *ESpell           = new DisplayableObject("img/ESpell.png", ESpellFunction);
    DisplayableObject *RSpell           = new DisplayableObject("img/RSpell.png", RSpellFunction);
    DisplayableObject *DSpell           = new DisplayableObject("img/DSpell.png", DSpellFunction);
    DisplayableObject *FSpell           = new DisplayableObject("img/FSpell.png", FSpellFunction);

    app.addObjectTo(background, "game");
    app.addObjectTo(bottomDecoration, "game");
    app.addObjectTo(QSpell, "game");
    app.addObjectTo(WSpell, "game");
    app.addObjectTo(ESpell, "game");
    app.addObjectTo(RSpell, "game");
    app.addObjectTo(DSpell, "game");
    app.addObjectTo(FSpell, "game");
}

void instantiateGameOver(App &app) {
    DisplayableObject *background       = new DisplayableObject("img/gameOverBackground.png");
    DisplayableObject *menuButton       = new DisplayableObject("img/menuButton.png", menuButtonFunction);
    TextObject        *gameOverText     = new TextObject("GAME OVER");

    app.addObjectTo(background, "gameOver");
    app.addObjectTo(menuButton, "gameOver");
    app.addObjectTo(gameOverText, "gameOver");
}

void QSpellFunction(GameObject *self)
{
    (void)self;
}

void WSpellFunction(GameObject *self)
{
    (void)self;
}

void ESpellFunction(GameObject *self)
{
    (void)self;
}

void RSpellFunction(GameObject *self)
{
    (void)self;
}

void DSpellFunction(GameObject *self)
{
    (void)self;
}

void FSpellFunction(GameObject *self)
{
    (void)self;
}

void menuButtonFunction(GameObject *self)
{
    (void)self;
}