#include "dodger.h"
#include <iostream>
int main(void)
{
    App app = App();
    DisplayableObject *player = new DisplayableObject("img/green.png");
    bool state = true;

    srand((unsigned int)time(NULL));
    app.addScene("Game");
    app.setCurrentScene("Game");
    while (state) {
        playerSetting(app, player);
        gameTimer(app);
        createEnnemies(app);
        createCollisionList(app);
        state = app.run();
        app.getSceneManager().clearSceneContent("Game");
        player = new DisplayableObject("img/green.png");
    }
    app.getSceneManager().clearSceneContent("Game");
}