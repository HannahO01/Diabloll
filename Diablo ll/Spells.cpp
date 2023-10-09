#include "Spells.h"

Spells::Spells (int someTime) : myTime (someTime)
{
}

int Spells::UseSpell (Player & aPlayer, int aUsageTimes)
{
    aUsageTimes = 2;
    int extraDamage = (aPlayer.GetStats().GetStrength() * 2);
    for(int i = 0; aUsageTimes > myTime; i++)
    {
        std::cout << "[SOME MAGIC STUFF damage: " << extraDamage << " ]" << std::endl;
        (extraDamage / 2);
    }
    return extraDamage;
}

int Spells::TimeLeftOnSpell (int someTime)
{
    someTime++;
    someTime = myTime;
    return myTime;
}

bool Spells::IsActive ()
{
    if(myTime < 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
