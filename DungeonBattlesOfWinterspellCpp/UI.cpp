#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include "IEnemy.h"
#include "CharacterFactory.h"
#include "IWeapon.h"
#include "Character.h"
#include "Weapons.h"
#include <sstream>
#include <conio.h>
#include <memory>
#include <numeric>
#include <iostream>
#include <cctype>
#include <map>


// Player Creation
std::string UI::ChooseClass() {
    system("cls");

   while (true) {

       gameText.WriteLine("Pray tell... Who are you ?\n");
       gameText.WriteLine("1)  Woodelf \n2)  Dwarf \n3)  Enchantress\n");

       std::string playerChoice; /**/ std::cin >> playerChoice;

       if (playerChoice != "") {
           
           if (playerChoice == "1" || playerChoice == "2" || playerChoice == "3") {

               return playerChoice;
           }
       }
       else {
           system("cls");
           gameText.WriteLine("Indeed you are a cheeky one aren't you? Please tell me true now, who art thou?");
       }
   }
}

void UI::CharacterSelected(std::shared_ptr<Character> characterClass) {

    if (characterClass->GetName() == "Wood Elf") {
        gameText.WriteLineInput("From the Halls of Miritar, you venture, where the ruins of Myth Drannor await your return.");
    }
    else if (characterClass->GetName() == "Dwarf") {
        gameText.WriteLineInput("Alas! An adoarable gnome with cheeks of rose fire!");
        gameText.WriteLineInput("Yes, Yes chillith Master, I was only jesting!");
    }
    else if (characterClass->GetName() == "Enchantress") {
        gameText.WriteLineInput("You posses the Thaumaturgy of the ancient world within you.");

    }
}

std::string UI::ChooseWeapon(std::shared_ptr<Character> characterClass) {

    system("cls");

    gameText.WriteLine("Ah! Now then. Though cannot see trechors below and fight gobgobs with just thy bare mitts!");
    gameText.WriteLineInput("Weapon of choice good sir ?");
    gameText.WriteLine("These are the only weapons fit for yee from the armoury, if it please thee, make thy choice.\n");

    while (true) {

        DisplayWeaponOptions(characterClass);

        if (playerChoice == "1" || playerChoice == "2" || playerChoice == "3") {

            return playerChoice;
        }
        else {
            system("cls");
            gameText.WriteLine("Indeed you are a cheeky one aren't you? Please tell me true now, which weapon is of choice?");
        }
    }
}

void UI::DisplayWeaponOptions(std::shared_ptr<Character> characterClass) {
    system("cls");

    gameText.WriteLine("These are the only weapons fit for yee from the armoury, if it please thee, make your choice.\n");

    int weaponID = 1;
    for (std::string weaponName : characterClass->GetWeaponOptions()) {

        gameText.WriteLineInput(std::to_string(weaponID) + ")   " + weaponName);
        weaponID++;
    }

    std::cout << "\n";
}

std::string UI::WeaponSelected(std::string weaponName) {
    gameText.WriteLineInput("The " + weaponName + ", an ardent choice!");
}




std::string UI::AttributeAssignment(int pointsRemaining, std::map<std::string, int> attributeJournal) {
    system("cls");

    bool selectionComplete = false;
    while (!selectionComplete) {

        if (pointsRemaining == 10) {
            gameText.WriteLineInput("Now shall we asses thine qualities ?");
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
                
                gameText.WriteLine("Forswear not to underestimate your natural abilities!");
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
            gameText.WriteLine("Shan't we try to be reasonable, and stay thee within the bounds of reality?");
            _getch();

            system("cls");
            gameText.WriteLine("So again...");
            std::stringstream ssPrompt;
            ssPrompt << "You have " << pointsRemaining << " points left to allocate into each attribute, please assign your skill points";
            gameText.WriteLine(ssPrompt.str());

        }
    }

    system("cls");
    return 0;
}


