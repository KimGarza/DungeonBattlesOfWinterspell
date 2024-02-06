#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include "IEnemy.h"
#include "Characters.h"
#include "IWeapon.h"
#include "Weapons.h"
#include <sstream>
#include <conio.h>
#include <memory>
#include <numeric>
#include <map>

// consider just adding one undiscovered afte rthe last discovered as to prevent player from knowing how many rooms remain, make it feel more mysterious

// Player Creation
std::shared_ptr<ICharacter> UI::ChooseClass() {

   bool selectionComplete = false;
   while (!selectionComplete) {

       gameText.WriteLine("Who are you?");
       gameText.WriteLine("1. wood elf \n2. dwarf \n3. enchantress");

       std::string playerChoice = input.PlayerChoice(std::vector<int> {1, 2, 3});

       if (playerChoice != "") {
           
           if (playerChoice == "1") {
               std::shared_ptr<ICharacter> woodElf = std::make_shared<WoodElf>(); // consider making these unique pointers after test
               return woodElf;
           }
           else if (playerChoice == "2") {
               std::shared_ptr<ICharacter> dwarf = std::make_shared<Dwarf>();
               return dwarf;
           }
           else if (playerChoice == "3") {
               std::shared_ptr<ICharacter> enchantress = std::make_shared<Enchantress>();
               return enchantress;
           }
       }
       else {
           system("cls");
           gameText.WriteLine("Indeed you are a cheeky one aren't you? Please tell me true now, who art thou?");
       }
   }

   return nullptr;
}

std::shared_ptr<IWeapon> UI::ChooseWeapon(std::shared_ptr<ICharacter> characterClass) {

    system("cls");
    bool selectionComplete = false;
    while (!selectionComplete) {

        DisplayWeaponOptions(characterClass);

        std::string playerChoice = input.PlayerChoice(std::vector<int> {1, 2, 3});

        if (playerChoice != "") {
            

            if (std::shared_ptr<WoodElf> woodElf = std::dynamic_pointer_cast<WoodElf>(characterClass)) {
                if (playerChoice == "1") {
                    return std::make_unique<ElvenLongsword>();
                }
                else if (playerChoice == "2") {
                    return std::make_unique<IvoryLongBowAndQuiver>();
                }
                else if (playerChoice == "3") {
                    return std::make_unique<ShortErnestBowAndQuiver>();
                }
            }
            else if (std::shared_ptr<Dwarf> dwarf = std::dynamic_pointer_cast<Dwarf>(characterClass)) {
                if (playerChoice == "1") {
                    return std::make_unique<DoubleBladedAxe>();
                }
                else if (playerChoice == "2") {
                    return std::make_unique<OrnateShortSword>();
                }
                else if (playerChoice == "3") {
                    return std::make_unique<SteelSplitHammer>();
                }
            }
            else if (std::shared_ptr<Enchantress> enchantress = std::dynamic_pointer_cast<Enchantress>(characterClass)) {
                if (playerChoice == "1") {
                    return std::make_unique<DualEtherealDaggers>();
                }
                else if (playerChoice == "2") {
                    return std::make_unique<GnarledBranchStaff>();
                }
                else if (playerChoice == "3") {
                    return std::make_unique<OakCarvedWand>();
                }
            }
        }
        else {
            system("cls");
            gameText.WriteLine("Indeed you are a cheeky one aren't you? Please tell me true now, which weapon is of choice?");
        }
    }

    return nullptr;
}

void UI::DisplayWeaponOptions(std::shared_ptr<ICharacter> characterClass) {

    std::stringstream ss;
    ss << "you r " << characterClass->GetName() << "\nweapon options :" << "\n";
    gameText.WriteLine(ss.str()); 

    int weaponID = 1;
    for (std::string weapon : characterClass->GetWeaponOptions()) {
        
        std::stringstream ss;
        ss << weaponID << ")    " << weapon << "\n";
        std::string weaponOption = ss.str();
        weaponID++;

        gameText.WriteLine(weaponOption);
    }

    std::cout << "\n";
}

std::string UI::AttributeAssignment(int pointsRemaining, std::map<std::string, int> attributeJournal) {
    
    system("cls");

    bool selectionComplete = false;
    while (!selectionComplete) {

        if (pointsRemaining == 10) {
            gameText.WriteLine("Now let's asses your qualities");
        }
        
        std::stringstream ssPrompt;
        ssPrompt << "You have " << pointsRemaining << " points left to allocate into each attribute, please assign your skill points";
        gameText.WriteLine(ssPrompt.str());

        std::stringstream ssAttributes;
        ssAttributes << "1) Intelligence: " << attributeJournal["intellegence"] << "		2) Dexterity: " << attributeJournal["dexterity"] << "		3) Strength: " << attributeJournal["strength"] << "\n";
        gameText.WriteLine(ssAttributes.str());

        gameText.WriteLine("Which attribute would you like to assign points to ?");

        // acts as a guide for correlating user selection dynamically with the attribute related
        std::map<std::string, std::string> selectableAttributes = {
            {"1", "intellegence"},
            {"2", "dexterity"},
            {"3", "strength"}
        };

        std::string playerChoice = input.PlayerChoice(std::vector<int>{ 1, 2, 3 });

        if (playerChoice != "") {
            return playerChoice;
        }
        else {
            system("cls");
            gameText.WriteLine("Please select from available attributes...");
        }
    }
    
}

int UI::PointsAllocation(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining, std::string specializedAttribute, std::map<std::string, int> attributeJournal) {

    system("cls");

    bool playerDeciding = true;
    while (playerDeciding) {

        std::stringstream ssPrompt; ssPrompt << "How many points would you like to spec to " << selectableAttributes[chosenAttribute] << "?\n";
        gameText.WriteLine(ssPrompt.str());

        std::string pointsToAssignStr = input.AttributePoints(pointsRemaining);
        int pointsToAssign = std::stoi(pointsToAssignStr);

        if (pointsToAssignStr != "") {

            // Checking that points do not reduce the naturally occuring 4 pts for users specialized attribute (ex: dwarf has 4 base strength)
            if (selectableAttributes[chosenAttribute] == specializedAttribute && (attributeJournal[selectableAttributes[chosenAttribute]] += pointsToAssign < 4)) {
                
                gameText.WriteLine("Don't certainly underestimate your natural abilities!");
                _getch();

                system("cls");
                gameText.WriteLine("So again...");
                std::stringstream ssPrompt;
                ssPrompt << "You have " << pointsRemaining << " points left to allocate into each attribute, please assign your skill points";
                gameText.WriteLine(ssPrompt.str());
            }
            else {
                return pointsToAssign;
            }
        }
        else {
            gameText.WriteLine("Why don't we try to be reasonable and stay within the bounds of reality?");
            _getch();

            system("cls");
            gameText.WriteLine("So again...");
            std::stringstream ssPrompt;
            ssPrompt << "You have " << pointsRemaining << " points left to allocate into each attribute, please assign your skill points";
            gameText.WriteLine(ssPrompt.str());

        }
    }

    return 0;
}


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

            std::shared_ptr<IWeapon> weapon = player->GetWeapon();

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

bool UI::DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, std::shared_ptr<IWeapon> weapon) {
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