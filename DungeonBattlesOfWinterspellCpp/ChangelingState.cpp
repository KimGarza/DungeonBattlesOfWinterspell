#include "ChangelingState.h"

void ChangelingState::ChangelingEncounter() {

    music_.PlayMusic(L"8bit-chikadou.wav");

    if (PlayerEngages()) {

        BattleChangeling();
    }

    ctx_->SetState(GameState::Battle);

}

bool ChangelingState::PlayerEngages() {

    ui_.DescribeDungeonRoom(ctx_->GetCurrentPlace()->GetDescription());

    std::string playerChoice = story.Changeling();
    if (playerChoice == "y") {

        return true;
    }

    return false;
}

void ChangelingState::BattleChangeling() {

    // factory method
    changeling_ = std::make_shared<Enemy>(
        "Changeling", 40, true, "Gutting Slash",
        "Slashes with needle like claws and a precise swipe to a foes area of most vunerabile.", 14);

    std::shared_ptr<ICreature> changeling = changeling_;
    std::shared_ptr<ICreature> player = ctx_->GetPlayer();

    std::vector<std::shared_ptr <ICreature>> turnOrder;

    turnOrder.push_back(changeling);
    turnOrder.push_back(player);

    while (true) {
        for (const auto& creature : turnOrder) {

            std::shared_ptr<PlayerCharacter> playerChar = std::dynamic_pointer_cast<PlayerCharacter>(creature);

            if (!changeling_->GetIsDead()) {
                if (playerChar) {
                    PlayerTurn();
                }
                else {
                    EnemyTurn();
                }
            }
            else {
                return;
            }
        }
    }
}

void ChangelingState::PlayerTurn() {

    bool isPlayerAttacking = battleUI_.DescribePlayerOptions(ctx_->GetPlayer());
    if (isPlayerAttacking) {

        bool isEnemyDead = battleUI_.DescribePlayerAttackOptions(changeling_, ctx_->GetPlayer()->GetWeapon());

        if (isEnemyDead) {

            battleUI_.KilledEnemy(changeling_);
            return;
        }
    }
}

void ChangelingState::EnemyTurn() {

    int attackDmg = changeling_->AttackPlayer();

    bool checkIfDead = ctx_->GetPlayer()->TakeDamage(attackDmg, 3); // attack player returns the hit points int

    if (checkIfDead) {
        std::cout << "YOU DIED. GAME OVER.";
        exit(0);
    }
    else {
        battleUI_.HealthRemaining(ctx_->GetPlayer()->GetHealth());
    }
}