#include "ExploreDungeon.h"
#include "DungeonGenerator.h"
#include "PlayerCharacter.h"
#include "AbalaskUI.h"
#include "AbalaskTrader.h"
#include "Battle.h"
#include "Inventory.h"
#include "Story.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime> 

ExploreDungeon::ExploreDungeon(std::shared_ptr<DungeonRoom> currentRoom, std::shared_ptr<PlayerCharacter> playerCharacter) : currentRoom(currentRoom), playerCharacter(playerCharacter), ui(ui) {}

/// <summary>
/// Enter dungeon, if it is locked, it will inform player that it is locked and return. If it is not locked but no enemies are present,
/// that can only mean that the player has vanquished them since upon entering all new dungeon rooms, enemies will generate.
/// If neither of those are true, the dungeon room will newly be described.
/// </summary>
void ExploreDungeon::EnterDungeonRoom() {

	if (currentRoom->GetIsLocked()) {
		ui.RoomLocked();
	}
	else if (currentRoom->GetCompleted()) {
		ui.NoEnemy();
	}
	else {
		ui.DescribeDungeonRoom(currentRoom->GetDescription());
	}
	return;
}


bool ExploreDungeon::ChangelingEvent() {
	ui.DescribeDungeonRoom(currentRoom->GetDescription());

	Story story;
	std::string playerChoice = story.Changeling();
	if (playerChoice == "y") {
		
		return true;
	}
	else {
		return false;
	}
}


void ExploreDungeon::PlayerMenu() {

	while (true) {
		system("cls");

		std::string playerChoice = ui.Inquiry();
		if (playerChoice == "i") {
			Inventory inv;
			inv.OpenInventory(playerCharacter);
		}
		else if (playerChoice == "c") {
			ui.OpenCharacterMenu(playerCharacter);
		}
		else {
			break;
		}
	}
}

bool ExploreDungeon::CheckForKey() {

	std::vector<std::shared_ptr<LootItem>> loot = playerCharacter->GetLoot(); // when utilizing player from member varaible, vector container variant error

	if (currentRoom->GetName() == "Hozwardian Keep") {

		auto key = std::find_if(loot.begin(), loot.end(), [](const std::shared_ptr<LootItem>& requiredKey) {
			return requiredKey->GetName() == "Iron Key";
			});

		return key != loot.end();
	}
	else if (currentRoom->GetName() == "Room of Offerings") {
		auto key = std::find_if(loot.begin(), loot.end(), [](const std::shared_ptr<LootItem>& requiredKey) {
			return requiredKey->GetName() == "Jewel Encrested Key";
			});

		return key != loot.end();
	}
	return false;
	
	ui.RoomLocked();
}

// most challenging function yet but to summarize, simply check for enemy swiftness and add those that are swift to the list first then the rest after
// insert player character in the group of swift or non swift enemies depending on whichever player is but randomize it so player can be anywhere in the group of either
std::vector<std::shared_ptr<ICreature>> ExploreDungeon::GenerateTurnOrder() {

	std::vector<std::shared_ptr<Enemy>> enemiesInRoom = currentRoom->GetEnemy();
	std::vector<std::shared_ptr<ICreature>> turnOrder;

	int swiftEnemy = 0;
	for (std::shared_ptr<Enemy> enemy : enemiesInRoom) { // put swift enemies at front and non at the back
		if (enemy->GetHasSwiftness()) {
			turnOrder.emplace(turnOrder.begin(), enemy);
			swiftEnemy++;
		}
		else {
			turnOrder.emplace(turnOrder.end(), enemy);
		}
	}
	int randomIndex = 0;

	if (playerCharacter->GetHasSwiftness()) {
		if (swiftEnemy == 0) {
			turnOrder.insert(turnOrder.begin(), playerCharacter);
		}
		randomIndex = std::rand() % (swiftEnemy + 1);
		turnOrder.insert(turnOrder.begin() + randomIndex, playerCharacter);
	}
	else {

		if (turnOrder.size() == swiftEnemy) {
			turnOrder.emplace(turnOrder.end(), playerCharacter);
		}
		else {
			// Safe to calculate randomIndex because turnOrder.size() > swiftEnemy
			randomIndex = swiftEnemy + (std::rand() % (turnOrder.size() - swiftEnemy));
			turnOrder.insert(turnOrder.begin() + randomIndex, playerCharacter);
		}
	}

	currentRoom->SetTurnOrder(turnOrder);
	return turnOrder;
}