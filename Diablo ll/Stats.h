#pragma once
#include <iostream>

class Stats
{
public:
	Stats(int aHp, int aStrength, int aStealth);
	int GetHp();
	void SetHP(int someHp);
	int GetStealth();
	int GetStrength();
	void PrintStats();
	void TakeDamage(int someDamage);

private:
	int myHp;
	int myStrength;
	int myStealth;
};

