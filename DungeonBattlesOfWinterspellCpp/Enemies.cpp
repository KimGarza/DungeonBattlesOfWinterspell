#include "Enemies.h"

Firespitter::Firespitter() {
	name = "Firespitter";
	health = 5;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 2;
	isDead = false;
}

void Firespitter::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int Firespitter::AttackPlayer() {
	return skillDamage;
}

// ---------------------------------


DungeonDweller::DungeonDweller() {
	name = "DungeonDweller";
	health = 8;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 4;
	isDead = false;
}

void DungeonDweller::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int DungeonDweller::AttackPlayer() {
	return skillDamage;
}

// ---------------------------------


Goblin::Goblin() {
	name = "Goblin";
	health = 5;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 3;
	isDead = false;
}

void Goblin::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int Goblin::AttackPlayer() {
	return skillDamage;
}

// ---------------------------------


HauntingSpirit::HauntingSpirit() {
	name = "HauntingSpirit";
	health = 30;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 7;
	isDead = false;
}

void HauntingSpirit::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int HauntingSpirit::AttackPlayer() {
	return skillDamage;
}

// ---------------------------------


Troll::Troll() {
	name = "Troll";
	health = 45;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 19;
	isDead = false;
}

void Troll::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int Troll::AttackPlayer() {
	return skillDamage;
}

// ---------------------------------


Skeleton::Skeleton() {
	name = "Skeleton";
	health = 50;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 5;
	isDead = false;
}

void Skeleton::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int Skeleton::AttackPlayer() {
	return skillDamage;
}

// ---------------------------------


UndeadWolf::UndeadWolf() {
	name = "UndeadWolf";
	health = 35;
	hasSwiftness = true;
	skillName = "Stealth";
	skillDescription = "Sneak through the shadows.";
	skillDamage = 12;
	isDead = false;
}

void UndeadWolf::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int UndeadWolf::AttackPlayer() {
	return skillDamage;
}
