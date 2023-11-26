#include "ExploreDungeon.h"
#include "PlayerCharacter.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime> 

ExploreDungeon::ExploreDungeon(std::shared_ptr<DungeonRoom> dungeonRoom, std::shared_ptr<PlayerCharacter> playerCharacter) : dungeonRoom(dungeonRoom), playerCharacter(playerCharacter), ui(ui) {}

void ExploreDungeon::EnterDungeonRoom() {
	ui.DescribeDungeonRoom(dungeonRoom->GetDescription());
	return;
}


// most challenging function yet
std::vector<std::shared_ptr<ICreature>> ExploreDungeon::GenerateTurnOrder() {

	std::vector<std::shared_ptr<IEnemy>> enemiesInRoom = dungeonRoom->GetEnemies();
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

	return turnOrder;
}