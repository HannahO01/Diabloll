#pragma once
#include "Stats.h"
#include <string> 
#include <iostream> 

class Enemy
{
public:
	Enemy(int aHp, int aStrength, int aStealth);
	int AttackCrit();	//could be like stealth + strength * random number 
	int Block();		// could be randomized between strength and hp
	Stats& GetStats();
private:
	Stats myStats;
};

