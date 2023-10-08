#include "Items.h"
#include <iostream>

Items::Items(int aHp, int aStregnth, int aStealth, int aMaxWeight, std::string anItemName) : myStats(aHp, aStregnth, aStealth, aMaxWeight), myMaxWeight(aMaxWeight)
{
}

Stats & Items::GetStats ()
{
	return myStats;
}

void Items::SetItemName (std::string someItem)
{
	this->myItemName = someItem;
}
#include "Tools.h"
#include "Stats.h"
std::string Items::GetItemName ()
{
	return myItemName;
}

int Items::GetWeight ()
{
	return myMaxWeight;
}
