#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include "IEnemy.h"
#include <conio.h>
#include <memory>

// consider just adding one undiscovered afte rthe last discovered as to prevent player from knowing how many rooms remain, make it feel more mysterious

void UI::DisplayMap(std::vector<std::string> dungeonRooms, int indexStop) {
    gameText.WriteLine("You have made a discovery! Your next dungeon location is revealed before you...\n\n");

    for (int i = 0; i < dungeonRooms.size(); i++) {
        if (i == 4 || i == 8) {
            std::cout << "\n\n"; // formatting
        }
        if (i != 0 && i >= indexStop) {
            if (i != dungeonRooms.size() - 1) {
                gameText.WriteText("Undiscovered...    -->  ");
            } else {
                gameText.WriteText("Undiscovered");
            }
        }
        else {
            if (i != dungeonRooms.size() - 1) {
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

void UI::EnemyAttackPlayer(std::string name, std::string skillName, std::string skillDescription) {
    gameText.WriteLine(name + " attacked with " + skillName + ". " + skillDescription);
}

void UI::DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player) {
    gameText.WriteLine("Now's your chance! What action will you take?!");
    gameText.WriteLine("1)  Attack\n2)  Drink Health Potion\n3)   flee cowardice");
    std::string playerChoice; std::cin >> playerChoice; std::cout << playerChoice;
}

//void UI::DescribeEnemyAttack(std::shared_ptr<IEnemy> enemy) {
//    std::string enemyAttackDescription = "You have been hit for " + std::to_string(enemy->GetSkillDamage()) + " hit points!";
//    gameText.WriteLine(enemyAttackDescription);
//}

void UI::DescribeEnemyAttack(std::shared_ptr<IEnemy> enemy) {

}