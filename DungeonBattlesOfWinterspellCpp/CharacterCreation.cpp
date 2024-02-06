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

/// <summary>
/// Utilizes UI class to describe options, and UI uses Input to receive palyer choices as to their class/race and weapon (based upon their class/race). 
/// PlayerCharacter is built based off of these choices.
/// </summary>
/// <returns></returns>
std::shared_ptr<PlayerCharacter> CharacterCreation::CreateCharacter() { // separate out class elements

	CharacterCreation cc;
	GameText gameText;

	characterInGrogpress = ui.ChooseClass();

	if (characterInGrogpress->GetName() == "Wood Elf") { specializedAttribute = "dexterity"; }
	else if (characterInGrogpress->GetName() == "Dwarf") { specializedAttribute = "strength"; }
	else if (characterInGrogpress->GetName() == "Enchantress") { specializedAttribute = "intellegence"; }

	weapon = ui.ChooseWeapon(characterInGrogpress);

	attributeJournal = AllocateAttributes();

	std::shared_ptr<PlayerCharacter> playerCharacter = GeneratePlayerCharacter(); // returns the fully built player character

	Deallocation();

	return playerCharacter;
}

std::shared_ptr<PlayerCharacter> CharacterCreation::GeneratePlayerCharacter() {
	
	return std::make_shared<PlayerCharacter>(
		characterInGrogpress->GetName(),
		characterInGrogpress->GetHealth(),
		attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
		characterInGrogpress->GetHealth(),
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

			int pointsSpent = AllocatePoints(chosenAttribute, selectableAttributes, pointsRemaining);
			
			pointsRemaining -= pointsSpent;

			// Barrowing the name/value ("intellegence", etc...) from selectableAttributes map so it can be used to find/alter the map item with the matching key in the attribute journal
			attributeJournal[selectableAttributes[chosenAttribute]] += pointsSpent; 
		}
	}

	CheckForSwiftness();

	return attributeJournal;
}


int CharacterCreation::AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining) {
	
	int pointsToAssign = ui.PointsAllocation(chosenAttribute, selectableAttributes, pointsRemaining, specializedAttribute, attributeJournal);

	attributeJournal[selectableAttributes[chosenAttribute]] += pointsToAssign;

	return pointsToAssign;
}

void CharacterCreation::CheckForSwiftness() {

	if (characterInGrogpress->GetDexterity() >= 4) {
		characterInGrogpress->SetHasSwiftness(true);
	}
}

void CharacterCreation::Deallocation() {
	characterInGrogpress.reset();
}

