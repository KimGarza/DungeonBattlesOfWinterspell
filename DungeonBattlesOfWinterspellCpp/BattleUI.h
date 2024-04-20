#pragma once
#include "GameContext.h"
#include "GameText.h"
#include <vector>
#include <string>
#include <memory>
#include <conio.h>

class BattleUI
{
private:
	std::shared_ptr<GameContext> ctx_;
	std::vector<std::shared_ptr<ICreature>> turnOrder_;
	GameText gameTxt_;

public:
	BattleUI(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void RevealTurnOrder();
	void DisplayTurnOrder(std::vector<std::string> creatureNames);
	void SlainAllEnemy();
	bool DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player);
	std::shared_ptr<Enemy> GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder);
	bool DescribePlayerAttackOptions(std::shared_ptr<Enemy> enemy, std::shared_ptr<Weapon> weapon);
	void KilledEnemy(std::shared_ptr<Enemy> enemy);
	void DescribeEnemyAttack(std::shared_ptr<Enemy> enemy, int attackDmg);
	void HealthRemaining(int healthRemaining);
};

