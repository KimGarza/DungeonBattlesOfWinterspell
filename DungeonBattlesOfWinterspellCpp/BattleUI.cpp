#include "BattleUI.h"

void BattleUI::RevealTurnOrder() {

    std::shared_ptr<DungeonRoom> room_ = std::dynamic_pointer_cast<DungeonRoom>(ctx_->GetCurrentPlace());
    turnOrder_ = room_->GetTurnOrder();

    std::vector<std::string> creatureNames; // string list of the names of creatures

    for (std::shared_ptr<ICreature> creature : turnOrder_) {

        std::shared_ptr<PlayerCharacter> player_ = std::dynamic_pointer_cast<PlayerCharacter>(creature);
        if (player_) {
            creatureNames.push_back("*You*");
        }

        std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(creature);
        if (enemy) {
            creatureNames.push_back(enemy->GetName());
        }
    }

    DisplayTurnOrder(creatureNames);
}

void BattleUI::DisplayTurnOrder(std::vector<std::string> creatureNames) {
    system("cls");

    gameTxt_.WriteLine("You discover lurkers in the dark!\n");

    std::string name = ctx_->GetCurrentPlace()->GetName();
    for (char& c : name) {
        c = std::toupper(c);
    }
    gameTxt_.WriteText(name);

    if (!creatureNames.empty()) {
        for (auto it = creatureNames.begin(); it != creatureNames.end(); ++it) {

            gameTxt_.WriteText(*it);

            if (it != creatureNames.end() - 1) {
                gameTxt_.WriteText(", ");
            }
            else {
                gameTxt_.WriteLine("\n");
            }
        }
    }
    _getch();
    return;
}

void BattleUI::SlainAllEnemy() {
    gameTxt_.WriteLineInput("You have slain all the scorbles that plague this room");
}

bool BattleUI::DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player) {

    system("cls");
    int consoleWidth = 100; // This is an example width, you may get or set this programmatically
    int panelWidth = 20; // The fixed width of your stats panel

    int spaceBeforePanel = consoleWidth - panelWidth;

    // Print the stats panel with the correct spacing
    for (int i = 0; i < spaceBeforePanel; ++i) {
        std::cout << " "; // Print spaces before the panel starts
    }
    std::cout << "| Health: " << std::to_string(player->GetHealth()) << " |\n";

    // ... print other stats with the same spacing

    gameTxt_.WriteLine("Now's your chance! What action will you do?!");


    while (true) {
        gameTxt_.WriteLine("1)  Attack\n2)  Drink Health Potion (" + std::to_string(player->GetHealthPotions()) + ")\n");
        std::string playerChoice; /**/ std::cin >> playerChoice;  // why not using input checker here


        if (playerChoice == "1") {

            return true;
        }
        else if (playerChoice == "2") {

            player->DrinkHealthPotion();
            return false;

        }
        else if (playerChoice == "3") {
            return false;

        }
        else {
            gameTxt_.WriteLineInput("\nNow's not the time for dobbling about!");

            system("cls");
            gameTxt_.WriteLine("Be hasty now!\n");
            gameTxt_.WriteLine("What action will you do?!\n");

        }
    }
    return false;
}


