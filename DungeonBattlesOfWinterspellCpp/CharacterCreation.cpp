#include "CharacterCreation.h"
#include "PlayerCharacter.h"
#include "Character.h"
#include "Weapon.h"
#include "Weapon.h"
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
std::shared_ptr<PlayerCharacter> CharacterCreation::CreateCharacter() {

	ChooseClass();
	ChooseWeapon();
	AllocateAttributes();

	// returns the fully built player character
	std::shared_ptr<PlayerCharacter> playerCharacter = GeneratePlayerCharacter(); 

	Deallocation();

	return playerCharacter;
}

/// <summary>
///  Sets the value of the characterInGrogpress member variable
/// </summary>
void CharacterCreation::ChooseClass() {

	std::string playerChoice = charCreatUI.ChooseClass();

	/* character factory - not dynamic but dynamic version can be implemented using CharacterFactory.cpp
		This version is more minimal just not abstracted */
	if (playerChoice == "1") {

		std::shared_ptr<Character> woodElf = std::make_shared<Character>(
			"Wood Elf", 400, 0, 4, 0,
			std::vector<std::string>{ "Elven Longsword", "Ivory Longbow and Quiver", "Short Ernest Bow and Quiver" });

		characterInGrogpress = woodElf;
		specializedAttribute = "dexterity";

	}
	else if (playerChoice == "2") {

		std::shared_ptr<Character> dwarf = std::make_shared<Character>(
			"Dwarf", 650, 0, 0, 4,
			std::vector<std::string>{ "Double Bladed Axe", "Ornate Short Sword", "Steel Split Hammer"});

		characterInGrogpress = dwarf;
		specializedAttribute = "strength";

	}
	else if (playerChoice == "3") {

		std::shared_ptr<Character> enchantress = std::make_shared<Character>(
			"Enchantress", 350, 4, 0, 0,
			std::vector<std::string>{ "Dual Ethereal Daggers", "Gnarled Branch Staff", "Oak Carved Wand" });

		characterInGrogpress = enchantress;
		specializedAttribute = "intellegence";

	}

	charCreatUI.CharacterSelected(characterInGrogpress);
}

/// <summary>
///  Sets the value of the weapoin member variable
/// </summary>
void CharacterCreation::ChooseWeapon() {

	std::string playerChoice = charCreatUI.ChooseWeapon(characterInGrogpress);

	if (characterInGrogpress->GetName() == "Wood Elf") {
		if (playerChoice == "1") {
			weapon = std::make_shared<Weapon>("Elven Longsword", false,
			"Elegant Divide", "a highly precise and powerful slash to a single enemy target", std::vector<int>{ 30, 40 },
			"Teachings of The Elders", "a practice of the lessons, taught by the elders of homeland", std::vector<int>{ 2, 4 });
		}
		else if (playerChoice == "2") {
			weapon = std::make_shared<Weapon>("Ivory Longbow and Quiver", true,
			"Double-Bladed Axe", "a highly precise shot to the head which never misses it's mark", std::vector<int>{ 1, 15 },
			"Majestic Volley", "a majestic volley of arrows are shot up and rain down from above", std::vector<int>{ 0, 8 });
		}
		else if (playerChoice == "3") {
			weapon = std::make_shared<Weapon>("Short Ernest Bow and Quiver", true,
			"Piercing Arrow", "an arrow to peirce through the heart of the enemy", std::vector<int>{ 3, 12 },
			"Fletchers Folley", "a powerful attack by the hand of the elf which effects surrounding enemies to the target", std::vector<int>{ 0, 6 });
		}
	}
	else if (characterInGrogpress->GetName() == "Dwarf") {
		if (playerChoice == "1") {
			weapon = std::make_shared<Weapon>("Double-Bladed Axe", false,
				"Aged, Sliced and Served", "fine wedge cuts to the targeted enemy, if the hit is critical, he may be served on a wooden board with Dom Pérignon",
				std::vector<int>{ 3, 14 },
				"Mighty Cleave", "a swipe of the axe horizontally to the surrounding enemies", std::vector<int>{ 3, 4 });
		}
		else if (playerChoice == "2") {
			weapon = std::make_shared<Weapon>("Ornate Short Sword", true,
				"Gut Wrencher", "a stab through the enemies ribs", std::vector<int>{ 3, 8 },
				"Double Swing", "a swing of the sword twice, with the ability to attack twice in one attack", std::vector<int>{ 0, 6 });
		}
		else if (playerChoice == "3") {
			weapon = std::make_shared<Weapon>("Steel Split Hammer", true,
				"Wounding Skull Cruncher", "a disturbing and heavy fall of his hammer, to the enemy's head, where, if it hits at it's mightiest", std::vector<int>{ 2, 8 },
				"Strike of Thunder and Steel", "a powerful and mighty blow of a heavy steel to the ground infront of the enemy's feet. This attack is powerful enough to effect the target enemy and one surrounding enemy on either side",
				std::vector<int>{ 1, 20 });
		}
	}
	else if (characterInGrogpress->GetName() == "Enchantress") {
		if (playerChoice == "1") {
			weapon = std::make_shared<Weapon>("Dual Ethereal Daggers", false,
				"Wind of Furry", "a highly precise and powerful slash to a single enemy target", std::vector<int>{ 3, 7 },
				"Dual Stab", "a practice of the lessons, taught by the elders of homeland", std::vector<int>{ 1, 5 });
		}
		else if (playerChoice == "2") {
			weapon = std::make_shared<Weapon>("Gnarled Branch Staff", true,
				"Brewed Storm", "a highly precise and powerful slash to a single enemy target", std::vector<int>{ 3, 9 },
				"Fire Beacon", "a practice of the lessons, taught by the elders of the homeland", std::vector<int>{ 1, 5 });
		}
		else if (playerChoice == "3") {
			weapon = std::make_shared<Weapon>("Oak Carved Wand", true,
				"Dark Charm", "a highly precise and powerful slash to a single enemy target", std::vector<int>{ 0, 13 },
				"Ancient Incantation", "a practice of the lessons, taught by the elders of the homeland", std::vector<int>{ 0, 22 });
		}
	}

	charCreatUI.WeaponSelected(weapon->GetName());
}

