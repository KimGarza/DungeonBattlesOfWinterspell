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
	weaponOptions.push_back(new ElvenLongsword);
	weaponOptions.push_back(new IvoryLongBowAndQuiver());
	weaponOptions.push_back(new ShortErnestBowAndQuiver());
}

Dwarf::Dwarf() {
	name = "Dwarf";
	health = 125;
	intelligence = 0;
	dexterity = 0;
	strength = 4;
	weaponOptions.push_back(new DoubleBladedAxe);
	weaponOptions.push_back(new OrnateShortSword());
	weaponOptions.push_back(new SteelSplitHammer());
}

Enchantress::Enchantress() {
	name = "Enchantress";
	health = 110;
	intelligence = 3;
	dexterity = 1;
	strength = 0;
	weaponOptions.push_back(new DualEtherealDaggers);
	weaponOptions.push_back(new GnarledBranchStaff());
	weaponOptions.push_back(new OakCarvedWand());
}