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
	pSkillDamageRange = { 3, 14 };

	sSkillName = "Teachings of The Elders";
	sSkillDescription = "a practice of the lessons, taught by the elders of homeland";
	sSkillDamageRange = { 3, 5 };
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
	pSkillDamageRange = { 12 };

	sSkillName = "Majestic Volley";
	sSkillDescription = "a majestic volley of arrows are shot up and rain down from above";
	sSkillDamageRange = { 1, 8 };
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
	pSkillDamageRange = { 9, 18 };

	sSkillName = "Fletchers Folley";
	sSkillDescription = "a powerful attack by the hand of the elf which effects surrounding enemies to the target";
	sSkillDamageRange = { 1, 3 };
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
	sSkillDamageRange = { 5, 8 };

	pSkillName = "Mighty Cleave";
	pSkillDescription = "a swipe of the axe horizontally to the surrounding enemies";
	pSkillDamageRange = { 8, 12 };
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
	sSkillDamageRange = { 5, 18 };

	pSkillName = "Double Swing";
	pSkillDescription = "a swing of the sword twice, with the ability to attack twice in one attack";
	pSkillDamageRange = { 3, 8 };
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
	pSkillDamageRange = { 33, 40 };

	sSkillName = "Strike of Thunder and Steel";
	sSkillDescription = "a powerful and mighty blow of a heavy steel to the ground infront of the enemy's feet. This attack is powerful enough to effect the target enemy and one surrounding enemy on either side";
	sSkillDamageRange = { 14, 20 };
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
	pSkillDamageRange = { 33, 40 };

	sSkillName = "Dual Stab";
	sSkillDescription = "a practice of the lessons, taught by the elders of the homeland";
	sSkillDamageRange = { 14, 20 };
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
	pSkillDamageRange = { 33, 40 };

	sSkillName = "Fire Beacon";
	sSkillDescription = "a practice of the lessons, taught by the elders of the homeland";
	sSkillDamageRange = { 14, 20 };
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
	pSkillDamageRange = { 33, 40 };

	sSkillName = "Ancient Incantation";
	sSkillDescription = "a practice of the lessons, taught by the elders of the homeland";
	sSkillDamageRange = { 14, 20 };
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