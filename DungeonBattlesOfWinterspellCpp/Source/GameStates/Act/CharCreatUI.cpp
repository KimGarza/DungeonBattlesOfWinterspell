#include "..\..\..\Headers\GameStates\Act\CharCreatUI.h"

std::string CharCreatUI::ChooseClass() {
    system("cls");

    gameText.WriteLine("Pray tell... Who are you ?");

    while (true) {
        gameText.WriteLine("\n1)  Woodelf \n2)  Dwarf \n3)  Enchantress\n");

        std::string playerChoice; /**/ std::cin >> playerChoice;

        if (playerChoice == "1" || playerChoice == "2" || playerChoice == "3") {

            return playerChoice;
        }
        else {
            system("cls");
            gameText.WriteLine("Indeed you are a cheeky one aren't you? Please tell me true now, who art thou?");
        }
    }
}

void CharCreatUI::CharacterSelected(std::shared_ptr<Character> characterClass) {

    system("cls");

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

std::string CharCreatUI::ChooseWeapon(std::shared_ptr<Character> characterClass) {

    system("cls");

    gameText.WriteLine("Ah! Now then. Though cannot see trechors below and fight gobgobs with just thy bare mitts!");
    gameText.WriteLineInput("Weapon of choice good sir ?");
    gameText.WriteLine("These are the only weapons fit for yee from the armoury, if it please thee, make thy choice.\n");

    while (true) {

        DisplayWeaponOptions(characterClass);

        std::string playerChoice; /**/ std::cin >> playerChoice;

        // this could get past to input class
        if (playerChoice == "1" || playerChoice == "2" || playerChoice == "3") {

            return playerChoice;
        }
        else {
            system("cls");
            gameText.WriteLine("Please tell me true now, which weapon is of choice?\n");
        }
    }
}

void CharCreatUI::DisplayWeaponOptions(std::shared_ptr<Character> characterClass) {

    int weaponID = 1;
    for (std::string weaponName : characterClass->GetWeaponOptions()) {

        gameText.WriteLine(std::to_string(weaponID) + ")   " + weaponName);
        weaponID++;
    }

    std::cout << "\n";
}

void CharCreatUI::WeaponSelected(std::string weaponName) {
    system("cls");

    gameText.WriteLineInput("The " + weaponName + ", an ardent choice!");
}

std::string CharCreatUI::AttributeAssignment(int pointsRemaining, std::map<std::string, int> attributeJournal) {
    system("cls");

    if (pointsRemaining == 3) { // only declared at starting point of attr allocation
        gameText.WriteLineInput("Now shall we asses thine qualities ?");
    }

    while (true) {

        gameText.WriteLine("You have " + std::to_string(pointsRemaining) + " points left to allocate into each attribute, please assign your skill points");
        gameText.WriteLine("\n1) Intelligence: " + std::to_string(attributeJournal["intellegence"]) + "		2) Dexterity: " + std::to_string(attributeJournal["dexterity"]) + "		3) Strength: " + std::to_string(attributeJournal["strength"]) + "\n");
        gameText.WriteLine("Which attribute would you like to assign points to ?");

        /* acts as a guide for correlating player selected attribute dynamically with the name of that attribute
            so that it can be used to find within the actual attribute journal and know which att player is trying to modify */
        std::map<std::string, std::string> selectableAttributes = {
            {"1", "intellegence"},
            {"2", "dexterity"},
            {"3", "strength"}
        };

        std::string playerChoice; /**/ std::cin >> playerChoice;

        if (playerChoice == "1" || playerChoice == "2" || playerChoice == "3") {
            return playerChoice;
        }
        else {
            system("cls");
            gameText.WriteLine("Please select from available attributes...");
        }
    }

    return "";
}

int CharCreatUI::PointsAllocation(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining, std::string specializedAttribute, std::map<std::string, int> attributeJournal) {

    system("cls");

    while (true) {

        gameText.WriteLine("How many points would you like to spec to " + selectableAttributes[chosenAttribute] + "?\n");

        std::string pointsToAssignStr = input.AttributePoints(pointsRemaining);

        if (pointsToAssignStr != "") {

            int pointsToAssign = std::stoi(pointsToAssignStr);
            // Checking that points do not reduce the naturally occuring 4 pts for users specialized attribute (ex: dwarf has 4 base strength)
            if (selectableAttributes[chosenAttribute] == specializedAttribute && (attributeJournal[selectableAttributes[chosenAttribute]] + pointsToAssign < 4)) {

                system("cls");
                gameText.WriteLineInput("Forswear not to underestimate your natural abilities!");

                system("cls");
                gameText.WriteLine("So again...");
                gameText.WriteLine("You have " + std::to_string(pointsRemaining) + " points left to allocate into each attribute, please assign your skill points");
            }
            else {
                return pointsToAssign;
            }
        }
        else {
            system("cls");
            gameText.WriteLineInput("Shan't we try to be reasonable, and stay thee within the bounds of reality?");

            system("cls");
            gameText.WriteLine("So again...");
            gameText.WriteLine("You have " + std::to_string(pointsRemaining) + " points left to allocate into each attribute, please assign your skill points");

        }
    }

    system("cls");
    return 0;
}