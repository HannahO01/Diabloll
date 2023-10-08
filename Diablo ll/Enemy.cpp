#include "Enemy.h"
#include "Stats.h"
#include "Items.h"

Enemy::Enemy(int aHp, int aStrength, int aStealth, int someInventory) : myStats(aHp, aStrength, aStealth, someInventory)
{
}

int Enemy::AttackCrit()
{
    return myStats.GetStrength() + myStats.GetStealth();
}

int Enemy::Block()
{
    return myStats.GetHp() + myStats.GetStrength();
}

Stats& Enemy::GetStats()
{
    return myStats;
}

void Enemy::DroppItems ()
{
    Items droppedFoot (1,1,1,1, "foot");
    myItemName = "foot";
    myItemWeight = 1;
}

std::string Enemy::GetItemName ()
{
    return myItemName;
}

int Enemy::GetItemWeight ()
{
    return myItemWeight;
}
