#include "ExploreUI.h"

void ExploreUI::RoomLocked() {
	gameTxt_.WriteLineInput("The room is locked, you will need a key to enter.");
}

void ExploreUI::NoEnemy() {
	gameTxt_.WriteLine("The shallow wispers in the room are faint and dismal, this room has had blood spilled of your hand this night."); /**/ _getch();
	gameTxt_.WriteLine("Seems safe enough, nothing more you can gain from this hallowed hall..."); /**/ _getch();
}

void ExploreUI::DescribeDungeonRoom(std::string description) {

	gameTxt_.WriteLine(description); /**/ _getch();
}
