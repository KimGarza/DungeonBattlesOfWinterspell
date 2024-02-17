#include "Battle.h"
#include "Battle.h"
#include "IEnemy.h"
#include "ICharacter.h"
#include "PlayerCharacter.h"
#include "Enemies.h"

Battle::Battle(std::vector<std::shared_ptr<ICreature>> turnOrder) : ui(ui), turnOrder(turnOrder) {}
Battle::Battle() {}

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

    std::shared_ptr<ICreature> slaughteredEnemy; // to remove from the list

    bool inBattle = true;
    while (inBattle) {

        if (slaughteredEnemy) { // this will only be a non nillptr after the player successfully kills an enemy

            auto it = std::find(turnOrder.begin(), turnOrder.end(), slaughteredEnemy); // iterate through to search for enemyToRemove (find it's iterator)

            if (it != turnOrder.end()) {
                turnOrder.erase(it);
            }
        }

        if (turnOrder.size() == 1) {
            ui.SlainAllEnemies();
            return;
        }

        for (const auto& creature : turnOrder) {

            std::shared_ptr<PlayerCharacter> player = std::dynamic_pointer_cast<PlayerCharacter>(creature); // down casting

            if (player) {

                // 'creature' is of type ICharacter, and 'character' is now a shared_ptr to it
                bool isPlayerAttacking = ui.DescribePlayerOptions(player);

                if (isPlayerAttacking) {
                    std::shared_ptr<IEnemy> targetedEnemy = ui.GetEnemyTargetForAttack(player, turnOrder);
                    bool isEnemyDead = ui.DescribePlayerAttackOptions(targetedEnemy, player->GetWeapon());
                    if (isEnemyDead) {
                        slaughteredEnemy = targetedEnemy;
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
                }
                else {
                    ui.HealthRemaining(playerCharacter->GetHealth());
                }
            }
        }
    }
}

void Battle::ChangelingFight(std::shared_ptr<PlayerCharacter> playerCharacter) {


    std::shared_ptr<Changeling> changeling = std::make_shared<Changeling>();
    std::shared_ptr<ICreature> player = playerCharacter;
    std::shared_ptr<ICreature> enemy = changeling;

    std::vector<std::shared_ptr <ICreature>> this_turnOrder;
    this_turnOrder.push_back(changeling);
    this_turnOrder.push_back(player);

    while (true) {
        for (const auto& creature : this_turnOrder) {

            std::shared_ptr<PlayerCharacter> player = std::dynamic_pointer_cast<PlayerCharacter>(creature); // down casting
            std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature); // down casting

            if (player) {

                bool isPlayerAttacking = ui.DescribePlayerOptions(player);

                if (isPlayerAttacking) {
                    std::shared_ptr<IEnemy> targetedEnemy = ui.GetEnemyTargetForAttack(player, this_turnOrder);
                    bool isEnemyDead = ui.DescribePlayerAttackOptions(targetedEnemy, player->GetWeapon());
                    if (isEnemyDead) {
                        ui.KilledEnemy(targetedEnemy);
                        break;
                    }
                }
            }
            else {
                int attackDmg = enemy->AttackPlayer();
                ui.DescribeEnemyAttack(enemy->GetName(), enemy->GetSkillName(), enemy->GetSkillDescription(), enemy->GetSkillDamage());
                bool checkIfDead = playerCharacter->TakeDamage(attackDmg); // attack player returns the hit points int
                if (checkIfDead) {
                    std::cout << "YOU DIED. GAME OVER.";
                    exit(0);
                }
                else {
                    ui.HealthRemaining(playerCharacter->GetHealth());
                }
            }
        }
    }
}