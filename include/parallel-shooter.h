#pragma once

#include "core.h"

/* FUNCTIONS */
void *myApp();

// Function : main.cpp

// Function : scene.cpp
void CreateScenes(App &app);

// Function : menu.cpp
void InitMenu(App &app);

// Function : game.cpp
void InitGame               (App &app);
void initBlackPlayer        (DisplayableObject *blackPlayer, DisplayableObject * blackBullet);
void initWhitePlayer        (DisplayableObject *whitePlayer);
void initBlackBackground    (DisplayableObject *blackBackground);
void initWhiteBackground    (DisplayableObject *whiteBackground);
void initEnnemies           (App &app, DisplayableObject *blackPlayer, DisplayableObject *whitePlayer);
void ennemyMovement         (GameObject *self);
void blackPlayerUpdate    (GameObject *self);
void whitePlayerUpdate    (GameObject *self);
void whitePlayerMovement    (GameObject *self);
void blackPlayerMovement    (GameObject *self);
void whitePlayerAttack      (GameObject *self);
void blackPlayerAttack      (GameObject *self);
void blackBulletUpdate      (GameObject *self);
void ennemyCollide          (GameObject *self, GameObject *collided);

// Different scenes and their names
#define MENU_SCENE ("menu")
#define GAME_SCENE ("game")
#define OPTIONS_SCENE ("options")
#define CREDITS_SCENE ("credits")
#define END_SCENE ("gameEnd")

#define _SPEED (5.f)

//Sprite
#define PLAYER_SIZE_PIXEL (100.f)

//Gameplay
#define ROTATE_SPEED (5.f)