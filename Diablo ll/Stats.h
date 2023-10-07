#pragma once
#include <iostream>

class Stats
{
public:
	Stats (int aHp, int aStrength, int aStealth, int someInventory);
	int GetHp ();
	void SetHP (int someHp);
	void SetStrength (int someStrength);
	void SetStealth (int someStealth);
	int GetStealth ();
	int GetStrength ();
	void PrintStats ();
	void TakeDamage (int someDamage);

private:
	int myHp;
	int myStrength;
	int myStealth;
	int myInventory;
};

