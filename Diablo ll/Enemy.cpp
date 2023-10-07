#include "Enemy.h"
#include "Stats.h"


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
