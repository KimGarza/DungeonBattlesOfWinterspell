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
	void EnemyAttackPlayer(std::string  name, std::string skillName, std::string skillDescription);
	void DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder);
	void DescribeEnemyAttack(std::shared_ptr<IEnemy> enemy);
	void DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, IWeapon* weapon);
};

