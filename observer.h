/***********************************************************************
* Header File:
*    OBSERVER
* Author:
*    Team 2
* Summary:
*    Base class for all elements that are also observers.
************************************************************************/
#pragma once

class Observer
{
public:
	Observer();
	virtual void update(int message) = 0;
};