std::shared_ptr<Enemy> BattleUI::GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder) {

    while (true) {
        system("cls");

        int consoleWidth = 100; // This is an example width, you may get or set this programmatically
        int panelWidth = 20; // The fixed width of your stats panel

        int spaceBeforePanel = consoleWidth - panelWidth;

        // Print the stats panel with the correct spacing
        for (int i = 0; i < spaceBeforePanel; ++i) {
            std::cout << " "; // Print spaces before the panel starts
        }
        std::cout << "Health: " << std::to_string(player->GetHealth());

        gameTxt_.WriteLine("\nYou have chosen to attack! \n***Choose your target***\n");

        std::map<std::string, std::shared_ptr<Enemy>> enemyWithCounter; /**/ int counter = 1; // for display and selection ex: #) enemy name

        for (const auto& creature : turnOrder) {

            std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(creature); // downcasting
            if (enemy) { // check turn order list for enemies only to print each enemy in a dictionary along side the key of a counter so that when the player chooses which enemy to attack, it is known

                gameTxt_.WriteLine(std::to_string(counter) + ")   " + enemy->GetName());

                enemyWithCounter.emplace(std::to_string(counter), enemy);
                counter++;
            }
        }

        std::string enemySelect; /**/ std::cin >> enemySelect;
        auto selectedEnemy = enemyWithCounter.find(enemySelect); // check player chose an (#) existing enemy

        if (selectedEnemy != enemyWithCounter.end()) {

            std::shared_ptr<Weapon> weapon = player->GetWeapon();

            std::shared_ptr<Enemy> value = selectedEnemy->second;

            return value;
        }
        else {
            gameTxt_.WriteLine("You have swung your sword at the air where no presence is detected.... Are you okay?... Let's try that again shall we sire?");
        }
    }
}


bool BattleUI::DescribePlayerAttackOptions(std::shared_ptr<Enemy> enemy, std::shared_ptr<Weapon> weapon) {
    system("cls");

    gameTxt_.WriteLine(std::string("Target is in sights, choose your next move...\n\n1)  ") + weapon->GetPrimarySkillName() + "\n2)  " + weapon->GetSecondarySkillName());

    std::string playerChoice; /**/ std::cin >> playerChoice;

    while (true) {

        if (playerChoice == "1") {

            system("cls");
            gameTxt_.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED
            gameTxt_.WriteLine("You used " + weapon->GetPrimarySkillName() + ", " + weapon->GetPrimarySkillDescription() + "...\n");

            gameTxt_.WriteLine("onamonapea that represents attack");

            int attackDmg = weapon->UseSkillPrimary(); /**/ enemy->TakeDamage(attackDmg);
            //consider accuracy, chance to hit, evasion ratings

            gameTxt_.WriteLineInput("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameTxt_.WriteLineInput(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED

            return enemy->GetIsDead();
        }
        else if (playerChoice == "2") {

            system("cls");

            gameTxt_.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED
            gameTxt_.WriteLine("You have chosen to use " + weapon->GetSecondarySkillName() + ", " + weapon->GetSecondarySkillDescription());

            gameTxt_.WriteLine("onamonapea that represents attack");

            int attackDmg = weapon->UseSkillPrimary(); /**/ enemy->TakeDamage(attackDmg);
            //consider accuracy, chance to hit, evasion ratings

            gameTxt_.WriteLineInput("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameTxt_.WriteLineInput(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED

            return enemy->GetIsDead();
        }
    }

    return false;

}


void BattleUI::KilledEnemy(std::shared_ptr<Enemy> enemy) {
    if (enemy->GetName() == "Changeling") {

        gameTxt_.WriteLineInput("You have slain the evil " + enemy->GetName());
        gameTxt_.WriteLineInput("He was a dispicable devil. Good to be rid of him, knighted you should be, at the King's Palace! On the fourth night of Dune Riah.");
        return;
    }
    gameTxt_.WriteLineInput("You have slain " + enemy->GetName());
}

void BattleUI::DescribeEnemyAttack(std::shared_ptr<Enemy> enemy, int attackDmg) {

    // maybe have enemies on side panel
    system("cls");
    gameTxt_.WriteLineInput(enemy->GetName() + " attacked you with " + enemy->GetSkillName() + ", " + enemy->GetSkillDescription() + " which hits for " + std::to_string(attackDmg) + " hit points!\n");
}

void BattleUI::HealthRemaining(int healthRemaining) {
    gameTxt_.WriteLine("You have " + std::to_string(healthRemaining) + "remaining TO BE REMOVED"); // ** TO BE REMOVED

}