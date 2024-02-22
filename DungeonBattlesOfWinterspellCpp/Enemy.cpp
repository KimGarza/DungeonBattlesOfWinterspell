#include "Enemy.h"

Enemy::Enemy(std::string name, int health, bool hasSwiftness,
	int accuracyRating, int armour, int evasionRating,
	std::string skillName, std::string skillDescription,
	int skillDamage)
	: name_(name), health_(health), hasSwiftness_(hasSwiftness), 
	accuracyRating_(accuracyRating), armour_(armour), evasionRating_(evasionRating), skillName_(skillName),
	skillDescription_(skillDescription), skillDamage_(skillDamage), isDead_(false) {}


void Enemy::TakeDamage(int hitPoints) {
	health_ -= hitPoints;
	if (health_ <= 0) {
		isDead_ = true;
	}
}

int Enemy::AttackPlayer() {
	return skillDamage_;
}