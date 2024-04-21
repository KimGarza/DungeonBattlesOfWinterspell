#include "TurnOrder.h"
#include "Enemy.h"
#include <vector>
#include <memory>

// creates vector of creatures including all enemies in room and player organized randomly 
// but swift creatures are at beginning of list
void TurnOrder::Generate() {

	std::vector<std::shared_ptr<Enemy>> enemiesInRoom = room_->GetEnemy();
	std::vector<std::shared_ptr<ICreature>> turnOrder;

	int swiftEnemy = 0;
	int randomIndex = 0;

	// enemy turn order
	for (std::shared_ptr<Enemy> enemy : enemiesInRoom) { // put swift enemies at front and non at the back
		if (enemy->GetHasSwiftness()) {
			turnOrder.emplace(turnOrder.begin(), enemy);
			swiftEnemy++;
		}
		else {
			turnOrder.emplace(turnOrder.end(), enemy);
		}
	}

	// shuffling in player where it make sense according to swiftness
	if (player_->GetHasSwiftness()) {
		if (swiftEnemy == 0) {
			turnOrder.insert(turnOrder.begin(), player_);
		}
		randomIndex = std::rand() % (swiftEnemy + 1);
		turnOrder.insert(turnOrder.begin() + randomIndex, player_);
	}
	else {

		if (turnOrder.size() == swiftEnemy) {
			turnOrder.emplace(turnOrder.end(), player_);
		}
		else {
			// Safe to calculate randomIndex because turnOrder.size() > swiftEnemy
			randomIndex = swiftEnemy + (std::rand() % (turnOrder.size() - swiftEnemy));
			turnOrder.insert(turnOrder.begin() + randomIndex, player_);
		}
	}

	room_->SetTurnOrder(turnOrder);
}
