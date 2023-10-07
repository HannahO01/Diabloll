#pragma once
#include <vector>
#include <iostream>
class Items
{
	Items(int aHp, int aStregnth, int aStealth, int aMaxWeight, std::string anItemName);

public:
	int GetItem();
	int SetNewStat();
	void AddItem();

private:
	int myHp;
	int myStrength;
	int myStealth;
	int myMaxWeight;
	std::string myItemName;
};
/*Föremål
Det ska finnas föremål i spelet.
•	Spelaren får dessa genom att plocka upp dem från golvet.
•	Det kan ligga föremål på golvet när man kommer in i ett rum.
•	Det kan även trilla ut föremål från en kista när den öppnas, men det går även bra att objekten plockas upp direkt ur kistan.
•	Fiender kan tappa föremål när dem dör.
•	När spelaren bär på föremål ska dessa kunna ge bonusar till spelarens egenskaper.
•	Föremål ska kunna ge bonusar till både grundegenskaper och sekundära egenskaper.
•	Varje föremål har en vikt. Om föremålens totalvikt överstiger spelarens bärkapacitet så kan inga fler objekt plockas upp.
*/
