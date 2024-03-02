/***********************************************************************
 * Header File:
 *    GAME STORAGE
 * Author:
 *    Team 2
 * Summary:
 *    The container class that stores all our game data.
 ************************************************************************/
#pragma once

#include "gameInterface.h"
#include "position.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "gun.h"
#include "time.h"
#include "score.h"
#include "points.h"
#include "constants.h"
#include <list>

class GameStorage
{
public:
	GameStorage() : gun(Position(800.0, 0.0)), time(), score(), hitRatio(), bullseye(false) {}
	void initialize(GameInterface &gameViews);
	Time getTime() { return time; }
	bool getBullseye() { return bullseye;}
	Gun getGun() { return gun; }

private:
	std::list<GameInterface> views;
	std::list<MobileStorage*> elements;
	Gun gun;                       // the gun
	Time time;                     // how many frames have transpired since the beginning
	Score score;                   // the player's score
	HitRatio hitRatio;             // the hit ratio for the birds
	static Position dimensions;    // size of the screen
	bool bullseye;
	
};



