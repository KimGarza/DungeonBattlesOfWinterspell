#include <vector>
#include <random>
#include <iostream>

#include "Weapons.h"

// here we are assigning values to private member variables
ElvenLongsword::ElvenLongsword() {
	name = "Elven Longsword";
	isRanged = false;

	pSkillName = "Elegant Divide";
	pSkillDescription = "a highly precise and powerful slash to a single enemy target";
	pSkillDamageRange = { 3, 11 };

	sSkillName = "Teachings of The Elders";
	sSkillDescription = "a practice of the lessons, taught by the elders of homeland";
	sSkillDamageRange = { 2, 4 };
}

int ElvenLongsword::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int ElvenLongsword::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}


IvoryLongBowAndQuiver::IvoryLongBowAndQuiver() {
	name = "Ivory Longbow and Quiver";
	isRanged = true;

	pSkillName = "Snipers Mark";
	pSkillDescription = "a highly precise shot to the head which never misses it's mark";
	pSkillDamageRange = { 1, 15 };

	sSkillName = "Majestic Volley";
	sSkillDescription = "a majestic volley of arrows are shot up and rain down from above";
	sSkillDamageRange = { 0, 8 };
}

int IvoryLongBowAndQuiver::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int IvoryLongBowAndQuiver::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

ShortErnestBowAndQuiver::ShortErnestBowAndQuiver() {
	name = "Short Ernest Bow and Quiver";
	isRanged = true;

	pSkillName = "Piercing Arrow";
	pSkillDescription = "an arrow to peirce through the heart of the enemy";
	pSkillDamageRange = { 3, 12 };

	sSkillName = "Fletchers Folley";
	sSkillDescription = "a powerful attack by the hand of the elf which effects surrounding enemies to the target";
	sSkillDamageRange = { 0, 6 };
}

int ShortErnestBowAndQuiver::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int ShortErnestBowAndQuiver::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

// Dwarven weapons ---------------------------------

DoubleBladedAxe::DoubleBladedAxe() {
	name = "Double-Bladed Axe";
	isRanged = false;

	sSkillName = "Aged, Sliced and Served";
	sSkillDescription = "fine wedge cuts to the targeted enemy, if the hit is critical, he may be served on a wooden board with Dom Pérignon";
	sSkillDamageRange = { 3, 14 };

	pSkillName = "Mighty Cleave";
	pSkillDescription = "a swipe of the axe horizontally to the surrounding enemies";
	pSkillDamageRange = { 3, 4 };
}

int DoubleBladedAxe::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int DoubleBladedAxe::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

OrnateShortSword::OrnateShortSword() {
	name = "Ornate Short Sword ";
	isRanged = false;

	sSkillName = "Gut Wrencher";
	sSkillDescription = "a stab through the enemies ribs";
	sSkillDamageRange = { 3, 8 };

	pSkillName = "Double Swing";
	pSkillDescription = "a swing of the sword twice, with the ability to attack twice in one attack";
	pSkillDamageRange = { 0, 6 };
}

int OrnateShortSword::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int OrnateShortSword::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}


SteelSplitHammer::SteelSplitHammer() {
	name = "Steel Split Hammer";
	isRanged = false;

	pSkillName = "Wounding Skull Cruncher";
	pSkillDescription = "a disturbing and heavy fall of his hammer, to the enemy's head, where, if it hits at it's mightiest";
	pSkillDamageRange = { 2, 8 };

	sSkillName = "Strike of Thunder and Steel";
	sSkillDescription = "a powerful and mighty blow of a heavy steel to the ground infront of the enemy's feet. This attack is powerful enough to effect the target enemy and one surrounding enemy on either side";
	sSkillDamageRange = { 1, 20 };
}

int SteelSplitHammer::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int SteelSplitHammer::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

// Enchatress weapons ---------------------------------

DualEtherealDaggers::DualEtherealDaggers() {
	name = "Dual Ethereal Daggers";
	isRanged = false;

	pSkillName = "Wind of Furry";
	pSkillDescription = "a highly precise and powerful slash to a single enemy target";
	pSkillDamageRange = { 3, 7 };

	sSkillName = "Dual Stab";
	sSkillDescription = "a practice of the lessons, taught by the elders of the homeland";
	sSkillDamageRange = { 1, 5 };
}

int DualEtherealDaggers::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int DualEtherealDaggers::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

GnarledBranchStaff::GnarledBranchStaff() {
	name = "Gnarled Branch Staff ";
	isRanged = false;

	pSkillName = "Brewed Storm";
	pSkillDescription = "a highly precise and powerful slash to a single enemy target";
	pSkillDamageRange = { 3, 9 };

	sSkillName = "Fire Beacon";
	sSkillDescription = "a practice of the lessons, taught by the elders of the homeland";
	sSkillDamageRange = { 1, 5 };
}

int GnarledBranchStaff::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int GnarledBranchStaff::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

OakCarvedWand::OakCarvedWand() {
	name = "Oak Carved Wand ";
	isRanged = false;

	pSkillName = "Dark Charm";
	pSkillDescription = "a highly precise and powerful slash to a single enemy target";
	pSkillDamageRange = { 0, 13 };

	sSkillName = "Ancient Incantation";
	sSkillDescription = "a practice of the lessons, taught by the elders of the homeland";
	sSkillDamageRange = { 0, 22 };
}


int OakCarvedWand::UseSkillPrimary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = pSkillDamageRange[0]; /**/ int max = pSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}

int OakCarvedWand::UseSkillSecondary() {
	std::random_device rd; /**/ std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	int min = sSkillDamageRange[0]; /**/ int max = sSkillDamageRange[1];
	std::uniform_int_distribution<> distrib(min, max); /**/ int random_number = distrib(gen);
	return random_number;
}