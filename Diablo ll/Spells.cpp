#include "Spells.h"

int Spells::UseSpell (Player & aPlayer, int usageTimes)
{
    usageTimes = 3;
    int extraDamage = (aPlayer.GetStats().GetStrength() * 2);
    for(int i = 0; usageTimes > i; i++)//denna bör bara köra max 3 gånger
    {
        (extraDamage / 2);
    }
    return extraDamage;
}
