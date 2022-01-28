#pragma once

#include <stdlib.h>
#include <time.h>
#include "core.h"

void playerSetting(App &app, DisplayableObject *player);
void playerController(GameObject *self);
void playerCollision(GameObject *self, GameObject *collided);

void gameTimer(App &app);
void updateTimer(GameObject *self);

void ennemyMovement(GameObject *self);
void createEnnemies(App &app);

void createCollisionList(App &app);
