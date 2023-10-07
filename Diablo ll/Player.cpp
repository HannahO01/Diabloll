#pragma once
#include "Player.h"
#include "Tools.h"
#include "Stats.h"

Player::Player(int aHp, int aStrength, int aStealth, std::string aPlayerName, int& aWinningPoint, int aStorage) : myPlayerName(aPlayerName), myStats(aHp, aStrength, aStealth, aStorage), myCurrentRoom(0), myWinningPoint(aWinningPoint)
{
}

int Player::AttackCrit()
{
    int randomCrit = Random::RandomNumber(1, 10);
    return (myStats.GetStrength() + myStats.GetStealth()) * randomCrit;
}
int Player::Block()
{
    return myStats.GetStealth();
}
int Player::Hunger()
{
    int halfHpGone = myStats.GetHp() / 2;
    myStats.SetHP(halfHpGone);

    return 10000;
}
int Player::PickingLock()
{
    return myStats.GetStrength() + myStats.GetStealth();
}

int Player::MaxStorage ()
{
    return 0;
}

void Player::SetCurrentRoom(int aRoomIndex)
{
    myCurrentRoom = aRoomIndex;
}
int Player::GetCurrentRoom()
{
    return myCurrentRoom;
}

bool Player::ControllName(std::string& aPlayerName)
{
    int i = 0, count = 0;
    while (true)
    {
        // check if name is too little by counting it
        for (int i = 0; (aPlayerName.size()) > i; ++i)
        {
            ++count;
        }
        if (count < 3)
        {
            Tools::ClearTxt();
            std::cout << "too little for the name, please try again: ";
            return false;
        }
        else
        {
            return true;
        }
    }
}
bool Player::ControllNamewNumbers(std::string& aPlayerName)
{
    bool wrong = false;
    while (!wrong)
    {
        //check name if number?
        for (char c : aPlayerName)
        {
            if (isdigit(c))
            {
                wrong = true;
                break;
            }
        }
        if (wrong)
        {
            Tools::ClearTxt();
            std::cout << "this contains a number please try again ";
            Tools::Wait();
            return false;
        }
        else
        {
            return true;
        }
        wrong = false;
    }
}
const std::string& Player::GetName() const
{
    return myPlayerName;
}
Stats& Player::GetStats()
{
    return myStats;
}

void Player::AddingItem(int someHp, int someStrength, int someStealth)
{
    myStats.SetHP(someHp);
    myStats.SetStrength(someStrength);
    myStats.SetStealth(someStealth);
}

void Player::TakeDamage(int someDamage)
{
    int hpToSet = myStats.GetHp() - someDamage;
    myStats.SetHP(hpToSet);
}

const int& Player::GetWinningPoint() const
{
    return myWinningPoint;
}
void Player::IncrementWinningPoint()
{
    myWinningPoint++;
}
