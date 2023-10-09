#pragma once
#include "Items.h"
#include "Spells.h"
#include "Tools.h"
#include "Player.h"

class Chest
{
public:
	Chest ();
	void OpenChest (Player & aPlayer, std::vector<Items> & aVectorItem, std::string & aitemName);
	void AddItems (Items anItem);


private:
	std::string myItemName;
	std::vector<Items> myVectorItem;
};

