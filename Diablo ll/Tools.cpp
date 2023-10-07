#include <iostream>
#include<random>
#include "Tools.h"

void Tools::DeleteText()
{
    system("cls");
}

void Tools::Wait()
{
    system("pause");
}

void Tools::ClearTxt()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
