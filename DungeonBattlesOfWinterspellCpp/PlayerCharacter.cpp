#pragma once
#include "PlayerCharacter.h"

// Initial assigned attributes: 4, total assigned additional by player 10
PlayerCharacter::PlayerCharacter() :

	name(""),
	health(0),
	xp(0),
	level(1),
	intelligence(0),
	dexterity(0),
	strength(0),
	weapon(nullptr),
	hasSwiftness(false),
	isDead(false)
{
	// Constructor code
}

void PlayerCharacter::CheckIfDead() {
	if (health < 1) {
		health = 0;
		isDead = true;
	}
}

void PlayerCharacter::TakeDamage(int damageTaken) {
	health -= damageTaken;
	CheckIfDead();
}

// Destructor implementation
PlayerCharacter::~PlayerCharacter() {}