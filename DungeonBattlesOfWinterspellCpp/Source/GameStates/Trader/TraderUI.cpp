#include "..\..\..\Headers\GameStates\Trader\TraderUI.h"

bool TraderUI::TradeInquiry() {
    system("cls");

    while (true) {
        gameText.WriteLine("Trade? \ny) Yes\nn) No\n");
        std::string playerChoice; /**/ std::cin >> playerChoice;

        if (playerChoice == "y") {
            return true;
        }
        else if (playerChoice == "n") {
            return false;
        }
        else {
            system("cls");
            gameText.WriteLine("Please make your choice known mortal squashable human.");
        }
    }
    return false;
}

std::string TraderUI::TradeSelectMenu(std::shared_ptr<PlayerCharacter> player) {
    system("cls");

    while (true) {
        gameText.WriteWithoutTyping("s) Sell\nb) Buy\nx) Cancel");

        std::string playerChoice; /**/ std::cin >> playerChoice;

        if (playerChoice == "s" || playerChoice == "b" || playerChoice == "x") {
            return playerChoice;
        }
        else {
            system("cls");
            gameText.WriteLine("Please make your choice known mortal squashable human.");
        }
    }

    return "";
}

std::shared_ptr<LootItem> TraderUI::DisplaySellMenu(std::shared_ptr<PlayerCharacter> player) {

    while (true) {
        system("cls");

        int consoleWidth = 100; // This is an example width, you may get or set this programmatically
        int panelWidth = 20; // The fixed width of your stats panel

        int spaceBeforePanel = consoleWidth - panelWidth;

        // Print the stats panel with the correct spacing
        for (int i = 0; i < spaceBeforePanel; ++i) {
            std::cout << " "; // Print spaces before the panel starts
        }


        auto gold = player->GetGold();
        std::cout << "Gold: " << std::to_string(gold);

        std::vector<std::shared_ptr<LootItem>> inventory = player->GetLoot();
        gameText.WriteLine("\n*** Select items to sell ***\n\n");

        std::vector < std::pair<int, std::shared_ptr<LootItem>>> selectableLoot;

        for (int i = 0; i < inventory.size(); i++) {

            std::shared_ptr<LootItem> item = inventory[i];
            gameText.WriteLine(std::to_string(i + 1) + ")  " + item->GetName() + item->GetInfo() + " (" + std::to_string(item->GetWorthInGold()) + " gp)");

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
            gameText.WriteLineInput("Please choose an item you wish to barter");
            system("cls");
        }
    }

    _getch();
    system("cls");

}

std::shared_ptr<LootItem> TraderUI::DisplayBuyMenu(std::shared_ptr<PlayerCharacter> player, std::shared_ptr<Trader> trader) {

    while (true) {
        system("cls");

        int consoleWidth = 100; // This is an example width, you may get or set this programmatically
        int panelWidth = 20; // The fixed width of your stats panel

        int spaceBeforePanel = consoleWidth - panelWidth;

        // Print the stats panel with the correct spacing
        for (int i = 0; i < spaceBeforePanel; ++i) {
            std::cout << " "; // Print spaces before the panel starts
        }

        std::cout << "Gold: " << std::to_string(player->GetGold());

        //std::vector<std::shared_ptr<LootItem>> inventory = abalask->GetWares();
        gameText.WriteLine("\n*** Select items to Barter ***\n\n");

        std::vector < std::pair<int, std::shared_ptr<LootItem>>> selectableLoot;

        for (int i = 0; i < trader->GetWares().size(); i++) {

            std::shared_ptr<LootItem> item = trader->GetWares()[i];
            gameText.WriteLine(std::to_string(i + 1) + ")  " + item->GetName() + item->GetInfo() + " (" + std::to_string(item->GetWorthInGold()) + " gp)");

            selectableLoot.emplace_back((i + 1), trader->GetWares()[i]);
        }

        gameText.WriteLine("x)  exit menu");

        std::string playerChoice = input.PlayerChoice(trader->GetWares().size());
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
            gameText.WriteLineInput("Please choose an item you wish to barter");
            system("cls");
        }
    }

    _getch();
    system("cls");

}

void TraderUI::CannotAfford() {
    gameText.WriteLineInput("You cannot afford that.");
}