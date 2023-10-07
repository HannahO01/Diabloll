#pragma once
#include <random>

namespace Random
{
	int RandomNumber(int aMinimal, int aMax);
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

