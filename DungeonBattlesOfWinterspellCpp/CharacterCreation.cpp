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

// add dynamicness forshorter functions
//PlayerCharacter
PlayerCharacter* CharacterCreation::ChooseClass() { // separate out class elements

	CharacterCreation cc;
	GameText gameText;

	gameText.WriteText("Who are you?");

	// pick character
	bool correctCharacter = false;
	while (!correctCharacter) {
		gameText.WriteText("1. wood elf \n2. dwarf \n3. enchantress");
		std::string inputCharChoice; std::cin >> inputCharChoice;

		if (inputCharChoice == "1") { // no switch statements in cpp for strings/ints
			correctCharacter = true; // charcter while loop resolved
			system("cls");

			WoodElf woodElf;

			IWeapon* weaponChoice = cc.ChooseWeapon(&woodElf);  // keeping it on the stack

			std::map<std::string, int> attributeJournal = AllocateAttributes(&woodElf); 

			PlayerCharacter* playerCharacter = new PlayerCharacter(
				woodElf.GetName(),
				woodElf.GetHealth(),
				attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
				weaponChoice,
				true // has naturally
			);
			return playerCharacter;
		}
		else if (inputCharChoice == "2") {
			correctCharacter = true;
			system("cls");

			Dwarf dwarf;
			IWeapon* weaponChoice = cc.ChooseWeapon(&dwarf);

			std::map<std::string, int> attributeJournal = AllocateAttributes(&dwarf);
			bool hasSwiftness = false;
			if (attributeJournal["intellegence"] >= 7) {
				hasSwiftness = true;
			}

			PlayerCharacter* playerCharacter = new PlayerCharacter(
				dwarf.GetName(),
				dwarf.GetHealth(),
				attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
				weaponChoice,
				hasSwiftness
			);
			return playerCharacter;
		}
		else if (inputCharChoice == "3") {
			correctCharacter = true;
			system("cls");

			Enchantress enchantress;
			IWeapon* weaponChoice = cc.ChooseWeapon(&enchantress);

			std::map<std::string, int> attributeJournal = AllocateAttributes(&enchantress);
			bool hasSwiftness = false;
			if (attributeJournal["intellegence"] >= 7) {
				hasSwiftness = true;
			}

			PlayerCharacter* playerCharacter = new PlayerCharacter(
				enchantress.GetName(),
				enchantress.GetHealth(),
				attributeJournal["intellegence"], attributeJournal["dexterity"], attributeJournal["strength"],
				weaponChoice,
				hasSwiftness
			);

			return playerCharacter;

		}
		else {
			system("cls");
			gameText.WriteText("Pick from avaiable character choices...");
		}
	}
}

IWeapon* CharacterCreation::ChooseWeapon(ICharacter* character) {
	GameText gameText;

	// pick weapon
	std::stringstream ssOptions;

	int weaponId = 1;

	bool correctWeapon = false;
	while (!correctWeapon) {

		std::stringstream ss; // stringstream is cpp's string interpolation
		ss << "you r " << character->GetName() << "\nweapon options :" << "\n";
		std::string presentOptions = ss.str();
		gameText.WriteText(presentOptions);

		for (std::string weapon : character->GetWeaponOptions()) {

			std::stringstream ss;
			ss << weaponId << ". " << weapon << "\n";
			std::string weapon = ss.str();
			gameText.WriteText(weapon);
			weaponId++;
		}
		std::cout << "\n";

		std::string inputWeaponChoice; std::cin >> inputWeaponChoice;

		if (inputWeaponChoice == "1" || inputWeaponChoice == "2" || inputWeaponChoice == "3") {
			correctWeapon = true;

			if (WoodElf* woodelf = dynamic_cast<WoodElf*>(character)) {
				system("cls");

				if (inputWeaponChoice == "1") { return new ElvenLongsword(); } /**/ else if (inputWeaponChoice == "2") { return new IvoryLongBowAndQuiver(); } /**/  else { return new ShortErnestBowAndQuiver(); }
			} 
			else if (Dwarf* dwarf = dynamic_cast<Dwarf*>(character)) {
				system("cls");

				if (inputWeaponChoice == "1") { return new DoubleBladedAxe(); } else if (inputWeaponChoice == "2") /**/  { return new OrnateShortSword(); } /**/ else { return new SteelSplitHammer(); }
			}
			else if (Enchantress* enchantress = dynamic_cast<Enchantress*>(character)) {
				system("cls");

				if (inputWeaponChoice == "1") { return new DualEtherealDaggers(); } /**/ else if (inputWeaponChoice == "2") { return new GnarledBranchStaff(); } /**/ else if (inputWeaponChoice == "2") { return new OakCarvedWand(); }
			}
			else {
				gameText.WriteText("Pick from avaiable weapon choices");
				system("cls");
			}
		}
		else {
			return nullptr;
		}
	}
}


