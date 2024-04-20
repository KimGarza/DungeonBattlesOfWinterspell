#include "BattleState.h"

void BattleState::Battle() {

    music_.PlayMusic(L"108 - Mouryou Senki Madara (VRC6) - Ma-Da-Ra.wav");

    SetValues();

    GenerateTurnOrder turnOrder(ctx_);
    turnOrder.Generate();

    ui_.RevealTurnOrder();

    CommenceBattle();

    ctx_->SetState(GameState::Loot);
}

void BattleState::CommenceBattle() {

    while (true) {

        if (slaughteredEnemy_) { // this will be a non nillptr only after the player_ successfully kills an enemy

            auto it = std::find(turnOrder_.begin(), turnOrder_.end(), slaughteredEnemy_); // iterate through to search for enemyToRemove (find it's iterator)

            if (it != turnOrder_.end()) {
                turnOrder_.erase(it);
            }
        }

        if (turnOrder_.size() == 1) {
            ui_.SlainAllEnemy();
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
    bool isPlayerAttacking = ui_.DescribePlayerOptions(player_);

    if (isPlayerAttacking) {

        std::shared_ptr<Enemy> targetedEnemy = ui_.GetEnemyTargetForAttack(player_, turnOrder_);
        bool isEnemyDead = ui_.DescribePlayerAttackOptions(targetedEnemy, player_->GetWeapon());

        if (isEnemyDead) {

            slaughteredEnemy_ = std::static_pointer_cast<ICreature>(targetedEnemy);
            ui_.KilledEnemy(targetedEnemy);

            return;
        }
    }
}

void BattleState::EnemyTurn() {

    int attackDmg = enemy_->AttackPlayer();
    ui_.DescribeEnemyAttack(enemy_, attackDmg);

    // returns the hit points player takes as dmg as int, it can be influenced by player's gear and attributes
    bool checkIfDead = ctx_->GetPlayer()->TakeDamage(attackDmg, 3); // made up enemy accuracy for now
    if (checkIfDead) {
        std::cout << "YOU DIED. GAME OVER.";
        exit(0);
    }
    
    ui_.HealthRemaining(ctx_->GetPlayer()->GetHealth());
}

// must dynamic/down cast IPlace to DungeonRoom since each IMap (DungeonMap) has places/current place represented as IPlace for other polymorphic purposes.
void BattleState::SetValues() {

    currentRoom_ = std::dynamic_pointer_cast<DungeonRoom>(ctx_->GetCurrentPlace());
    turnOrder_ = currentRoom_->GetTurnOrder();
}