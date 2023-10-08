#include "Room.h"
#include <iostream>
#include "Player.h"
#include "Tools.h"
#include "Door.h"
#include "Enemy.h"
#include "Stats.h"
#include "Chest.h"
#include "Spells.h"

Room::Room(bool aHasEnemies, std::string aRoomName, bool someItems)
{
    myEnemies;
    myDoors;
    myItems;
    myChest;
    if(someItems)
    {
        //AddChest (Chest (myChestItem, mySpells));

    }

    if (aHasEnemies)
    {
        int randomRoll = Random::RandomNumber(1, 2);
        for (size_t i = 0; i < randomRoll; i++)
        {
            AddEnemies(Enemy(50, 5, 5,5));
        }
    }
    myRoomName = aRoomName;
}

void Room::AddEnemies(Enemy aEnemy)
{
    myEnemies.push_back(aEnemy);
}

void Room::AddDoor(Door* aDoor)
{
    myDoors.push_back(aDoor);
}

void Room::AddItems(Items anItem)//ta bort senare
{
    myItems.push_back(anItem);
}

void Room::AddChest (Chest aChest)
{
    myChest.push_back (aChest);
}

bool Room::Fighting(bool& allowedToLeave, Player& aPlayer)
{
    allowedToLeave = false;
    bool isFigthing = true;
    int action;
    int abilities;
    int outputBlock = 0;

    while (!myEnemies.empty() && aPlayer.GetStats().GetHp() > 0)
    {
        Tools::DeleteText();
        std::vector<int> enemiesRemove;

        std::cout << "Who would you like to attack? " << std::endl;
        for (int i = 0; i < myEnemies.size(); i++)
        {
            std::cout << "[Enemy " << i + 1 << "]       ";
        }
        std::cin >> action;

        std::cout << "What would you like to do? " << '\n' << "[1, Attack]      [2, Block]      [3, Hunger]" << std::endl;
        std::cin >> abilities;

        if (action <= myEnemies.size() && action >= 0)
        {
            action--;

            switch (abilities)
            {
            case Attack:
            {
                int outputDamage = aPlayer.AttackCrit();
                myEnemies[action].GetStats().TakeDamage(outputDamage);

                std::cout << "you attacked: " << outputDamage << std::endl;
                std::cout << "[Enemy " << action << "] hp: " << myEnemies[action].GetStats().GetHp() << std::endl;
                break;
            }
            case Block:
            {
                outputBlock = aPlayer.Block();
                std::cout << "you will block: " << outputBlock << '\n' << " for the next attack" << std::endl;
                break;
            }
            case Hunger:
            {
                int outputHunger = aPlayer.Hunger();
                myEnemies[action].GetStats().TakeDamage(outputHunger);

                std::cout << "you attacked: " << outputHunger << std::endl;
                std::cout << "[Enemy  " << action << "] hp: " << myEnemies[action].GetStats().GetHp() << std::endl;
                std::cout << "[Player " << action << "] hp: " << aPlayer.GetStats().GetHp() << std::endl;
                break;
            }
            }
            Tools::Wait();

            //output if enemies is dead
            for (int i = 0; i < myEnemies.size(); i++)
            {
                if (myEnemies[i].GetStats().GetHp() <= 0)
                {
                    int awnserLoot;
                    std::cout << "[Enemy " << i + 1 << " is dead]" << std::endl;
                    myEnemies[i].DroppItems ();
                    std::cout << "[Dropped " << myEnemies[i].GetItemName() << " ]" << '\n' 
                        << "Would you like to pick it up?" << '\n' 
                        << "[1, Yes]        [2, No]" << std::endl;
                    std::cin >> awnserLoot;
                    if(awnserLoot == 1)
                    {
                        if(aPlayer.MaxStorage (myEnemies[i].GetItemWeight ()) > 6)
                        {
                            break;
                        } 
                        std::cout << "...thats a bit weird but ok..." << std::endl;
                        aPlayer.GetStats ().SetMaxInventory (myEnemies[i].GetItemWeight());
                    }
                    else
                    {
                        std::cout << "Thats fair" << std::endl;
                    }
                    
                    enemiesRemove.push_back(i);
                }
            }
            for (int i = 0; i < enemiesRemove.size(); i++)
            {
                myEnemies.erase(myEnemies.begin() + enemiesRemove[i]);
            }
            //getting rid of enemies from myenemies vector list

            // enemie(s) hitting player
            for (int i = 0; i < myEnemies.size(); i++)
            {
                int enemyOutPutDamage = myEnemies[i].AttackCrit();

                aPlayer.GetStats().TakeDamage(enemyOutPutDamage -= outputBlock);
                std::cout << "[Enemy " << i + 1 << " ] hit " << aPlayer.GetName() << " with " << enemyOutPutDamage << " damage" << std::endl;
            }

            aPlayer.GetStats().PrintStats();
            Tools::Wait();
        }
        else
        {
            Tools::ClearTxt();
            std::cout << "Please chose one of the enemies" << std::endl;
        }
    }

    if (aPlayer.GetStats().GetHp() <= 0)
    {
        std::cout << "[you dead]" << std::endl;
        return false;
        Tools::Wait();
    }

    aPlayer.IncrementWinningPoint();
    allowedToLeave = true;
    return allowedToLeave;
}

