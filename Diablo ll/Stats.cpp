#include "Stats.h"
#include "Player.h"

Stats::Stats(int aHp, int aStrength, int aStealth, int someInventory) : myHp(aHp), myStrength(aStrength), myStealth(aStealth), myInventory(someInventory)
{
}

int Stats::GetHp()
{
    return myHp;
}

void Stats::SetHP(int someHp)
{
    this->myHp = someHp;
}

void Stats::SetStrength(int someStrength)
{
    this->myStrength = someStrength;
}

void Stats::SetStealth(int someStealth)
{
    this->myStealth = someStealth;
}

int Stats::GetStealth()
{
    return myStealth;
}

int Stats::GetStrength()
{
    return myStrength;
}

void Stats::PrintStats()
{
    std::cout << '\n' << "[stat]: " << '\n'
        << "HP: " << myHp << '\n'
        << "Strength: " << myStealth << '\n'
        << "Stealth: " << myStrength << '\n'
        << std::endl;

}

void Stats::TakeDamage(int someDamage)
{
    this->myHp -= someDamage;
}
