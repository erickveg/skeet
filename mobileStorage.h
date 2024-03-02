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
public:
	MobileStorage();
	void subscribe(Observer* observer);
	void unsubscribe(Observer* observer);
	virtual void notify(int message) = 0;
	virtual ~MobileStorage();
};
