#include "Spells.h"

int Spells::UseSpell (Player & aPlayer, int aUsageTimes)
{
    aUsageTimes = 3;
    int extraDamage = (aPlayer.GetStats().GetStrength() * 2);
    for(int i = 0; aUsageTimes > i; i++)
    {
        (extraDamage / 2);
    }
    return extraDamage;
}

int Spells::TimeLeftOnSpell (int someTime)
{
    someTime += myTime;
    return myTime;
}

bool Spells::IsActive ()
{
    if(myTime < 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
