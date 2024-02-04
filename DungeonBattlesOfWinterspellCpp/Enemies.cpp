#include "Enemies.h"

Firespitter::Firespitter() {
	name = "Firespitter";
	health = 16;
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

int Firespitter::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 2;
}

// ---------------------------------


DungeonDweller::DungeonDweller() {
	name = "DungeonDweller";
	health = 8;
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

int DungeonDweller::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 4;
}

// ---------------------------------


Goblin::Goblin() {
	name = "Goblin";
	health = 5;
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

int Goblin::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 3;
}

// ---------------------------------


HauntingSpirit::HauntingSpirit() {
	name = "HauntingSpirit";
	health = 30;
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

int HauntingSpirit::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 7;
}

// ---------------------------------


Troll::Troll() {
	name = "Troll";
	health = 45;
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

int Troll::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 19;
}

// ---------------------------------


Skeleton::Skeleton() {
	name = "Skeleton";
	health = 50;
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

int Skeleton::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 5;
}

// ---------------------------------


UndeadWolf::UndeadWolf() {
	name = "UndeadWolf";
	health = 35;
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

int UndeadWolf::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return 12;
}