void CharacterCreation::AllocateAttributes() {

	// tracks the attribute with label of which to organize and reduce complexity
	attributeJournal = {
		{"intellegence", characterInGrogpress->GetIntelligence()},
		{"dexterity", characterInGrogpress->GetDexterity()},
		{"strength", characterInGrogpress->GetStrength()}
	};

	// player starts with 3 attributes to assign and can assign 3 more per level
	int pointsRemaining = 3;
	while (pointsRemaining > 0) {

		// associates ID as a string with attributes player can select from to modify
		std::map<std::string, std::string> selectableAttributes = {
			{"1", "intellegence"},
			{"2", "dexterity"},
			{"3", "strength"}
		};

		std::string chosenAttribute = charCreatUI.AttributeAssignment(pointsRemaining, attributeJournal);

		auto it = selectableAttributes.find(chosenAttribute);
		if (it != selectableAttributes.end()) {

			int pointsSpent = AllocatePoints(chosenAttribute, selectableAttributes, pointsRemaining);

			pointsRemaining -= pointsSpent;

			// Barrowing the name/value ("intellegence", etc...) from selectableAttributes map so it can be used to find/alter the map item with the matching key in the attribute journal
			attributeJournal[selectableAttributes[chosenAttribute]] += pointsSpent;
		}
	}
}

int CharacterCreation::AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining) {

	int pointsToAssign = charCreatUI.PointsAllocation(chosenAttribute, selectableAttributes, pointsRemaining, specializedAttribute, attributeJournal);

	attributeJournal[selectableAttributes[chosenAttribute]] += pointsToAssign;

	return pointsToAssign;
}

void CharacterCreation::Deallocation() {
	characterInGrogpress.reset();
}

std::shared_ptr<PlayerCharacter> CharacterCreation::GeneratePlayerCharacter() {

	bool isSwift = characterInGrogpress->GetDexterity() >= 4 ? true : false;

	return std::make_shared<PlayerCharacter>(
		characterInGrogpress->GetName(),
		characterInGrogpress->GetHealth(),
		attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
		characterInGrogpress->GetHealth(),
		isSwift,
		weapon
	);
}


