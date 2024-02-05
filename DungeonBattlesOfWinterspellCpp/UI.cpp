#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include "IEnemy.h"
#include <conio.h>
#include <memory>
#include <map>

// consider just adding one undiscovered afte rthe last discovered as to prevent player from knowing how many rooms remain, make it feel more mysterious

void UI::DisplayMap(std::vector<std::string> dungeonRooms, int indexStop) {
    system("cls");
    gameText.WriteLine("You have made a discovery! Your next dungeon location is revealed before you...\n\n");

    for (int i = 0; i < dungeonRooms.size(); i++) {
        if (i == 4 || i == 8) {
            std::cout << "\n\n"; // formatting
        }
        if (i > indexStop) {
            if (i < dungeonRooms.size() - 1) {
                gameText.WriteText("Undiscovered...    -->  ");
            } else {
                gameText.WriteText("Undiscovered");
            }
        }
        else {
            if (i < dungeonRooms.size() - 1) {
                gameText.WriteText(dungeonRooms[i] + "   -->  ");
            }
            else {
                gameText.WriteText(dungeonRooms[i]);
            }
        }
    }

    _getch();
    system("cls");
};

void UI::DescribeDungeonRoom(std::string description) {
    gameText.WriteLine(description);
    _getch();
    return;
}

void UI::DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName) {
    system("cls");
    gameText.WriteLine(dungeonRoomName + "\n\n");
    for (std::string name : creatureNames) {
        gameText.WriteLine(name);
    }
    _getch();
    return;
}

bool UI::DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player) {
    gameText.WriteLine("Now's your chance! What action will you take?!");
    gameText.WriteLine("1)  Attack\n2)  Drink Health Potion\n3)   flee cowardice");

    std::string playerChoice; /**/ std::cin >> playerChoice; 

    bool validChoice = false;
    while (!validChoice) {

        if (playerChoice == "1") {
            validChoice = true; /**/ system("cls");
            return true;
        } 
        else if (playerChoice == "2") {
            validChoice = true;

            player->DrinkHealthPotion();
            return false;

        }
        else if (playerChoice == "3") {
            validChoice = true;
            return false;

        }
        else {
            gameText.WriteLine("That is beyond your capabilities, please estimate yourself!");
            _getch();

            system("cls");
            return false;
        }
    }
    return false;
}

std::shared_ptr<IEnemy> UI::GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder) {

    bool targetChosen = false;
    while (!targetChosen) {
        system("cls");

        gameText.WriteLine("You have chosen to attack!\nChoose your target\n");

        std::map<std::string, std::shared_ptr<IEnemy>> enemyWithCounter; /**/ int counter = 1; // for display and selection ex: #) enemy name

        for (const auto& creature : turnOrder) {

            std::shared_ptr<IEnemy> enemy = std::dynamic_pointer_cast<IEnemy>(creature); // downcasting
            if (enemy) { // check turn order list for enemies only to print each enemy in a dictionary along side the key of a counter so that when the player chooses which enemy to attack, it is known

                gameText.WriteLine(std::to_string(counter) + ")   " + enemy->GetName());

                enemyWithCounter.emplace(std::to_string(counter), enemy);
                counter++;
            }
        }

        std::string enemySelect; /**/ std::cin >> enemySelect;
        auto selectedEnemy = enemyWithCounter.find(enemySelect); // check player chose an (#) existing enemy

        if (selectedEnemy != enemyWithCounter.end()) {

            IWeapon* weapon = player->GetWeapon();

            std::shared_ptr<IEnemy> value = selectedEnemy->second;

            return value;
        }
        else {
            gameText.WriteLine("You have swung your sword at the air where no presence is detected.... Are you okay?... Let's try that again shall we sire?");
        }
    }
}

void UI::DescribeEnemyAttack(std::string name, std::string skillName, std::string skillDescription, int attackDmg) {
    gameText.WriteLine(name + " attacked with " + skillName + ". " + skillDescription);
    gameText.WriteLine("You have been hit for " + std::to_string(attackDmg) + " hit points!");
}

bool UI::DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, IWeapon* weapon) {
    system("cls");

    gameText.WriteLine(std::string("Target in sights, choose your skill\n1)  ") + weapon->GetPrimarySkillName() + "\n2)   " + weapon->GetSecondarySkillName());

    std::string playerChoice; /**/ std::cin >> playerChoice;
    bool validChoice = false;
    while (!validChoice) {
        if (playerChoice == "1") {
            validChoice = true;
            system("cls");
            gameText.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining");
            gameText.WriteLine("You have chosen to use " + weapon->GetPrimarySkillName() + ", " + weapon->GetPrimarySkillDescription());
            _getch();
            int attackDmg = weapon->UseSkillPrimary(); /**/ enemy->TakeDamage(attackDmg);
            gameText.WriteLine("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameText.WriteLine(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining");
            return enemy->GetIsDead();

            _getch();

        }
        else if (playerChoice == "2") {
            validChoice = true;
            system("cls");
            gameText.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining");
            gameText.WriteLine("You have chosen to use " + weapon->GetSecondarySkillName() + ", " + weapon->GetSecondarySkillDescription());
            _getch();
            int attackDmg = weapon->UseSkillSecondary(); /**/ enemy->TakeDamage(attackDmg);
            gameText.WriteLine("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameText.WriteLine(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining");
            _getch();
            return enemy->GetIsDead();

        }
        return false;
    }
    return false;

}

void UI::HealthRemaining(int healthRemaining) {
    gameText.WriteLine("You have " + std::to_string(healthRemaining) + "remaining");
}

void UI::KilledEnemy(std::shared_ptr<IEnemy> enemy) {
    gameText.WriteLine("You have slain " + enemy->GetName());
}

void UI::SlainAllEnemies() {
    gameText.WriteLine("You have slain all the scorbles that plague this room");
    _getch();
}