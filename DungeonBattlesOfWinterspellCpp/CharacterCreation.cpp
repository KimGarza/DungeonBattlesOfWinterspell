#include "CharacterCreation.h"
#include "PlayerCharacter.h"
#include "Characters.h"
#include "ICharacter.h"
#include "IWeapon.h"
#include "Weapons.h"
#include "GameText.h"
#include <sstream>
#include <cstdlib>

//PlayerCharacter
void ChooseClass() {

	CharacterCreation cc;
	GameText gameText;

	gameText.WriteText("Who are you?");

	// pick character
	bool correctCharacter = false;
	while (!correctCharacter) {
		gameText.WriteText("1. wood elf \n2. dwarf \n3. enchantress");
		std::string inputCharChoice; std::cin >> inputCharChoice;

		if (inputCharChoice == "1") {

			correctCharacter = true; // charcter while loop resolved
			system("cls");

			WoodElf woodElf;
			IWeapon weaponChoice = cc.ChooseWeapon(&woodElf);  // keeping it on the stack

		}
		else if (inputCharChoice == "2") {
			correctCharacter = true;
			system("cls");

			Dwarf dwarf;
			IWeapon weaponChoice = cc.ChooseWeapon(&dwarf);
		}
		else if (inputCharChoice == "3") {
			correctCharacter = true;
			system("cls");

			Enchantress enchantress;
			IWeapon weaponChoice = cc.ChooseWeapon(&enchantress);
		}
		else {
			gameText.WriteText("Pick from avaiable character choices");
			system("cls");
		}
	}
}

IWeapon CharacterCreation::ChooseWeapon(ICharacter* character) {
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
			if (WoodElf* woodelf = dynamic_cast<WoodElf*>(character)) {
				correctWeapon = true; // weapon while loop resolved
				system("cls");

				if (inputWeaponChoice == "1") { return new ElvenLongsword(); }
			}
			else if (inputWeaponChoice == "2") {
				correctWeapon = true;
				system("cls");

				Dwarf dwarf;
				IWeapon inputWeaponChoice = cc.ChooseWeapon(&dwarf);
			}
			else if (inputWeaponChoice == "3") {
				correctWeapon = true;
				system("cls");

				Enchantress enchantress;
				IWeapon inputWeaponChoice = cc.ChooseWeapon(&enchantress);
			}
			else {
				gameText.WriteText("Pick from avaiable weapon choices");
				system("cls");
			}
		}

	}
}


//	GameText gameText;
//
//	// pick weapon
//	std::stringstream ssOptions;
//
//	int weaponId = 1;
//
//	bool correctWeapon = false;
//	while(!correctWeapon) {
//
//		std::stringstream ss; // stringstream is cpp's string interpolation
//		ss << "you r " << character->GetName() << "\nweapon options :" << "\n";
//		std::string presentOptions = ss.str();
//		gameText.WriteText(presentOptions);
//
//		for (std::string weapon : character.GetWeaponOptions()) {
//
//			std::stringstream ss;
//			ss << weaponId << ". " << weapon << "\n";
//			std::string weaponOptions = ss.str();
//			std::cout << weaponOptions;
//			weaponId++;
//		}
//
//		std::string weaponChoice; std::cin >> weaponChoice;
//
//		if (weaponChoice == "1") {
//
//			correctWeapon = true; // weapon while loop resolved
//			system("cls");
//		}
//	}
//
//	return new DoubleBladedAxe();



//IWeapon weaponChosen;

				//if (input == "1") { // Elven Longsword
				//	weaponChosen = new ElvenLongsword();
				//} else if (input == "2") { // Ivory Longbow and Quiver
				//	weaponChosen = ""
				//} else if (input == "3") { // Short Ernest Bow and Quiver
				//	weaponChosen = ""

				//}

				//PlayerCharacter* playerCharacter = new PlayerCharacter(
				//	woodElf.GetName(),
				//	woodElf.GetHealth(),
				//	woodElf.GetIntelligence(),
				//	woodElf.GetDexterity(),
				//	woodElf.GetStrength(),
				//	weaponChosen
				//);