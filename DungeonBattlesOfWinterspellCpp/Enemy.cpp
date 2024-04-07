#include "Enemy.h"

Enemy::Enemy(std::string name, int health, bool hasSwiftness,
	std::string skillName, std::string skillDescription,
	int skillDamage)
	: name(name), health(health), hasSwiftness(hasSwiftness), skillName(skillName), 
	skillDescription(skillDescription), skillDamage(skillDamage), isDead(false) {}


void Enemy::TakeDamage(int hitPoints) {
	health -= hitPoints;
	if (health <= 0) {
		isDead = true;
	}
}

int Enemy::AttackPlayer() {
	return skillDamage;
}