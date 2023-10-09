#pragma once
#include "Player.h"
#include "Stats.h"

class Spells
{
	Spells(int aHp, int aStrength, int aStealth, int someInventory);

public:
	int UseSpell(Player& aPlayer, int aUsageTimes);
	int TimeLeftOnSpell(int someTime);
	bool IsActive ();

private:
	int myHp;
	int myStrength;
	int myStealth;
	int myInventory;
	int const myTime;

};

