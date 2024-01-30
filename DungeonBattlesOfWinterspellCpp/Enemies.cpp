#include "Enemies.h"

Firespitter::Firespitter() {
	name = "Firespitter";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void Firespitter::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

// ---------------------------------


DungeonDweller::DungeonDweller() {
	name = "DungeonDweller";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void DungeonDweller::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

// ---------------------------------


Goblin::Goblin() {
	name = "Goblin";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void Goblin::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

// ---------------------------------


HauntingSpirit::HauntingSpirit() {
	name = "HauntingSpirit";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void HauntingSpirit::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

// ---------------------------------


Troll::Troll() {
	name = "Troll";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void Troll::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

// ---------------------------------


Skeleton::Skeleton() {
	name = "Skeleton";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void Skeleton::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

// ---------------------------------


UndeadWolf::UndeadWolf() {
	name = "UndeadWolf";
	health = 100;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 10;
	isDead = false;
}

void UndeadWolf::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}
