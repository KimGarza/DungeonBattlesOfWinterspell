#include "ExploreDungeon.h"
#include "PlayerCharacter.h"
#include "Inventory.h"
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
	system("cls");

	if (ui.OpenInventoryInquiry()) {
		Inventory inv;
		inv.OpenInventory(playerCharacter);
	}

	if (currentRoom->GetIsLocked()) {
		ui.RoomLocked();
	}
	else if (currentRoom->GetCompleted()) {
		ui.NoEnemies();
	}
	else {
		ui.DescribeDungeonRoom(currentRoom->GetDescription());
	}
		
	return;
}

// most challenging function yet but to summarize, simply check for enemy swiftness and add those that are swift to the list first then the rest after
// insert player character in the group of swift or non swift enemies depending on whichever player is but randomize it so player can be anywhere in the group of either
std::vector<std::shared_ptr<ICreature>> ExploreDungeon::GenerateTurnOrder() {

	std::vector<std::shared_ptr<IEnemy>> enemiesInRoom = currentRoom->GetEnemies();
	std::vector<std::shared_ptr<ICreature>> turnOrder;

	int swiftEnemies = 0;
	for (std::shared_ptr <IEnemy> enemy : enemiesInRoom) { // put swift enemies at front and non at the back
		if (enemy->GetHasSwiftness()) {
			turnOrder.emplace(turnOrder.begin(), enemy);
			swiftEnemies++;
		}
		else {
			turnOrder.push_back(enemy);
		}
	}
	int randomIndex = 0;

	if (playerCharacter->GetHasSwiftness()) {
		if (swiftEnemies == 0) {
			turnOrder.insert(turnOrder.begin(), playerCharacter);
		}
		randomIndex = std::rand() % (swiftEnemies + 1);
		turnOrder.insert(turnOrder.begin() + randomIndex, playerCharacter);
	}
	else {

		if (turnOrder.size() == swiftEnemies) {
			turnOrder.push_back(playerCharacter);
		}
		else {
			// Safe to calculate randomIndex because turnOrder.size() > swiftEnemies
			randomIndex = swiftEnemies + (std::rand() % (turnOrder.size() - swiftEnemies));
			turnOrder.insert(turnOrder.begin() + randomIndex, playerCharacter);
		}
	}

	currentRoom->SetCurrentTurnOrder(turnOrder);
	return turnOrder;
}