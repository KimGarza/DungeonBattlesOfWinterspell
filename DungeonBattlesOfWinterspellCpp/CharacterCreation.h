 #pragma once
#include "map"
#include "UI.h"
#include <iostream>
#include "PlayerCharacter.h"
#include "ICharacter.h"

class CharacterCreation
{
private:
	UI ui;
	std::shared_ptr<ICharacter> characterInGrogpress;
	std::string specializedAttribute;

public:
	std::shared_ptr<PlayerCharacter> CreateCharacter();
	std::shared_ptr<PlayerCharacter> GeneratePlayerCharacter(std::shared_ptr<IWeapon> weapon, std::map<std::string, int> attributeJournal);
	std::shared_ptr<IWeapon> ChooseWeapon(ICharacter* character);
	std::map<std::string, int> AllocateAttributes();
	int AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, std::map<std::string, int> attributeJournal, int pointsRemaining);
	std::shared_ptr<PlayerCharacter> GeneratePlayerCharacter(std::shared_ptr<ICharacter> character, std::shared_ptr<IWeapon> weapon, std::map<std::string, int> attributeJournal);
};

