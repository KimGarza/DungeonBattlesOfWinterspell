#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "PlayerCharacter.h"
#include "IEnemy.h"
#include "Input.h"
#include "LootItem.h"
#include "ICharacter.h"
#include "GameText.h"

class UI
{
private:
	GameText gameText;
	Input input;

public:
	std::shared_ptr<ICharacter> ChooseClass();
	void DisplayWeaponOptions(std::shared_ptr<ICharacter> characterClass);
	std::shared_ptr<IWeapon> ChooseWeapon(std::shared_ptr<ICharacter> characterClass);
	std::string AttributeAssignment(int pointsRemaining, std::map<std::string, int> attributeJournal);
	int PointsAllocation(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining, std::string specializedAttribute, std::map<std::string, int> attributeJournal);

	std::string DisplayMapMenu(std::vector<std::string> dungeonRooms, int indexStop);
	std::string DisplayRoomSelect(std::vector<std::pair<int, std::string>> availableRooms);
	void DescribeDungeonRoom(std::string description);
	void DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName);
	void NoEnemies();
	bool DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player);
	void DescribeEnemyAttack(std::string name, std::string skillName, std::string skillDescription, int attackDmg);
	bool DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, std::shared_ptr<IWeapon> weapon);
	std::shared_ptr<IEnemy> GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder);
	void HealthRemaining(int healthRemaining);
	void KilledEnemy(std::shared_ptr<IEnemy> enemy);
	void SlainAllEnemies();

	void FoundKey(std::string dungeonName);
	void RoomLocked();

	void LootBegin(std::vector<std::shared_ptr<LootItem>> loot);

};

