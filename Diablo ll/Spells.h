#pragma once
class Spells
{
	Spells(int aHp, int aStrength, int aStealth);

public:
	void UseSpell();
	int TimeLeftOnSpell();

private:
	int myHp;
	int myStrength;
	int myStealth;

};

