#pragma once
#include <iostream>
#include "Stats.h"
#include <string>
class Player
{
public:
	Player(int aHp, int aStrength, int aStealth, std::string aPlayerName, int& aWinningPoint);
	int AttackCrit();	//could be like stealth + strength * random number 
	int Block();		// could be randomized between strength and hp. wokring on this.
	int Hunger();		// kill enemy on one hit but lose 50% of health 
	int PickingLock(); // strength & stealth. working on this 

	void SetCurrentRoom(int aRoomIndex);
	int GetCurrentRoom();

	static bool ControllName(std::string& aPlayerName);
	static bool ControllNamewNumbers(std::string& aPlayerName);
	const std::string& GetName() const;
	Stats& GetStats();
	void TakeDamage(int someDamage);
	const int& GetWinningPoint() const;
	void IncrementWinningPoint();


private:
	const std::string myPlayerName;
	Stats myStats;
	int myCurrentRoom;
	int myWinningPoint;
};

