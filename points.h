/***********************************************************************
 * Header File:
 *    Points : Points graphic drawn on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Inert point values on the screen.
 ************************************************************************/

#pragma once

#include "position.h"
#include "mobileStorage.h"
#include "mobileInterface.h"

 /*********************************************
  * POINTS STORAGE
  * Points graphic drawn on the screen
  *********************************************/
class PointsStorage: public MobileStorage
{
public:
   PointsStorage(const Position& pt, int value): MobileStorage() {};
   bool isDead() const {return age <= 0.0; }
   
   // needed b/c PointStorage has additional data
   ~PointsStorage() override {
	   MobileStorage::~MobileStorage();
   }
private:
   Position pt;
   Velocity v;
   int value;
   float age;
};

/*********************************************
 * POINTS INTERFACE
 * Points graphic drawn on the screen
 *********************************************/
class PointsInterface: public MobileInterface
{
public:
  PointsInterface(): MobileInterface() {};
  void draw(MobileStorage* points) override {};
  void update(int message) override {};

};