// Map
std::string UI::DisplayMapMenu(std::vector<std::string> dungeonRooms, int indexStop) {

    gameText.WriteLine("Map of Winterspell's Dungeon Cells");
    std::cout << " ____________________________________\n\n";

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

                selectableDungeons.emplace_back((i + 1), dungeonRooms[i]);
            }
        }
    }

    std::cout << "\n\n";

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
            gameText.WriteLine("Check your eyes buster!");
            system("cls");
            gameText.WriteLine("Please select a dungeon room");
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
    gameText.WriteLine("The shallow wispers in the room are faint and dismal, this room has had blood spilled of your hand this night."); /**/ _getch();
    gameText.WriteLine("Seems safe enough, nothing more you can gain from this hallowed hall..."); /**/ _getch();
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
    std::cout << "| Health: " << std::to_string(player->GetHealth()) << " |\n";

    // ... print other stats with the same spacing

    gameText.WriteLine("Now's your chance! What action will you do?!");


    while (true) {
        gameText.WriteLine("1)  Attack\n2)  Drink Health Potion (" + std::to_string(player->GetHealthPotions()) + ")");
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

        gameText.WriteLine("You have chosen to attack! \n***Choose your target***\n");

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

    // maybe have enemies on side panel
    system("cls");
    gameText.WriteLineInput(name + " attacked you with " + skillName + ", " + skillDescription + " which hits for " + std::to_string(attackDmg) + " hit points!\n");
}

