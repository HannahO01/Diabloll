// Diablo II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Stats.h"
#include "Tools.h"
#include "Door.h"
#include "Room.h"

int main()
{
    HANDLE consoleColor;
    consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    int P = 12;
    SetConsoleTextAttribute(consoleColor, P);
    //changing color for text

    std::string playerName;

    std::cout << "You are in hell, Welcome!" << '\n' << "Now, what are you? " << '\n' 
        << "forget it i don't care about that just give me your name " << std::endl;
    while (true)
    {
        std::cin >> playerName;
        if (Player::ControllName(playerName) == true && Player::ControllNamewNumbers(playerName) == true)
        {
            std::cout << "Really? " << '\n' << "lol ok" << '\n' << playerName << " hope you suffer." << std::endl;
            break;
        }
    }
    Tools::Wait();
    Tools::DeleteText();
    int winningPoints = 0;
    Player thePlayer = Player(100, 50, 10, playerName, winningPoints,10);
    thePlayer.GetStats().PrintStats();
    //             enemies, name of room, item in room
    Room room0 = Room(true, "[Living room]", true);
    Room room1 = Room(false, "[Bed Room]", false);
    Room room2 = Room(true, "[Kitchen]", true);
    Room room3 = Room(false, "[Closet]", true);

    std::vector<Room> roomList;
    roomList.push_back(room0);
    roomList.push_back(room1);
    roomList.push_back(room2);
    roomList.push_back(room3);

    Door* door0 = new Door(0, 1, true, "A");
    Door* door1 = new Door(0, 2, true, "B");
    Door* door2 = new Door(1, 2, true, "C");
    Door* door3 = new Door(2, 3, false, "D");

    roomList[0].AddDoor(door0);
    roomList[0].AddDoor(door1);
    roomList[1].AddDoor(door0);
    roomList[1].AddDoor(door2);
    roomList[2].AddDoor(door1);
    roomList[2].AddDoor(door2);
    roomList[2].AddDoor(door3);
    roomList[3].AddDoor(door3);

    roomList[0].GetRoomName();
    roomList[1].GetRoomName();
    roomList[2].GetRoomName();
    roomList[3].GetRoomName();


    int awnser;
    std::cout << "Would you like to enter hell? " << thePlayer.GetName() << '\n'
        << "[1, Enter]     [2, Leave]" << std::endl;
    int roomToEnter;    // this track what room we are in.

    thePlayer.SetCurrentRoom(0);
    std::cin >> awnser;
    if (awnser == 1)
    {
        std::cout << roomList[0].GetRoomName() << std::endl;
        roomToEnter = roomList[0].EnterRoom(thePlayer, roomToEnter);

        while (thePlayer.GetStats().GetHp() > 0 && roomToEnter > -1)
        {
            std::cout << roomList[roomToEnter].GetRoomName() << std::endl;
            thePlayer.SetCurrentRoom(roomToEnter);
            roomToEnter = roomList[roomToEnter].EnterRoom(thePlayer, roomToEnter);
            winningPoints += thePlayer.GetWinningPoint();
        }
    }
    else if (awnser == 2)
    {
        return 0;
    }
    else
    {
        Tools::ClearTxt();
        std::cout << "Chose option [1, Enter] or [2, Leave]" << std::endl;
    }

    if (winningPoints == 2)
    {
        std::cout << "You won, congrats(?) " << std::endl;
        Tools::Wait();
    }
    else
    {
        std::cout << "Have a nice trip in hell... " << std::endl;
        Tools::Wait();
    }
}