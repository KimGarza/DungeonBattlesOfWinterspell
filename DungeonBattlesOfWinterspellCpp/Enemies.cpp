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

int Firespitter::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
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

int DungeonDweller::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
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

int Goblin::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
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

int HauntingSpirit::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
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

int Troll::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
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

int Skeleton::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
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

int UndeadWolf::AttackPlayer() {
	ui.EnemyAttackPlayer(name, skillName, skillDescription);
	return skillDamage;
}
