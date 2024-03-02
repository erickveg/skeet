/***********************************************************************
 * Header File:
 *    BirdStorage : Everything that can be shot
 * Author:
 *    Team 2
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once
#include "position.h"
#include "mobileStorage.h"
#include "mobileInterface.h"

/**********************
 * BIRD STORAGE
 * Everything that can be shot
 **********************/
class BirdStorage : public MobileStorage
{
private:
   Position pt;               // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   
public:
	BirdStorage() : MobileStorage(), dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Position    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }
   void setPoints(int pts)              { points = pts;}

   // getters
   bool isDead()           const { return dead;   }
   Position getPosition()  const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
	
	// needed b/c BirdStorage has additional data
	~BirdStorage() override {
		MobileStorage::~MobileStorage();
	}

};

/*********************************************
 * BIRD INTERFACE
 * The base class for drawing birds.
 *********************************************/
class BirdInterface: public MobileInterface
{
public:
	BirdInterface() : MobileInterface() {}
	void draw(MobileStorage* bird) override {};
	void update(int message) override {};
};
 
/*********************************************
 * STANDARD INTERFACE
 * Draws Standard birds.
 *********************************************/
class StandardInterface : public BirdInterface
{
public:
	StandardInterface() : BirdInterface() {}
	void draw(MobileStorage* bird) override {};
	void update(int message) override {};
};

 /*********************************************
 * FLOATER INTERFACE
 * Draws Floater birds.
 *********************************************/
class FloaterInterface : public BirdInterface
{
public:
	FloaterInterface() : BirdInterface() {}
	void draw(MobileStorage* bird) override {};
	void update(int message) override {};
};
 
/*********************************************
 * CRAZY INTERFACE
 * Draws Crazy birds.
 *********************************************/
class CrazyInterface : public BirdInterface
{
public:
	CrazyInterface() : BirdInterface() {}
	void draw(MobileStorage* bird) override {};
	void update(int message) override {};
};
 
/*********************************************
 * SINKER INTERFACE
 * Draws Sinker birds.
 *********************************************/
class SinkerInterface : public BirdInterface
{
public:
	SinkerInterface() : BirdInterface() {}
	void draw(MobileStorage* bird) override {};
	void update(int message) override {};
};

/*********************************************
 * BIRD LOGIC
 * Handles all bird-related algorithms.
 *********************************************/

/*********************************************
 * STANDARD LOGIC
 * Moves Standard birds.
 *********************************************/

/*********************************************
 * SINKER LOGIC
 * Moves Sinker birds.
 *********************************************/

/*********************************************
 * CRAZY LOGIC
 * Moves Crazy birds.
 *********************************************/

/*********************************************
 * FLOATER LOGIC
 * Moves Floater birds.
 *********************************************/

