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
#include <iostream>
#include <cctype>
#include <map>


// Player Creation
std::shared_ptr<ICharacter> UI::ChooseClass() {
    system("cls");

   bool selectionComplete = false;
   while (!selectionComplete) {

       gameText.WriteLine("Pray tell... Who are you?\n");
       gameText.WriteLine("1)  Woodelf \n2)  Dwarf \n3)  Enchantress\n");

       std::string playerChoice = input.PlayerChoice(std::vector<int> {1, 2, 3});

       if (playerChoice != "") {
           
           if (playerChoice == "1") {
               std::shared_ptr<ICharacter> woodElf = std::make_shared<WoodElf>(); // consider making these unique pointers after test
               
               gameText.WriteLine("From the Halls of Miritar, you venture, where the ruins of Myth Drannor await your return."); /**/ _getch();

               return woodElf;
           }
           else if (playerChoice == "2") {
               std::shared_ptr<ICharacter> dwarf = std::make_shared<Dwarf>();
               
               gameText.WriteLine("Aw, what an adoarable gnome!"); /**/ _getch();
               gameText.WriteLine("Okay, okay calm down, I was only jesting!"); /**/ _getch();

               return dwarf;
           }
           else if (playerChoice == "3") {
               std::shared_ptr<ICharacter> enchantress = std::make_shared<Enchantress>();
               
               gameText.WriteLine("You posses the Thaumaturgy of the ancient world within you."); /**/ _getch();

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
    
    gameText.WriteLine("Now, you can't go around fight gobgobs and the undead with just your bare hands..."); /**/ _getch();

    bool selectionComplete = false;
    std::shared_ptr<IWeapon> weapon;

    while (!selectionComplete) {

        DisplayWeaponOptions(characterClass);

        std::string playerChoice = input.PlayerChoice(std::vector<int> {1, 2, 3});

        if (playerChoice != "") {
            
            if (std::shared_ptr<WoodElf> woodElf = std::dynamic_pointer_cast<WoodElf>(characterClass)) {
                if (playerChoice == "1") {
                    weapon = std::make_shared<ElvenLongsword>();
                }
                else if (playerChoice == "2") {
                    weapon = std::make_shared<IvoryLongBowAndQuiver>();
                }
                else if (playerChoice == "3") {
                    weapon = std::make_shared<ShortErnestBowAndQuiver>();
                }
            }
            else if (std::shared_ptr<Dwarf> dwarf = std::dynamic_pointer_cast<Dwarf>(characterClass)) {
                if (playerChoice == "1") {
                    weapon = std::make_shared<DoubleBladedAxe>();
                }
                else if (playerChoice == "2") {
                    weapon = std::make_shared<OrnateShortSword>();
                }
                else if (playerChoice == "3") {
                    weapon = std::make_shared<SteelSplitHammer>();
                }
            }
            else if (std::shared_ptr<Enchantress> enchantress = std::dynamic_pointer_cast<Enchantress>(characterClass)) {
                if (playerChoice == "1") {
                    weapon = std::make_shared<DualEtherealDaggers>();
                }
                else if (playerChoice == "2") {
                    weapon = std::make_shared<GnarledBranchStaff>();
                }
                else if (playerChoice == "3") {
                    weapon = std::make_shared<OakCarvedWand>();
                }
            }
            std::string weaponName = weapon->GetName();
            gameText.WriteLine("The " + weaponName + ", an ardent choice!"); /**/ _getch();
            return weapon;
        }
        else {
            system("cls");
            gameText.WriteLine("Indeed you are a cheeky one aren't you? Please tell me true now, which weapon is of choice?");
        }
    }

    return nullptr;
}

void UI::DisplayWeaponOptions(std::shared_ptr<ICharacter> characterClass) {

    gameText.WriteLine("These are the only weapons fit for you from the armoury, please make your choice.\n");

    int weaponID = 1;
    for (std::string weapon : characterClass->GetWeaponOptions()) {
        
        std::stringstream ss;
        ss << weaponID << ")    " << weapon;
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
            gameText.WriteLine("Now let's asses your qualities...");
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


// Map

std::string UI::DisplayMapMenu(std::vector<std::string> dungeonRooms, int indexStop) {

    system("cls");
    gameText.WriteLine("You have made a discovery! Your next dungeon location is revealed before you...\n\n");

    std::vector<std::pair<int, std::string>> selectableDungeons; /**/ int roomCount;

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

                selectableDungeons.emplace_back((i + 1), dungeonRooms[i]); // creating a menu for the player to select a room to enter
            }
            else {
                gameText.WriteText(dungeonRooms[i]);
            }
        }
    }

    return DisplayRoomSelect(selectableDungeons);

    _getch();
    system("cls");
};

std::string UI::DisplayRoomSelect(std::vector<std::pair<int, std::string>> availableRooms) {

    while (true) {


        for (const auto& room : availableRooms) {
            gameText.WriteLine("\n" + std::to_string(room.first) + ")  " + room.second);
        }

        std::string playerChoice = input.PlayerChoice(availableRooms.size());

        int roomNum = std::stoi(playerChoice);

        // std::find_if with a lambda to find the matching room
        auto selectedRoomIt = std::find_if(availableRooms.begin(), availableRooms.end(), [roomNum](const std::pair<int, std::string>& room) {
            return room.first == roomNum;
        });

        if (selectedRoomIt != availableRooms.end()) {
            std::pair<int, std::string> room = *selectedRoomIt;

            return room.second;
        }
        else {
            gameText.WriteLine("Check your eyes buster");
            _getch();

            system("cls");
            gameText.WriteLine("Please select a dungeon room...");
        }
    }

    return "";
}

void UI::DescribeDungeonRoom(std::string description) {
    
    gameText.WriteLine(description);
    _getch();
    return;
}

void UI::DisplayTurnOrder(std::vector<std::string> creatureNames, std::string dungeonRoomName) {

    system("cls");

    gameText.WriteLine("You discover lurkers in the dark!\n");

    for (char& c : dungeonRoomName) {
        c = std::toupper(c);
    }
    gameText.WriteLine(dungeonRoomName);

    if (!creatureNames.empty()) {
        for (auto it = creatureNames.begin(); it != creatureNames.end(); ++it) {

            gameText.WriteText(*it);

            if (it != creatureNames.end() - 1) {
                gameText.WriteText(", ");
            }
            else {
                gameText.WriteLine("\n");
            }
        }
    }
    _getch();
    return;
}

void UI::NoEnemies() {
    gameText.WriteLine("The shallow wispers in the room are faint and dismal, this room has had blood spilled of your hand this night. Seems safe enough.");
}

bool UI::DescribePlayerOptions(std::shared_ptr<PlayerCharacter> player) {

    system("cls");
    int consoleWidth = 100; // This is an example width, you may get or set this programmatically
    int panelWidth = 20; // The fixed width of your stats panel

    int spaceBeforePanel = consoleWidth - panelWidth;

    // Print the stats panel with the correct spacing
    for (int i = 0; i < spaceBeforePanel; ++i) {
        std::cout << " "; // Print spaces before the panel starts
    }
    std::cout << "| Health: " << "health" << " |\n";

    for (int i = 0; i < spaceBeforePanel; ++i) {
        std::cout << " ";
    }
    std::cout << "| Potions: " << "potionCount" << " |\n";

    // ... print other stats with the same spacing

    gameText.WriteLine("Now's your chance! What action will you do?!");
    gameText.WriteLine("1)  Attack\n2)  Drink Health Potion (" + std::to_string(player->GetHealthPotions()) + " remaining)");

    std::string playerChoice; /**/ std::cin >> playerChoice; 

    while (true) {
        gameText.WriteLine("1)  Attack\n2)  Drink Health Potion (" + std::to_string(player->GetHealthPotions()) + " remaining)");

        if (playerChoice == "1") {
            system("cls");
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
            gameText.WriteLine("That is beyond your capabilities, please estimate yourself!");
            _getch();

            system("cls");
            gameText.WriteLine("Be hasty now!");

            return false;
        }
    }
    return false;
}

std::shared_ptr<IEnemy> UI::GetEnemyTargetForAttack(std::shared_ptr<PlayerCharacter> player, std::vector<std::shared_ptr<ICreature>> turnOrder) {

    bool targetChosen = false;
    while (!targetChosen) {
        system("cls");

        int consoleWidth = 100; // This is an example width, you may get or set this programmatically
        int panelWidth = 20; // The fixed width of your stats panel

        int spaceBeforePanel = consoleWidth - panelWidth;

        // Print the stats panel with the correct spacing
        for (int i = 0; i < spaceBeforePanel; ++i) {
            std::cout << " "; // Print spaces before the panel starts
        }
        std::cout << "| Health: " << "health" << " |\n";

        for (int i = 0; i < spaceBeforePanel; ++i) {
            std::cout << " ";
        }
        std::cout << "| Potions: " << "potionCount" << " |\n";

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

    gameText.WriteLine("\n" + name + " attacked you with " + skillName + ". " + skillDescription + " for " + std::to_string(attackDmg) + " hit points!\n");
    _getch();
}

bool UI::DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, std::shared_ptr<IWeapon> weapon) {
    system("cls");

    int consoleWidth = 100; // This is an example width, you may get or set this programmatically
    int panelWidth = 20; // The fixed width of your stats panel

    int spaceBeforePanel = consoleWidth - panelWidth;

    // Print the stats panel with the correct spacing
    for (int i = 0; i < spaceBeforePanel; ++i) {
        std::cout << " "; // Print spaces before the panel starts
    }
    std::cout << "| Health: " << "health" << " |\n";

    for (int i = 0; i < spaceBeforePanel; ++i) {
        std::cout << " ";
    }
    std::cout << "| Potions: " << "potionCount" << " |\n";

    gameText.WriteLine(std::string("Target is in sights, choose your next move...\n1)  ") + weapon->GetPrimarySkillName() + "\n2)   " + weapon->GetSecondarySkillName());

    std::string playerChoice; /**/ std::cin >> playerChoice;

    bool validChoice = false;
    while (!validChoice) {

        if (playerChoice == "1") {

            system("cls");
            gameText.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining");
            gameText.WriteLine("You have chosen to use " + weapon->GetPrimarySkillName() + ", " + weapon->GetPrimarySkillDescription() + "...");
            _getch();

            int attackDmg = weapon->UseSkillPrimary(); /**/ enemy->TakeDamage(attackDmg);
            gameText.WriteLine("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameText.WriteLine(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining");

            _getch();
            return enemy->GetIsDead();
        }
        else if (playerChoice == "2") {

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
    gameText.WriteLine("You have " + std::to_string(healthRemaining) + "remaining"); /**/ _getch();
}

void UI::KilledEnemy(std::shared_ptr<IEnemy> enemy) {
    gameText.WriteLine("You have slain " + enemy->GetName()); /**/ _getch();
}

void UI::SlainAllEnemies() {
    gameText.WriteLine("You have slain all the scorbles that plague this room"); /**/ _getch();
}

void UI::FoundKey(std::string dungeonName) {
    if (dungeonName == "Tenebrific Depths") {
        gameText.WriteLine("You have filled your pockets with all the glitters of this Foul Tomb, but upon your leave, a strange twinkle catches your glance"); /**/ _getch();
        gameText.WriteLine("A key! Tis metal and skeletal, an iron thing. You should pocket it for safe keeping, in case you will need it later on!"); /**/ _getch();
    }
    else if (dungeonName == "Cursed Abyssal Sanctum") {
        gameText.WriteLine("What's this??"); /**/ _getch();
        gameText.WriteLine("How intriguing... You notice upon stepping upon a particular brick in the floor, that is one quite loose! As you remove it from it's place of settlement you see..."); /**/ _getch();
        gameText.WriteLine("Another key!! But this one is rather unique..."); /**/ _getch();
        gameText.WriteLine("It glimmers of fine iron and with an ornate hand made crest on the handle. A purple gem placed in the center surrounded by small black rustic unpolished rare gemstones.");
        gameText.WriteLine("Surely this is dwarven-make. I would keep that if I were you sire, could open doors of great mytery."); /**/ _getch();
    }
}

void UI::RoomLocked() {
    gameText.WriteLine("The room is locked, you will need a key to enter."); /**/ _getch();
}

void UI::LootBegin() {
    gameText.WriteLine("You peer around, silence. The town of Winterspell inches closer to security by victory of your hand!"); /**/ _getch();
    gameText.WriteLine("You wander through the empty dark decrepid room to fill your pockets, you greedy little thing."); /**/ _getch();
    gameText.WriteLine("You find..."); /**/ _getch();
}