#include "parallel-shooter.h"

void *Gapp;

int main()
{
    App app = App();
    Gapp = &app;
    // Create scenes
    CreateScenes(app);

    // Init menu
    InitMenu(app);

    // Init game
    InitGame(app);
    app.run();
    return 0;
}

void *myApp()
{
    return Gapp;
}
//cmake --build . -j8