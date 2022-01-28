#pragma once

#include <stdlib.h>
#include <time.h>
#include "core.h"

void initPlayer(App &app, GameObject *camera);
void playerController(GameObject *self);
void cameraController(GameObject *self);
