#include "shooter.h"

int main(void)
{
    App app = App();
    GameObject *camera = app.getCamera();

    initPlayer(app, camera);
    app.run();
    return 0;
}