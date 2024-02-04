#include "Characters.h"
#include "IWeapon.h"
#include "Weapons.h"

// Initial assigned attributes: 4, total assigned additional by player 10
WoodElf::WoodElf() {
	name = "Wood Elf";
	health = 10;
	intelligence = 0;
	dexterity = 4;
	strength = 0;
	weaponOptions.push_back("Elven Longsword");
	weaponOptions.push_back("Ivory Longbow and Quiver");
	weaponOptions.push_back("Short Ernest Bow and Quiver");
}

Dwarf::Dwarf() {
	name = "Dwarf";
	health = 10;
	intelligence = 0;
	dexterity = 0;
	strength = 4;
	weaponOptions.push_back("DoubleBladedAxe");
	weaponOptions.push_back("OrnateShortSword");
	weaponOptions.push_back("Steel Split Hammer");
}

Enchantress::Enchantress() {
	name = "Enchantress";
	health = 10;
	intelligence = 3;
	dexterity = 1;
	strength = 0;
	weaponOptions.push_back("DualEtherealDaggers");
	weaponOptions.push_back("GnarledBranchStaff");
	weaponOptions.push_back("OakCarvedWand");
}