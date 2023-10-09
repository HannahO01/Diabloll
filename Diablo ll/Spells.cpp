#include "Spells.h"

Spells::Spells (int someTime) : myTime (someTime)
{
}

int Spells::UseSpell (Player & aPlayer, int aUsageTimes)
{
    aUsageTimes = myTime;
    int extraDamage = (aPlayer.GetStats ().GetStrength ()) * 2;
    std::cout << "[SOME MAGIC STUFF damage: " << extraDamage << " ]" << std::endl;
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
