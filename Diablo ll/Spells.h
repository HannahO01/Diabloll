#pragma once
#include "Player.h"
#include "Stats.h"

class Spells
{
public:

	Spells (int someInventory);
	int UseSpell(Player& aPlayer, int aUsageTimes);
	int TimeLeftOnSpell(int someTime);
	bool IsActive ();

private:
	int myTime;

};

