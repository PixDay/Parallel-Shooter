#include "shooter.h"

int main()
{
    App app = App();
    TextObject *HelloWorld = new TextObject("Hello World");
    GameObject *camera = app.getCamera();

    app.addObject(HelloWorld);
    app.addObject(camera);
    app.run();
    return 0;
}