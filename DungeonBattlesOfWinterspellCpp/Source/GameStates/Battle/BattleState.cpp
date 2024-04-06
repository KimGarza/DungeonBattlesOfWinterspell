#include "..\..\..\Headers\GameStates\Battle\BattleState.h"

void BattleState::Battle() {

    music_.PlayMusic(L"108 - Mouryou Senki Madara (VRC6) - Ma-Da-Ra.wav");

    turnOrder_ = ctx_->GetCurrentRoom()->GetTurnOrder();

    RevealTurnOrder();
    CommenceBattle();

    ctx_->SetState(GameState::Loot);
}

void BattleState::RevealTurnOrder() {

    std::vector<std::string> orderedTurns;

    for (std::shared_ptr<ICreature> creature : ctx_->GetCurrentRoom()->GetTurnOrder()) {

        std::shared_ptr<PlayerCharacter> player_ = std::dynamic_pointer_cast<PlayerCharacter>(creature);
        if (player_) {
            orderedTurns.push_back("*You*");
        }

        std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(creature);
        if (enemy) {
            orderedTurns.push_back(enemy->GetName());
        }
    }

    ui.DisplayTurnOrder(orderedTurns, ctx_->GetCurrentRoom()->GetName());
}

void BattleState::CommenceBattle() {

    std::vector<std::shared_ptr<ICreature>> turnOrder_ = ctx_->GetCurrentRoom()->GetTurnOrder();

    while (true) {

        if (slaughteredEnemy_) { // this will be a non nillptr only after the player_ successfully kills an enemy

            auto it = std::find(turnOrder_.begin(), turnOrder_.end(), slaughteredEnemy_); // iterate through to search for enemyToRemove (find it's iterator)

            if (it != turnOrder_.end()) {
                turnOrder_.erase(it);
            }
        }

        if (turnOrder_.size() == 1) {
            ui.SlainAllEnemy();
            return;
        }

        for (const auto& creature : turnOrder_) {

            player_ = std::dynamic_pointer_cast<PlayerCharacter>(creature); // down casting

            if (player_) {
                PlayerTurn();
            }
            else {

                enemy_ = std::dynamic_pointer_cast<Enemy>(creature); // down casting

                EnemyTurn();
            }
        }
    }
}

void BattleState::PlayerTurn() {

    // 'creature' is of type PlayerCharacter, and 'player_' is now a shared_ptr to it
    bool isPlayerAttacking = ui.DescribePlayerOptions(player_);

    if (isPlayerAttacking) {

        std::shared_ptr<Enemy> targetedEnemy = ui.GetEnemyTargetForAttack(player_, turnOrder_);
        bool isEnemyDead = ui.DescribePlayerAttackOptions(targetedEnemy, player_->GetWeapon());

        if (isEnemyDead) {

            slaughteredEnemy_ = std::static_pointer_cast<ICreature>(targetedEnemy);
            ui.KilledEnemy(targetedEnemy);

            return;
        }
    }
}

void BattleState::EnemyTurn() {

    int attackDmg = enemy_->AttackPlayer();
    ui.DescribeEnemyAttack(enemy_, attackDmg);

    // returns the hit points player takes as dmg as int, it can be influenced by player's gear and attributes
    bool checkIfDead = ctx_->GetPlayer()->TakeDamage(attackDmg, 3); // made up enemy accuracy for now
    if (checkIfDead) {
        std::cout << "YOU DIED. GAME OVER.";
        exit(0);
    }
    
    ui.HealthRemaining(ctx_->GetPlayer()->GetHealth());
}