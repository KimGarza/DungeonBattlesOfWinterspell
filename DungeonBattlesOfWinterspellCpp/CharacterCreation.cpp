#include "CharacterCreation.h"
#include "PlayerCharacter.h"

PlayerCharacter CharacterCreation::ChooseClass() {

	PlayerCharacter playerCharacter;
	int wait;
	//ui to ask
	std::cout << "UI to ask who are you? get input of int to respond" << std::endl;
	std::cout << "1. wood elf 2. dwarf 3. enchantress" << std::endl;
	std::string characterChoice;
	std::cin >> characterChoice;
	std::cout << "You chose: " + characterChoice << std::endl;
	// create ICharcter of that base class maybe switch statement
	// make a comment about each choice
	// now based on the character choose the weapon from their weapon list and set new Iweapon class = to it
	std::cout << "UI to ask what weapon you pick? get input of int to respond" << std::endl;
	std::cout << "1. weapon1 2. weapon2 3. weapon3" << std::endl;
	std::string weaponChoice;
	std::cin >> weaponChoice;
	std::cout << "You chose: " + weaponChoice << std::endl;
	// ui says stuff to character and builds your player character
	// let's evaluate your attributes qualities
	std::cout << "UI to say let's evaluate your attributes qualities" << std::endl;
	std::cout << "current int, dex and str with number and int 1 dex 2 str 3 pick to change" << std::endl;
	// here do while player is choosing stats while loop keep showing the main menu of values assigned, then let player pick num, 
	// switch case of number to then show perhaps a render of that att and any number, once selected it updates it
	// can start over and clear changes or submit and whatever those values are for each int with assigned name add it to player character
	std::cout << "YOUVE BUILT YOUR CHARACTER" << std::endl;
	std::cin >> wait;
	return playerCharacter;
}