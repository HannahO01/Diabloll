#pragma once
#include "Player.h"
#include "Stats.h"

class Spells
{
	Spells(int aHp, int aStrength, int aStealth);

public:
	int UseSpell(Player& aPlayer, int usageTimes);
	int TimeLeftOnSpell();

private:
	int myHp;
	int myStrength;
	int myStealth;

};

