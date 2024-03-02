/***********************************************************************
 * Header File:
 *    GAME INTERFACE
 * Author:
 *    Team 2
 * Summary:
 *    The container class that deals with drawing objects
 *    and handling user input.
 ************************************************************************/
#pragma once

#include "uiInteract.h"
#include "gameLogic.h"
 
class GameInterface
{
 
public:
	GameInterface();
	void initialize(GameLogic &gameLogic);
   BirdInterface birdInterface;
   BulletInterface bulletInterface;
   EffectInterface effectInterface;
 
   void interact(const UserInput& ui);
   void const drawLevel();
   void const drawStatus();
 
private:
	GameLogic logic;
	
   void const drawBackground(double redBack, double greenBack, double blueBack);
   void const drawTimer(double percent, double redFore, double greenFore,
   double blueFore, double redBack, double greenBack, double blueBack);
};
