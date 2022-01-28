#include "shooter.h"

void initScenes(App &app)
{
    createScenes(app);
    instantiateMenu(app);
    instantiateGame(app);
    instantiateOptions(app);
    instantiateGameOver(app);
    app.setCurrentScene("menu");
}

void createScenes(App &app)
{
    app.addScene("menu");
    app.addScene("game");
    app.addScene("options");
    app.addScene("gameOver");
}
