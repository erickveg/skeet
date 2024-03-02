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
#include "gameStorage.h"
 
class GameInterface
{
 
public:
	GameInterface();
	void initialize(GameLogic &gameLogic);
    std::map <BirdType, BirdInterface*> birdInterfaces;
    std::map <EffectType, EffectInterface*> effectInterfaces;
    std::map <BulletType, BulletInterface*> bulletInterfaces;
    GunInterface gunInterface;
 
    void interact(const UserInput& ui);
    void drawLevel() const;
    void drawStatus() const;
 
private:
	GameLogic &logic;
    GameStorage &storage;
	
    void drawBackground(double redBack, double greenBack, double blueBack) const;
    void drawTimer(
        double percent,
        double redFore,
        double greenFore,
        double blueFore,
        double redBack,
        double greenBack,
        double blueBack) const;
    void drawBullseye(double angle) const;
};
