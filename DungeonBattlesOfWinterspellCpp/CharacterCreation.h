 #pragma once
#include <iostream>
#include "map"
#include "UI.h"
#include "PlayerCharacter.h"
#include "CharacterCreation.h"
#include "CharCreatUI.h"

class CharacterCreation
{
private:
	CharCreatUI charCreatUI;
	std::shared_ptr<Character> characterInGrogpress;
	std::string specializedAttribute;
	std::shared_ptr<IWeapon> weapon;
	std::map<std::string, int> attributeJournal;

public:

	std::shared_ptr<PlayerCharacter> CreateCharacter();
	void ChooseClass();
	void ChooseWeapon();

	void AllocateAttributes();
	int AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining);
	std::shared_ptr<PlayerCharacter> GeneratePlayerCharacter();
	void Deallocation();
};

