#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Door.h"
#include "Items.h"
#include "Chest.h"
#include "Spells.h"

class Room
{
	//generate 0-4 enemies in a room
	//need to have max 3 door and 1 door needs to go back to the old room

public:
	Room(bool aHasEnemies, std::string aRoomName, bool someItems);
	void AddEnemies(Enemy aEnemy);
	void AddDoor(Door* aDoor);
	void AddItems(Items anItem);
	void AddChest (Chest aChest);

	bool Fighting(bool& allowedToLeave, Player& aPlayer);
	int EnterRoom(Player& aPlayer, int& whatRoom);
	const std::string GetRoomName() const;
	void SetRoomName(const std::string aNameIndex);

	enum Choise { items = 1, fight = 2, rooms = 3, leave = 4 };
	enum Abilities { Attack = 1, Block = 2, Hunger = 3 };

private:
	std::vector<Enemy> myEnemies;
	std::vector<Door*> myDoors;
	std::string myRoomName;
	std::vector<Items> myItems;
	int myChestItem;
	std::vector<Spells> mySpells;
	std::string myItemName;
	std::vector<Chest> myChest;
};