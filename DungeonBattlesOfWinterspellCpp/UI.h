#pragma once
#include <vector>
#include <memory>
#include <string>
#include "PlayerCharacter.h"
#include "IEnemy.h"
#include "GameText.h"

class UI
{
private:
	GameText gameText;

public:
	void DisplayMap(std::vector<std::string> dungeonRooms, int indexStop);
	void DescribeDungeonRoom(std::string description);
	void DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName);
	bool DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player);
	void DescribeEnemyAttack(std::string name, std::string skillName, std::string skillDescription, int attackDmg);
	bool DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, IWeapon* weapon);
	std::shared_ptr<IEnemy> GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder);
	void HealthRemaining(int healthRemaining);
	void KilledEnemy(std::shared_ptr<IEnemy> enemy);
	void SlainAllEnemies();
};

