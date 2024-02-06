 #pragma once
#include <iostream>
#include "map"
#include "UI.h"
#include "PlayerCharacter.h"
#include "ICharacter.h"

class CharacterCreation
{
private:
	UI ui;
	std::shared_ptr<ICharacter> characterInGrogpress;
	std::string specializedAttribute;
	std::shared_ptr<IWeapon> weapon;
	std::map<std::string, int> attributeJournal;

public:
	std::shared_ptr<PlayerCharacter> CreateCharacter();
	std::map<std::string, int> AllocateAttributes();
	int AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining);
	void CheckForSwiftness();
	std::shared_ptr<PlayerCharacter> GeneratePlayerCharacter();
	void Deallocation();
};

