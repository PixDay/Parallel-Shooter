#pragma once

#include "core.h"

/* FUNCTIONS */

// Function : main.cpp

// Function : scene.cpp
void CreateScenes(App &app);

// Function : menu.cpp
void InitMenu(App &app);

// Function : game.cpp
void InitGame               (App &app);
void initBlackPlayer        (DisplayableObject *blackPlayer);
void initWhitePlayer        (DisplayableObject *whitePlayer);
void initBlackBackground    (DisplayableObject *blackBackground);
void initWhiteBackground    (DisplayableObject *whiteBackground);
void blackPlayerMovement    (GameObject *self);
void initEnnemies           (App &app, DisplayableObject *blackPlayer, DisplayableObject *whitePlayer);
void ennemyMovement         (GameObject *self);
void whitePlayerMovement    (GameObject *self);

// Different scenes and their names
#define MENU_SCENE          ("menu")
#define GAME_SCENE          ("game")
#define OPTIONS_SCENE       ("options")
#define CREDITS_SCENE       ("credits")
#define END_SCENE           ("gameEnd")

// Player specific defines
#define ROTATE_SPEED        (5.f)

// Menu Button sizes
#define MENU_BUTTON_SIZE_X  (220)
#define MENU_BUTTON_SIZE_Y  (120)
