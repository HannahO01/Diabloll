#include "Chest.h"
#include "Player.h"
#include "Tools.h"

Chest::Chest (int anItem, int aSpells) : myItem(anItem), mySpells(aSpells)
{
}

void Chest::OpenChest (Player& aPlayer, std::vector<Items>& aVectorItem, std::string & aitemName)//vet inte ifall de går å göra detta uppdelat i två, men fick inte de å fungera. 
{
    this->myVectorItem = aVectorItem;
    int pickUpItem;
    int randomItem = Random::RandomNumber (1, 5);
    switch(randomItem)
    {
    case 1:
    {
        AddItems (Items (40, 50, 2, 2, "Heavy Pillow"));
        myItemName = "Heavy Pillow";
        break;
    }
    case 2:
    {
        AddItems (Items (200, 5, 5, 5, "Heavy Jacket"));
        myItemName = "Heavy Jacket";
        break;
    }
    case 3:
    {
        AddItems (Items (1, 1, 1, 1, "smol rock"));
        myItemName = "smol rock";
        break;
    }
    case 4:
    {
        AddItems (Items (500, 500, 500, 5, "Devils favorite snack"));
        myItemName = "Devils favorite snack";
        break;
    }
    case 5:
    {
        AddItems (Items (100, 1, 1, 1, "One Sock"));
        myItemName = "One Sock";
        break;
    }
    }

    std::cout << "Would you like to pick up the item?" << '\n'
        << "[1, Yes]        [2, No]" << std::endl;
    std::cin >> pickUpItem;

    if(myVectorItem.empty ())
    {
        std::cout << "[There is no Items in here]" << std::endl;
    }


    if(pickUpItem == 1)
    {
        for(int i = 0; i < myVectorItem.size (); i++)
        {
            if(aPlayer.MaxStorage (myVectorItem[i].GetWeight ()) > 6)
            {
                break;
            }
            myVectorItem[i].SetItemName (myItemName);
            std::cout << "[You got " << myItemName << " ]       ";

            aPlayer.GetStats ().SetHP (myVectorItem[i].GetStats ().GetHp ());
            aPlayer.GetStats ().SetStrength (myVectorItem[i].GetStats ().GetStrength ());
            aPlayer.GetStats ().SetStealth (myVectorItem[i].GetStats ().GetStealth ());
            aPlayer.GetStats ().SetMaxInventory (myVectorItem[i].GetStats ().GetInventoryWeight ());

            aPlayer.GetStats ().PrintStats ();
            
        }
    }
    else
    {
        std::cout << "Boring..." << std::endl;
    }
    myItemName = aitemName;
}

void Chest::AddItems (Items anItem)
{
    myVectorItem.push_back (anItem);
}

