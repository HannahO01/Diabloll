#pragma once
#include "Player.h"
#include "Stats.h"

class Spells
{
	Spells(int aHp, int aStrength, int aStealth);

public:
	int UseSpell(Player& aPlayer, int aUsageTimes);
	int TimeLeftOnSpell(int someTime);
	bool IsActive ();

private:
	int myHp;
	int myStrength;
	int myStealth;
	int const myTime;

};

