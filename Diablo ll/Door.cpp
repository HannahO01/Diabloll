#include "Door.h"
#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Room.h"
#include "Tools.h"

Door::Door(const int aRoomIndex1, const int aRoomIndex2, const bool aLoockedDoor, const std::string aColor) : myRoomIndex1(aRoomIndex1), myRoomIndex2(aRoomIndex2), myLoockedDoor(aLoockedDoor), mycollour(aColor)
{
}

int Door::GetRoom1() const
{
    return myRoomIndex1;
}

int Door::GetRoom2() const
{
    return myRoomIndex2;
}

int Door::EnterDoor(Player& aPlayer)
{
    if (!myLoockedDoor)
    {
        int choise;
        int difficulty = 120;
        int gettingHurt = 10;
        while (!myLoockedDoor)
        {
            std::cout << "[This room is locked]" << '\n' << "what will you do?" << '\n'
                << "[1, Pick locket]    or      [2, Hit it HARD]" << std::endl;
            std::cin >> choise;

            if (choise == 1)
            {
                difficulty -= aPlayer.PickingLock();
                std::cout << "[Door Hp] " << difficulty << std::endl;
            }
            else if (choise == 2)
            {
                difficulty -= aPlayer.AttackCrit();
                aPlayer.TakeDamage(gettingHurt);
                std::cout << "[Door Hp] " << difficulty << '\n'
                    << "[You took " << gettingHurt << " damage] " << std::endl;
                aPlayer.GetStats().PrintStats();
            }
            else
            {
                Tools::ClearTxt();
                std::cout << "Chose between [1, Pick locket]    or      [2, Hit it HARD]" << std::endl;
            }

            if (difficulty <= 0)
            {
                myLoockedDoor = true;
            }
        }
    }
    if (aPlayer.GetCurrentRoom() == myRoomIndex1)
    {
        return myRoomIndex2;
    }
    return myRoomIndex1;
}

void Door::SetLockedDoor(bool& aDoor)
{
    aDoor = myLoockedDoor;
}

const bool Door::GetLockedDoor() const
{
    return myLoockedDoor;
}

const std::string Door::GetCollour(Player aPlayer)
{
    // living room P 12 / Bed room P 13 / Kitchen P 9 /  Closet P 8 /
    HANDLE consoleColor;
    consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    int setColour = 0;
    int witchDoor;
    if (aPlayer.GetCurrentRoom() == myRoomIndex1)
    {
        witchDoor = myRoomIndex2;
    }
    else
    {
        witchDoor = myRoomIndex1;
    }
    switch (witchDoor)
    {
    case 0:
    {
        setColour = 12;
        break;
    }
    case 1:
    {
        setColour = 13;
        break;
    }
    case 2:
    {
        setColour = 9;
        break;
    }
    case 3:
    {
        setColour = 8;
        break;
    }
    }

    SetConsoleTextAttribute(consoleColor, setColour);

    return mycollour;
}