std::map<std::string, int> CharacterCreation::AllocateAttributes(ICharacter* character) {
	GameText gameText;
	InputManager inputManager;

	std::map<std::string, int> attributeJournal = {
		{"intellegence", character->GetIntelligence()},
		{"dexterity", character->GetDexterity()},
		{"strength", character->GetStrength()}
	};

	std::map<std::string, int> initialAttributeValues = {
		{"intellegence", attributeJournal["intellegence"]},
		{"dexterity", attributeJournal["dexterity"]},
		{"strength", attributeJournal["strength"]}
	};

	//std::map<std::string, int>* attributeJournalClonePtr = new std::map<std::string, int>(originalMap);

	gameText.WriteText("Now let's asses your qualities");
	std::cin.get();

	int remainingPoints = 10;
	while (remainingPoints > 0) {
		std::stringstream ss;
		ss << "You have " << remainingPoints << " points left to allocate into each attribute, please assign your skill points"; /**/ std::string ssStr = ss.str(); /**/ gameText.WriteText(ssStr);

		std::stringstream ss2; /**/ ss2 << "1) Intelligence: " << attributeJournal["intellegence"] << "		2) Dexterity: " << attributeJournal["dexterity"] << "		3) Strength: " << attributeJournal["strength"] << "\n";
		std::string ss2Str = ss2.str(); /**/ gameText.WriteText(ss2Str);

		gameText.WriteText("Which attribute would you like to assign points to ?");

		// acts as a guide for correlating user selection dynamically with the attribute related
		std::string attribute;
		std::map<std::string, std::string> attributeSelection = {
			{"1", "intellegence"},
			{"2", "dexterity"},
			{"3", "strength"}
		};

		std::string selectedAttribute; std::cin >> selectedAttribute;

		auto it = attributeSelection.find(selectedAttribute); // chatgpt: the auto keyword allows the compiler to automatically deduce the data type of the variable based on the value it's initialized with. In this case, it is being used to declare an iterator for the std::map container.
		if (it != attributeSelection.end()) { // key was found in the map

			// which character type is ICharacter being passed in, need to pass it down further so must know the type
			int pointsSpent = AllocatePoints(selectedAttribute, attributeSelection, attributeJournal, initialAttributeValues, remainingPoints, character);
			// by gathering points spent we must recalculate some things but it's all the info we need to know to do so rather than asking for the updated journal, remaining points, etc...
			remainingPoints -= pointsSpent;
			attributeJournal[attributeSelection[selectedAttribute]] += pointsSpent;

		} else {
			system("cls");
			gameText.WriteText("Please select from avaialable attributes...");
		}
	}
	return attributeJournal;
}


int CharacterCreation::AllocatePoints(std::string selectedAttribute, std::map<std::string, std::string> attributeSelection, std::map<std::string, int> attributeJournal, std::map<std::string, int> initialAttributeValues,
	int remainingPoints, ICharacter* character) {
	GameText gameText; // try using one declared in .h file same for input manager
	InputManager inputManager;

	std::string attribute = attributeSelection[selectedAttribute]; // the attribute user has chosen to alter

	bool playerDeciding = true;
	while (playerDeciding) {
		std::stringstream ss; ss << "How many points would you like to spec to " << attributeSelection[selectedAttribute] << "?\n"; /**/ std::string ssStr = ss.str();
		gameText.WriteText(ssStr);

		std::string pointsToAssign; /**/ std::cin >> pointsToAssign; /**/ int points = inputManager.ParseIntCheck(pointsToAssign);
					 
		if (attributeJournal[attribute] + points >= 0 && // checking points allocated doesn't go below 0
			remainingPoints - points <= 10 && // or user isn't adding so many negetive allocations that it gives them extra points, or uses more than they have allowed
			remainingPoints - points >= 0) {

			if (attributeJournal[attribute] + points < initialAttributeValues[attribute]) { // or go below inherited count for attribute if removing
				gameText.WriteText("You must maintain your natural values. Don't undersell your own worth!");
				std::cin.get(); /**/ system("cls"); /**/ gameText.WriteText("So... again");
			}
			else {
				playerDeciding = false;
				system("cls");
				return points;
			}
		}
		else {
			gameText.WriteText("Please stay within the bounds of reality!");
			std::cin.get(); /**/ system("cls"); /**/ gameText.WriteText("So... again");
			std::stringstream ss2;
			ss << "You have " << remainingPoints << " points left to allocate.\n"; /**/ std::string ssStr = ss.str(); /**/ gameText.WriteText(ssStr);
		}
	}
}
