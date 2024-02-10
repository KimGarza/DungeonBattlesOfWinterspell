#include "Battle.h"
#include "Battle.h"
#include "IEnemy.h"
#include "ICharacter.h"
#include "PlayerCharacter.h"

Battle::Battle(std::shared_ptr<DungeonRoom> currentRoom) : currentRoom(currentRoom), ui(ui) {}

void Battle::RevealTurnOrder() {
	
	std::vector<std::string> creatureNames;
	
    for (std::shared_ptr<ICreature> creature : currentRoom->GetTurnOrder()) {

        std::shared_ptr<PlayerCharacter> player = std::dynamic_pointer_cast<PlayerCharacter>(creature);
        if (player) {
            creatureNames.push_back("player");
        }

        std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature);
        if (enemy) {
            creatureNames.push_back(enemy->GetName());
        }
    }
    ui.DisplayTurnOrder(creatureNames, currentRoom->GetName());
}

void Battle::CommenceBattle(std::shared_ptr<PlayerCharacter> playerCharacter) {

    std::shared_ptr<ICreature> slaughteredEnemy; // to remove from the list

    bool inBattle = true;
    while (inBattle) {
        std::shared_ptr<ICreature> address = slaughteredEnemy;
        if (slaughteredEnemy) { // this will only be a non nillptr after the player successfully kills an enemy
            
            auto it2 = std::find_if(currentRoom->GetTurnOrder().begin(), currentRoom->GetTurnOrder().end(), [slaughteredEnemy](std::shared_ptr<ICreature>& enemy) {
                return enemy;
             });

            if (it2 != currentRoom->GetTurnOrder().end()) {
                currentRoom->GetTurnOrder().erase(it2);
            }
        }
        if (currentRoom->GetTurnOrder().size() == 1) {
            ui.SlainAllEnemies();
            return;
        }
        for (const auto& creature : currentRoom->GetTurnOrder()) {
            
            std::shared_ptr<PlayerCharacter> player = std::dynamic_pointer_cast<PlayerCharacter>(creature); // down casting
            
            if (player) {

                // 'creature' is of type ICharacter, and 'character' is now a shared_ptr to it
                bool isPlayerAttacking = ui.DescribePlayerOptions(player);

                if (isPlayerAttacking) {
                    std::shared_ptr<IEnemy> targetedEnemy = ui.GetEnemyTargetForAttack(player, currentRoom->GetTurnOrder());
                    bool isEnemyDead = ui.DescribePlayerAttackOptions(targetedEnemy, player->GetWeapon());

                    if (isEnemyDead) {

                        std::shared_ptr<ICreature> enemyToRemove = std::make_shared<ICreature>();
                        slaughteredEnemy = enemyToRemove;

                        ui.KilledEnemy(targetedEnemy);
                        break;
                    }
                }
            }
            else {
                std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature); // down casting
                int attackDmg = enemy->AttackPlayer();
                ui.DescribeEnemyAttack(enemy->GetName(), enemy->GetSkillName(), enemy->GetSkillDescription(), enemy->GetSkillDamage());
                bool checkIfDead = playerCharacter->TakeDamage(attackDmg); // attack player returns the hit points int
                if (checkIfDead) {
                    std::cout << "YOU DIED. GAME OVER.";
                    exit(0);
                } else {
                    ui.HealthRemaining(playerCharacter->GetHealth());
                }
            }
        }
    }
}