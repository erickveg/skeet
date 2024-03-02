/***********************************************************************
* Header File:
*    CONSTANTS
* Author:
*    Team 2
* Summary:
*    Contains all constants found in the Skeet game.
************************************************************************/
#pragma once

// viewport dimensions
#define WIDTH  800.0
#define HEIGHT 800.0

enum BirdType {
	STANDARD,
	FLOATER,
	SINKER,
	CRAZY
};

enum BulletType {
	PELLET,
	BOMB,
	SHRAPNEL,
	MISSILE
};

enum EffectType {
	FRAGMENT,
	STREEK,
	EXHAUST
};
