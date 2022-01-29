#include "parallel-shooter.h"

void CreateScenes(App &app)
{
    app.addScene(MENU_SCENE);
    app.addScene(GAME_SCENE);
    app.addScene(OPTIONS_SCENE);
    app.addScene(CREDITS_SCENE);
    app.addScene(END_SCENE);
}