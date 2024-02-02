#include "PlayerCharacter.h"

// Initial assigned attributes: 4, total assigned additional by player 10
// 1. Values passed into construc during playerCharacter creation. The ones xp, level, swift, dead is to be assigned in the assignment section without expecting them to come in
PlayerCharacter::PlayerCharacter() {}
PlayerCharacter::PlayerCharacter(
	// constructor args
	std::string inName,
	int inHealth,
	int inIntelligence,
	int inDexterity,
	int inStrength,
	IWeapon* inWeapon,
	bool hasSwiftness
	// 2. Assigning the priv member variables we declared in header as the in[argValue] and assigning manual initial values to level, xp, etc...
	// In the constructor source, the colon : is used to initiate a member initializer list. It's used to initialize the member variables of a class with values provided to the constructor.
	// After the : is the assignment secition
) : name(inName), health(inHealth), intelligence(inIntelligence), dexterity(inDexterity), strength(inStrength),
weapon(inWeapon), hasSwiftness(hasSwiftness), xp(0), level(1), isDead(false) {}

PlayerCharacter::PlayerCharacter(const PlayerCharacter& other) : name(other.name), health(other.health), intelligence(other.intelligence),
dexterity(other.dexterity), strength(other.strength), weapon(other.weapon),
xp(0), level(1), hasSwiftness(other.hasSwiftness), isDead(false) {}
	// Copy or clone other members if needed

bool PlayerCharacter::TakeDamage(int damageTaken) {
	health -= damageTaken;
	return CheckIfDead();
}

bool PlayerCharacter::CheckIfDead() {
	if (health < 1) {
		health = 0;
		isDead = true;
		return true;
	}
	return false;
}

