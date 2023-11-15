 #pragma once
#include "map"
#include <iostream>
#include "PlayerCharacter.h"
#include "ICharacter.h"

class CharacterCreation
{
public:
	void ChooseClass();
	IWeapon* ChooseWeapon(ICharacter* character);
	void AllocateAttributes(ICharacter* character);
	int AllocatePoints(std::string selectedAttribute, std::map<std::string, std::string> attributeSelection, std::map<std::string, int> attributeJournal, std::map<std::string, int> initialAttributeValues, int remainingPoints, ICharacter* character);
};

