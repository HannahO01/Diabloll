#include "Spells.h"

int Spells::UseSpell (Player & aPlayer, int usageTimes)
{
    usageTimes = 3;
    int extraDamage = (aPlayer.GetStats().GetStrength() * 2);
    for(int i = 0; usageTimes > i; i++)//denna b�r bara k�ra max 3 g�nger
    {
        (extraDamage / 2);
    }
    return extraDamage;
}
