#pragma once
#include <random>

namespace Random
{
	int RandomNumber(int aMinimal, int aMax)
	{

		std::random_device rd;
		std::uniform_int_distribution<int> dist(aMinimal, aMax);
		return dist(rd);
	}

}


class Tools
{
public:
	static void DeleteText();
	static void Wait();
	static void ClearTxt();
	int myValue;

private:

	int myDiceMiniNr;
	int myDiceMaxNr;
};

