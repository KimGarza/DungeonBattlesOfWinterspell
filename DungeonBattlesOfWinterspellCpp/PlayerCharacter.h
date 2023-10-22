#ifndef IPLAYERCHARACTER_H
#define IPLAYERCHARACTER_H

#include <vector>
#include <string>
#include "IWeapon.h"
#include "InvItem.h"

class PlayerCharacter {
public:
	PlayerCharacter();

	std::string GetName() { return name; }
	int GetXP() { return xp; }
	int GetLevel() { return level; }
	int GetHealth() { return health; }
	int GetIntelligence() { return intelligence; }
	int GetDexterity() { return dexterity; }
	int GetStrength() { return strength; }
	IWeapon GetWeapon() { return weapon; }
	bool GetHasSwiftness() { return hasSwiftness; }
	bool GetIsDead() { return isDead; }

	void CheckIfDead() {};

private:
	std::string name;
	int health;
	int xp;
	int level;
	int intelligence;
	int dexterity;
	int strength;
	IWeapon weapon;
	bool hasSwiftness;
	bool isDead;
	std::vector<InvItem*> inventory;
};
#endif // IPLAYERCHARACTER_H