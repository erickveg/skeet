/***********************************************************************
 * Header File:
 *    Fragment : Pieces that fly off a dead bird
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Pieces that fly off a dead bird
 ************************************************************************/

#pragma once
#include "position.h"
#include "mobileStorage.h"
#include "mobileInterface.h"

/**********************
 * Effect: stuff that is not interactive
 **********************/
class EffectStorage : public MobileStorage
{
protected:
    Position pt;      // location of the effect
    double age;    // 1.0 = new, 0.0 = dead
public:
    // create a fragment based on the velocity and position of the bullet
    EffectStorage(const Position & pt) : MobileStorage(), pt(pt), age(0.5) {}
    
    // it is dead when age goes to 0.0
    bool isDead() const { return age <= 0.0; }
	
	// needed b/c EffectStorage has additional data
	~EffectStorage() override {
		MobileStorage::~MobileStorage();
	}
};

/*********************************************
 * EFFECT INTERFACE
 * The base class for drawing effects.
 *********************************************/
class EffectInterface : public MobileInterface
{
public:
	EffectInterface() : MobileInterface() {}
	void draw(MobileStorage* effect) override {};
	void update(int message) override {};
};

/*********************************************
 * FRAGMENT INTERFACE
 * Draws Fragment effects.
 *********************************************/
class FragmentInterface : public EffectInterface
{
public:
	FragmentInterface() : EffectInterface() {}
	void draw(MobileStorage* effect) override {};
	void update(int message) override {};
};
 
/*********************************************
 * STREEK INTERFACE
 * Draws Streek effects.
 *********************************************/
class StreekInterface : public EffectInterface
{
public:
	StreekInterface() : EffectInterface() {}
	void draw(MobileStorage* effect) override {};
	void update(int message) override {};
};
 
/*********************************************
 * EXHAUST INTERFACE
 * Draws Exhaust effects.
 *********************************************/
class ExhaustInterface : public EffectInterface
{
public:
	ExhaustInterface() : EffectInterface() {}
	void draw(MobileStorage* effect) override {};
	void update(int message) override {};
};

/*********************************************
 * EFFECT LOGIC
 * Handles all effect-related algorithms.
 *********************************************/

/*********************************************
 * FRAGMENT LOGIC
 * Moves Fragments
 * *********************************************/

/*********************************************
 * STREEK LOGIC
 * Moves Streeks
 *********************************************/

/*********************************************
 * EXHAUST LOGIC
 * Moves Exhaust
 *********************************************/


/**********************
 * FRAGMENT
 * Pieces that fly off a dead bird
 **********************/
/*class Fragment : public Effect
{
private:
   Velocity v;    // direction the fragment is flying
   double size;   // size of the fragment
public:
	// create a fragment based on the velocity and position of the bullet
	Fragment(const Position & pt, const Velocity & v);
	
	// draw it
	void render() const;
	
	// move it forward with regards to inertia. Let it age
	void fly();
};*/

/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
/*class Streek : public Effect
{
private:
   Position ptEnd;
public:
	// create a fragment based on the velocity and position of the bullet
	Streek(const Position & pt, Velocity v);
	
	// draw it
	void render() const;
	
	// move it forward with regards to inertia. Let it age
	void fly();
};*/

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
/*class Exhaust : public Effect
{
private:
   Position ptEnd;
public:
	// create a fragment based on the velocity and position of the bullet
	Exhaust(const Position & pt, Velocity v);
	
	// draw it
	void render() const;
	
	// move it forward with regards to inertia. Let it age
	void fly();
};*/

