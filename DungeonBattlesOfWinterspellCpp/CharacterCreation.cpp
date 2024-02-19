#include "CharacterCreation.h"
#include "PlayerCharacter.h"
#include "Character.h"
#include "IWeapon.h"
#include "Weapons.h"
#include "GameText.h"
#include "InputManager.h"
#include "CharacterFactory.h"
#include <sstream>
#include <cstdlib>
#include <memory>
#include <iostream>
#include <vector>
#include <map>

/// <summary>
/// Utilizes UI class to describe options, and UI uses Input to receive palyer choices as to their class/race and weapon (based upon their class/race). 
/// PlayerCharacter is built based off of these choices.
/// </summary>
/// <returns></returns>
std::shared_ptr<PlayerCharacter> CharacterCreation::CreateCharacter() { // separate out class elements

	ChooseClass();
	ChooseWeapon();

	attributeJournal = AllocateAttributes();

	std::shared_ptr<PlayerCharacter> playerCharacter = GeneratePlayerCharacter(); // returns the fully built player character

	Deallocation();

	return playerCharacter;
}

void CharacterCreation::ChooseClass() {

	std::string playerChoice = ui.ChooseClass();

	/* character factory - not dynamic but dynamic version can be implemented using CharacterFactory.cpp
		This version is more minimal just not abstracted */
	if (playerChoice == "1") {

		std::shared_ptr<Character> woodElf = std::make_shared<Character>(
			"Wood Elf", 400, 0, 4, 0, 0, 10,
			std::vector<std::string>{ "Elven Longsword", "Ivory Longbow and Quiver", "Short Ernest Bow and Quiver" });

		characterInGrogpress = woodElf;
		specializedAttribute = "dexterity";

	}
	else if (playerChoice == "2") {

		std::shared_ptr<Character> dwarf = std::make_shared<Character>(
			"Dwarf", 650, 0, 0, 4, 25, 0,
			std::vector<std::string>{ "Double Bladed Axe", "Ornate Short Sword", "Steel Split Hammer"});

		characterInGrogpress = dwarf;
		specializedAttribute = "strength";

	}
	else if (playerChoice == "3") {

		std::shared_ptr<Character> enchantress = std::make_shared<Character>(
			"Enchantress", 350, 4, 0, 0, 2, 8,
			std::vector<std::string>{ "Dual Ethereal Daggers", "Gnarled Branch Staff", "Oak Carved Wand" });

		characterInGrogpress = enchantress;
		specializedAttribute = "intellegence";

	}

	ui.CharacterSelected(characterInGrogpress);
}

void CharacterCreation::ChooseWeapon() {

	std::string playerChoice = ui.ChooseWeapon(characterInGrogpress);

	if (characterInGrogpress->GetName() == "Wood Elf") {
		if (playerChoice == "1") {
			weapon = std::make_shared<ElvenLongsword>();
		}
		else if (playerChoice == "2") {
			weapon = std::make_shared<IvoryLongBowAndQuiver>();
		}
		else if (playerChoice == "3") {
			weapon = std::make_shared<ShortErnestBowAndQuiver>();
		}
	}
	else if (characterInGrogpress->GetName() == "Dwarf") {
		if (playerChoice == "1") {
			weapon = std::make_shared<DoubleBladedAxe>();
		}
		else if (playerChoice == "2") {
			weapon = std::make_shared<OrnateShortSword>();
		}
		else if (playerChoice == "3") {
			weapon = std::make_shared<SteelSplitHammer>();
		}
	}
	else if (characterInGrogpress->GetName() == "Enchantress") {
		if (playerChoice == "1") {
			weapon = std::make_shared<DualEtherealDaggers>();
		}
		else if (playerChoice == "2") {
			weapon = std::make_shared<GnarledBranchStaff>();
		}
		else if (playerChoice == "3") {
			weapon = std::make_shared<OakCarvedWand>();
		}
	}

	ui.WeaponSelected(weapon->GetWeaponName());
	gameText.WriteLine("The " + weaponName + ", an ardent choice!"); /**/ _getch();
	return weapon;
}

std::shared_ptr<PlayerCharacter> CharacterCreation::GeneratePlayerCharacter() {

	return std::make_shared<PlayerCharacter>(
		characterInGrogpress->GetName(),
		characterInGrogpress->GetHealth(),
		attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
		characterInGrogpress->GetHealth(),
		characterInGrogpress->GetHasSwiftness(),
		characterInGrogpress->GetArmourRating(),
		weapon
	);
}

std::map<std::string, int> CharacterCreation::AllocateAttributes() {

	std::map<std::string, int> attributeJournal = {
		{"intellegence", characterInGrogpress->GetIntelligence()},
		{"dexterity", characterInGrogpress->GetDexterity()},
		{"strength", characterInGrogpress->GetStrength()}
	};

	int pointsRemaining = 4;
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

