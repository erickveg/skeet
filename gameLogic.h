/***********************************************************************
* Header File:
*    GAME LOGIC
* Author:
*    Team 2
* Summary:
*    Contains instructions for the game logic
************************************************************************/
#pragma once

#include "position.h"
#include "mobileStorage.h"
#include "constants.h"
#include <map>

// forward declare to avoid circular dependencies
class GameInterface;
class GameStorage;
 
class GameLogic
{
public:
	GameLogic();
	void initialize(GameStorage &gameStorage, GameInterface &gameInterface);
	void animate();
	void advanceAll();
	bool isOutOfBounds(MobileStorage* element);
	bool detectColiisions();

	std::map <BirdType, BirdLogic*> birdLogics;
	std::map <EffectType, EffectLogic*> effectLogic;
	std::map <BulletType, BulletLogic*> bulletLogic;
 
private:
	double minimumDistance(Position pt1, Velocity v1, Position pt2, Velocity v2);
	int randow(int min, int max);
	double random(double min, double max);
};
