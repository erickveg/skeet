/***********************************************************************
 * Header File:
 *    Bullet
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that kills other things
 ************************************************************************/

#pragma once
#include "position.h"
#include "effect.h"
#include "mobileStorage.h"
#include "mobileInterface.h"
#include <list>
#include <cassert>

/*********************************************
 * BULLET STORAGE
 * Something to shoot something else
 *********************************************/
class BulletStorage : public MobileStorage
{
protected:
   Position pt;                  // position of the bullet
   Velocity v;                // velocity of the bullet
   double radius;             // the size (radius) of the bullet
   bool dead;                 // is this bullet dead?
   int value;                 // how many points does this cost?
    
public:
   BulletStorage() : MobileStorage(), dead(false), value(0), radius(1.0) { }
   
   // setters
   void kill()                   { dead = true; }
   void setValue(int newValue)   { value = newValue; }
   
   // getters
   bool isDead()           const { return dead;   }
   Position getPosition()  const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getValue()          const { return value;  }

   // still unsure about this method...I think it belongs in Storage,
   // but it would need to be overridden, and there are no child classes
   virtual void death(std::list<Bullet *> & bullets) {}

   // needed b/c BulletStorage has additional data
   ~BulletStorage() override {
	MobileStorage::~MobileStorage();
   }

};
/*********************************************
 * BULLET INTERFACE
 * The base class for drawing bullets and handling
 * user input.
 *********************************************/
class BulletInterface: public MobileInterface
{
public:
	BulletInterface(): MobileInterface() {};
	void input(bool isUp, bool isDown, bool isB) {};
	void draw(MobileStorage* bullet) override {};
	void update(int message) override {};
	
protected:
	void const drawLine(Position begin, Position end, double red,
		double green, double blue) {};
	void drawDot(Position point, double radius) {};
};
 
/*********************************************
 * MISSILE INTERFACE
 * Draws Missile bullets and handles user input.
 *********************************************/
class MissileInterface : public BulletInterface
{
public:
	void draw(MobileStorage* bullet) override {};
	void update(int message) override {};
	void input(bool isUp, bool isDown, bool isB) {};
};

/*********************************************
 * SHRAPNEL INTERFACE
 * Draws Shrapnel Bullets
 *********************************************/
class ShrapnelInterface : public BulletInterface
{
public:
	void draw(MobileStorage* bullet) override {};
	void update(int message) override {};
};
 
/*********************************************
 * PELLET INTERFACE
 * Draws Pellet bullets.
 *********************************************/
class PelletInterface : public BulletInterface
{
public:
	void draw(MobileStorage* bullet) override {};
	void update(int message) override {};
};
 
/*********************************************
 * BOMB INTERFACE
 * Draws Bomb bullets.
 *********************************************/
class BombInterface : public BulletInterface
{
public:
	void draw(MobileStorage* bullet) override {};
	void update(int message) override {};
};
 
/*********************************************
 * BULLET LOGIC
 * Handles all bullet-related algorithms.
 *********************************************/

/*********************************************
 * MISSILE LOGIC
 * Moves Missiles
 * *********************************************/

/*********************************************
 * SHRAPNEL LOGIC
 * Moves Shrapnel
 *********************************************/

/*********************************************
 * PELLET LOGIC
 * Moves Pellets
 *********************************************/

/*********************************************
 * BOMB LOGIC
 * Moves Bombs
 *********************************************/

/*********************
 * PELLET
 * Small little bullet
 **********************/
/*class Pellet : public Bullet
{
public:
   Pellet(double angle, double speed = 15.0) : Bullet(angle, speed, 1.0, 1) {}
   
   void output();
};*/

/*********************
 * BOMB
 * Things that go "boom"
 **********************/
/*class Bomb : public Bullet
{
private:
   int timeToDie;
public:
   Bomb(double angle, double speed = 10.0) : Bullet(angle, speed, 4.0, 4), timeToDie(60) {}
   
   void output();
   void move(std::list<Effect*> & effects);
   void death(std::list<Bullet *> & bullets);
};*/

/*********************
 * Shrapnel
 * A piece that broke off of a bomb
 **********************/
/*class Shrapnel : public Bullet
{
private:
   int timeToDie;
public:
   Shrapnel(const Bomb & bomb)
   {
      // how long will this one live?
      timeToDie = random(5, 15);
      
      // The speed and direction is random
      v.set(random(0.0, 6.2), random(10.0, 15.0));
      pt = bomb.getPosition();

      value = 0;
      
      radius = 3.0;
   }
   
   void output();  
   void move(std::list<Effect*> & effects);
};*/


/*********************
 * MISSILE
 * Guided missiles
 **********************/
/*class Missile : public Bullet
{
public:
   Missile(double angle, double speed = 10.0) : Bullet(angle, speed, 1.0, 3) {}
   
   void output();
   void input(bool isUp, bool isDown, bool isB)
   {
      if (isUp)
         v.turn(0.04);
      if (isDown)
         v.turn(-0.04);
   }
   void move(std::list<Effect*> & effects);
};*/
 
