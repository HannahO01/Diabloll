#include <iostream>
#include<random>
#include "Tools.h"

namespace Tools
{
    int RandomNumber(int aMinimal, int aMax)
    {

        std::random_device rd;
        std::uniform_int_distribution<int> dist(aMinimal, aMax);
        return dist(rd);
    }

}

void ToolsC::DeleteText()
{
    system("cls");
}

void ToolsC::Wait()
{
    system("pause");
}

void ToolsC::ClearTxt()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
