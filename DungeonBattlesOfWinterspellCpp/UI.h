#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "PlayerCharacter.h"
#include "Enemy.h"
#include "Input.h"
#include "LootItem.h"
#include "Character.h"
#include "GameText.h"

class UI
{
private:
	GameText gameText;
	Input input;

public:

	bool DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player);
	void DescribeEnemyAttack(std::shared_ptr<Enemy> enemy, int attackDmg);
	bool DescribePlayerAttackOptions(std::shared_ptr<Enemy> enemy, std::shared_ptr<Weapon> weapon);
	std::shared_ptr<Enemy> GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder);
	void HealthRemaining(int healthRemaining);
	void KilledEnemy(std::shared_ptr<Enemy> enemy);
	void SlainAllEnemy();

	void FoundKey(std::string dungeonName);
	void RoomLocked();

	void LootBegin(std::vector<std::shared_ptr<LootItem>> loot);
	std::shared_ptr<LootItem> DisplayInventoryMenu(std::vector<std::shared_ptr<LootItem>> playersLoot);
	void CannotUseItem();
	void PotionItemMenu();
	void ItemMenu(std::shared_ptr<LootItem> item, std::shared_ptr<PlayerCharacter> playerCharacter);
	std::string Inquiry();
	void AlreadyEquiptItem();
	void OpenCharacterMenu(std::shared_ptr<PlayerCharacter> playerCharacter);


};

