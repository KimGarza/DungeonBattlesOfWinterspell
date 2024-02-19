 #pragma once
#include <iostream>
#include <memory>
#include "map"
#include "UI.h"
#include "PlayerCharacter.h"
#include "Character.h"

class CharacterCreation
{
private:
	UI ui;
	std::shared_ptr<Character> characterInGrogpress;
	std::string specializedAttribute;
	std::shared_ptr<IWeapon> weapon;
	std::map<std::string, int> attributeJournal;

public:
	void CreateCharacter();
	void ChooseClass();
	void ChooseWeapon();

	std::map<std::string, int> AllocateAttributes();
	int AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining);
	void CheckForSwiftness();
	std::shared_ptr<PlayerCharacter> GeneratePlayerCharacter();
	void Deallocation();
};

