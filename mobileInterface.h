/***********************************************************************
* Header File:
*    MOBILE INTERFACE
* Author:
*    Team 2
* Summary:
*    Abstract base class for all elements that move onscreen,
*    which are birds, bullets, effects, and points. Provides
*    virtual draw and interact methods.
************************************************************************/
#pragma once

#include "mobileStorage.h"

class MobileInterface
{
public:
	MobileInterface();
	virtual void draw(MobileStorage* element)= 0;
	virtual void update(int message) = 0;
	virtual ~MobileInterface();
};
