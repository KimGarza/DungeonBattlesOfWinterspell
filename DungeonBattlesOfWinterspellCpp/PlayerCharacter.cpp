#include "PlayerCharacter.h"

// Initial assigned attributes: 4, total assigned additional by player 10
// 1. Values passed into construc during playerCharacter creation. The ones xp, level, swift, dead is to be assigned in the assignment section without expecting them to come in
PlayerCharacter::PlayerCharacter(
	// constructor args
	std::string inName,
	int inHealth,
	int inIntelligence,
	int inDexterity,
	int inStrength,
	IWeapon* inWeapon
	// 2. Assigning the priv member variables we declared in header as the in[argValue] and assigning manual initial values to level, xp, etc...
	// In the constructor source, the colon : is used to initiate a member initializer list. It's used to initialize the member variables of a class with values provided to the constructor.
	// After the : is the assignment secition
) : name(inName), health(inHealth), intelligence(inIntelligence), dexterity(inDexterity), strength(inStrength),
weapon(inWeapon), xp(0), level(1), hasSwiftness(false), isDead(false) {}

void PlayerCharacter::TakeDamage(int damageTaken) {
	health -= damageTaken;
	CheckIfDead();
}

void PlayerCharacter::CheckIfDead() {
	if (health < 1) {
		health = 0;
		isDead = true;
	}
}
