#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include "Enemy.h"
#include "Character.h"
#include "Weapon.h"
#include <sstream>
#include <conio.h>
#include <memory>
#include <numeric>
#include <iostream>
#include <cctype>
#include <map>













void UI::FoundKey(std::string dungeonName) {
    if (dungeonName == "Tenebrific Depths") {
        gameText.WriteLineInput("You have filled your pockets with all the glitters of this Foul Tomb, but upon your leave, a strange twinkle catches your glance");
        gameText.WriteLineInput("Wait...");
        gameText.WriteLineInput("A key! Tis metal and skeletal, an iron thing, sitting right upon a jagged stone, \n which is surrounded a stagnate black water puddle. \nYee should pockets it for keepsakes, 'case you'll find need of it by and by!");
    }
    else if (dungeonName == "Abyssal Crypts") {
        gameText.WriteLineInput("What's this??");
        gameText.WriteLineInput("How intriguing... You notice upon stepping upon a particular brick in the floor, that is one quite loose! As you remove it from it's place of settlement you see...");
        gameText.WriteLineInput("Another key!! But this one is rather unique...");
        gameText.WriteLineInput("It glimmers of fine iron and with an ornate hand made crest on the handle. \nA purple gem placed in the center surrounded by small black rustic unpolished rare gemstones.");
        gameText.WriteLineInput("Surely this is dwarven-make. I would keep that if I were you sire, could open doors of great mytery.");
    }
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
        else if (playerChoice != "") {

            int IDSelected = std::stoi(playerChoice);

            // lambda function
            auto selectedItem = std::find_if(selectableLoot.begin(), selectableLoot.end(), [IDSelected](const std::pair<int, std::shared_ptr<LootItem>>& item) {
                return item.first == IDSelected;
                });

            if (selectedItem != selectableLoot.end()) {

                return selectedItem->second;
            }
        }
        else {
            system("cls");
            gameText.WriteLineInput("Please select an item from your inventory.");
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