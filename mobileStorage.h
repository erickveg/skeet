/***********************************************************************
* Header File:
*    MOBILE STORAGE
* Author:
*    Team 2
* Summary:
*    Abstract base class for all elements that move onscreen,
*    which are birds, bullets, effects, and points
************************************************************************/
#pragma once

#include "observer.h"
#include "position.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "points.h"

class MobileStorage
{
protected:
	Position pt;
	Velocity v;
public:
	MobileStorage();
	void subscribe(Observer* observer);
	void unsubscribe(Observer* observer);
	virtual void notify(int message) = 0;
	Position getPosition() const { return pt; }
	Velocity getVelocity() const { return v;  }
	
};

/*********************************************
 * ELEMENT STORAGE
 * Holds all objects that represent Skeet game elements,
 * which are birds, bullets, and effects.
 * *********************************************/
class ElementStorage: public MobileStorage
{
protected:
	double radius;
	bool dead;
	int points;
public:
	ElementStorage(); // is an abstract class like MobileStorage
	double getRadius() const { return radius; }
	double getPoints() const { return points; }
	bool isDead() const { return dead; }
	void setPoints(int pts) { points = pts; }
};
