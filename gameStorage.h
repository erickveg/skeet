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
	Time getTime() { return time;}
	bool getBullseye() { return bullseye;}
	Gun getGun() { return gun;}
	void addBird(BirdStorage* newBird); //adds a bird onto the list of birds
	std::list<BirdStorage*> getBirds() { return birds;}//returns the list of birds
	void addBullet(BulletStorage* newBullet); //adds a bullet onto the list of bullets
	std::list<BulletStorage*> getBullets() { return bullets;} //returns the list of bullets
	void addEffect(EffectStorage* newEffect); //adds an effect onto the list of effects
	std::list<EffectStorage*> getEffects() { return effects;} //returns the list of effects
	void addPoints(Position pos, int pts); //adds points onto the points variable
	std::list<PointsStorage> getPoints() { return points;} //returns the list of points


private:
	std::list<GameInterface> views;
	std::list<MobileStorage*> elements;
	Gun gun;                       // the gun
	Time time;                     // how many frames have transpired since the beginning
	Score score;                   // the player's score
	HitRatio hitRatio;             // the hit ratio for the birds
	static Position dimensions;    // size of the screen
	bool bullseye;
	std::list<BirdStorage*> birds;        // all the shootable birds
	std::list<BulletStorage*> bullets;    // the bullets
	std::list<EffectStorage*> effects;    // the fragments of a dead bird.
	std::list<PointsStorage>  points;     // point values;

};



