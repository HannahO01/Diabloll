#pragma once
#include <vector>
#include <iostream>
#include "Stats.h"
class Items
{
public:

	Items (int aHp, int aStregnth, int aStealth, int aMaxWeight, std::string anItemName);
	Stats& GetStats (); 
	void SetItemName (std::string someItem); 
	std::string GetItemName ();

private:
	int myHp;
	int myStrength;
	int myStealth;
	int myMaxWeight;

	Stats myStats;

	std::string myItemName;
};
/*F�rem�l
Det ska finnas f�rem�l i spelet.
�	Spelaren f�r dessa genom att plocka upp dem fr�n golvet.
�	Det kan ligga f�rem�l p� golvet n�r man kommer in i ett rum.
�	Det kan �ven trilla ut f�rem�l fr�n en kista n�r den �ppnas, men det g�r �ven bra att objekten plockas upp direkt ur kistan.
�	Fiender kan tappa f�rem�l n�r dem d�r.
�	N�r spelaren b�r p� f�rem�l ska dessa kunna ge bonusar till spelarens egenskaper.
�	F�rem�l ska kunna ge bonusar till b�de grundegenskaper och sekund�ra egenskaper.
�	Varje f�rem�l har en vikt. Om f�rem�lens totalvikt �verstiger spelarens b�rkapacitet s� kan inga fler objekt plockas upp.
*/
