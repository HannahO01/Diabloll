#include "Stats.h"
#include "Player.h"

Stats::Stats(int aHp, int aStrength, int aStealth) : myHp(aHp), myStrength(aStrength), myStealth(aStealth)
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
