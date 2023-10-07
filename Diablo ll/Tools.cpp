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

int Random::RandomNumber(int aMinimal, int aMax)
{
	{
		std::random_device rd;
		std::uniform_int_distribution<int> dist(aMinimal, aMax);
		return dist(rd);
	}
}
