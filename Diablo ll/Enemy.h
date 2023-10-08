#pragma once
#include "Stats.h"
#include <string> 
#include <iostream> 
#include "Items.h"

class Enemy
{
public:
	Enemy(int aHp, int aStrength, int aStealth, int someInventory);

	int AttackCrit();	//could be like stealth + strength * random number 
	int Block();		// could be randomized between strength and hp

	Stats& GetStats();

	void DroppItems ();
	std::string GetItemName();
	int GetItemWeight ();

private:
	Stats myStats;
	std::string myItemName;
	int myItemWeight;
};

