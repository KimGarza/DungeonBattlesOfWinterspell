#include "Characters.h"
#include "IWeapon.h"
#include "Weapons.h"

// Initial assigned attributes: 4, total assigned additional by player 10
WoodElf::WoodElf() {
	name = "Wood Elf";
	health = 100;
	intelligence = 0;
	dexterity = 4;
	strength = 0;
	hasSwiftness = true;
	weaponOptions.push_back("Elven Longsword");
	weaponOptions.push_back("Ivory Longbow and Quiver");
	weaponOptions.push_back("Short Ernest Bow and Quiver");
}

Dwarf::Dwarf() {
	name = "Dwarf";
	health = 125;
	intelligence = 0;
	dexterity = 0;
	strength = 4;
	hasSwiftness = false;
	weaponOptions.push_back("DoubleBladedAxe");
	weaponOptions.push_back("OrnateShortSword");
	weaponOptions.push_back("Steel Split Hammer");
}

Enchantress::Enchantress() {
	name = "Enchantress";
	health = 110;
	intelligence = 4;
	dexterity = 0;
	strength = 0;
	hasSwiftness = false;
	weaponOptions.push_back("DualEtherealDaggers");
	weaponOptions.push_back("GnarledBranchStaff");
	weaponOptions.push_back("OakCarvedWand");
}