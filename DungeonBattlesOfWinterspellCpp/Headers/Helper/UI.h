#pragma once
#include "..\Game\GameContext.h"
#include "..\Game\GameText.h"
#include "..\Helper\UI.h"
#include "..\Actors\PlayerCharacter.h"
#include "..\Actors\Enemy.h"
#include "..\Actors\LootItem.h"
#include "..\Actors\Character.h"
#include "Input.h"
#include <vector>
#include <memory>
#include <map>
#include <string>

class UI
{
private:
	GameText gameText;
	Input input;

public:

	std::string DisplayMapMenu(std::vector<std::string> dungeonRooms, int indexStop);
	std::string DisplayRoomSelect(std::vector<std::pair<int, std::string>> availableRooms);
	void DescribeDungeonRoom(std::string description);
	void DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName);
	void NoEnemy();
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

