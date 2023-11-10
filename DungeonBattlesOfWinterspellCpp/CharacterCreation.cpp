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
#include <map>


//PlayerCharacter
void CharacterCreation::ChooseClass() {

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
			AllocateAttributes(&woodElf);
		}
		else if (inputCharChoice == "2") {
			correctCharacter = true;
			system("cls");

			Dwarf dwarf;
			IWeapon* weaponChoice = cc.ChooseWeapon(&dwarf);
		}
		else if (inputCharChoice == "3") {
			correctCharacter = true;
			system("cls");

			Enchantress enchantress;
			IWeapon* weaponChoice = cc.ChooseWeapon(&enchantress);
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

				if (inputWeaponChoice == "1") { return new ElvenLongsword(); }
				else if (inputWeaponChoice == "2") { return new IvoryLongBowAndQuiver(); }
				else { return new ShortErnestBowAndQuiver(); }
			}

			else if (Dwarf* dwarf = dynamic_cast<Dwarf*>(character)) {
				system("cls");

				if (inputWeaponChoice == "1") { return new DoubleBladedAxe(); }
				else if (inputWeaponChoice == "2") { return new OrnateShortSword(); }
				else { return new SteelSplitHammer(); }
			}
			else if (Enchantress* enchantress = dynamic_cast<Enchantress*>(character)) {
				system("cls");

				if (inputWeaponChoice == "1") { return new DualEtherealDaggers(); }
				else if (inputWeaponChoice == "2") { return new GnarledBranchStaff(); }
				else if (inputWeaponChoice == "2") { return new OakCarvedWand(); }
			}
			else {
				gameText.WriteText("Pick from avaiable weapon choices");
				system("cls");
			}
		}
	}
	return nullptr;
}


void CharacterCreation::AllocateAttributes(ICharacter* character) {
	GameText gameText;
	InputManager inputManager;
	std::map<std::string, int> AttributeJournal;

	gameText.WriteText("Now let's asses your qualities");
	std::cin.get();

	int remainingPoints = 10;
	while (remainingPoints > 0) {

		std::stringstream ss;
		ss << "You have " << remainingPoints << " points left to allocate into each attribute, please assign your skill points";
		std::string presentPoints = ss.str();
		gameText.WriteText(presentPoints);

		std::stringstream ss2;
		ss2 << "1) Intelligence: " << character->GetIntelligence() << "		2) Dexterity: " << character->GetDexterity() << "		3) Strength: " << character->GetStrength() << "\n";
		std::string presentCurrentPoints = ss2.str();
		gameText.WriteText(presentCurrentPoints);
		gameText.WriteText("Which attribute would you like to assign points to ? : ");

		std::string attributeSelect; std::cin >> attributeSelect;
		if (attributeSelect == "1" || attributeSelect == "2" || attributeSelect == "3") {
			if (attributeSelect == "1") {

			} else if (attributeSelect == "2") {

			}
			else if (attributeSelect == "3") {
			}
		}
		else {
			system("cls");
			gameText.WriteText("Please select from avaialable attributes...");
		}
	}



}