#include "UI.h"
#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include <conio.h>

void UI::DisplayMap(std::vector<std::string> dungeonRooms, int indexStop) {
    gameText.WriteLine("You have made a discovery! Your next dungeon location is revealed before you...\n\n");

    //for (int i = 0; i < dungeonRooms.size(); i++) {
    //    if (i == 4 || i == 8) {
    //        std::cout << "\n\n";
    //    }
    //    if (i != 0 && i >= indexStop) {
    //        if (i != dungeonRooms.size() - 1) {
    //            gameText.WriteText("Undiscovered...    -->  ");
    //        } else {
    //            gameText.WriteText("Undiscovered");
    //        }
    //    }
    //    else {
    //        if (i != dungeonRooms.size() - 1) {
    //            gameText.WriteText(dungeonRooms[i] + "   -->  ");
    //        }
    //        else {
    //            gameText.WriteText(dungeonRooms[i]);
    //        }
    //    }
    //}

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