#include "Battle.h"
#include "Battle.h"
#include "IEnemy.h"
#include "ICharacter.h"
#include "PlayerCharacter.h"

Battle::Battle(std::vector<std::shared_ptr<ICreature>> turnOrder) : ui(ui), turnOrder(turnOrder) {}

void Battle::RevealTurnOrder(std::vector<std::shared_ptr<ICreature>> turnOrder, std::string dungeonRoomName) {
	
	std::vector<std::string> creatureNames;
	
    for (std::shared_ptr<ICreature> creature : turnOrder) {

        std::shared_ptr<PlayerCharacter> player = std::dynamic_pointer_cast<PlayerCharacter>(creature);
        if (player) {
            creatureNames.push_back("player");
        }

        std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature);
        if (enemy) {
            creatureNames.push_back(enemy->GetName());
        }
    }
    ui.DisplayTurnOrder(creatureNames, dungeonRoomName);
}

void Battle::CommenceBattle(std::shared_ptr<PlayerCharacter> playerCharacter) {

    bool inBattle = true;
    while (inBattle) {
        for (const auto& creature : turnOrder) {
            std::shared_ptr<PlayerCharacter> player = std::dynamic_pointer_cast<PlayerCharacter>(creature);
            if (player) {
                // 'creature' is of type ICharacter, and 'character' is now a shared_ptr to it
                ui.DescribePlayerOptions(player);
            }
            else {
                std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature); // down casting
                bool checkIfDead = playerCharacter->TakeDamage(enemy->AttackPlayer()); // attack player returns the hit points int
            }
        }
    }
}