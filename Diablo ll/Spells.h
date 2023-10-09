#pragma once
#include "Player.h"
#include "Stats.h"

class Spells
{
	Spells(int someInventory);

public:
	int UseSpell(Player& aPlayer, int aUsageTimes);
	int TimeLeftOnSpell(int someTime);
	bool IsActive ();

private:
	int myTime;

};

