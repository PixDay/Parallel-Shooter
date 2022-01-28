#pragma once

#include "core.h"

/* FUNCTIONS */

// Function : main.cpp
void initScenes             (App &app);
void initPlayer             (App &app);
void initEnemy              (App &app);
void initOptions            (App &app);
void initMenu               (App &app);

// Function : initScene.cpp
void createScenes           (App &app);

// Function : menu.cpp
void instantiateMenu        (App &app);
void playButtonFunction     (GameObject *self);
void optionsButtonFunction  (GameObject *self);
void exitButtonFunction     (GameObject *self);

// Function : game.cpp
void instantiateGame        (GameObject *self);
void instantiateGameOver    (GameObject *self);
void QSpellFunction         (GameObject *self);
void WSpellFunction         (GameObject *self);
void ESpellFunction         (GameObject *self);
void RSpellFunction         (GameObject *self);
void DSpellFunction         (GameObject *self);
void FSpellFunction         (GameObject *self);
void menuButtonFunction     (GameObject *self);

// Function : options.cpp
void instantiateOptions     (App &app);