int Room::EnterRoom(Player& aPlayer, int& whatRoom)
{
    int action;
    int winContintion = 0; //if  you kill all enemies 
    bool allowedToLeave = false;
    int cheater = 10;
    int wonThisFight = 0;

    std::string roomOptions[4] = { "[1, Open a Chest]", "[2, fight monster ?]", "[3, next room]", "[4, Leave]" };
    if (aPlayer.GetWinningPoint() == 2)
    {
        roomOptions[3] = "[4, You Won!!]";
    }

    while (aPlayer.GetStats().GetHp() > 0)
    {
        std::vector<int> removeItem;
        std::cout << "What would you like to do? " << '\n'
            << roomOptions[0] << "    " << roomOptions[1] << "    " << roomOptions[2] << "    " << roomOptions[3] << std::endl;
        std::cin >> action;
        if (action <= 4 && action >= 0)
        {
            switch (action)
            {
            case items:
            {
                Tools::DeleteText ();

                if(myChest.empty ())
                {
                    std::cout << "[There is no Items in here]" << std::endl;
                }

                for(int i = 0; i < myChest.size (); i++)
                {
                    myChest[i].OpenChest (aPlayer, myItems, myItemName);
                    removeItem.push_back (i);
                    myChest.erase (myChest.begin () + removeItem[i]); 
                }

                Tools::Wait ();
                Tools::DeleteText (); 
                continue;
            }
            case fight:
            {
                bool changeLeave;
                Fighting(changeLeave, aPlayer);
                allowedToLeave = changeLeave;
                aPlayer.IncrementWinningPoint();
                Tools::DeleteText (); 
                continue;
            }
            case rooms:
            {
                switch (whatRoom)
                {
                case 0:
                {
                    if (aPlayer.GetWinningPoint() >= 1)
                    {
                        allowedToLeave = true;
                    }
                    break;
                }
                case 1:
                {
                    allowedToLeave = true;
                    break;
                }
                case 2:
                {
                    if (aPlayer.GetWinningPoint() >= 2)
                    {
                        allowedToLeave = true;
                    }
                    break;
                }
                case 3:
                {
                    allowedToLeave = true;
                    break;
                }
                }

                if (allowedToLeave == false)
                {
                    std::cout << "[Enemies blocking your way]" << std::endl;
                    aPlayer.TakeDamage(cheater);
                    aPlayer.GetStats().PrintStats();
                    continue;
                }

                std::cout << "Would you like to open door?" << std::endl;

                int option = 1;

                for (Door* door : myDoors)
                {
                    std::cout << "[ " << option << ", Door " << door->GetCollour(aPlayer) << "]" << std::endl;
                    option++;
                }
                do
                {

                    while (true)
                    {
                        std::cin >> action;
                        if (action >= option || action < 0)
                        {
                            Tools::ClearTxt();
                            std::cout << "Please chose a door" << std::endl;

                        }
                        break;
                    }

                } while (action > myDoors.size() || action < 1);
                myDoors[action - 1]->GetCollour(aPlayer);

                return myDoors[action - 1]->EnterDoor(aPlayer);

            }
            case leave:
            {
                if (aPlayer.GetWinningPoint() == 2)
                {
                    std::cout << "You won!!!!" << std::endl;
                }
                std::cout << "[Leaving rooms]" << std::endl;
                Tools::Wait();
                return -1;
                break;
            }
            }
        }
        else
        {
            Tools::ClearTxt();
            std::cout << "Please chose between the options" << std::endl;
        }
        Tools::DeleteText();
    }
}

const std::string Room::GetRoomName() const
{
    return myRoomName;
}

void Room::SetRoomName(const std::string aNameIndex)
{
    myRoomName = aNameIndex;
}