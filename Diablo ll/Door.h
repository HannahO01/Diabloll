#pragma once
#include <vector>
#include "Player.h"

class Door
{
	//keeps track of how many rooms there are
	//track what room you've been in
	//magical door that can come in between room 1-2
	// locked or unloocked - if locked then you can do stuff to open it

public:
	Door(const int aRoomIndex1, const int aRoomIndex2, const bool aLoockedDoor, const std::string aColor);
	int GetRoom1() const;
	int GetRoom2() const;
	int EnterDoor(Player& aPlayer);
	void SetLockedDoor(bool& aDoor);
	const bool GetLockedDoor() const;
	const std::string GetCollour(Player aPlayer);
private:
	const int myRoomIndex1;
	const int myRoomIndex2;

	const std::string mycollour;

	bool myLoockedDoor;
};