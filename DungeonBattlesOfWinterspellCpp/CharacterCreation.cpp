#include "CharacterCreation.h"
#include "PlayerCharacter.h"
#include "Characters.h"
#include "ICharacter.h"
#include "IWeapon.h"
#include "Weapons.h"
#include "GameText.h"
#include "InputManager.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>

std::shared_ptr<PlayerCharacter> CharacterCreation::CreateCharacter() { // separate out class elements

	CharacterCreation cc;
	GameText gameText;

	std::shared_ptr<ICharacter> charClass = ui.ChooseClass();
	characterInGrogpress = charClass;
	if (charClass->GetName() == "Wood Elf") { specializedAttribute = "dexterity"; } 
	else if (charClass->GetName() == "Dwarf") { specializedAttribute = "strength"; }
	else if (charClass->GetName() == "Enchantress") { specializedAttribute = "intellegence"; }

	/*specializedAttribute = (charClass->GetName() == "Wood Elf") ? "dexterity" :
	(charClass->GetName() == "Dwarf") ? "strength" :
	(charClass->GetName() == "Enchantress") ? "intellegence" : "";*/

	std::shared_ptr<IWeapon> weaponChosen = ui.ChooseWeapon(charClass);

	std::map<std::string, int> attributeJournal = AllocateAttributes();

	return GeneratePlayerCharacter(weaponChosen, attributeJournal); // returns the fully built player character
}

std::shared_ptr<PlayerCharacter> CharacterCreation::GeneratePlayerCharacter(std::shared_ptr<IWeapon> weapon, std::map<std::string, int> attributeJournal) {
	
	return std::make_shared<PlayerCharacter>(
		characterInGrogpress->GetName(),
		characterInGrogpress->GetHealth(),
		attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
		characterInGrogpress->GetHasSwiftness(),
		weapon
	);
}

std::map<std::string, int> CharacterCreation::AllocateAttributes() {

	std::map<std::string, int> attributeJournal = {
		{"intellegence", characterInGrogpress->GetIntelligence()},
		{"dexterity", characterInGrogpress->GetDexterity()},
		{"strength", characterInGrogpress->GetStrength()}
	};

	int pointsRemaining = 10;
	while (pointsRemaining > 0) {

		// For tracking player's selection with their desired attribute to modify
		std::map<std::string, std::string> selectableAttributes = {
			{"1", "intellegence"},
			{"2", "dexterity"},
			{"3", "strength"}
		};

		std::string chosenAttribute = ui.AttributeAssignment(pointsRemaining, attributeJournal);

		auto it = selectableAttributes.find(chosenAttribute);
		if (it != selectableAttributes.end()) {

			int pointsSpent = AllocatePoints(chosenAttribute, selectableAttributes, attributeJournal, pointsRemaining);
			
			pointsRemaining -= pointsSpent;

			// Barrowing the name/value ("intellegence", etc...) from selectableAttributes map so it can be used to find/alter the map item with the matching key in the attribute journal
			attributeJournal[selectableAttributes[chosenAttribute]] += pointsSpent; 
		}
	}
	return attributeJournal;
}


int CharacterCreation::AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, std::map<std::string, int> attributeJournal, int pointsRemaining) {
	
	int pointsToAssign = ui.PointsAllocation(chosenAttribute, selectableAttributes, pointsRemaining, specializedAttribute, attributeJournal);

	attributeJournal[selectableAttributes[chosenAttribute]] += pointsToAssign;

	return pointsToAssign;
}



