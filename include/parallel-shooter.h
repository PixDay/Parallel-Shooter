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
void initBlackPLayer        (DisplayableObject *blackPlayer);
void initWhitePLayer        (DisplayableObject *whitePlayer);
void initBlackBackground    (DisplayableObject *blackBackground);
void initWhiteBackground    (DisplayableObject *whiteBackground);

void InitGame(App &app);

// Different scenes and their names
#define MENU_SCENE ("menu")
#define GAME_SCENE ("game")
#define OPTIONS_SCENE ("options")
#define CREDITS_SCENE ("credits")
#define END_SCENE ("gameEnd")
