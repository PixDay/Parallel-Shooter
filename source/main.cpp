#include "parallel-shooter.h"

int main()
{
    App app = App();
    
    // Create scenes
    CreateScenes(app);

    // Init menu
    InitMenu(app);

    // Init game
    InitGame(app);
    app.setCurrentScene(GAME_SCENE);
    app.run();
    return 0;
}

//cmake --build . -j8