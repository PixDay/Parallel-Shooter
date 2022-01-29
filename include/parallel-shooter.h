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