bool UI::DescribePlayerAttackOptions(std::shared_ptr<IEnemy> enemy, std::shared_ptr<IWeapon> weapon) {
    system("cls");

    gameText.WriteLine(std::string("Target is in sights, choose your next move...\n\n1)  ") + weapon->GetPrimarySkillName() + "\n2)  " + weapon->GetSecondarySkillName());

    std::string playerChoice; /**/ std::cin >> playerChoice;

    while (true) {

        if (playerChoice == "1") {

            system("cls");
            gameText.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED
            gameText.WriteLine("You used " + weapon->GetPrimarySkillName() + ", " + weapon->GetPrimarySkillDescription() + "...\n");
            
            gameText.WriteLine("onamonapea that represents attack");

            int attackDmg = weapon->UseSkillPrimary(); /**/ enemy->TakeDamage(attackDmg);
            //consider accuracy, chance to hit, evasion ratings

            gameText.WriteLineInput("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameText.WriteLineInput(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED

            return enemy->GetIsDead();
        }
        else if (playerChoice == "2") {

            system("cls");

            gameText.WriteLine(std::string(enemy->GetName()) + " currently has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED
            gameText.WriteLine("You have chosen to use " + weapon->GetSecondarySkillName() + ", " + weapon->GetSecondarySkillDescription());

            gameText.WriteLine("onamonapea that represents attack");

            int attackDmg = weapon->UseSkillPrimary(); /**/ enemy->TakeDamage(attackDmg);
            //consider accuracy, chance to hit, evasion ratings

            gameText.WriteLineInput("You have inflicted " + std::to_string(attackDmg) + " onto " + enemy->GetName());
            gameText.WriteLineInput(std::string(enemy->GetName()) + " now has " + std::to_string(enemy->GetHealth()) + " hp remaining TO BE REMOVED"); // ** TO BE REMOVED

            return enemy->GetIsDead();
        }
    }

    return false;

}

void UI::HealthRemaining(int healthRemaining) {
    gameText.WriteLine("You have " + std::to_string(healthRemaining) + "remaining TO BE REMOVED"); // ** TO BE REMOVED

}

void UI::KilledEnemy(std::shared_ptr<IEnemy> enemy) {
    if (enemy->GetName() == "Changeling") {

        gameText.WriteLineInput("You have slain the evil " + enemy->GetName());
        gameText.WriteLineInput("He was a dispicable devil. Good to be rid of him, knighted you should be, at the King's Palace! On the fourth night of Dune Riah.");
        return;
    }
    gameText.WriteLineInput("You have slain " + enemy->GetName());
}

void UI::SlainAllEnemies() {
    gameText.WriteLineInput("You have slain all the scorbles that plague this room");
}

void UI::FoundKey(std::string dungeonName) {
    if (dungeonName == "Tenebrific Depths") {
        gameText.WriteLineInput("You have filled your pockets with all the glitters of this Foul Tomb, but upon your leave, a strange twinkle catches your glance");
        gameText.WriteLineInput("Wait...");
        gameText.WriteLineInput("A key! Tis metal and skeletal, an iron thing, sitting right upon a jagged stone, \n which is surrounded a stagnate black water puddle. \nYee should pockets it for keepsakes, 'case you'll find need of it by and by!");
    }
    else if (dungeonName == "Cursed Abyssal Sanctum") {
        gameText.WriteLineInput("What's this??");
        gameText.WriteLineInput("How intriguing... You notice upon stepping upon a particular brick in the floor, that is one quite loose! As you remove it from it's place of settlement you see...");
        gameText.WriteLineInput("Another key!! But this one is rather unique...");
        gameText.WriteLineInput("It glimmers of fine iron and with an ornate hand made crest on the handle. \nA purple gem placed in the center surrounded by small black rustic unpolished rare gemstones.");
        gameText.WriteLineInput("Surely this is dwarven-make. I would keep that if I were you sire, could open doors of great mytery.");
    }
}

void UI::RoomLocked() {
    gameText.WriteLineInput("The room is locked, you will need a key to enter.");
}

void UI::LootBegin(std::vector<std::shared_ptr<LootItem>> loot) {
    system("cls");
    gameText.WriteLineInput("You peer around, silence. The town of Winterspell inches closer to security by victory of your hand!");
    gameText.WriteLineInput("You wander through the empty dark, damp, decrepit room to fill your pockets, you greedy little thing.");
    gameText.WriteLine("You find...\n");

    for (const auto& item : loot) {

        gameText.WriteText(item->GetName() + ", \n");
    }

    _getch();
}

std::shared_ptr<LootItem> UI::DisplayInventoryMenu(std::vector<std::shared_ptr<LootItem>> inventory) {
    
    while (true) {
        system("cls");
        gameText.WriteLine("*____________Inventory____________*\n\n");

        std::vector < std::pair<int, std::shared_ptr<LootItem>>> selectableLoot;

        for (int i = 0; i < inventory.size(); i++) {

            std::shared_ptr<LootItem> item = inventory[i];
            gameText.WriteLine(std::to_string(i + 1) + ")  " + item->GetName() + item->GetInfo());

            selectableLoot.emplace_back((i + 1), inventory[i]);
        }

        gameText.WriteLine("x)  exit menu");

        std::string playerChoice = input.PlayerChoice(inventory.size());
        if (playerChoice == "x") { // player wishes to exit menu
            system("cls");

            return nullptr;
        }

        int IDSelected = std::stoi(playerChoice);

        // lambda function
        auto selectedItem = std::find_if(selectableLoot.begin(), selectableLoot.end(), [IDSelected](const std::pair<int, std::shared_ptr<LootItem>>& item) {
            return item.first == IDSelected;
            });

        if (selectedItem != selectableLoot.end()) {

            return selectedItem->second;
        }
        else {
            gameText.WriteLineInput("Not sure you are being rational! Please save all the cans of beans for the charity this spring");
            system("cls");
        }
    }

    _getch();
    system("cls");

}

void UI::CannotUseItem() {
    gameText.WriteLineInput("Not sure what you can use that right now.");
}

// maybe need to scope some out to inventory
void UI::ItemMenu(std::shared_ptr<LootItem> item, std::shared_ptr<PlayerCharacter> playerCharacter) {

    while (true) {
        system("cls");
        gameText.WriteLine("\nWhat would you like to do with the " + item->GetName() + item->GetInfo() + "?");


        if (item->GetItemType() == ItemType::Equiptment) {
            gameText.WriteLine("e)  Equipt");
            gameText.WriteLine("t)  Get Description");
            gameText.WriteLine("d)  Drop");
            gameText.WriteLine("x)  Cancel");
        }
        else {
            gameText.WriteLine("t)  Get Description");
            gameText.WriteLine("d)  Drop");
            gameText.WriteLine("x)  Cancel");
        }

        std::string playerChoice; /**/ std::cin >> playerChoice;
        if (playerChoice == "e" && item->GetItemType() == ItemType::Equiptment) {
            playerCharacter->SetEquiptItems(item);
            return;
        }
        else if (playerChoice == "t") {
            gameText.WriteLineInput(item->GetDescription());
            return;
        }
        else if (playerChoice == "d") {
            playerCharacter->RemoveFromInventory(item);
            return;
        }
        else if (playerChoice == "") {
            system("cls");
            return;
        }
        else {
            system("cls");

            gameText.WriteLine("wut? UwU");
        }
    }
}

std::string UI::Inquiry() {

    while (true) {

        gameText.WriteLine("What would you like to do next?\n");
        gameText.WriteLine("i)  View Inventory");
        gameText.WriteLine("c)  View Character");
        gameText.WriteLine("x)  venture forth");

        std::string playerChoice; /**/ std::cin >> playerChoice;

        if (playerChoice == "i" || playerChoice ==  "I") {
            return "i";
        }
        else if (playerChoice == "c" || playerChoice == "C") {
            return "c";
        }
        else if (playerChoice == "x" || playerChoice == "X") {
            system("cls");
            return "x";
        }
        else {
            system("cls");
            gameText.WriteLine("wut UwU");
        }
    }
}

void UI::AlreadyEquiptItem() {
    gameText.WriteLine("You already have this item equipt!");
}

void UI::OpenCharacterMenu(std::shared_ptr<PlayerCharacter> playerCharacter) {
    system("cls");
    gameText.WriteWithoutTyping(playerCharacter->GetName() + " | Level: " + std::to_string(playerCharacter->GetLevel()));

    gameText.WriteWithoutTyping("Max health: " + std::to_string(playerCharacter->GetMaxHealth()) + " | Current health: " + std::to_string(playerCharacter->GetHealth()));
    
    gameText.WriteWithoutTyping("Armour rating: " + std::to_string(playerCharacter->GetArmourRating()));
    //gameText.WriteLine("Spell resistance: " + std::to_string(playerCharacter->GetSpellResistance()) + " | ");

    std::string isSwift = playerCharacter->GetHasSwiftness() ? " (has swiftness)" : "";
    gameText.WriteWithoutTyping("Strength: " + std::to_string(playerCharacter->GetStrength())
    + " | Dexterity: " + std::to_string(playerCharacter->GetDexterity()) + isSwift
    + " | Intellegence: " + std::to_string(playerCharacter->GetIntelligence()));
    gameText.WriteWithoutTyping("xp: " + std::to_string(playerCharacter->GetXP()) + " | xp to next level: " + "tbd");

    gameText.WriteWithoutTyping("weapon: " + playerCharacter->GetWeapon()->GetName());

    gameText.WriteWithoutTyping("Skill 1: " + playerCharacter->GetWeapon()->GetPrimarySkillName()
    + ": " + playerCharacter->GetWeapon()->GetPrimarySkillDescription() + " | Damage: " + std::to_string(playerCharacter->GetWeapon()->GetPrimarySkillDamageRange()[0]) + "-" + std::to_string(playerCharacter->GetWeapon()->GetPrimarySkillDamageRange()[1]));

    gameText.WriteWithoutTyping("Skill 2 (AOE): " + playerCharacter->GetWeapon()->GetSecondarySkillName()
        + ": " + playerCharacter->GetWeapon()->GetSecondarySkillDescription() + " | Damage: " + std::to_string(playerCharacter->GetWeapon()->GetSecondarySkillDamageRange()[0]) + "-" + std::to_string(playerCharacter->GetWeapon()->GetSecondarySkillDamageRange()[1]));

    _getch();
}