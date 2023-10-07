#include "Enemy.h"
#include "Stats.h"


Enemy::Enemy(int aHp, int aStrength, int aStealth) : myStats(aHp, aStrength, aStealth)
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
